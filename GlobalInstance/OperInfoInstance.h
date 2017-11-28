#pragma once
//#include "DataType.h"
#include "Global.h"
#include "BATTLE_1V1_Protocol.h" // 使用 ProtocolHeader.h 会报错
#include "BATTLE_1V1_PT_Structure.h"


class COperInfoInstance
{
private:
	bool mIsOperInfoRecv;

	S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U mPtBattle1V1ArrangeSuccU;

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
	// 存取函数
	void setPtBattle1V1ArrangeSuccU(S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U ptBattle1V1ArrganeSuccU) { memcpy(&mPtBattle1V1ArrangeSuccU, &ptBattle1V1ArrganeSuccU, sizeof(S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U)); };
	S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U getPtBattle1V1ArrangeSuccU() { return mPtBattle1V1ArrangeSuccU; };
};