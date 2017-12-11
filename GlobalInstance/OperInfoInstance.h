#pragma once
//#include "DataType.h"
#include "Global.h"
#include "BATTLE_Protocol.h" // ʹ�� ProtocolHeader.h �ᱨ��
#include "BATTLE_PT_Structure.h"
#include "Weapon.h"


class COperInfoInstance
{
// ���ݽ��ճɹ���ָʾ��־
private:
	bool mIsOperInfoRecv;
	// ս��̬�Ƹ���ָʾ
	bool mIsBattleFieldSituationUpdate;

// �������ݵĻ�����
private:
	// ������������ɹ���Ϣ�����ݻ�����
	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M mPtBattleArrangeWeaponSuccM;
	// ���շ�ս��̬�Ƹ�����Ϣ�����ݻ�����
	S_PT_BATTLE_UPDATE_SITUATION_M mPtBattleUpdateSituationM;

public:
	void resetOperInfoInstance();

private:
	COperInfoInstance();
	virtual ~COperInfoInstance();
	bool init();

	static COperInfoInstance* operInfoInstance;
	COperInfoInstance* mOperInfoInstance;

// ��־λ��ȡ����
public:
	void setIsOperInfoRecv(bool isOperInfoRecv) { mIsOperInfoRecv = isOperInfoRecv; }
	bool getIsOperInfoRecv() { return mIsOperInfoRecv; }
	// ս��̬�Ƹ���ָʾ
	void setIsBattleFieldSituationUpdate(bool isBattleFieldSituationUpdate){ mIsBattleFieldSituationUpdate = isBattleFieldSituationUpdate; };
	bool getIsBattleFieldSituationUpdate(){ return mIsBattleFieldSituationUpdate; };

public:
	static COperInfoInstance* getInstance();
	void setOperInfoInstance(COperInfoInstance* operInfoInstance) { mOperInfoInstance = operInfoInstance; };

// ���ݻ�������ȡ����
public:
	// ������������ɹ���Ϣ�����ݻ�����
	void setPtBattleArrangeWeaponSuccM(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M ptBattleArrganeWeaponSuccM) { memcpy(&mPtBattleArrangeWeaponSuccM, &ptBattleArrganeWeaponSuccM, sizeof(S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M)); };
	S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M getPtBattleArrangeWeaponSuccM() { return mPtBattleArrangeWeaponSuccM; };

	// ���շ�ս��̬�Ƹ�����Ϣ�����ݻ�����
	void setPtBattleUpdateSituationM(S_PT_BATTLE_UPDATE_SITUATION_M ptBattleUpdateSituationM){ memcpy(&mPtBattleUpdateSituationM, &ptBattleUpdateSituationM, sizeof(S_PT_BATTLE_UPDATE_SITUATION_M)); };
	S_PT_BATTLE_UPDATE_SITUATION_M getPtBattleUpdateSituationM(){ return mPtBattleUpdateSituationM; };
};