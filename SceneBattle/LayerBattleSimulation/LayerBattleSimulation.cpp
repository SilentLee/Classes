#include "LayerBattleSimulation.h"

LayerBattleSimulation* LayerBattleSimulation::create()
{
	LayerBattleSimulation* ret = new LayerBattleSimulation();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleSimulation::init()
{
	Layer::init();
	
	// ��ʼ��ս����ͼ
	initSimulationMap();

	

	return true;
};

// ����ս���ռ��ͼ����
void LayerBattleSimulation::initSimulationMap()
{
	for (int index_width = 0; index_width < WIDTH_OF_BATTLE_SIMULATION_MAP; index_width++)
	{
		for (int index_height = 0; index_height < HEIGHT_OF_BATTLE_SIMULATION_MAP; index_height++)
		{
			// ������ͼ����
			mBattleSimulationMapCellArray[index_width][index_height] = CBattleSimulationMapCell::createWithCoordinate(index_width, index_height);
			// ����ͼ������ӵ�ս�������ͼ
			this->addChild(mBattleSimulationMapCellArray[index_width][index_height]);
		}
	}
}