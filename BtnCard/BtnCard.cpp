#include "BtnCard.h"

// 创建函数
BtnCard* BtnCard::create(ENUM_CARD_TYPE cardType, float posX, float posY)
{
	BtnCard* ret = new BtnCard();
	if (ret && ret->init(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BtnCard::init(ENUM_CARD_TYPE cardType, float posX, float posY)
{
	// 调用父类初始化函数
	Button::init(CU_ImgLoader::getCardImg(cardType).c_str());
	// 设置位置
	this->setPosition(Vec2(posX, posY));

	return true;
}

// 松开按钮的回调函数
void BtnCard::onPressStateChangedToNormal()
{
	this->setScale(1.0f);
}

// 按下按钮的回调函数
void BtnCard::onPressStateChangedToPressed()
{
	this->setScale(0.8f);
}

// 设置按钮图片
void BtnCard::setButtonImage(std::string filename)
{
	this->loadTextures(filename, filename, filename);
}