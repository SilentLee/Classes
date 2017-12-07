#pragma once

#include "cocos2d.h"
#include <string>
#include <map>
#include "LibParamApi.h"

// 武器基本属性结构体
typedef struct _PROPERTY_WP
{
	ENUM_WEAPON_TYPE WP_TYPE;
	int LEVEL;
	float SPEED;
	int RANGE_DEC;
	int DP;
	int HP;
	int RANGE_FIRE;
} PROPERTY_WP;

using namespace std;
USING_NS_CC;

class CU_CardLoader
{
public:
	static void loadCardParams();
	static PROPERTY_WP getCardParam(int key);
	static void loadAirborneWeaponParams();
	static PROPERTY_WP getAirborneWeaponParams(int key);
};