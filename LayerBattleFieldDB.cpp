#include "LayerBattleFieldDB.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattleFieldGraphApi.h"

LayerBattleFieldDB* LayerBattleFieldDB::create()
{
	LayerBattleFieldDB* ret = new LayerBattleFieldDB();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleFieldDB::init()
{ 
	Layer::init();
	// 添加战场迷雾
	addFog(0.05, 0.3, 10, 18, 0.1, 0.035);
	// 添加防线
	addDefenseLine();

	// 注册通知监听函数
	//registNotification();

	return true;
};

// originX = 0.05, originY = 0.3, width = 10, height = 18, stepX = 0.1, stepY = 0.035
void LayerBattleFieldDB::addFog(float originX, float originY, int width, int height, float stepX, float stepY)
{
	// 创建战场迷雾
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//int imageKeyInt = 5 * CCRANDOM_0_1();
			int imageKeyInt = 0;
			BFG_FrogOfWar* fog = BFG_FrogOfWar::createWithRelativePos(CU_ImgLoader::getFogImg(imageKeyInt).c_str(), originX + stepX * i, originY + stepY * j);
			this->addChild(fog, 1, i + j * width); 

			/*auto body = PhysicsBody::createEdgeBox();*/
		}
	}
}

void LayerBattleFieldDB::addDefenseLine()
{
	// 创建我方防线
	CG_Sprite* defenseLineOwn = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.15);
	this->addChild(defenseLineOwn);

	// 创建对手防线
	CG_Sprite* defenseLineOppo = CG_Sprite::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_DEFENSE_LINE).c_str(), 0.5, 0.9);
	this->addChild(defenseLineOppo);
}

void LayerBattleFieldDB::registNotification()
{
	// 注册卡牌布置到战场时的通知函数
	//__NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(LayerBattleFieldDB::arrangeCardCallback), MSG_ARRANGE_CARD, NULL);
}

void LayerBattleFieldDB::arrangeWeaponWithAbsolutePos(int weaponType, int posX, int posY, int discardTimes)
{
	Node* weapon = NULL;

	switch (weaponType)
	{
	case CARD_TYPE_FIGHTER_PLANE:
		weapon = BFW_FighterPlane::createWithRealAbsolutePos(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;
		
	case CARD_TYPE_BOMBING_PLANE:
		//weapon = WpBombingPlane::createWpBombingPlaneWithRealAbsolutePos(IMAGE_URL_WEAPON_BOMBING_PLANE_OWN, posX, posY);
		weapon = BFW_BombingPlane::createWithPosInSquare(IMG_URL_WEAPON_BOMBING_PLANE_OWN, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_ANTI_AIRCRAFT_MISSILE:
		//weapon = WpFighterPlane::createWpFighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_ANTI_AIRCRAFT_MISSILE, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_ANTI_AIRCRAFT_MISSILE, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_EARLY_WARNING_PLANE:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_EARLY_WARNING_PLANE, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_EARLY_WARNING_PLANE, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_FLAK:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_FLAK, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_FLAK, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_JAMMING_PLANE:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_JAMMING_PLANE, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_JAMMING_PLANE, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_RADAR:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_RADAR, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_RADAR, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_8:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_8, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_8, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_9:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_9, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_9, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_10:
		//weapon = BFW_FighterPlane::createBFW_FighterPlaneWithRealAbsolutePos(IMAGE_URL_CARD_10, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_10, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;

	case CARD_TYPE_11:
		//weapon = BFW_FighterPlane::createWithRealAbsolutePos(IMAGE_URL_CARD_11, posX, posY);
		weapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_CARD_11, posX, posY);
		this->addChild(weapon, 0, discardTimes);
		break;
	}
}

void LayerBattleFieldDB::arrangeWeaponWithRelativePos(int weaponType, int posX, int posY, int discardTimes)
{
	log("LayerBattleFieldDB::arrangeWeaponWithRelativePos");
}

void LayerBattleFieldDB::onEnter()
{
	Layer::onEnter();

	// 注册碰撞检测监听事件
	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(LayerBattleFieldDB::onContact, this);
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithFixedPriority(contactListener, 1);

}

// 碰撞检测回调函数
bool LayerBattleFieldDB::onContact(PhysicsContact& contact)
{
	log("onContact");



	return true;
}