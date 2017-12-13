#include "BattleFieldWeapon_OPPO.h"

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BattleFieldWeapon_OPPO::initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	// 载入卡牌参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);

	// 父类初始化
	CG_Sprite::initWithPosInSquare(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// 初始化物理属性
	initPhysicsBody();

	// 创建时设置 update 无效
	// 在接收到服务器布设消息的处理函数中将 update 设置为有效
	this->unscheduleUpdate();

	return true;
}

bool BattleFieldWeapon_OPPO::initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	// 载入卡牌参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);

	// 父类初始化
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);
	setPropertyWp(propertyWp);

	// 初始化物理属性
	initPhysicsBody();

	// 创建时设置 update 无效
	// 在接收到服务器布设消息的处理函数中将 update 设置为有效
	this->unscheduleUpdate();

	return true;
}

// 初始化物理属性参数
void BattleFieldWeapon_OPPO::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_FIGHTER_PLANE); // 设定物体类别掩码
	body->setCollisionBitmask(BIT_MASK_COLLISION_FIGHTER_PLANE); // 设定碰撞掩码 执行碰撞反应
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_FIGHTER_PLANE); // 设定接触掩码 执行碰撞事件
	this->setPhysicsBody(body);
}

// 获取战场坐标
Vec2 BattleFieldWeapon_OPPO::getCoordinateInBF()
{
	// 刷新战场坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF;
}

float BattleFieldWeapon_OPPO::getCoordinateXInBF()
{
	// 刷新战场坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.x;
}

float BattleFieldWeapon_OPPO::getCoordinateYInBF()
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
void BattleFieldWeapon_OPPO::setPosInSquare(float posX, float posY)
{
	// 获取全局屏幕缩放因子
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// 将武器布设坐标放置在屏幕底部向上数 3 到 5 个方格之间
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 3), BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 5);
	
	// 将坐标归纳到方格内
	CG_ResolutionAdapter::setPosInSquare(posX, posY);
}

void BattleFieldWeapon_OPPO::setPosXInSquare(float posX)
{
	CG_ResolutionAdapter::setPosXInSquare(posX);
}

void BattleFieldWeapon_OPPO::setPosYInSquare(float posY)
{
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// 将武器布设坐标放置在屏幕底部向上数 3 到 5 个方格之间
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * 3), BATTLE_FIELD_SQUARE_WIDTH * 5);

	// 将坐标归纳到方格内
	CG_ResolutionAdapter::setPosYInSquare(posY);
}

// 设置武器属性
void BattleFieldWeapon_OPPO::setPropertyWp(PROPERTY_WP propertyWp)
{
	memcpy(&mPropertyWp, &propertyWp, sizeof(PROPERTY_WP));
}
// 获取武器属性
PROPERTY_WP BattleFieldWeapon_OPPO::getPropertyWp()
{
	return mPropertyWp;
}

// 更新函数
void BattleFieldWeapon_OPPO::update(float dt)
{
	// 更新飞行位置
	//Vec2 pos = this->getAdpPosWithRelativeValue();
	//this->setAdpPosWithRelativeValue(pos.x, pos.y - mPropertyWp.SPEED);

	// 更新飞行位置
	// 此处使用绝对坐标
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	this->setAdpPosWithAbsoluteValue(pos.x, pos.y - mPropertyWp.SPEED);

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->getCoordinateXInBF(), (int)this->getCoordinateYInBF());

	return;
}