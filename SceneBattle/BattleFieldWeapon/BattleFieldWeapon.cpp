#include "BattleFieldWeapon.h"

// 创建函数 使用本地操作数据
BattleFieldWeapon* BattleFieldWeapon::createWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
{
	BattleFieldWeapon* ret = new BattleFieldWeapon();
	if (ret && ret->initWithLocalOperationData(fileName.c_str(), position, weaponType, IFF))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
// 创建函数 使用服务器接收数据
BattleFieldWeapon* BattleFieldWeapon::createWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
{
	BattleFieldWeapon* ret = new BattleFieldWeapon();
	if (ret && ret->initWithRecvServerData(fileName.c_str(), position, weaponType, IFF))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数 使用本地操作数据
bool BattleFieldWeapon::initWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
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

	// 设定敌我
	mIFF = IFF;

	return true;
}

// 初始化函数 使用服务器接收数据
bool BattleFieldWeapon::initWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
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

	// 设定敌我识别
	mIFF = IFF;

	return true;
}

// 设置武器在战场态势仿真地图中的尺寸
void BattleFieldWeapon::initSizeInSimulationMap()
{
	Size weaponSize = this->getContentSize();

	int weaponSizeWidth = weaponSize.width / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int weaponSizeHeight = weaponSize.height / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	mSizeInSimulationMap = Size(weaponSizeWidth, weaponSizeHeight);
}

// 获取战场态势仿真地图坐标
Vec2 BattleFieldWeapon::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}

// 获取武器在战场态势仿真地图中的大小
Size BattleFieldWeapon::GetSizeInSimulationMap()
{
	return mSizeInSimulationMap;
}

// 行为函数
// 移动函数
void BattleFieldWeapon::Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// 获取武器在战场态势仿真地图中的坐标
	Vec2 Coordinate = this->GetCoordinate();
	// 重置地图方格中的武器标签
	BattleSimulationMapCellArray[(int)Coordinate.x][(int)Coordinate.y]->resetWeaponTag();

	// 获取当前战场态势显示坐标
	float posX = this->getPositionX();
	float posY = this->getPositionY();

	// 判断当前武器敌我属性 计算移动后的战场态势显示坐标
	if (mIFF == IFF_FRIEND) {
		// 武器属于本方 从屏幕下方向上方飞行 最大不能越过 HEIGHT_OF_BATTLE_DISPLAY_MAP
		posY = min(HEIGHT_OF_BATTLE_DISPLAY_MAP, posY + mPropertyWp.SPEED);
	}
	else if (mIFF == IFF_FOE) {
		// 武器属于对方 从屏幕上方向下方飞行 最小不能越过 0
		posY = max(0.0f, posY - mPropertyWp.SPEED);
	}

	// 设置移动后的战场态势显示坐标
	this->setPosition(Vec2(posX, posY));
	// 移动后再次读取武器在战场态势仿真地图中的坐标
	Coordinate = this->GetCoordinate();
	// 设置战场态势仿真地图中对应的方格坐标的武器标签
	BattleSimulationMapCellArray[(int)Coordinate.x][(int)Coordinate.y]->SetWeaponTag(this->getTag());
}
// 探测函数
void BattleFieldWeapon::Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// 获取战场态势仿真坐标
	Vec2 Coordinate = this->GetCoordinate();
	int DetectDistance = mPropertyWp.RANGE_DEC;
	// 计算探测范围
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
// 攻击函数
void BattleFieldWeapon::Attack()
{

}
// 被攻击函数
int BattleFieldWeapon::BeAttacked()
{
	return 0;
}