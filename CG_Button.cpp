#include "CG_Button.h"

CG_Button* CG_Button::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	CG_Button* ret = new CG_Button();
	if (ret && ret->initWithAbsolutePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CG_Button* CG_Button::createWithRelativePos(std::string fileName, float posX, float posY)
{
	CG_Button* ret = new CG_Button();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CG_Button::initWithAbsolutePos(std::string filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Button::init(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setAdpPosWithAbsoluteValue(posX, posY);

	return true;
}

bool CG_Button::initWithRelativePos(std::string filename, float posX, float posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Button::init(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setAdpPosWithRelativeValue(posX, posY);

	return true;
}

void CG_Button::onPressStateChangedToNormal()
{
	this->setSizeAdp(1.0);
}

void CG_Button::onPressStateChangedToPressed()
{
	this->setSizeAdp(0.8);
}

void CG_Button::setButtonImage(std::string filename)
{
	this->loadTextures(filename, filename, filename);
}
