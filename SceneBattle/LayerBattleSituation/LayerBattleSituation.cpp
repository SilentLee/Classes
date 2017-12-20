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
	//// ���ս������
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	//// ע��ս��������º���
	//this->schedule(schedule_selector(LayerBattleDisplay::updateFrog), 1 / 60);

	// ��ʼ��ս��̬�Ʒ����ͼ
	initBattleSimulationMap();

	// ��ӷ���
	initDefenseLine();

	// ע��֪ͨ��������
	//registNotification();

	// ע�����ڼ�������ս��̬�Ƹ������ݲ����¿ͻ���ս��̬����ʾ�ĸ��º���
	this->schedule(schedule_selector(LayerBattleSituation::updateBFSituation), 1 / 60);
	// ע�����ڱ���ս��̬�Ƹ��º��� ��ƽ��������
	this->schedule(schedule_selector(LayerBattleSituation::updateLocalSituation), 1 / 60);

	return true;
};

// ��ʼ��ս��̬�Ʒ����ͼ
void LayerBattleSituation::initBattleSimulationMap()
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

void LayerBattleSituation::initDefenseLine()
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