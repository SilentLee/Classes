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
	LayerEx::init();

	this->GetSizeAdjustFactor();
	this->GetVisibleSize();
	
	// 初始化战场地图
	initSimulationMap();

	Sprite* a = Sprite::create(CU_ImgLoader::getFogImg(1).c_str());
	this->addChild(a);
	a->setPosition(1080, 1920);


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

//// 更新函数
//void LayerBattleSimulation::updateFrog(float dt)
//{
//	// 计算迷雾分界线所在位置
//	memset(mFrogLine, 0, sizeof(int) * BATTLE_FIELD_WIDTH_IN_SQUARE);
//
//	for (int i = 0; i < mWeaponsOwn.size(); i++)
//	{
//		int posX = mWeaponsOwn[i]->GetCoordinate().x;
//		int posY = mWeaponsOwn[i]->GetCoordinate().y;
//		int rangeDec = mWeaponsOwn[i]->GetPropertyWp().RANGE_DEC;
//
//		mFrogLine[max(0, posX - 1)] = max(mFrogLine[max(0, posX - 1)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//		mFrogLine[posX] = max(mFrogLine[posX], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//		mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)] =
//			max(mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
//	}
//
//	// 设置战场迷雾显示范围
//	for (int indexX = 0; indexX < BATTLE_FIELD_WIDTH_IN_SQUARE; indexX++)
//	{
//		for (int indexY = 0; indexY < BATTLE_FIELD_HEIGHT_IN_SQUARE; indexY++)
//		{
//			if (indexY <= mFrogLine[indexX])
//			{
//				mFrogOfWarArray[indexX][indexY]->setVisible(false);
//			}
//			else {
//				mFrogOfWarArray[indexX][indexY]->setVisible(true);
//			}
//		}
//	}
//
//	// 用于测试迷雾功能的代码
//	for (vector<BattleFieldWeapon_OWN*>::iterator iter = mWeaponsOwn.begin(); iter != mWeaponsOwn.end(); iter++) {
//		BattleFieldWeapon_OWN* weapon = (BattleFieldWeapon_OWN*)*iter;
//		if (weapon->GetCoordinate().y == 10)
//		{
//			mWeaponsOwn.erase(iter);
//			//weapon->retain();
//			weapon->removeFromParent();
//			return;
//		}
//	}
//}