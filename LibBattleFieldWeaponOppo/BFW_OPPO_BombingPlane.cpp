#include "BFW_OPPO_BombingPlane.h"

BFW_OPPO_BombingPlane* BFW_OPPO_BombingPlane::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_OPPO_BombingPlane* ret = new BFW_OPPO_BombingPlane();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BombingPlane* BFW_OPPO_BombingPlane::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_BombingPlane* ret = new BFW_OPPO_BombingPlane();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BombingPlane* BFW_OPPO_BombingPlane::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_BombingPlane* ret = new BFW_OPPO_BombingPlane();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BombingPlane* BFW_OPPO_BombingPlane::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_OPPO_BombingPlane* ret = new BFW_OPPO_BombingPlane();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BFW_OPPO_BombingPlane::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 载入轰炸机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_BOMBING_PLANE);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_BombingPlane::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入轰炸机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_BOMBING_PLANE);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_BombingPlane::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 载入轰炸机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_BOMBING_PLANE);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_BombingPlane::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入轰炸机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_BOMBING_PLANE);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

void BFW_OPPO_BombingPlane::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_BOMBING_PLANE); // 设定物体类别掩码
	body->setCollisionBitmask(BIT_MASK_COLLISION_BOMBING_PLANE); // 设定碰撞掩码 执行碰撞反应
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_BOMBING_PLANE); // 设定接触掩码 执行碰撞事件
	this->setPhysicsBody(body);
}

//// 调度函数
//void BFW_BombingPlane::update(float dt)
//{
//	// 设置飞机行进
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_BOMBING_PLANE);
//	this->setRotation(0);
//	return;
//}