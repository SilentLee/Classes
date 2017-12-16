#include "BattleFieldWeapon_OWN.h"

BattleFieldWeapon_OWN* BattleFieldWeapon_OWN::createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OWN* ret = new BattleFieldWeapon_OWN();
	if (ret && ret->initWithCoordinate(fileName.c_str(), coordinate, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 使用本地操作数据的战场态势显示地图位置的创建函数
BattleFieldWeapon_OWN* BattleFieldWeapon_OWN::createWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OWN* ret = new BattleFieldWeapon_OWN();
	if (ret && ret->initWithLocalOperationPosData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 使用接受服务器数据的战场态势显示地图位置的创建函数
BattleFieldWeapon_OWN* BattleFieldWeapon_OWN::createWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OWN* ret = new BattleFieldWeapon_OWN();
	if (ret && ret->initWithRecvServerPosData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
bool BattleFieldWeapon_OWN::initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
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

// 使用本地操作数据的战场态势显示地图位置的初始化函数
bool BattleFieldWeapon_OWN::initWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// 父类初始化
	Sprite::initWithFile(fileName);
	// 设置锚点为 Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// 将 战场态势显示地图坐标 与 战场态势仿真地图坐标 对齐
	mCoordinate.x = (int)(position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	mCoordinate.y = (int)(position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);

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

// 使用接受服务器数据的战场态势显示地图位置的初始化函数
bool BattleFieldWeapon_OWN::initWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
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
void BattleFieldWeapon_OWN::update(float dt)
{
	// 更新战场态势显示地图坐标
	Vec2 position = this->getPosition();
	this->setPosition(position.x, position.y + mPropertyWp.SPEED);

	// 更新战场态势仿真地图坐标
	mCoordinate.x = (int)(position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	mCoordinate.y = (int)(position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}

void BattleFieldWeapon_OWN::SetCoordinate(Vec2 coordinate) 
{ 
	mCoordinate = coordinate;
	// 根据当前战场态势仿真坐标 重新计算战场态势显示坐标
	float posX = (mCoordinate.x + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (mCoordinate.y + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	this->setPosition(Vec2(posX, posY));
};