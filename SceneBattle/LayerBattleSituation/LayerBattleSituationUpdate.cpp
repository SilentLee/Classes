#include "LayerBattleSituation.h"
#include "BattleFieldWeapon.h"
#include "GlobalInstanceApi.h"
#include "ParamCards.h"

// 更新函数
void LayerBattleSituation::updateFrog(float dt)
{
	// 计算迷雾分界线所在位置
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

	// 设置战场迷雾显示范围
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

// 检测服务器战场态势更新数据并更新客户端战场态势显示的更新函数
void LayerBattleSituation::updateBFSituation(float dt)
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
		int SizeOfBlueTroopsData = BlueTroopsDataLength / sizeof(S_WEAPON);
		int SizeOfRedTroopsData = RedTroopsDataLength / sizeof(S_WEAPON);

		vector<S_WEAPON> BlueTroopsData;
		vector<S_WEAPON> RedTroopsData;

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

		// 清除对战双方仿真兵力存储动态数组
		mWeaponsOwn.clear();
		mWeaponsOppo.clear();

		// 刷新蓝方兵力
		for (int i = 0; i < SizeOfBlueTroopsData; i++) {
			this->removeChildByTag(BlueTroopsData[i].WEAPON_TAG);
			if (BlueTroopsData[i].TROOP_IN == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].TROOP_IN, BlueTroopsData[i].PROPERTY_WP.WP_TYPE, BlueTroopsData[i].POSITION_IN_SIMULATION_MAP.x, BlueTroopsData[i].POSITION_IN_SIMULATION_MAP.y, BlueTroopsData[i].WEAPON_TAG);
			}
			else {
				arrangeEnemyWeaponWithPosition((ENUM_TROOPS)BlueTroopsData[i].TROOP_IN, BlueTroopsData[i].PROPERTY_WP.WP_TYPE, BlueTroopsData[i].POSITION_IN_SIMULATION_MAP.x, BlueTroopsData[i].POSITION_IN_SIMULATION_MAP.y, BlueTroopsData[i].WEAPON_TAG);
			}
		}

		// 刷新红方兵力
		for (int i = 0; i < SizeOfRedTroopsData; i++) {
			this->removeChildByTag(RedTroopsData[i].WEAPON_TAG);
			if (RedTroopsData[i].TROOP_IN == userInstance->getTroopsIn()) {
				arrangeOwnWeaponWithPosition((ENUM_TROOPS)RedTroopsData[i].TROOP_IN, RedTroopsData[i].PROPERTY_WP.WP_TYPE, RedTroopsData[i].POSITION_IN_SIMULATION_MAP.x, RedTroopsData[i].POSITION_IN_SIMULATION_MAP.y, RedTroopsData[i].WEAPON_TAG);
			}
			else {
				arrangeEnemyWeaponWithPosition((ENUM_TROOPS)RedTroopsData[i].TROOP_IN, RedTroopsData[i].PROPERTY_WP.WP_TYPE, RedTroopsData[i].POSITION_IN_SIMULATION_MAP.x, RedTroopsData[i].POSITION_IN_SIMULATION_MAP.y, RedTroopsData[i].WEAPON_TAG);
			}
		}
		operInfoInstance->setIsBattleFieldSituationUpdate(false);
	}
}

// 本地战场态势更新函数 用于平滑
void LayerBattleSituation::updateLocalSituation(float dt)
{
	// 刷新本方兵力
	if (mWeaponsOwn.size() > 0) {
		for (int index = 0; index < mWeaponsOwn.size(); index++) {
			// 移动
			mWeaponsOwn[index]->Move(mBattleSimulationMapCellArray);
			// 探测
			mWeaponsOwn[index]->Detect(mBattleSimulationMapCellArray);
		}
	}
	// 刷新对方兵力
	if (mWeaponsOppo.size() > 0) {
		for (int index = 0; index < mWeaponsOppo.size(); index++) {
			// 移动
			mWeaponsOppo[index]->Move(mBattleSimulationMapCellArray);
		}
	}

	// 重置本方兵力刷新操作状态
	if (mWeaponsOwn.size() > 0) {
		for (int index = 0; index < mWeaponsOwn.size(); index++) {
			// 重置兵力移动操作状态
			mWeaponsOwn[index]->ResetMoveStatus();
		}
	}
	// 重置对方兵力刷新操作状态
	if (mWeaponsOppo.size() > 0) {
		for (int index = 0; index < mWeaponsOppo.size(); index++) {
			// 重置兵力移动操作状态
			mWeaponsOppo[index]->ResetMoveStatus();
		}
	}
}