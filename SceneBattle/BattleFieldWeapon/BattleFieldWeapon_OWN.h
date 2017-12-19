#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// BattleFieldWeapon 类中
// Coordinate 为 战场态势仿真地图坐标
// Position 为 战场态势显示地图坐标
// Coordinate 随着 Position 的改变而刷新

class BattleFieldWeapon_OWN : public Sprite
{
private:
	// 武器属性
	PROPERTY_WP mPropertyWp;
	// 武器在战场态势仿真地图中的大小
	Size mSizeInSimulationMap;

// 生成函数
public:
	// 使用本地操作数据
	static BattleFieldWeapon_OWN* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用服务器接受数据
	static BattleFieldWeapon_OWN* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

// 初始化函数
public:
	// 使用本地操作数据
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用服务器接收数据
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 初始化武器在战场态势仿真地图中的大小
	void initSizeInSimulationMap();

// 更新函数
public:
	//virtual void update(float dt);

public:
	// 获取战场态势仿真地图坐标
	Vec2 GetCoordinate();
// 行为函数
public:
	// 移动
	void Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// 探测
	void Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// 攻击
	void Attack();
	// 被攻击
	int BeAttacked();

// 存取函数
public:
	// 武器属性
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
	// 武器在战场态势仿真地图中的大小
	Size GetSizeInSimulationMap();
};