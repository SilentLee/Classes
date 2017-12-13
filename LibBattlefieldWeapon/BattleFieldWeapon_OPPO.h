#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include"LayerBattleField.h"

class BattleFieldWeapon_OPPO : public CG_Sprite
{
	// 武器属性
private:
	PROPERTY_WP mPropertyWp;
protected:
	Vec2 mCoordinateInBF;

	// 更新函数
public:
	virtual void update(float dt);

public:
	static BattleFieldWeapon_OPPO* createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	static BattleFieldWeapon_OPPO* createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

	// 初始化物理属性参数
	void initPhysicsBody();

public:
	// 获取战场坐标
	Vec2 getCoordinateInBF();
	float getCoordinateXInBF();
	float getCoordinateYInBF();

	// 设置方格坐标
	void setPosInSquare(float posX, float posY);
	void setPosXInSquare(float posX);
	void setPosYInSquare(float posY);

	// 武器属性存取函数
public:
	void setPropertyWp(PROPERTY_WP propertyWp);
	PROPERTY_WP getPropertyWp();
};