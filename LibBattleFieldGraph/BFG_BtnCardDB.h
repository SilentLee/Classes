#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

class BFG_BtnCard : public CG_Button
{
public:
	static BFG_BtnCard* createWithAbsolutePos(int cardType, int posX, int posY);
	static BFG_BtnCard* createWithRelativePos(int cardType, float posX, float posY);

	bool initWithAbsolutePos(int cardType, int posX, int posY);
	bool initWithRelativePos(int cardType, float posX, float posY);

private:
	int mCardType;

public:
	void setCardType(int cardType){ mCardType = cardType; };
	int getCardType(){ return mCardType; };
};