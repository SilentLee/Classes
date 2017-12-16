#include "LayerBattleDisplay.h"
#include "BattleFieldWeapon_OWN.h"
#include "LibBattleFieldGraphApi.h"
#include "GlobalInstanceApi.h"

// 更新函数
//void LayerBattleDisplay::updateFrog(float dt)
//{
//	// 计算迷雾分界线所在位置
//	memset(mFrogLine, 0, sizeof(int) * BATTLE_FIELD_WIDTH_IN_SQUARE);
//
//	for (int i = 0; i < mWeaponsOwn.size(); i++)
//	{
//		int posX = mWeaponsOwn[i]->GetCoordinate().x;
//		int posY = mWeaponsOwn[i]->GetCoordinate().y;
//		int rangeDec = mWeaponsOwn[i]->GetPropertyWp().RANGE_DEC;
//
//		mFrogLine[max(0, posX - 1)] = max(mFrogLine[max(0, posX - 1)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//		mFrogLine[posX] = max(mFrogLine[posX], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//		mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)] =
//			max(mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//	}
//
//	// 设置战场迷雾显示范围
//	for (int indexX = 0; indexX < BATTLE_FIELD_WIDTH_IN_SQUARE; indexX++)
//	{
//		for (int indexY = 0; indexY < BATTLE_FIELD_HEIGHT_IN_SQUARE; indexY++)
//		{
//			if (indexY <= mFrogLine[indexX])
//			{
//				mFrogOfWarArray[indexX][indexY]->setVisible(false);
//			}
//			else {
//				mFrogOfWarArray[indexX][indexY]->setVisible(true);
//			}
//		}
//	}
//
//	// 用于测试迷雾功能的代码
//	for (vector<BattleFieldWeapon_OWN*>::iterator iter = mWeaponsOwn.begin(); iter != mWeaponsOwn.end(); iter++) {
//		BattleFieldWeapon_OWN* weapon = (BattleFieldWeapon_OWN*)*iter;
//		if (weapon->GetCoordinate().y == 10)
//		{
//			mWeaponsOwn.erase(iter);
//			//weapon->retain();
//			weapon->removeFromParent();
//			return;
//		}
//	}
//}

void LayerBattleDisplay::updateBFSituation(float dt)
{
	log("LayerBattleFieldDB::updateBFSituation");

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	CUserInstance* userInstance = CUserInstance::getInstance();

	// 接收到武器
	// onPT_ARRANGE_WEAPON_SUCC_M
	if (operInfoInstance->getIsOperInfoRecv()) {
		S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M ptBattleArrangeWeaponSuccU = operInfoInstance->getPtBattleArrangeWeaponSuccM();
		operInfoInstance->setIsOperInfoRecv(false);
		log("load S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M");

		// 属于对战哪一方
		ENUM_TROOPS troopsIn = (ENUM_TROOPS)ptBattleArrangeWeaponSuccU.TROOPS_IN;
		// 武器类型
		int weaponType = ptBattleArrangeWeaponSuccU.WEAPON_TYPE;
		// 初始布设坐标
		float posX = ptBattleArrangeWeaponSuccU.POS_X;
		float posY = ptBattleArrangeWeaponSuccU.POS_Y;
		// 在战场中的标签
		int weaponTag = ptBattleArrangeWeaponSuccU.WEAPON_TAG;
		// 飞行速度
		int speed = ptBattleArrangeWeaponSuccU.SPEED;
		
		// 若武器与当前客户端玩家同属一方 加入本方阵营
		if (troopsIn == userInstance->getTroopsIn()) {
			arrangeOwnWeaponWithPosition(troopsIn, weaponType, posX, posY, weaponTag);
		}
		// 若武器与当前客户端玩家不同属一方 加入对方阵营
		else {
			arrangeEnemyWeaponWithPosition(troopsIn, weaponType, posX, posY, weaponTag);
		}
	}


	// 更新战场态势
	// onPT_BATTLE_UPDATE_SITUATION_M
	if (operInfoInstance->getIsBattleFieldSituationUpdate()) {

		S_PT_BATTLE_UPDATE_SITUATION_M ptBattleUpdateSituationM = operInfoInstance->getPtBattleUpdateSituationM();

		// 读取游戏剩余时间
		int RemainingTime = ptBattleUpdateSituationM.REMAINING_GAME_TIME;
		// 读取蓝方兵力数据长度
		int BlueTroopsDataLength = ptBattleUpdateSituationM.BLUE_TROOPS_DATA_LENGTH;
		// 读取红方兵力数据长度
		int RedTroopsDataLength = ptBattleUpdateSituationM.RED_TROOPS_DATA_LENGTH;
		//// 读取蓝方兵力行为数据长度
		//int BlueTroopsActionDataLength = recvData.BLUE_TROOPS_ACTION_DATA_LENGTH;
		//// 读取红方兵力行为数据长度
		//int RedTroopsActionDataLength = recvData.RED_TROOPS_ACTION_DATA_LENGTH;

		// 计算需要开辟的数据缓冲区的长度
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
				arrangeOwnWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
			else {
				arrangeEnemyWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].GetTroopsIn(), BlueTroopsData[i].GetProperty().WP_TYPE, BlueTroopsData[i].GetPosX(), BlueTroopsData[i].GetPosY(), BlueTroopsData[i].GetWeaponTag());
			}
		}

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