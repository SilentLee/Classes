#pragma once
#include "DataType.h"
#include "LibParamApi.h"
#include <list>

#include "BATTLE_Protocol.h" // ʹ�� ProtocolHeader.h �ᱨ��
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
// ����ģʽ�ı�Ҫ����
private:
	CRoomInstance(){};
	virtual ~CRoomInstance(){};
	bool init();
	static CRoomInstance* roomInstance;
	CRoomInstance* mRoomInstance;

// ����ģʽ�ı�Ҫ����
public:
	static CRoomInstance* getInstance();
	void setRoomInstance(CRoomInstance* roomInstance) { mRoomInstance = roomInstance; };

private:
	// ��������
	ROOM_TYPE mRoomType;
	// ���䵱ǰ״̬
	ROOM_STATUS mRoomStatus;
	// �����ڷ������е�ָ���ַ
	DWORD_PTR mRoomID;
	// ��ǰ�������
	int mCurrentUserCount;

	// ��ǰ��ʣ��Ϸʱ��
	int mRemainingTime;
	// ��Ϸ��ʼ��־λ
	//bool mHasGameBegan;

	// ��������б�
	list<S_USER*> mUsersInBlueTeam;
	list<S_USER*> mUsersInRedTeam;

public:
	// ���临λ����
	bool resetRoom(){ return init(); };

// ��ȡ����
public:
	void setRoomType(ROOM_TYPE type){ mRoomType = type; };
	ROOM_TYPE geRoomtType(){ return mRoomType; };

	void setRoomStatus(ROOM_STATUS roomStatus){ mRoomStatus = roomStatus; };
	ROOM_STATUS getRoomStatus(){ return mRoomStatus; };

	//int getCurrentUserCount(){ return mUsersInBlueTeam.size() + mUsersInRedTeam.size(); };

	void setRoomID(DWORD_PTR roomID){ mRoomID = roomID; };
	DWORD_PTR getRoomID(){ return mRoomID; };

	void setCurrentUserCount(int currentUserCount){ mCurrentUserCount = currentUserCount; };
	int getCurrentUserCount(){ return mCurrentUserCount; };

	void setRemainingTime(int remainingTime){ mRemainingTime = remainingTime; };
	int getRemainingTime(){ return mRemainingTime; };

	//void setHasGameBegan(bool hasGameBegan){ mHasGameBegan = hasGameBegan; };
	//int getHasGameBegan(){ return mHasGameBegan; };
};
