#pragma once
#include "..\Classes\GraphicLib\ApiGraphicLib.h"
#include "..\Classes\Utils\ImageUrlLoader.h"

class BtnCardDB : public CButton
{
public:
	static BtnCardDB* createBtnCardDBWithAbsolutePos(int cardType, int posX, int posY);
	static BtnCardDB* createBtnCardDBWithRelativePos(int cardType, float posX, float posY);

	bool initWithAbsolutePos(int cardType, int posX, int posY);
	bool initWithRelativePos(int cardType, float posX, float posY);

private:
	int mCardType;

public:
	void setCardType(int cardType){ mCardType = cardType; };
	int getCardType(){ return mCardType; };
};