#include "LayerSelectButton.h"

void LayerSelectButton::BtnStartCallback(ROOM_TYPE roomType)
{
	log("SceneSelect::BtnStartCallback");

	S_PT_BATTLE_SEARCH_ROOM ptBattleSearchRoom;
	memset(&ptBattleSearchRoom, 0, sizeof(S_PT_BATTLE_SEARCH_ROOM));

	ptBattleSearchRoom.ROOM_TYPE = roomType;

	BYTE WriteBuffer[MAX_BUFFER_LENGTH] = { 0, };
	CNetworkSession* networkSession = CNetworkInstance::getInstance()->getNetworkSession();
	networkSession->WritePacket(PT_BATTLE_SEARCH_ROOM,
		WriteBuffer,
		WRITE_PT_BATTLE_SEARCH_ROOM(WriteBuffer, ptBattleSearchRoom));
}