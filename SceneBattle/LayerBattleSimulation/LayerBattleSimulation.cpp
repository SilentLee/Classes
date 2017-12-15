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
	
	// 初始化战场地图
	initSimulationMap();

	

	return true;
};

// 生成战场空间地图方格
void LayerBattleSimulation::initSimulationMap()
{
	for (int index_width = 0; index_width < WIDTH_OF_BATTLE_SIMULATION_MAP; index_width++)
	{
		for (int index_height = 0; index_height < HEIGHT_OF_BATTLE_SIMULATION_MAP; index_height++)
		{
			// 创建地图方格
			mBattleSimulationMapCellArray[index_width][index_height] = CBattleSimulationMapCell::createWithCoordinate(index_width, index_height);
			// 将地图方格添加到战场仿真地图
			this->addChild(mBattleSimulationMapCellArray[index_width][index_height]);
		}
	}
}