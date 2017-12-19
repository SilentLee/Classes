#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// 敌我识别
// identification friend or foe
typedef enum ENUM_IFF {
	IFF_NONE,
	IFF_FRIEND,
	IFF_FOE
};

// BattleFieldWeapon 类中
// Coordinate 为 战场态势仿真地图坐标
// Position 为 战场态势显示地图坐标
// Coordinate 随着 Position 的改变而刷新

class BattleFieldWeapon : public Sprite
{
private:
	// 武器属性
	PROPERTY_WP mPropertyWp;
	// 武器在战场态势仿真地图中的大小
	Size mSizeInSimulationMap;
	// 敌我识别标志
	ENUM_IFF mIFF;

// 生成函数
public:
	// 使用本地操作数据
	static BattleFieldWeapon* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
	// 使用服务器接受数据
	static BattleFieldWeapon* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);

// 初始化函数
public:
	// 使用本地操作数据
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
	// 使用服务器接收数据
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
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
	// 移动函数
	void Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// 探测函数
	void Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// 攻击函数
	void Attack();
	// 被攻击函数
	int BeAttacked();

// 存取函数
public:
	// 武器属性
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
	// 武器在战场态势仿真地图中的大小
	Size GetSizeInSimulationMap();
	// 敌我识别标志
	void SetIFF(ENUM_IFF IFF) { mIFF = IFF; };
	ENUM_IFF GetIFF() { return mIFF; };
};