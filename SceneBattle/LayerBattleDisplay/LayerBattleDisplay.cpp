#include "LayerBattleDisplay.h"
#include "BattleFieldWeapon_OWN.h"
#include "LibBattleFieldGraphApi.h"


LayerBattleDisplay* LayerBattleDisplay::create()
{
	LayerBattleDisplay* ret = new LayerBattleDisplay();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleDisplay::init()
{ 
	LayerEx::init();
	//// 添加战场迷雾
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	//// 注册战场迷雾更新函数
	//this->schedule(schedule_selector(LayerBattleDisplay::updateFrog), 1 / 60);

	// 添加防线
	addDefenseLine();

	// 注册通知监听函数
	//registNotification();

	// 注册战场态势更新函数
	this->schedule(schedule_selector(LayerBattleDisplay::updateBFSituation), 1 / 60);
	return true;
};

void LayerBattleDisplay::addDefenseLine()
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