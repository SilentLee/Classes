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
	//// ���ս������
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	//// ע��ս��������º���
	//this->schedule(schedule_selector(LayerBattleDisplay::updateFrog), 1 / 60);

	// ��ӷ���
	addDefenseLine();

	// ע��֪ͨ��������
	//registNotification();

	// ע��ս��̬�Ƹ��º���
	this->schedule(schedule_selector(LayerBattleDisplay::updateBFSituation), 1 / 60);
	return true;
};

void LayerBattleDisplay::addDefenseLine()
{
	// �����ҷ�����
	Sprite* defenseLineOwn = Sprite::create(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str());
	defenseLineOwn->setPosition(WIDTH_OF_BATTLE_DISPLAY_MAP / 2, WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	this->addChild(defenseLineOwn);

	// �������ַ���
	Sprite* defenseLineOppo = CG_Sprite::create(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str());
	defenseLineOppo->setPosition(WIDTH_OF_BATTLE_DISPLAY_MAP / 2, HEIGHT_OF_BATTLE_DISPLAY_MAP - WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	this->addChild(defenseLineOppo);
}