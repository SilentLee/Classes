#include "NetworkSession.h"
#include "GlobalInstanceApi.h"
#include "Weapon.h"

USING_NS_CC;

// Ѱ�ҵ��������Ϣ������
void CNetworkSession::onPT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
	log("CNetworkSession::onPT__BATTLE_SEARCH_ROOM_SUCC_U");
	READ_PACKET(PT_BATTLE_SEARCH_ROOM_SUCC_U);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();
	CUserInstance* userInstance = CUserInstance::getInstance();

	// ��������ڶ�ս��������һ��
	userInstance->setSideInGame((ENUM_SIDE_IN_GAME)recvData.SIDE_IN_GAME);
	// ������ұ�������
	if (recvData.SIDE_IN_GAME == SIDE_BLUE) {
		userInstance->setTroopsIn(TROOPS_BLUE);
	}
	else if (recvData.SIDE_IN_GAME == SIDE_RED) {
		userInstance->setTroopsIn(TROOPS_RED);
	}

	// ���÷���������ָ��
	roomInstance->setRoomID(recvData.ROOM_ID);
	// ���÷�������
	roomInstance->setRoomType((ROOM_TYPE)recvData.ROOM_TYPE);
	// ���õ�ǰ�ж�������ڷ�����
	roomInstance->setCurrentUserCount(recvData.CURRENT_USER_COUNT);
	// ���÷���״̬
	// ת�� SceneSelect::UpdateToBattle �н��д���
	roomInstance->setRoomStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

// ��ʼ��Ϸ����Ϣ������
void CNetworkSession::onPT_BATTLE_START_GAME_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_START_GAME_M");
	READ_PACKET(PT_BATTLE_START_GAME_M);

	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// ת�� SceneSelect::UpdateToBattle �н��д���
	roomInstance->setRoomStatus((ROOM_STATUS)recvData.ROOM_STATUS);
}

// ���յ���������ɹ�����Ϣ������
void CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_M(BYTE* packet)
{
	log("CNetworkSession::onPT_ARRANGE_WEAPON_SUCC_M");
	READ_PACKET(PT_BATTLE_ARRANGE_WEAPON_SUCC_M);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleArrangeWeaponSuccM(recvData);

	// ת�� LayerBattleFieldDB::updateBFSituation �н��д���
	operInfoInstance->setIsOperInfoRecv(true);
}

// ս��̬�Ƹ��µ���Ϣ������
void CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M(BYTE* packet)
{
	log("CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M");
	READ_PACKET(PT_BATTLE_UPDATE_SITUATION_M);

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	operInfoInstance->setPtBattleUpdateSituationM(recvData);

	// ת�� LayerBattleFieldDB::updateBFSituation �н��д���
	operInfoInstance->setIsBattleFieldSituationUpdate(true);





	//log("CNetworkSession::onPT_BATTLE_UPDATE_SITUATION_M");
	//READ_PACKET(PT_BATTLE_UPDATE_SITUATION_M);

	//// ��ȡ��Ϸʣ��ʱ��
	//int RemainingTime = recvData.REMAINING_GAME_TIME;
	//// ��ȡ�����������ݳ���
	//int BlueTroopsDataLength = recvData.BLUE_TROOPS_DATA_LENGTH;
	//// ��ȡ�췽�������ݳ���
	//int RedTroopsDataLength = recvData.RED_TROOPS_DATA_LENGTH;
	////// ��ȡ����������Ϊ���ݳ���
	////int BlueTroopsActionDataLength = recvData.BLUE_TROOPS_ACTION_DATA_LENGTH;
	////// ��ȡ�췽������Ϊ���ݳ���
	////int RedTroopsActionDataLength = recvData.RED_TROOPS_ACTION_DATA_LENGTH;

	//// ������Ҫ���ٵ����ݻ������ĳ���
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