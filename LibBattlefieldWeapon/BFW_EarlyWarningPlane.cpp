#include "BFW_EarlyWarningPlane.h"

BFW_EarlyWarningPlane* BFW_EarlyWarningPlane::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_EarlyWarningPlane* ret = new BFW_EarlyWarningPlane();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_EarlyWarningPlane* BFW_EarlyWarningPlane::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_EarlyWarningPlane* ret = new BFW_EarlyWarningPlane();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_EarlyWarningPlane* BFW_EarlyWarningPlane::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_EarlyWarningPlane* ret = new BFW_EarlyWarningPlane();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_EarlyWarningPlane* BFW_EarlyWarningPlane::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_EarlyWarningPlane* ret = new BFW_EarlyWarningPlane();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BFW_EarlyWarningPlane::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 载入预警机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_EARLY_WARNING_PLANE);

	// 父类初始化
	BFW_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_EarlyWarningPlane::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入预警机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_EARLY_WARNING_PLANE);

	// 父类初始化
	BFW_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_EarlyWarningPlane::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 载入预警机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_EARLY_WARNING_PLANE);

	// 父类初始化
	BFW_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_EarlyWarningPlane::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入预警机参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_EARLY_WARNING_PLANE);

	// 父类初始化
	BFW_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

void BFW_EarlyWarningPlane::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_FIGHTER_PLANE); // 设定物体类别掩码
	body->setCollisionBitmask(BIT_MASK_COLLISION_FIGHTER_PLANE); // 设定碰撞掩码 执行碰撞反应
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_FIGHTER_PLANE); // 设定接触掩码 执行碰撞事件
	this->setPhysicsBody(body);
}

//// 调度函数
//void BFW_EarlyWarningPlane::update(float dt)
//{
//	// 设置预警机飞行
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_EARLY_WARNING_PLANE);
//	this->setRotation(0);
//	return;
//}