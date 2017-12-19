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

	// 初始化战场态势仿真地图中的武器大小
	initSizeInSimulationMap();

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

	// 初始化战场态势仿真地图中的武器大小
	initSizeInSimulationMap();

	// 创建时设置 update 无效
	// 在接收到服务器布设消息的处理函数中将 update 设置为有效
	//this->unscheduleUpdate();

	return true;
}

// 设置武器在战场态势仿真地图中的尺寸
void BattleFieldWeapon_OPPO::initSizeInSimulationMap()
{
	Size weaponSize = this->getContentSize();

	int weaponSizeWidth = weaponSize.width / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int weaponSizeHeight = weaponSize.height / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	mSizeInSimulationMap = Size(weaponSizeWidth, weaponSizeHeight);
}

// 更新函数
//void BattleFieldWeapon_OPPO::update(float dt)
//{
//	// 更新战场态势显示地图坐标
//	this->Move();
//	this->Detect();
//
//	return;
//}

// 获取战场态势仿真地图坐标
Vec2 BattleFieldWeapon_OPPO::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}

// 获取武器在战场态势仿真地图中的大小
Size BattleFieldWeapon_OPPO::GetSizeInSimulationMap()
{
	return mSizeInSimulationMap;
}

// 行为函数
// 移动
void BattleFieldWeapon_OPPO::Move()
{
	// 获取当前战场态势显示坐标
	float posX = this->getPositionX();
	float posY = this->getPositionY();
	// 计算移动后的战场态势显示坐标
	posY = max(0.0f, posY - mPropertyWp.SPEED);
	// 设置移动后的战场态势显示坐标
	this->setPosition(Vec2(posX, posY));
}
// 探测
void BattleFieldWeapon_OPPO::Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// 获取战场态势仿真坐标
	Vec2 Coordinate = this->GetCoordinate();
	int DetectDistance = mPropertyWp.RANGE_DEC;

	int BorderlineLeft = Coordinate.x - mSizeInSimulationMap.width / 2 - mPropertyWp.RANGE_DEC;
	int BorderlineRight = Coordinate.x + mSizeInSimulationMap.width / 2 + mPropertyWp.RANGE_DEC;
	int BorderlineBottom = Coordinate.y - mSizeInSimulationMap.height / 2 - mPropertyWp.RANGE_DEC;
	int BorderlineTop = Coordinate.y + mSizeInSimulationMap.height / 2 + mPropertyWp.RANGE_DEC;

	// 遍历战场态势仿真地图中处于探测区域中的每一个点
	for (int indexX = BorderlineLeft; indexX <= BorderlineRight; indexX++) {
		for (int indexY = BorderlineBottom; indexY <= BorderlineTop; indexY++) {
			// 当前遍历点在战场态势仿真地图中的坐标
			int mapCellX = indexX;
			int mapCellY = indexY;
			// 将探测区域遍历的点限制在战场态势仿真地图范围内
			mapCellX = max(0, min(indexX, WIDTH_OF_BATTLE_SIMULATION_MAP - 1));
			mapCellY = max(0, min(indexY, HEIGHT_OF_BATTLE_SIMULATION_MAP - 1));

			BattleSimulationMapCellArray[mapCellX][mapCellY]->setVisible(false);
		}
	}
}
// 攻击
void BattleFieldWeapon_OPPO::Attack()
{

}
// 被攻击
int BattleFieldWeapon_OPPO::BeAttacked()
{
	return 0;
}