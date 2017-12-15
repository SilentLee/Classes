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
	Layer::init();
	//// ����ս������
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	//// ע��ս���������º���
	//this->schedule(schedule_selector(LayerBattleDisplay::updateFrog), 1 / 60);

	// ���ӷ���
	addDefenseLine();

	// ע��֪ͨ��������
	//registNotification();

	// ע��ս��̬�Ƹ��º���
	this->schedule(schedule_selector(LayerBattleDisplay::updateBFSituation), 1 / 60);
	return true;
};

// ��������Ϊ�����볤������Ӧ��ʽ����������
void LayerBattleDisplay::addFog(float originX, float originY, int width, int height, float stepX, float stepY)
{
	// ����ս������
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//int imageKeyInt = 5 * CCRANDOM_0_1();
			int imageKeyInt = 1;
			mFrogOfWarArray[i][j] = BFG_FrogOfWar::createWithRelativePos(CU_ImgLoader::getFogImg(imageKeyInt).c_str(), originX + stepX * i, originY + stepY * j);
			//mFrogOfWarArray[i][j]->setZOrder(1);
			this->addChild(mFrogOfWarArray[i][j]);
		}
	}
}

void LayerBattleDisplay::addDefenseLine()
{
	// �����ҷ�����
	CG_Sprite* defenseLineOwn = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.15);
	this->addChild(defenseLineOwn);

	// �������ַ���
	CG_Sprite* defenseLineOppo = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.9);
	this->addChild(defenseLineOppo);
}

void LayerBattleDisplay::registNotification()
{
	// ע�Ῠ�Ʋ��õ�ս��ʱ��֪ͨ����
	//__NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(LayerBattleFieldDB::arrangeCardCallback), MSG_ARRANGE_CARD, NULL);
}

void LayerBattleDisplay::onEnter()
{
	Layer::onEnter();

	// ע����ײ�������¼�
	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(LayerBattleDisplay::onContact, this);
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithFixedPriority(contactListener, 1);

}

// ��ײ���ص�����
bool LayerBattleDisplay::onContact(PhysicsContact& contact)
{
	log("onContact");



	return true;
}
