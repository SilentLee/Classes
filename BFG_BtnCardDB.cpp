#include "LibBattleFieldGraphApi.h"

BFG_BtnCard* BFG_BtnCard::createWithAbsolutePos(int cardType, int posX, int posY)
{
	BFG_BtnCard* ret = new BFG_BtnCard();
	if (ret && ret->initWithAbsolutePos(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFG_BtnCard* BFG_BtnCard::createWithRelativePos(int cardType, float posX, float posY)
{
	BFG_BtnCard* ret = new BFG_BtnCard();

	if (ret && ret->initWithRelativePos(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool BFG_BtnCard::initWithAbsolutePos(int cardType, int posX, int posY)
{
	mCardType = cardType;
	CG_Button::initWithAbsolutePos(CU_ImgLoader::getCardImg(cardType).c_str(), posX, posY);

	return true;
}

bool BFG_BtnCard::initWithRelativePos(int cardType, float posX, float posY)
{
	mCardType = cardType;
	CG_Button::initWithRelativePos(CU_ImgLoader::getCardImg(cardType).c_str(), posX, posY);

	return true;
}