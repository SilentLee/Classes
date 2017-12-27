#include "BattleSimulationMapCell.h"
#include "CU_ImgLoader.h"

// 创建函数 使用仿真地图坐标
CBattleSimulationMapCell* CBattleSimulationMapCell::createWithCoordinate(int coordinateX, int coordinateY)
{
	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();

	if (ret && ret->initWithCoordinate(coordinateX, coordinateY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// 初始化函数
// 在战场显示坐标系下进行坐标设定 1920 * 1080
bool CBattleSimulationMapCell::initWithCoordinate(int coordinateX, int coordinateY)
{
	// 计算战场显示坐标系下的坐标
	float posX = (coordinateX + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (coordinateY + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	//float posX = 540;
	//float posY = 960;

	// 父类初始化
	Sprite::initWithFile(CU_ImgLoader::getFogImg(1).c_str());
	// 设置位置
	this->setPosition(posX, posY);

	// 自适应设置方格大小
	float sizeFactor = WIDTH_OF_BATTLE_SIMULATION_MAP_CELL / this->getContentSize().width;
	this->setScale(sizeFactor);

	// 设置战场方格的仿真坐标
	mCoordinate.x = coordinateX;
	mCoordinate.y = coordinateY;

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