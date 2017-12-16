#include "BattleFieldWeapon_OPPO.h"

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithCoordinate(fileName.c_str(), coordinate, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithPosition(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BattleFieldWeapon_OPPO::initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
{
	// 父类初始化
	Sprite::initWithFile(fileName);
	// 设置锚点为 Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 将 战场态势仿真地图坐标 转换为 战场态势显示地图坐标
	float posX = (coordinate.x + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (coordinate.y + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	// 设置武器在战场态势显示地图中的位置
	this->setPosition(posX, posY);

	// 加载武器参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
	SetPropertyWp(propertyWp);
	// 加载位置参数
	mCoordinate = coordinate;

	// 创建时设置 update 无效
	// 在接收到服务器布设消息的处理函数中将 update 设置为有效
	this->unscheduleUpdate();

	return true;
}

bool BattleFieldWeapon_OPPO::initWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// 父类初始化
	Sprite::initWithFile(fileName);
	// 设置锚点为 Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// 将 战场态势显示地图坐标 与 战场态势仿真地图坐标 对齐
	mCoordinate.x = (int)position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	mCoordinate.y = (int)position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	float posX = (mCoordinate.x + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (mCoordinate.y + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	// 设置武器在战场态势显示地图中的位置
	this->setPosition(posX, posY);
	// 加载卡牌参数
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
	SetPropertyWp(propertyWp);

	// 创建时设置 update 无效
	// 在接收到服务器布设消息的处理函数中将 update 设置为有效
	this->unscheduleUpdate();

	return true;
}

// 更新函数
void BattleFieldWeapon_OPPO::update(float dt)
{
	// 更新战场态势显示地图坐标
	Vec2 position = this->getPosition();
	this->setPosition(position.x, position.y - mPropertyWp.SPEED);

	// 更新战场态势仿真地图坐标
	mCoordinate.x = (int)position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	mCoordinate.y = (int)position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}