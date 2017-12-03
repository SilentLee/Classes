#include "NetworkSession.h"
#include "GlobalInstanceApi.h"

USING_NS_CC;

void CNetworkSession::onPT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT__BATTLE_SEARCH_ROOM_SUCC_U");
	READ_PACKET(PT_BATTLE_SEARCH_ROOM_SUCC_U);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	roomInstance->setRoomID(recvData.ROOM_ID);
	roomInstance->setStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

void CNetworkSession::onPT_ARRANGE_CARD_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_CARD_SUCC_U");
	READ_PACKET(PT_BATTLE_ARRANGE_CARD_SUCC_U);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleArrangeSuccU(recvData);
	operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_BATTLE_START_GAME_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_1V1_START_GAME_M");
	READ_PACKET(PT_BATTLE_START_GAME_M);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();
	roomInstance->setCurrentTime(recvData.START_TIME);
	roomInstance->setStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}