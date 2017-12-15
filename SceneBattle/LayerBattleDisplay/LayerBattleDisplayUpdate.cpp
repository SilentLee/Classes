#include "LayerBattleDisplay.h"
#include "BattleFieldWeapon_OWN.h"
#include "LibBattleFieldGraphApi.h"
#include "GlobalInstanceApi.h"

// ���º���
void LayerBattleDisplay::updateFrog(float dt)
{
	// ���������ֽ�������λ��
	memset(mFrogLine, 0, sizeof(int) * BATTLE_FIELD_WIDTH_IN_SQUARE);

	for (int i = 0; i < mWeaponsOwn.size(); i++)
	{
		int posX = mWeaponsOwn[i]->getPosXInSquare();
		int posY = mWeaponsOwn[i]->getPosYInSquare();
		int rangeDec = mWeaponsOwn[i]->getPropertyWp().RANGE_DEC;

		mFrogLine[max(0, posX - 1)] = max(mFrogLine[max(0, posX - 1)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[posX] = max(mFrogLine[posX], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)] =
			max(mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
	}

	// ����ս��������ʾ��Χ
	for (int indexX = 0; indexX < BATTLE_FIELD_WIDTH_IN_SQUARE; indexX++)
	{
		for (int indexY = 0; indexY < BATTLE_FIELD_HEIGHT_IN_SQUARE; indexY++)
		{
			if (indexY <= mFrogLine[indexX])
			{
				mFrogOfWarArray[indexX][indexY]->setVisible(false);
			}
			else {
				mFrogOfWarArray[indexX][indexY]->setVisible(true);
			}
		}
	}

	// ���ڲ����������ܵĴ���
	for (vector<BattleFieldWeapon_OWN*>::iterator iter = mWeaponsOwn.begin(); iter != mWeaponsOwn.end(); iter++) {
		BattleFieldWeapon_OWN* weapon = (BattleFieldWeapon_OWN*)*iter;
		if (weapon->getPosYInSquare() == 10)
		{
			mWeaponsOwn.erase(iter);
			//weapon->retain();
			weapon->removeFromParent();
			return;
		}
	}
}

void LayerBattleDisplay::updateBFSituation(float dt)
{
	log("LayerBattleFieldDB::updateBFSituation");

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	CUserInstance* userInstance = CUserInstance::getInstance();

	// ���յ�����
	// onPT_ARRANGE_WEAPON_SUCC_M
	if (operInfoInstance->getIsOperInfoRecv()) {
		S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M ptBattleArrangeWeaponSuccU = operInfoInstance->getPtBattleArrangeWeaponSuccM();
		operInfoInstance->setIsOperInfoRecv(false);
		log("load S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M");

		// ���ڶ�ս��һ��
		ENUM_TROOPS troopsIn = (ENUM_TROOPS)ptBattleArrangeWeaponSuccU.TROOPS_IN;
		// ��������
		int weaponType = ptBattleArrangeWeaponSuccU.WEAPON_TYPE;
		// ��ʼ��������
		float posX = ptBattleArrangeWeaponSuccU.POS_X;
		float posY = ptBattleArrangeWeaponSuccU.POS_Y;
		// ��ս���еı�ǩ
		int weaponTag = ptBattleArrangeWeaponSuccU.WEAPON_TAG;
		// �����ٶ�
		int speed = ptBattleArrangeWeaponSuccU.SPEED;
		
		// �������뵱ǰ�ͻ������ͬ��һ�� ���뱾����Ӫ
		if (troopsIn == userInstance->getTroopsIn()) {
			arrangeOwnWeaponWithAbsolutePos(troopsIn, weaponType, posX, posY, weaponTag);
		}
		// �������뵱ǰ�ͻ�����Ҳ�ͬ��һ�� ����Է���Ӫ
		else {
			arrangeEnemyWeaponWithAbsolutePos(troopsIn, weaponType, posX, posY, weaponTag);
		}
	}


	// ����ս��̬��
	// onPT_BATTLE_UPDATE_SITUATION_M
	if (operInfoInstance->getIsBattleFieldSituationUpdate()) {

		S_PT_BATTLE_UPDATE_SITUATION_M ptBattleUpdateSituationM = operInfoInstance->getPtBattleUpdateSituationM();

		// ��ȡ��Ϸʣ��ʱ��
		int RemainingTime = ptBattleUpdateSituationM.REMAINING_GAME_TIME;
		// ��ȡ�����������ݳ���
		int BlueTroopsDataLength = ptBattleUpdateSituationM.BLUE_TROOPS_DATA_LENGTH;
		// ��ȡ�췽�������ݳ���
		int RedTroopsDataLength = ptBattleUpdateSituationM.RED_TROOPS_DATA_LENGTH;
		//// ��ȡ����������Ϊ���ݳ���
		//int BlueTroopsActionDataLength = recvData.BLUE_TROOPS_ACTION_DATA_LENGTH;
		//// ��ȡ�췽������Ϊ���ݳ���
		//int RedTroopsActionDataLength = recvData.RED_TROOPS_ACTION_DATA_LENGTH;

		// ������Ҫ���ٵ����ݻ������ĳ���
		int SizeOfBlueTroopsData = BlueTroopsDataLength / sizeof(Weapon);
		int SizeOfRedTroopsData = RedTroopsDataLength / sizeof(Weapon);

		vector<Weapon> BlueTroopsData;
		vector<Weapon> RedTroopsData;

		if (BlueTroopsDataLength != 0) {
			log("receive weapons blue");
			BlueTroopsData.resize(SizeOfBlueTroopsData);
			memcpy(&BlueTroopsData[0], ptBattleUpdateSituationM.DATA, BlueTroopsDataLength);
		}

		if (RedTroopsDataLength != 0){
			log("receive weapons red");
			RedTroopsData.resize(SizeOfRedTroopsData);
			memcpy(&RedTroopsData[0], ptBattleUpdateSituationM.DATA + BlueTroopsDataLength, RedTroopsDataLength);
		}

		for (int i = 0; i < SizeOfBlueTroopsData; i++) {
			this->removeChildByTag(BlueTroopsData[i].GetWeaponTag());
			if (BlueTroopsData[i].GetTroopsIn() == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithAbsolutePos((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
			else {
				arrangeEnemyWeaponWithAbsolutePos((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
		}

		for (int i = 0; i < SizeOfRedTroopsData; i++) {
			this->removeChildByTag(RedTroopsData[i].GetWeaponTag());
			if (RedTroopsData[i].GetTroopsIn() == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithAbsolutePos((ENUM_TROOPS)RedTroopsData[i].GetTroopsIn(), RedTroopsData[i].GetProperty().WP_TYPE, RedTroopsData[i].GetPosX(), RedTroopsData[i].GetPosY(), RedTroopsData[i].GetWeaponTag());
			}
			else {
				arrangeEnemyWeaponWithAbsolutePos((ENUM_TROOPS)RedTroopsData[i].GetTroopsIn(), RedTroopsData[i].GetProperty().WP_TYPE, RedTroopsData[i].GetPosX(), RedTroopsData[i].GetPosY(), RedTroopsData[i].GetWeaponTag());
			}
		}

		operInfoInstance->setIsBattleFieldSituationUpdate(false);
	}
}