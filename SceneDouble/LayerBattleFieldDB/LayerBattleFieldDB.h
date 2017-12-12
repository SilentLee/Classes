#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"


USING_NS_CC;
extern class BattleFieldWeapon_OWN;

class LayerBattleFieldDB : public Layer
{
private:
	// 战场迷雾
	BFG_FrogOfWar* mFrogOfWarArray[BATTLE_FIELD_WIDTH_IN_SQUARE][BATTLE_FIELD_HEIGHT_IN_SQUARE];

	// 对战双方存在于战场中的兵力
	vector<BattleFieldWeapon_OWN*> mWeaponsOwn;
	vector<BattleFieldWeapon_OWN*> mWeaponsOppo;

	// 战争迷雾分界线
	int mFrogLine[BATTLE_FIELD_WIDTH_IN_SQUARE];

public:
	static LayerBattleFieldDB* create();
	bool init();
	void onEnter();

	// 注册通知函数
	void registNotification();

public:
	void addFog(float originX, float originY, int width, int height, float stepX, float stepY);
	void addDefenseLine();

	// 碰撞检测事件处理函数
	bool onContact(PhysicsContact& contact);

	// 更新函数
	virtual void updateFrog(float dt);
	virtual void updateBFSituation(float dt);

	// 预览本方兵力放置效果函数
	void previewWeaponWithAbsolutePosOnBegan(int weaponType, int posX, int posY);
	void previewWeaponWithAbsolutePosOnMoved(float posX, float posY);
	void previewWeaponWithAbsolutePosOnEnded();
	void previewWeaponWithAbsolutePosCancelled();

	// 布置对方兵力函数
	void arrangeEnemyWeaponWithAbsolutePos(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// 布置本方兵力函数
	void arrangeOwnWeaponWithAbsolutePos(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);

};