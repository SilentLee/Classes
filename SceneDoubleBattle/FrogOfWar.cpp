#include "FrogOfWar.h"

FrogOfWar* FrogOfWar::createFrogOfWarWithAbsolutePos(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithRelativePos(std::string fileName, float posX, float posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithPosInSquare(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool FrogOfWar::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CSprite::initWithAbsolutePos(filename, posX, posY);

	// 初始化物理引擎

	return true;
}

bool FrogOfWar::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CSprite::initWithRelativePos(filename, posX, posY);

	return true;
}

bool FrogOfWar::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CSprite::initWithRealAbsolutePos(filename, posX, posY);

	return true;
}

bool FrogOfWar::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CSprite::initWithPosInSquare(filename, posX, posY);

	return true;
}
