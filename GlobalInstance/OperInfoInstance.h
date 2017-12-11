#pragma once
//#include "DataType.h"
#include "Global.h"
#include "BATTLE_Protocol.h" // 使用 ProtocolHeader.h 会报错
#include "BATTLE_PT_Structure.h"
#include "Weapon.h"


class COperInfoInstance
{
// 数据接收成功的指示标志
private:
	bool mIsOperInfoRecv;
	// 战场态势更新指示
	bool mIsBattleFieldSituationUpdate;

// 接收数据的缓冲区
private:
	// 接收武器布设成功消息的数据缓冲区
	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M mPtBattleArrangeWeaponSuccM;
	// 接收服战场态势更新消息的数据缓冲区
	S_PT_BATTLE_UPDATE_SITUATION_M mPtBattleUpdateSituationM;

public:
	void resetOperInfoInstance();

private:
	COperInfoInstance();
	virtual ~COperInfoInstance();
	bool init();

	static COperInfoInstance* operInfoInstance;
	COperInfoInstance* mOperInfoInstance;

// 标志位存取函数
public:
	void setIsOperInfoRecv(bool isOperInfoRecv) { mIsOperInfoRecv = isOperInfoRecv; }
	bool getIsOperInfoRecv() { return mIsOperInfoRecv; }
	// 战场态势更新指示
	void setIsBattleFieldSituationUpdate(bool isBattleFieldSituationUpdate){ mIsBattleFieldSituationUpdate = isBattleFieldSituationUpdate; };
	bool getIsBattleFieldSituationUpdate(){ return mIsBattleFieldSituationUpdate; };

public:
	static COperInfoInstance* getInstance();
	void setOperInfoInstance(COperInfoInstance* operInfoInstance) { mOperInfoInstance = operInfoInstance; };

// 数据缓冲区存取函数
public:
	// 接收武器布设成功消息的数据缓冲区
	void setPtBattleArrangeWeaponSuccM(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M ptBattleArrganeWeaponSuccM) { memcpy(&mPtBattleArrangeWeaponSuccM, &ptBattleArrganeWeaponSuccM, sizeof(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M)); };
	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M getPtBattleArrangeWeaponSuccM() { return mPtBattleArrangeWeaponSuccM; };

	// 接收服战场态势更新消息的数据缓冲区
	void setPtBattleUpdateSituationM(S_PT_BATTLE_UPDATE_SITUATION_M ptBattleUpdateSituationM){ memcpy(&mPtBattleUpdateSituationM, &ptBattleUpdateSituationM, sizeof(S_PT_BATTLE_UPDATE_SITUATION_M)); };
	S_PT_BATTLE_UPDATE_SITUATION_M getPtBattleUpdateSituationM(){ return mPtBattleUpdateSituationM; };
};