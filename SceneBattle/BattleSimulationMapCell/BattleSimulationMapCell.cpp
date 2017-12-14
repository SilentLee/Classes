#include "BattleSimulationMapCell.h"

//// 创建函数
//CBattleSimulationMapCell* CBattleSimulationMapCell::createWithAbsolutePos(float posX, float posY)
//{
//	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();
//	
//	if (ret && ret->initWithAbsolutePos(posX, posY))
//	{
//		ret->autorelease();
//		return ret;
//	}
//	CC_SAFE_DELETE(ret);
//	return nullptr;
//}

// 创建函数 使用仿真地图坐标
CBattleSimulationMapCell* CBattleSimulationMapCell::createWithCoordinate(int coordinateX, int coordinateY)
{
	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();

	float posX = (coordinateX + 0.5) * WIDTH_OF_MAP_CELL;
	float posY = (coordinateY + 0, 5) * WIDTH_OF_MAP_CELL;

	if (ret && ret->initWithAbsolutePos(posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
// 在战场显示坐标系下进行坐标设定 1920 * 1080
bool CBattleSimulationMapCell::initWithAbsolutePos(float posX, float posY)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	CG_Sprite::initWithAbsolutePos(CU_ImgLoader::getFogImg(1).c_str(), posX, posY);

	// 设置战场方格的仿真坐标
	mCoordinate.x = posX / WIDTH_OF_MAP_CELL;
	mCoordinate.y = posY / WIDTH_OF_MAP_CELL;

	// 重置位于方格兵力的武器类型
	mWeaponType = WP_TYPE_NONE;
	// 重置位于方格兵力的武器标签
	mWeaponTag = -1;

	// 重置对战双方分别面对的战争迷雾
	mFogAgainstBlueEn = true;
	mFogAgainstRedEn = true;

	// 清空电磁波传输动态数组
	mHertzWaveVec.clear();

	return true;
}