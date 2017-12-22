#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"
#include "LayerEx.h"
#include "BattleSimulationMapCell.h"

#define HEIGHT_OF_RANGE_TO_ARRANGE_WEAPON_ON_SIMULATION_MAP		5

USING_NS_CC;
extern class BattleFieldWeapon;

class LayerBattleSituation : public LayerEx
{
private:
	// 对战双方存在于战场中的兵力
	vector<BattleFieldWeapon*> mWeaponsOwn;
	vector<BattleFieldWeapon*> mWeaponsOppo;

// 数据仿真变量
private:
	// 战场态势仿真地图 数组
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
	// 战争迷雾分界线
	int mFrogLine[WIDTH_OF_BATTLE_SIMULATION_MAP];

// 创建函数
public:
	static LayerBattleSituation* create();

// 初始化函数
public:
	// 初始化战场态势层
	bool init();
	// 初始化战场态势仿真地图
	void initBattleSimulationMap();
	// 初始化防线
	void initDefenseLine();

// 更新函数
public:
	// 更新战场迷雾
	void updateFrog(float dt);
	// 检测服务器战场态势更新数据并更新客户端战场态势显示的更新函数 用于同步
	void updateBFSituation(float dt);
	// 本地战场态势更新函数 用于平滑
	void updateLocalSituation(float dt);

// 兵力操作函数
public:
	// 操作过程中本方兵力放置效果预览函数
	void previewWeaponWithPositionOnBegan(int weaponType, float posX, float posY);
	void previewWeaponWithPositionOnMoved(float posX, float posY);
	void previewWeaponWithPositionOnEnded();
	void previewWeaponWithPositionCancelled();
	// 对方兵力布设函数
	void arrangeEnemyWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// 本方兵力布设函数
	void arrangeOwnWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
};