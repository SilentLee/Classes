#include "BFG_FrogOfWar.h"

BFG_FrogOfWar* BFG_FrogOfWar::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFG_FrogOfWar* ret = new BFG_FrogOfWar();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFG_FrogOfWar* BFG_FrogOfWar::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFG_FrogOfWar* ret = new BFG_FrogOfWar();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFG_FrogOfWar* BFG_FrogOfWar::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFG_FrogOfWar* ret = new BFG_FrogOfWar();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFG_FrogOfWar* BFG_FrogOfWar::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFG_FrogOfWar* ret = new BFG_FrogOfWar();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool BFG_FrogOfWar::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);

	// 初始化物理引擎
	initPhysicsBody();

	return true;
}

bool BFG_FrogOfWar::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CG_Sprite::initWithRelativePos(filename, posX, posY);

	// 初始化物理引擎
	initPhysicsBody();

	return true;
}

bool BFG_FrogOfWar::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CG_Sprite::initWithRealAbsolutePos(filename, posX, posY);

	// 初始化物理引擎
	initPhysicsBody();

	return true;
}

bool BFG_FrogOfWar::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CG_Sprite::initWithPosInSquare(filename, posX, posY);

	return true;
}

void BFG_FrogOfWar::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(0x0001); // 设定物体类别掩码
	body->setCollisionBitmask(0x0001); // 设定碰撞掩码 执行碰撞反应
	body->setContactTestBitmask(0x0011); // 设定接触掩码 执行碰撞事件
	this->setPhysicsBody(body);
}