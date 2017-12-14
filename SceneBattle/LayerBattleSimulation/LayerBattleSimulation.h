#pragma once
#include "BattleSimulationMapCell.h"

class LayerBattleSimulation : public Layer
{
private:
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
public:
	// ��������
	static LayerBattleSimulation* create();
	// ��ʼ������
	bool init();

	// ��ʼ��ս�������ͼ
	void initSimulationMap();
};