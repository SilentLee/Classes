#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// BattleFieldWeapon 类中
// Coordinate 为 战场态势仿真地图坐标
// Position 为 战场态势显示地图坐标
// Coordinate 随着 Position 的改变而刷新

class BattleFieldWeapon_OPPO : public Sprite
{
	// 武器属性
private:
	PROPERTY_WP mPropertyWp;

	// 战场坐标
protected:

	// 生成函数
public:
	// 使用本地操作数据
	static BattleFieldWeapon_OPPO* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用服务器接受数据
	static BattleFieldWeapon_OPPO* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// 初始化函数
public:
	// 使用本地操作数据
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用服务器接收数据
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// 更新函数
public:
	virtual void update(float dt);

public:
	// 获取战场坐标
	Vec2 GetCoordinate();

	// 武器属性存取函数
public:
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
};