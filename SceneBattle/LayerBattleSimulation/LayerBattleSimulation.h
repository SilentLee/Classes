#pragma once
#include "BattleSimulationMapCell.h"

class LayerBattleSimulation : public Layer
{
private:
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
public:
	// 创建函数
	static LayerBattleSimulation* create();
	// 初始化函数
	bool init();

	// 初始化战场仿真地图
	void initSimulationMap();
};