#include "BattleFieldWeapon_OPPO.h"

// 创建函数 使用本地操作数据
BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithLocalOperationData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
// 创建函数 使用服务器接收数据
BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithRecvServerData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数 使用本地操作数据
bool BattleFieldWeapon_OPPO::initWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// 父类初始化
	Sprite::initWithFile(fileName);
	// 设置锚点为 Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// 设置战场态势显示坐标
	float posX = ((int)(position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = ((int)(position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

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

// 初始化函数 使用服务器接收数据
bool BattleFieldWeapon_OPPO::initWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// 父类初始化
	Sprite::initWithFile(fileName);
	// 设置锚点为 Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// 设置武器在战场态势显示地图中的位置
	this->setPosition(position.x, position.y);

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

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}

Vec2 BattleFieldWeapon_OPPO::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}