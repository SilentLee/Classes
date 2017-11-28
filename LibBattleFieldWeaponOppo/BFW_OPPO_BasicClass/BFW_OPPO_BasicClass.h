#pragma once
#include "LibBattlefieldWeaponOppoInclude.h"
//#include "LibParamApi.h"

class BFW_OPPO_BasicClass : public CG_Sprite
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
	static BFW_OPPO_BasicClass* createWithPosInSquare(std::string fileName, int posX, int posY, PROPERTY_WP mPropertyWp);
	static BFW_OPPO_BasicClass* createWithAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP mPropertyWp);
	static BFW_OPPO_BasicClass* createWithRelativePos(std::string fileName, float posX, float posY, PROPERTY_WP mPropertyWp);
	static BFW_OPPO_BasicClass* createWithRealAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP mPropertyWp);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY, PROPERTY_WP mPropertyWp);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP mPropertyWp);
	bool initWithRelativePos(const std::string& filename, float posX, float posY, PROPERTY_WP mPropertyWp);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP mPropertyWp);

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