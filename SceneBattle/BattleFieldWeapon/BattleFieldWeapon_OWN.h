#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

// BattleFieldWeapon 类中
// Coordinate 为虚拟战场坐标
// Position 为物理显示位置
// Coordinate 随着 Position 的改变而刷新

class BattleFieldWeapon_OWN : public CG_Sprite
{
// 武器属性
private:
	PROPERTY_WP mPropertyWp;

// 战场坐标
protected:
	Vec2 mCoordinate;

// 生成函数
public:
	static BattleFieldWeapon_OWN* createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	static BattleFieldWeapon_OWN* createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

// 初始化函数
public:
	bool initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	// 初始化物理属性参数
	void initPhysicsBody();

// 更新函数
public:
	virtual void update(float dt);

// 存取函数
public:
	// 获取战场坐标
	Vec2 getCoordinate();
	float getCoordinateX();
	float getCoordinateY();

	// 设置方格坐标
	void setPosInSquare(float posX, float posY);
	void setPosXInSquare(float posX);
	void setPosYInSquare(float posY);

	// 武器属性存取函数
public:
	void setPropertyWp(PROPERTY_WP propertyWp);
	PROPERTY_WP getPropertyWp();
};