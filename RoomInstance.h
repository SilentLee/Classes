#pragma once
#include "DataType.h"
#include "LibParamApi.h"
#include <list>

#include "BATTLE_1V1_Protocol.h" // ʹ�� ProtocolHeader.h �ᱨ��
#include "BATTLE_1V1_PT_Structure.h"

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
	ROOM_TYPE mType;
	// ���䵱ǰ״̬
	ROOM_STATUS mStatus;
	// �����ڷ������е�ָ���ַ
	DWORD_PTR mRoomID;
	// ��ǰ��ʣ��Ϸʱ��
	int mCurrentTime;
	// ��Ϸ��ʼ��־λ
	bool mHasGameBegan;

	// ��������б�
	list<S_USER*> mUsersInBlueTeam;
	list<S_USER*> mUsersInRedTeam;

public:
	// ���临λ����
	bool resetRoom(){ return init(); };

// ��ȡ����
public:
	void setType(ROOM_TYPE type){ mType = type; };
	ROOM_TYPE getType(){ return mType; };

	void setStatus(ROOM_STATUS status){ mStatus = status; };
	ROOM_STATUS getStatus(){ return mStatus; };

	int getCurrentUserCount(){ return mUsersInBlueTeam.size() + mUsersInRedTeam.size(); };

	void setRoomID(DWORD_PTR roomID){ mRoomID = roomID; };
	DWORD_PTR getRoomID(){ return mRoomID; };

	void setCurrentTime(int currentTime){ mCurrentTime = currentTime; };
	int getCurrentTime(){ return mCurrentTime; };

	void setHasGameBegan(bool hasGameBegan){ mHasGameBegan = hasGameBegan; };
	int getHasGameBegan(){ return mHasGameBegan; };
};