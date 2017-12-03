#include "NetworkSession.h"
#include "GlobalInstanceApi.h"

USING_NS_CC;

void CNetworkSession::onPT__BATTLE_1V1_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT__BATTLE_1V1_SEARCH_ROOM_SUCC_U");
	READ_PACKET(PT_BATTLE_1V1_SEARCH_ROOM_SUCC_U);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	roomInstance->setRoomID(recvData.ROOM_ID);
	roomInstance->setStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

void CNetworkSession::onPT_ARRANGE_CARD_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_CARD_SUCC_U");
	READ_PACKET(PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattle1V1ArrangeSuccU(recvData);
	operInfoInstance->setIsOperInfoRecv(true);
}