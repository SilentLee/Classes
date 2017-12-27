#pragma once

#include "cocos2d.h"
#include <string>
#include <map>
#include "WeaponStructure.h"

using namespace std;
USING_NS_CC;

class CU_CardLoader
{
public:
	static void loadCardParams();
	static S_PROPERTY_WP getCardParam(int key);
	static void loadAirborneWeaponParams();
	static S_PROPERTY_WP getAirborneWeaponParams(int key);
};