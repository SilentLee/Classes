#include "NetworkSession.h"
#include "GlobalInstanceApi.h"

USING_NS_CC;

void CNetworkSession::onPT_ARRANGE_CARD_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_CARD_SUCC_U");
	READ_PACKET(PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattle1V1ArrangeSuccU(recvData);
	operInfoInstance->setIsOperInfoRecv(true);
}