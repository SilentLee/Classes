#include "BattleFieldWeapon.h"
#include "CU_CardLoader.h"

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
	S_PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
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
	S_PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
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
ENUM_STATUS_MOVE BattleFieldWeapon::Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// 如果当前移动计算已经完成 直接返回 完成状态 STATUS_MOVE_COMPLETE
	if (mMoveStatus == STATUS_MOVE_COMPLETE || mMoveStatus == STATUS_MOVE_PROCESSING) {
		mMoveStatus = STATUS_MOVE_COMPLETE;
		return mMoveStatus;
	}

	// 将当前移动状态设置为 STATUS_MOVE_PROCESSING
	mMoveStatus = STATUS_MOVE_PROCESSING;

	// 获取当前战场态势显示坐标
	Vec2 CurrentPosition = this->getPosition();
	// 获取武器在战场态势仿真地图中的坐标
	Vec2 CurrentCoordinate = this->GetCoordinate();

	// 计算武器当前在战场态势仿真地图中所占的空间
	int CurrentBorderlineLeft = CurrentCoordinate.x - mSizeInSimulationMap.width / 2;
	int CurrentBorderlineRight = CurrentCoordinate.x + mSizeInSimulationMap.width / 2;
	int CurrentBorderlineBottom = CurrentCoordinate.y - mSizeInSimulationMap.height / 2;
	int CurrentBorderlineTop = CurrentCoordinate.y + mSizeInSimulationMap.height / 2;

	// 下一步移动的 战场态势显示坐标 与 战场态势仿真坐标
	Vec2  NextPosition, NextCoordinate;

	// 根据当前武器敌我属性 计算移动后的战场态势显示坐标
	// 如果武器属于本方 从屏幕下方向上方飞行 最大不能越过 HEIGHT_OF_BATTLE_DISPLAY_MAP
	if (mIFF == IFF_FRIEND) {
		NextPosition.x = CurrentPosition.x;
		NextPosition.y = min(HEIGHT_OF_BATTLE_DISPLAY_MAP, CurrentPosition.y + mPropertyWp.SPEED);
	}
	// 如果武器属于对方 从屏幕上方向下方飞行 最小不能越过 0
	else if (mIFF == IFF_FOE) {
		NextPosition.x = CurrentPosition.x;
		NextPosition.y = max(0.0f, CurrentPosition.y - mPropertyWp.SPEED);
	}
	// 根据移动后的战场态势显示坐标 计算移动后的战场态势仿真坐标
	NextCoordinate.x = (int)(NextPosition.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	NextCoordinate.y = (int)(NextPosition.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);

	// 重新计算武器移动后在战场态势仿真地图中所占的空间
	int NextBorderlineLeft = NextCoordinate.x - mSizeInSimulationMap.width / 2;
	int NextBorderlineRight = NextCoordinate.x + mSizeInSimulationMap.width / 2;
	int NextBorderlineBottom = NextCoordinate.y - mSizeInSimulationMap.height / 2;
	int NextBorderlineTop = NextCoordinate.y + mSizeInSimulationMap.height / 2;

	// 遍历武器移动后在战场态势仿真地图中所占空间的每一个点
	for (int indexX = NextBorderlineLeft; indexX <= NextBorderlineRight; indexX++) {
		for (int indexY = NextBorderlineBottom; indexY <= NextBorderlineTop; indexY++) {
			// 声明探测区域内当前遍历坐标点的坐标 并将探测区域遍历的点限制在战场态势仿真地图范围内
			int mapCellX = max(0, min(indexX, WIDTH_OF_BATTLE_SIMULATION_MAP - 1));
			int mapCellY = max(0, min(indexY, HEIGHT_OF_BATTLE_SIMULATION_MAP - 1));
			// 获取当前遍历坐标点的武器标签
			int WeaponTag = BattleSimulationMapCellArray[mapCellX][mapCellY]->GetWeaponTag();
			// 若检测到武器移动后在战场态势仿真地图中所占空间的某个点已经有武器存在 且该点不是当前移动武器的武器标签
			if (WeaponTag != TAG_NO_WEAPON_IN && WeaponTag != this->getTag()) {
				// 通过武器标签获取当前占用该点发生接触的武器
				BattleFieldWeapon* WeaponOnContact = (BattleFieldWeapon*)this->getParent()->getChildByTag(WeaponTag);
				// 移动占用该点发生接触武器
				WeaponOnContact->Move(BattleSimulationMapCellArray);
				// 在发生接触的武器移动后 重新检测该点 
				// 若仍然有武器占用该点 当前武器维持原位置不变
				if (BattleSimulationMapCellArray[mapCellX][mapCellY]->GetWeaponTag() != TAG_NO_WEAPON_IN) {
					// 完成武器位置移动的计算 维持原有位置不变
					mMoveStatus = STATUS_MOVE_COMPLETE;
					// 返回武器移动状态
					return mMoveStatus;
				} // endif (BattleSimulationMapCellArray[indexX][indexY]->GetWeaponTag() != TAG_NO_WEAPON_IN)
			} // endif ( WeaponTag != TAG_NO_WEAPON_IN && WeaponTag != this->getTag())
		} // endfor (int indexY = NextBorderlineBottom; indexY <= NextBorderlineTop; indexY++)
	} // endfor (int indexX = NextBorderlineLeft; indexX <= NextBorderlineRight; indexX++)

	  // 重置武器移动前在战场态势仿真地图中所占空间的每一个点的武器标签
	for (int indexX = CurrentBorderlineLeft; indexX <= CurrentBorderlineRight; indexX++) {
		for (int indexY = CurrentBorderlineBottom; indexY <= CurrentBorderlineTop; indexY++) {
			// 声明探测区域内当前遍历坐标点的坐标 并将探测区域遍历的点限制在战场态势仿真地图范围内
			int mapCellX = max(0, min(indexX, WIDTH_OF_BATTLE_SIMULATION_MAP - 1));
			int mapCellY = max(0, min(indexY, HEIGHT_OF_BATTLE_SIMULATION_MAP - 1));
			// 设置武器标签
			BattleSimulationMapCellArray[mapCellX][mapCellY]->SetWeaponTag(TAG_NO_WEAPON_IN);
		}
	}

	// 设置武器移动后在战场态势仿真地图中所占空间的每一个点的武器标签
	for (int indexX = NextBorderlineLeft; indexX <= NextBorderlineRight; indexX++) {
		for (int indexY = NextBorderlineBottom; indexY <= NextBorderlineTop; indexY++) {
			// 声明探测区域内当前遍历坐标点的坐标 并将探测区域遍历的点限制在战场态势仿真地图范围内
			int mapCellX = max(0, min(indexX, WIDTH_OF_BATTLE_SIMULATION_MAP - 1));
			int mapCellY = max(0, min(indexY, HEIGHT_OF_BATTLE_SIMULATION_MAP - 1));
			// 设置武器标签
			BattleSimulationMapCellArray[mapCellX][mapCellY]->SetWeaponTag(this->getTag());
		}
	}

	//// 设置移动后的武器位置
	this->setPosition(NextPosition);
	// 设置武器移动后的状态
	mMoveStatus = STATUS_MOVE_COMPLETE;
	// 返回武器移动状态
	return mMoveStatus;
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