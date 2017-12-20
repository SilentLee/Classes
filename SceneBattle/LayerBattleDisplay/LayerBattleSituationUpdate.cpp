#include "LayerBattleSituation.h"
#include "BattleFieldWeapon.h"
#include "LibBattleFieldGraphApi.h"
#include "GlobalInstanceApi.h"

// ���º���
void LayerBattleSituation::updateFrog(float dt)
{
	// ��������ֽ�������λ��
	memset(mFrogLine, 0, sizeof(int) * WIDTH_OF_BATTLE_SIMULATION_MAP);

	for (int i = 0; i < mWeaponsOwn.size(); i++)
	{
		int posX = mWeaponsOwn[i]->GetCoordinate().x;
		int posY = mWeaponsOwn[i]->GetCoordinate().y;
		int rangeDec = mWeaponsOwn[i]->GetPropertyWp().RANGE_DEC;

		mFrogLine[max(0, posX - 1)] = max(mFrogLine[max(0, posX - 1)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[posX] = max(mFrogLine[posX], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[min(posX + 1, WIDTH_OF_BATTLE_SIMULATION_MAP)] =
			max(mFrogLine[min(posX + 1, WIDTH_OF_BATTLE_SIMULATION_MAP)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
	}

	// ����ս��������ʾ��Χ
	for (int indexX = 0; indexX < WIDTH_OF_BATTLE_SIMULATION_MAP; indexX++)
	{
		for (int indexY = 0; indexY < WIDTH_OF_BATTLE_SIMULATION_MAP; indexY++)
		{
			if (indexY <= mFrogLine[indexX])
			{
				mBattleSimulationMapCellArray[indexX][indexY]->setVisible(false);
			}
			else {
				mBattleSimulationMapCellArray[indexX][indexY]->setVisible(true);
			}
		}
	}
}

// ��������ս��̬�Ƹ������ݲ����¿ͻ���ս��̬����ʾ�ĸ��º���
void LayerBattleSituation::updateBFSituation(float dt)
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
			arrangeOwnWeaponWithPosition(troopsIn, weaponType, posX, posY, weaponTag);
		}
		// �������뵱ǰ�ͻ�����Ҳ�ͬ��һ�� ����Է���Ӫ
		else {
			arrangeEnemyWeaponWithPosition(troopsIn, weaponType, posX, posY, weaponTag);
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

		// �����ս˫����������洢��̬����
		mWeaponsOwn.clear();
		mWeaponsOppo.clear();

		// ˢ����������
		for (int i = 0; i < SizeOfBlueTroopsData; i++) {
			this->removeChildByTag(BlueTroopsData[i].GetWeaponTag());
			if (BlueTroopsData[i].GetTroopsIn() == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
			else {
				arrangeEnemyWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
		}

		// ˢ�º췽����
		for (int i = 0; i < SizeOfRedTroopsData; i++) {
			this->removeChildByTag(RedTroopsData[i].GetWeaponTag());
			if (RedTroopsData[i].GetTroopsIn() == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithPosition((ENUM_TROOPS)RedTroopsData[i].GetTroopsIn(), RedTroopsData[i].GetProperty().WP_TYPE, RedTroopsData[i].GetPosX(), RedTroopsData[i].GetPosY(), RedTroopsData[i].GetWeaponTag());
			}
			else {
				arrangeEnemyWeaponWithPosition((ENUM_TROOPS)RedTroopsData[i].GetTroopsIn(), RedTroopsData[i].GetProperty().WP_TYPE, RedTroopsData[i].GetPosX(), RedTroopsData[i].GetPosY(), RedTroopsData[i].GetWeaponTag());
			}
		}
		operInfoInstance->setIsBattleFieldSituationUpdate(false);
	}
}

// ����ս��̬�Ƹ��º��� ����ƽ��
void LayerBattleSituation::updateLocalSituation(float dt)
{
	// ˢ�±�������
	if (mWeaponsOwn.size() > 0) {
		for (int index = 0; index < mWeaponsOwn.size(); index++) {
			mWeaponsOwn[index]->Move(mBattleSimulationMapCellArray);
			mWeaponsOwn[index]->Detect(mBattleSimulationMapCellArray);
		}
	}
	// ˢ�¶Է�����
	if (mWeaponsOppo.size() > 0) {
		for (int index = 0; index < mWeaponsOppo.size(); index++) {
			mWeaponsOppo[index]->Move(mBattleSimulationMapCellArray);
		}
	}
}