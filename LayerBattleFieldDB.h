#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

USING_NS_CC;

class LayerBattleFieldDB : public Layer
{
public:
	static LayerBattleFieldDB* create();
	bool init();
	void onEnter();

	// 注册通知函数
	void registNotification();

public:
	void addFog(float originX, float originY, int width, int height, float stepX, float stepY);
	void addDefenseLine();

	// 通知函数
	void arrangeWeaponWithAbsolutePos(int weaponType, int posX, int posY, int discardTimes);
	void arrangeWeaponWithRelativePos(int weaponType, int posX, int posY, int discardTimes);

	// 碰撞检测事件处理函数
	bool onContact(PhysicsContact& contact);
};