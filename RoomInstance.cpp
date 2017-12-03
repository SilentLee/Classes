#include "RoomInstance.h"

CRoomInstance* CRoomInstance::roomInstance = NULL;

bool CRoomInstance::init()
{
	mType = RM_NO_TYPE;
	mStatus = RM_EMPTY;
	mRoomID = 0;
	mCurrentTime = DEFAULT_GAME_TIME;

	mHasGameBegan = false;

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