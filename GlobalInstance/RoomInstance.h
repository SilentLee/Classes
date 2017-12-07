#pragma once
#include "DataType.h"
#include "LibParamApi.h"
#include <list>

#include "BATTLE_Protocol.h" // 使用 ProtocolHeader.h 会报错
#include "BATTLE_PT_Structure.h"

using namespace std;

extern struct S_USER;

typedef enum ROOM_STATUS
{
	RM_EMPTY = 0,
	RM_WAITING,
	RM_READY,
	RM_GAME_START,
	RM_GAME_IN_PROGRESS,
	RM_GAME_ENDING,
	RM_GAME_ENDED
};

typedef enum ROOM_TYPE
{
	RM_NO_TYPE = 0,
	RM_TYPE_1V1,
	RM_TYPE_2V2
};

class CRoomInstance
{
// 单例模式的必要函数
private:
	CRoomInstance(){};
	virtual ~CRoomInstance(){};
	bool init();
	static CRoomInstance* roomInstance;
	CRoomInstance* mRoomInstance;

// 单例模式的必要函数
public:
	static CRoomInstance* getInstance();
	void setRoomInstance(CRoomInstance* roomInstance) { mRoomInstance = roomInstance; };

private:
	// 房间类型
	ROOM_TYPE mType;
	// 房间当前状态
	ROOM_STATUS mStatus;
	// 房间在服务器中的指针地址
	DWORD_PTR mRoomID;
	// 当前所剩游戏时间
	int mRemainingTime;
	// 游戏开始标志位
	//bool mHasGameBegan;

	// 蓝队玩家列表
	list<S_USER*> mUsersInBlueTeam;
	list<S_USER*> mUsersInRedTeam;

public:
	// 房间复位函数
	bool resetRoom(){ return init(); };

// 存取函数
public:
	void setType(ROOM_TYPE type){ mType = type; };
	ROOM_TYPE getType(){ return mType; };

	void setStatus(ROOM_STATUS status){ mStatus = status; };
	ROOM_STATUS getStatus(){ return mStatus; };

	int getCurrentUserCount(){ return mUsersInBlueTeam.size() + mUsersInRedTeam.size(); };

	void setRoomID(DWORD_PTR roomID){ mRoomID = roomID; };
	DWORD_PTR getRoomID(){ return mRoomID; };

	void setRemainingTime(int remainingTime){ mRemainingTime = remainingTime; };
	int getRemainingTime(){ return mRemainingTime; };

	//void setHasGameBegan(bool hasGameBegan){ mHasGameBegan = hasGameBegan; };
	//int getHasGameBegan(){ return mHasGameBegan; };
};
