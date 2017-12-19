#pragma once
#include "BattleSimulationMapCell.h"
#include "LayerEx.h"

class LayerBattleSimulation : public LayerEx
{
private:
	// �����ͼ���ȵ�λ
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
	// ս������ֽ���
	int mFrogLine[WIDTH_OF_BATTLE_SIMULATION_MAP];
public:
	// ��������
	static LayerBattleSimulation* create();

public:
	// ��ʼ������
	bool init();
	// ��ʼ��ս�������ͼ
	void initSimulationMap();

public:
	//void updateFrog(float dt);

public:
	void insertWeaponOwnInBattleSimulation();
	void insertWeaponOppoInBattleSimulation();
};