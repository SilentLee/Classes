#pragma once
//#include "DataType.h"
#include "Global.h"
#include "BATTLE_Protocol.h" // ʹ�� ProtocolHeader.h �ᱨ��
#include "BATTLE_PT_Structure.h"


class COperInfoInstance
{
private:
	bool mIsOperInfoRecv;

	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U mPtBattleArrangeWeaponSuccU;

public:
	void resetOperInfoInstance();
public:
	

public:
	void setIsOperInfoRecv(bool isOperInfoRecv) { mIsOperInfoRecv = isOperInfoRecv; }
	bool getIsOperInfoRecv() { return mIsOperInfoRecv; }
private:
	COperInfoInstance();
	virtual ~COperInfoInstance();
	bool init();

	static COperInfoInstance* operInfoInstance;
	COperInfoInstance* mOperInfoInstance;
public:
	static COperInfoInstance* getInstance();
	void setOperInfoInstance(COperInfoInstance* operInfoInstance) { mOperInfoInstance = operInfoInstance; };

public:
	// ��ȡ����
	void setPtBattleArrangeWeaponSuccU(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U ptBattleArrganeWeaponSuccU) { memcpy(&mPtBattleArrangeWeaponSuccU, &ptBattleArrganeWeaponSuccU, sizeof(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U)); };
	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U getPtBattleArrangeWeaponSuccU() { return mPtBattleArrangeWeaponSuccU; };
};