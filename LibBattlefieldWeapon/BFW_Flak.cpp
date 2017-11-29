#include "BFW_Flak.h"

BFW_Flak* BFW_Flak::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_Flak* ret = new BFW_Flak();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_Flak* BFW_Flak::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_Flak* ret = new BFW_Flak();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_Flak* BFW_Flak::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_Flak* ret = new BFW_Flak();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_Flak* BFW_Flak::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_Flak* ret = new BFW_Flak();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BFW_Flak::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 载入高射炮参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_FLAK);

	// 父类初始化
	BFW_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_Flak::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入高射炮参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_FLAK);

	// 父类初始化
	BFW_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_Flak::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 载入高射炮参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_FLAK);

	// 父类初始化
	BFW_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

bool BFW_Flak::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入高射炮参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_FLAK);

	// 父类初始化
	BFW_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// 设置 update 无效
	this->unscheduleUpdate();

	return true;
}

void BFW_Flak::initPhysicsBody()
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
//void BFW_Flak::update(float dt)
//{
//	// 设置高射炮飞行
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_FLAK);
//	this->setRotation(0);
//	return;
//}