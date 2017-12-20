#include "LayerBattleSituation.h"
#include "LibBattleFieldGraphApi.h"


LayerBattleSituation* LayerBattleSituation::create()
{
	LayerBattleSituation* ret = new LayerBattleSituation();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleSituation::init()
{ 
	LayerEx::init();
	//// 添加战场迷雾
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	//// 注册战场迷雾更新函数
	//this->schedule(schedule_selector(LayerBattleDisplay::updateFrog), 1 / 60);

	// 初始化战场态势仿真地图
	initBattleSimulationMap();

	// 添加防线
	initDefenseLine();

	// 注册通知监听函数
	//registNotification();

	// 注册用于检测服务器战场态势更新数据并更新客户端战场态势显示的更新函数
	this->schedule(schedule_selector(LayerBattleSituation::updateBFSituation), 1 / 60);
	// 注册用于本地战场态势更新函数 起到平滑的作用
	this->schedule(schedule_selector(LayerBattleSituation::updateLocalSituation), 1 / 60);

	return true;
};

// 初始化战场态势仿真地图
void LayerBattleSituation::initBattleSimulationMap()
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

void LayerBattleSituation::initDefenseLine()
{
	// 创建我方防线
	Sprite* defenseLineOwn = Sprite::create(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str());
	defenseLineOwn->setPosition(WIDTH_OF_BATTLE_DISPLAY_MAP / 2, WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	this->addChild(defenseLineOwn);

	// 创建对手防线
	Sprite* defenseLineOppo = CG_Sprite::create(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str());
	defenseLineOppo->setPosition(WIDTH_OF_BATTLE_DISPLAY_MAP / 2, HEIGHT_OF_BATTLE_DISPLAY_MAP - WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	this->addChild(defenseLineOppo);
}