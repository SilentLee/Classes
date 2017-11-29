#include "SceneSelect.h"
#include "GlobalInstanceApi.h"

void SceneSelect::BtnStartCallback()
{
	log("SceneSelect::BtnStartCallback");

	S_PT_BATTLE_1V1_SEARCH_ROOM ptDBSearchRoom;
	memset(&ptDBSearchRoom, 0, sizeof(ptDBSearchRoom));

	BYTE WriteBuffer[MAX_BUFFER_LENGTH] = { 0, };
	CNetworkSession* networkSession = CNetworkInstance::getInstance()->getNetworkSession();
	networkSession->WritePacket(PT_BATTLE_1V1_SEARCH_ROOM,
		WriteBuffer,
		WRITE_PT_BATTLE_1V1_SEARCH_ROOM(WriteBuffer, ptDBSearchRoom));
}