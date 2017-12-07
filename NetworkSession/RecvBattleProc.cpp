#include "NetworkSession.h"
#include "GlobalInstanceApi.h"
#include "Weapon.h"

USING_NS_CC;

void CNetworkSession::onPT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT__BATTLE_SEARCH_ROOM_SUCC_U");
	READ_PACKET(PT_BATTLE_SEARCH_ROOM_SUCC_U);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	roomInstance->setRoomID(recvData.ROOM_ID);
	roomInstance->setStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

void CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_U");
	READ_PACKET(PT_BATTLE_ARRANGE_WEAPON_SUCC_U);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleArrangeWeaponSuccU(recvData);
	operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_BATTLE_START_GAME_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_START_GAME_M");
	READ_PACKET(PT_BATTLE_START_GAME_M);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();
	roomInstance->setRemainingTime(recvData.START_TIME);
	roomInstance->setStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

void CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M");
	READ_PACKET(PT_BATTLE_UPDATE_SITUATION_M);

	// 读取游戏剩余时间
	int RemainingTime = recvData.REMAINING_GAME_TIME;
	// 读取蓝方兵力数据长度
	int BlueTroopsDataLength = recvData.BLUE_TROOPS_DATA_LENGTH;
	// 读取红方兵力数据长度
	int RedTroopsDataLength = recvData.RED_TROOPS_DATA_LENGTH;
	// 读取蓝方兵力行为数据长度
	int BlueTroopsActionDataLength = recvData.BLUE_TROOPS_ACTION_DATA_LENGTH;
	// 读取红方兵力行为数据长度
	int RedTroopsActionDataLength = recvData.RED_TROOPS_ACTION_DATA_LENGTH;

	// 计算需要开辟的数据缓冲区的长度
	int SizeOfBlueTroopsData = BlueTroopsDataLength / sizeof(Weapon);
	int SizeOfRedTroopsData = RedTroopsDataLength / sizeof(Weapon);

	vector<Weapon> BlueTroopsData;
	vector<Weapon> RedTroopsData;

	if (BlueTroopsDataLength != 0) {
		log("receive weapons blue");
		BlueTroopsData.resize(SizeOfBlueTroopsData + 1);
		memcpy(&BlueTroopsData[0], recvData.DATA, BlueTroopsDataLength);
	}

	if (RedTroopsDataLength != 0){
		log("receive weapons red");		
		RedTroopsData.resize(SizeOfRedTroopsData + 1);
		memcpy(&RedTroopsData[0], recvData.DATA + BlueTroopsDataLength, RedTroopsDataLength);
	}

	return;
}