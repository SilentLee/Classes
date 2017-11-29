#include "BFW_OPPO_BasicClass.h"

BFW_OPPO_BasicClass* BFW_OPPO_BasicClass::createWithPosInSquare(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_OPPO_BasicClass* ret = new BFW_OPPO_BasicClass();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BasicClass* BFW_OPPO_BasicClass::createWithRealAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_OPPO_BasicClass* ret = new BFW_OPPO_BasicClass();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BasicClass* BFW_OPPO_BasicClass::createWithAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_OPPO_BasicClass* ret = new BFW_OPPO_BasicClass();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_BasicClass* BFW_OPPO_BasicClass::createWithRelativePos(std::string fileName, float posX, float posY, PROPERTY_WP propertyWp)
{
	BFW_OPPO_BasicClass* ret = new BFW_OPPO_BasicClass();
	if (ret && ret->initWithRelativePos(fileName, posX, posY, propertyWp));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BFW_OPPO_BasicClass::initWithPosInSquare(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// 父类初始化
	CG_Sprite::initWithPosInSquare(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// 设置 update
	//this->unscheduleUpdate();
	this->scheduleUpdate();

	return true;
}

bool BFW_OPPO_BasicClass::initWithAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// 父类初始化
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);
	setPropertyWp(propertyWp);

	// 设置 update 无效
	//this->unscheduleUpdate();
	this->scheduleUpdate();

	return true;
}

bool BFW_OPPO_BasicClass::initWithRelativePos(const std::string& filename, float posX, float posY, PROPERTY_WP propertyWp)
{
	// 父类初始化
	CG_Sprite::initWithRelativePos(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// 设置 update 无效
	//this->unscheduleUpdate();
	this->scheduleUpdate();

	return true;
}

bool BFW_OPPO_BasicClass::initWithRealAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// 父类初始化
	CG_Sprite::initWithRealAbsolutePos(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// 设置 update 无效
	//this->unscheduleUpdate();
	this->scheduleUpdate();

	return true;
}

// 获取战场坐标
Vec2 BFW_OPPO_BasicClass::getCoordinateInBF()
{
	// 刷新战场坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF;
}

float BFW_OPPO_BasicClass::getCoordinateXInBF()
{
	// 刷新战场坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.x;
}

float BFW_OPPO_BasicClass::getCoordinateYInBF()
{
	// 刷新战场坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.y;
}

// 设置方格坐标
void BFW_OPPO_BasicClass::setPosInSquare(float posX, float posY)
{
	// 获取全局屏幕缩放因子
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// 将武器布设坐标放置在屏幕底部向上数 3 到 5 个方格之间
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 3), BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 5);
	
	// 将坐标归纳到方格内
	CG_ResolutionAdapter::setPosInSquare(posX, posY);
}

void BFW_OPPO_BasicClass::setPosXInSquare(float posX)
{
	CG_ResolutionAdapter::setPosXInSquare(posX);
}

void BFW_OPPO_BasicClass::setPosYInSquare(float posY)
{
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// 将武器布设坐标放置在屏幕底部向上数 3 到 5 个方格之间
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * 3), BATTLE_FIELD_SQUARE_WIDTH * 5);

	// 将坐标归纳到方格内
	CG_ResolutionAdapter::setPosYInSquare(posY);
}

// 设置武器属性
void BFW_OPPO_BasicClass::setPropertyWp(PROPERTY_WP propertyWp)
{
	memcpy(&mPropertyWp, &propertyWp, sizeof(PROPERTY_WP));
}
// 获取武器属性
PROPERTY_WP BFW_OPPO_BasicClass::getPropertyWp()
{
	return mPropertyWp;
}

// 更新函数
void BFW_OPPO_BasicClass::update(float dt)
{
	// 更新飞行位置
	Vec2 pos = this->getAdpPosWithRelativeValue();
	this->setAdpPosWithRelativeValue(pos.x, pos.y - mPropertyWp.SPEED);
	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->getCoordinateXInBF(), (int)this->getCoordinateYInBF());

	return;
}