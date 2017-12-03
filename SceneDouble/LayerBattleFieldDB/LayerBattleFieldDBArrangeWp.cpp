#include "LayerBattleFieldDB.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattleFieldGraphApi.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattlefieldWeaponOppoApi.h"
#include "GlobalInstanceApi.h"

void LayerBattleFieldDB::arrangeWeaponWithAbsolutePosOnBegan(int weaponType, int posX, int posY, int discardTimes)
{
	Node* weaponToArrange = NULL;

	switch (weaponType)
	{
	case CARD_TYPE_FIGHTER_PLANE:
		weaponToArrange = BFW_FighterPlane::createWithPosInSquare(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_BOMBING_PLANE:
		weaponToArrange = BFW_BombingPlane::createWithPosInSquare(IMG_URL_WEAPON_BOMBING_PLANE_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_ANTI_AIRCRAFT_MISSILE:
		weaponToArrange = BFW_AntiAirCraftMissile::createWithPosInSquare(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_EARLY_WARNING_PLANE:
		weaponToArrange = BFW_EarlyWarningPlane::createWithPosInSquare(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_FLAK:
		weaponToArrange = BFW_Flak::createWithPosInSquare(IMG_URL_WEAPON_FLAK_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_JAMMING_PLANE:
		weaponToArrange = BFW_JammingPlane::createWithPosInSquare(IMG_URL_WEAPON_JAMMING_PLANE_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_RADAR:
		weaponToArrange = BFW_Radar::createWithPosInSquare(IMG_URL_WEAPON_RADAR_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_8:
		weaponToArrange = BFW_8::createWithPosInSquare(IMG_URL_WEAPON_8_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_9:
		weaponToArrange = BFW_9::createWithPosInSquare(IMG_URL_WEAPON_9_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_10:
		weaponToArrange = BFW_10::createWithPosInSquare(IMG_URL_WEAPON_10_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;

	case CARD_TYPE_11:
		weaponToArrange = BFW_11::createWithPosInSquare(IMG_URL_WEAPON_11_OWN, posX, posY);
		this->addChild(weaponToArrange, 0, discardTimes);
		break;
	}

	weaponToArrange->setOpacity(150);
}

void LayerBattleFieldDB::arrangeWeaponWithAbsolutePosOnMoved(float posX, float posY, int discardTimes)
{
	BFW_BasicClass* weaponToArrange = (BFW_BasicClass*)this->getChildByTag(discardTimes);
	weaponToArrange->setOpacity(150);
	weaponToArrange->setPosInSquare(posX, posY);
}

void LayerBattleFieldDB::arrangeWeaponWithAbsolutePosOnEnded(int discardTimes)
{
	BFW_BasicClass* weaponToArrange = (BFW_BasicClass*)this->getChildByTag(discardTimes);
	weaponToArrange->setOpacity(255);
	weaponToArrange->scheduleUpdate();

	mWeaponsOwn.push_back(weaponToArrange);

	S_PT_BATTLE_1V1_ARRANGE_CARD ptBattle1V1ArrangeCard;
	memset(&ptBattle1V1ArrangeCard, 0, sizeof(ptBattle1V1ArrangeCard));


	// 发送此时布设的卡牌
	ptBattle1V1ArrangeCard.CARD_TYPE = weaponToArrange->getPropertyWp().WP_TYPE;
	ptBattle1V1ArrangeCard.COORDINATE_X = weaponToArrange->getPosXInSquare();
	ptBattle1V1ArrangeCard.COORDINATE_Y = weaponToArrange->getPosYInSquare();
	ptBattle1V1ArrangeCard.POS_X = weaponToArrange->getAdpPosXWithAbsoluteValue();
	ptBattle1V1ArrangeCard.POS_Y = weaponToArrange->getAdpPosYWithAbsoluteValue();
	ptBattle1V1ArrangeCard.SPEED = weaponToArrange->getPropertyWp().SPEED;

	BYTE WriteBuffer[MAX_BUFFER_LENGTH] = { 0, };
	CNetworkSession* networkSession = CNetworkInstance::getInstance()->getNetworkSession();
	networkSession->WritePacket(PT_BATTLE_1V1_ARRANGE_CARD,
		WriteBuffer,
		WRITE_PT_BATTLE_1V1_ARRANGE_CARD(WriteBuffer, ptBattle1V1ArrangeCard));
}

void LayerBattleFieldDB::arrangeWeaponWithAbsolutePosCancelled(int discardTimes)
{
	this->removeChildByTag(discardTimes);
}

// 布设对方兵力函数
void LayerBattleFieldDB::arrangeEnemyWeaponWithAbsolutePos(int weaponType, int posX, int posY, int enemyDiscardTimes)
{
	Node* enemyWeaponToArrange = NULL;

	switch (weaponType)
	{
	case CARD_TYPE_FIGHTER_PLANE:
		enemyWeaponToArrange = BFW_OPPO_FighterPlane::createWithAbsolutePos(IMG_URL_WEAPON_FIGHTER_PLANE_OPPO, posX, posY);
		break;

	case CARD_TYPE_BOMBING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_BombingPlane::createWithAbsolutePos(IMG_URL_WEAPON_BOMBING_PLANE_OPPO, posX, posY);
		break;

	case CARD_TYPE_ANTI_AIRCRAFT_MISSILE:
		enemyWeaponToArrange = BFW_OPPO_AntiAirCraftMissile::createWithAbsolutePos(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OPPO, posX, posY);
		break;

	case CARD_TYPE_EARLY_WARNING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_EarlyWarningPlane::createWithAbsolutePos(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OPPO, posX, posY);
		break;

	case CARD_TYPE_FLAK:
		enemyWeaponToArrange = BFW_OPPO_Flak::createWithAbsolutePos(IMG_URL_WEAPON_FLAK_OPPO, posX, posY);
		break;

	case CARD_TYPE_JAMMING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_JammingPlane::createWithAbsolutePos(IMG_URL_WEAPON_JAMMING_PLANE_OPPO, posX, posY);
		break;

	case CARD_TYPE_RADAR:
		enemyWeaponToArrange = BFW_OPPO_Radar::createWithAbsolutePos(IMG_URL_WEAPON_RADAR_OPPO, posX, posY);
		break;

	case CARD_TYPE_8:
		enemyWeaponToArrange = BFW_OPPO_8::createWithAbsolutePos(IMG_URL_WEAPON_8_OPPO, posX, posY);
		break;

	case CARD_TYPE_9:
		enemyWeaponToArrange = BFW_OPPO_9::createWithAbsolutePos(IMG_URL_WEAPON_9_OPPO, posX, posY);
		break;

	case CARD_TYPE_10:
		enemyWeaponToArrange = BFW_OPPO_10::createWithAbsolutePos(IMG_URL_WEAPON_10_OPPO, posX, posY);
		break;

	case CARD_TYPE_11:
		enemyWeaponToArrange = BFW_OPPO_11::createWithAbsolutePos(IMG_URL_WEAPON_11_OPPO, posX, posY);
		break;
	}
	this->addChild(enemyWeaponToArrange, 3, enemyDiscardTimes);
	enemyWeaponToArrange->scheduleUpdate();
}