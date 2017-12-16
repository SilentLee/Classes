#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"
#include "LayerEx.h"
#include "BattleSimulationMapCell.h"


USING_NS_CC;
extern class BattleFieldWeapon_OWN;

class LayerBattleDisplay : public LayerEx
{
private:
	// 战场迷雾
	//BFG_FrogOfWar* mFrogOfWarArray[WIDTH_OF_BATTLE_SIMULATION_MAP][WIDTH_OF_BATTLE_SIMULATION_MAP];

	// 对战双方存在于战场中的兵力
	vector<BattleFieldWeapon_OWN*> mWeaponsOwn;
	vector<BattleFieldWeapon_OWN*> mWeaponsOppo;

	// 战争迷雾分界线
	int mFrogLine[BATTLE_FIELD_WIDTH_IN_SQUARE];

public:
	static LayerBattleDisplay* create();
	bool init();

public:
	void addDefenseLine();

	// 更新函数
	//virtual void updateFrog(float dt);
	virtual void updateBFSituation(float dt);

	// 预览本方兵力放置效果函数
	void previewWeaponWithPositionOnBegan(int weaponType, int posX, int posY);
	void previewWeaponWithPositionOnMoved(float posX, float posY);
	void previewWeaponWithPositionOnEnded();
	void previewWeaponWithPositionCancelled();

	// 布置对方兵力函数
	void arrangeEnemyWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// 布置本方兵力函数
	void arrangeOwnWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);

};