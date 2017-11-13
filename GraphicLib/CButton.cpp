#include "CButton.h"

CButton* CButton::createButtonWithAbsolutePos(std::string fileName, int posX, int posY)
{
	CButton* ret = new CButton();
	if (ret && ret->initWithAbsolutePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CButton* CButton::createButtonWithRelativePos(std::string fileName, float posX, float posY)
{
	CButton* ret = new CButton();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CButton::initWithAbsolutePos(std::string filename, int posX, int posY)
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

bool CButton::initWithRelativePos(std::string filename, float posX, float posY)
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

void CButton::onPressStateChangedToNormal()
{
	this->setSizeAdp(1.0);
}

void CButton::onPressStateChangedToPressed()
{
	this->setSizeAdp(0.8);
}

void CButton::setButtonImage(std::string filename)
{
	this->loadTextures(filename, filename, filename);
}
