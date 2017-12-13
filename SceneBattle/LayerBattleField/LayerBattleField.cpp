#include "LayerBattleField.h"
#include "BattleFieldWeapon_OWN.h"
#include "LibBattleFieldGraphApi.h"


LayerBattleField* LayerBattleField::create()
{
	LayerBattleField* ret = new LayerBattleField();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleField::init()
{ 
	Layer::init();
	// 添加战场迷雾
	//addFog(0.05, 0.3, BATTLE_FIELD_WIDTH_IN_SQUARE, BATTLE_FIELD_HEIGHT_IN_SQUARE, 0.1, 0.05625);
	// 注册战场迷雾更新函数
	//this->schedule(schedule_selector(LayerBattleFieldDB::updateFrog), 1 / 60);

	// 添加防线
	addDefenseLine();

	// 注册通知监听函数
	//registNotification();

	// 注册战场态势更新函数
	this->schedule(schedule_selector(LayerBattleField::updateBFSituation), 1 / 60);
	return true;
};

// 后续更改为坐标与长宽自适应方式？？？？？
void LayerBattleField::addFog(float originX, float originY, int width, int height, float stepX, float stepY)
{
	// 创建战场迷雾
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

void LayerBattleField::addDefenseLine()
{
	// 创建我方防线
	CG_Sprite* defenseLineOwn = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.15);
	this->addChild(defenseLineOwn);

	// 创建对手防线
	CG_Sprite* defenseLineOppo = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.9);
	this->addChild(defenseLineOppo);
}

void LayerBattleField::registNotification()
{
	// 注册卡牌布置到战场时的通知函数
	//__NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(LayerBattleFieldDB::arrangeCardCallback), MSG_ARRANGE_CARD, NULL);
}

void LayerBattleField::onEnter()
{
	Layer::onEnter();

	// 注册碰撞检测监听事件
	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(LayerBattleField::onContact, this);
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithFixedPriority(contactListener, 1);

}

// 碰撞检测回调函数
bool LayerBattleField::onContact(PhysicsContact& contact)
{
	log("onContact");



	return true;
}

