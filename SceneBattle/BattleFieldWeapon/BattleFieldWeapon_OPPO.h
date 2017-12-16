#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

class BattleFieldWeapon_OPPO : public Sprite
{
// 武器属性
private:
	PROPERTY_WP mPropertyWp;

	// 战场坐标
protected:
	Vec2 mCoordinate;

// 生成函数
public:
	// 使用战场态势仿真地图坐标的创建函数
	static BattleFieldWeapon_OPPO* createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	// 使用本地操作数据的战场态势显示地图位置的创建函数
	static BattleFieldWeapon_OPPO* createWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用接受服务器数据的战场态势显示地图位置的创建函数
	static BattleFieldWeapon_OPPO* createWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// 初始化函数
public:
	// 使用战场态势仿真地图坐标的初始化函数
	bool initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	// 使用本地操作数据的战场态势显示地图位置的初始化函数
	bool initWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// 使用接受服务器数据的战场态势显示地图位置的初始化函数
	bool initWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

// 更新函数
public:
	virtual void update(float dt);

public:
	// 获取战场坐标
	void SetCoordinate(Vec2 coordinate) { mCoordinate = coordinate; };
	Vec2 GetCoordinate() { return mCoordinate; };

	// 武器属性存取函数
public:
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
};