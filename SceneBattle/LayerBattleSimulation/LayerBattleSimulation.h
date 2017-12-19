#pragma once
#include "BattleSimulationMapCell.h"
#include "LayerEx.h"

class LayerBattleSimulation : public LayerEx
{
private:
	// 仿真地图粒度单位
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
	// 战争迷雾分界线
	int mFrogLine[WIDTH_OF_BATTLE_SIMULATION_MAP];
public:
	// 创建函数
	static LayerBattleSimulation* create();

public:
	// 初始化函数
	bool init();
	// 初始化战场仿真地图
	void initSimulationMap();

public:
	//void updateFrog(float dt);

public:
	void insertWeaponOwnInBattleSimulation();
	void insertWeaponOppoInBattleSimulation();
};