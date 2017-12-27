#pragma once
//#include "DataType.h"
#include "Global.h"
//#include "BATTLE_Protocol.h" // 使用 ProtocolHeader.h 会报错
//#include "BATTLE_PT_Structure.h"
//#include "Weapon.h"
#include "WeaponStructure.h"

typedef enum ENUM_SIDE_IN_GAME {
	SIDE_NONE,
	SIDE_BLUE,
	SIDE_RED
};

class CUserInstance
{
// 对战时的参数
private:
	ENUM_SIDE_IN_GAME mSideInGame;
	ENUM_TROOPS mTroopsIn;

public:
	void setSideInGame(ENUM_SIDE_IN_GAME sideInGame){ mSideInGame = sideInGame; };
	ENUM_SIDE_IN_GAME getSideInGame(){ return mSideInGame; };

	void setTroopsIn(ENUM_TROOPS troopsIn){ mTroopsIn = troopsIn; };
	ENUM_TROOPS getTroopsIn(){ return mTroopsIn; };

public:
	void resetUserInstance();

private:
	CUserInstance();
	virtual ~CUserInstance();
	bool init();

	static CUserInstance* userInstance;
	CUserInstance* mUserInstance;
public:
	static CUserInstance* getInstance();
	void setUserInstance(CUserInstance* userInstance) { mUserInstance = userInstance; };
};