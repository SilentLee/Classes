#include "RoomInstance.h"

CRoomInstance* CRoomInstance::roomInstance = NULL;

bool CRoomInstance::init()
{
	mRoomType = RM_NO_TYPE;
	mRoomStatus = RM_EMPTY;
	mRoomID = 0;
	mRemainingTime = DEFAULT_GAME_TIME;

	mUsersInBlueTeam.clear();
	mUsersInRedTeam.clear();
	return true;
}

CRoomInstance* CRoomInstance::getInstance()
{
	if (NULL == roomInstance) {
		roomInstance = new CRoomInstance();
		roomInstance->init();
	}
	return roomInstance;
}