#include "NetworkSession.h"
#include "GlobalInstanceApi.h"

USING_NS_CC;

// 寻找到房间的消息处理函数
void CNetworkSession::onPT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT__BATTLE_SEARCH_ROOM_SUCC_U");
	READ_PACKET(PT_BATTLE_SEARCH_ROOM_SUCC_U);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();
	CUserInstance* userInstance = CUserInstance::getInstance();

	// 设置玩家在对战中属于哪一方
	userInstance->setSideInGame((ENUM_SIDE_IN_GAME)recvData.SIDE_IN_GAME);
	// 设置玩家兵力所属
	if (recvData.SIDE_IN_GAME == SIDE_BLUE) {
		userInstance->setTroopsIn(TROOPS_BLUE);
	}
	else if (recvData.SIDE_IN_GAME == SIDE_RED) {
		userInstance->setTroopsIn(TROOPS_RED);
	}

	// 设置服务器房间指针
	roomInstance->setRoomID(recvData.ROOM_ID);
	// 设置房间类型
	roomInstance->setRoomType((ROOM_TYPE)recvData.ROOM_TYPE);
	// 设置当前有多少玩家在房间中
	roomInstance->setCurrentUserCount(recvData.CURRENT_USER_COUNT);
	// 设置房间状态
	// 转到 SceneSelect::UpdateToBattle 中进行处理
	roomInstance->setRoomStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

// 开始游戏的消息处理函数
void CNetworkSession::onPT_BATTLE_START_GAME_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_START_GAME_M");
	READ_PACKET(PT_BATTLE_START_GAME_M);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// 转到 SceneSelect::UpdateToBattle 中进行处理
	roomInstance->setRoomStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

// 接收到武器布设成功的消息处理函数
void CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_M(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_M");
	READ_PACKET(PT_BATTLE_ARRANGE_WEAPON_SUCC_M);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleArrangeWeaponSuccM(recvData);

	// 转到 LayerBattleFieldDB::updateBFSituation 中进行处理
	operInfoInstance->setIsOperInfoRecv(true);
}

// 战场态势更新的消息处理函数
void CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M");
	READ_PACKET(PT_BATTLE_UPDATE_SITUATION_M);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleUpdateSituationM(recvData);

	// 转到 LayerBattleFieldDB::updateBFSituation 中进行处理
	operInfoInstance->setIsBattleFieldSituationUpdate(true);





	//log("CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M");
	//READ_PACKET(PT_BATTLE_UPDATE_SITUATION_M);

	//// 读取游戏剩余时间
	//int RemainingTime = recvData.REMAINING_GAME_TIME;
	//// 读取蓝方兵力数据长度
	//int BlueTroopsDataLength = recvData.BLUE_TROOPS_DATA_LENGTH;
	//// 读取红方兵力数据长度
	//int RedTroopsDataLength = recvData.RED_TROOPS_DATA_LENGTH;
	////// 读取蓝方兵力行为数据长度
	////int BlueTroopsActionDataLength = recvData.BLUE_TROOPS_ACTION_DATA_LENGTH;
	////// 读取红方兵力行为数据长度
	////int RedTroopsActionDataLength = recvData.RED_TROOPS_ACTION_DATA_LENGTH;

	//// 计算需要开辟的数据缓冲区的长度
	//int SizeOfBlueTroopsData = BlueTroopsDataLength / sizeof(Weapon);
	//int SizeOfRedTroopsData = RedTroopsDataLength / sizeof(Weapon);

	//vector<Weapon> BlueTroopsData;
	//vector<Weapon> RedTroopsData;

	//if (BlueTroopsDataLength != 0) {
	//	log("receive weapons blue");
	//	BlueTroopsData.resize(SizeOfBlueTroopsData + 1);
	//	memcpy(&BlueTroopsData[0], recvData.DATA, BlueTroopsDataLength);
	//}

	//if (RedTroopsDataLength != 0){
	//	log("receive weapons red");		
	//	RedTroopsData.resize(SizeOfRedTroopsData + 1);
	//	memcpy(&RedTroopsData[0], recvData.DATA + BlueTroopsDataLength, RedTroopsDataLength);
	//}

	//COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();

	return;
}