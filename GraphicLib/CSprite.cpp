#include "CSprite.h"

CSprite* CSprite::createSpriteWithAbsolutePos(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithRelativePos(std::string fileName, float posX, float posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithPosInSquare(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CSprite::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Sprite::initWithFile(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setAdpPosWithAbsoluteValue(posX, posY);

	// 父类初始化
	return true;
}

bool CSprite::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Sprite::initWithFile(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setAdpPosWithRelativeValue(posX, posY);

	return true;
}
bool CSprite::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Sprite::initWithFile(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setRealPosWithAbsoluteValue(posX, posY);

	// 父类初始化
	return true;
}

bool CSprite::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Sprite::initWithFile(filename);

	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setPosInSquare(posX, posY);

	// 父类初始化
	return true;
}