#include "BtnCardDB.h"

BtnCardDB* BtnCardDB::createBtnCardDBWithAbsolutePos(int cardType, int posX, int posY)
{
	BtnCardDB* ret = new BtnCardDB();
	if (ret && ret->initWithAbsolutePos(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BtnCardDB* BtnCardDB::createBtnCardDBWithRelativePos(int cardType, float posX, float posY)
{
	BtnCardDB* ret = new BtnCardDB();

	if (ret && ret->initWithRelativePos(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool BtnCardDB::initWithAbsolutePos(int cardType, int posX, int posY)
{
	mCardType = cardType;
	CButton::initWithAbsolutePos(ImageUrlLoader::getCardImageUrls(cardType).c_str(), posX, posY);

	return true;
}

bool BtnCardDB::initWithRelativePos(int cardType, float posX, float posY)
{
	mCardType = cardType;
	CButton::initWithRelativePos(ImageUrlLoader::getCardImageUrls(cardType).c_str(), posX, posY);

	return true;
}