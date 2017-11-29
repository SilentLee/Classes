#include "BFW_OPPO_AAM.h"

BFW_OPPO_AAM* BFW_OPPO_AAM::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_OPPO_AAM* ret = new BFW_OPPO_AAM();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_AAM* BFW_OPPO_AAM::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_AAM* ret = new BFW_OPPO_AAM();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_AAM* BFW_OPPO_AAM::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_AAM* ret = new BFW_OPPO_AAM();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_AAM* BFW_OPPO_AAM::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_OPPO_AAM* ret = new BFW_OPPO_AAM();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BFW_OPPO_AAM::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// 载入空空导弹参数
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(AIRBORNE_WP_TYPE_AAM);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	// 发射位置初始化
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_OPPO_AAM::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入空空导弹参数
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(AIRBORNE_WP_TYPE_AAM);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	// 发射位置初始化
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_OPPO_AAM::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// 载入空空导弹参数
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(AIRBORNE_WP_TYPE_AAM);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	// 发射位置初始化
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_OPPO_AAM::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// 载入空空导弹参数
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(AIRBORNE_WP_TYPE_AAM);

	// 父类初始化
	BFW_OPPO_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	// 发射位置初始化
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

void BFW_OPPO_AAM::initPhysicsBody()
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
//void BFW_AAM::update(float dt)
//{
//	// 设置战斗机飞行
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_AAM);
//	this->setRotation(0);
//	return;
//}

// 获取发射位置
Vec2 BFW_OPPO_AAM::getFirePosition()
{
	return mFirePosition;
}

int BFW_OPPO_AAM::getFirePositionX()
{
	return mFirePosition.x;
}

int BFW_OPPO_AAM::getFirePositionY()
{
	return mFirePosition.y;
}