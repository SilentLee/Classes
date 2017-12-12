#include "LayerBattleFieldDB.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattleFieldGraphApi.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattlefieldWeaponOppoApi.h"
#include "GlobalInstanceApi.h"

// 布设兵力预览函数
// 与 onTouchBegan 配合使用
void LayerBattleFieldDB::previewWeaponWithAbsolutePosOnBegan(int weaponType, int posX, int posY)
{
	Node* previewWeapon = NULL;

	switch (weaponType)
	{
	case CARD_TYPE_FIGHTER_PLANE:
		previewWeapon = BFW_FighterPlane::createWithPosInSquare(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_BOMBING_PLANE:
		previewWeapon = BFW_BombingPlane::createWithPosInSquare(IMG_URL_WEAPON_BOMBING_PLANE_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_ANTI_AIRCRAFT_MISSILE:
		previewWeapon = BFW_AntiAirCraftMissile::createWithPosInSquare(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_EARLY_WARNING_PLANE:
		previewWeapon = BFW_EarlyWarningPlane::createWithPosInSquare(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_FLAK:
		previewWeapon = BFW_Flak::createWithPosInSquare(IMG_URL_WEAPON_FLAK_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_JAMMING_PLANE:
		previewWeapon = BFW_JammingPlane::createWithPosInSquare(IMG_URL_WEAPON_JAMMING_PLANE_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_RADAR:
		previewWeapon = BFW_Radar::createWithPosInSquare(IMG_URL_WEAPON_RADAR_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_8:
		previewWeapon = BFW_8::createWithPosInSquare(IMG_URL_WEAPON_8_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_9:
		previewWeapon = BFW_9::createWithPosInSquare(IMG_URL_WEAPON_9_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_10:
		previewWeapon = BFW_10::createWithPosInSquare(IMG_URL_WEAPON_10_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case CARD_TYPE_11:
		previewWeapon = BFW_11::createWithPosInSquare(IMG_URL_WEAPON_11_OWN, posX, posY);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;
	}

	previewWeapon->setOpacity(150);
}

// 布设兵力预览函数
// 与 onTouchMoved 配合使用
void LayerBattleFieldDB::previewWeaponWithAbsolutePosOnMoved(float posX, float posY)
{
	BFW_BasicClass* previewWeapon = (BFW_BasicClass*)this->getChildByName("previewWeapon");
	previewWeapon->setOpacity(150);
	previewWeapon->setPosInSquare(posX, posY);
}

// 布设兵力预览函数
// 与 onTouchEnded 配合使用
void LayerBattleFieldDB::previewWeaponWithAbsolutePosOnEnded()
{
	CUserInstance* userInstance = CUserInstance::getInstance();

	BFW_BasicClass* previewWeapon = (BFW_BasicClass*)this->getChildByName("previewWeapon");

	S_PT_BATTLE_ARRANGE_WEAPON ptBattleArrangeWeapon;
	memset(&ptBattleArrangeWeapon, 0, sizeof(ptBattleArrangeWeapon));


	// 发送此时布设的卡牌
	ptBattleArrangeWeapon.WEAPON_TYPE = previewWeapon->getPropertyWp().WP_TYPE;
	ptBattleArrangeWeapon.COORDINATE_X = previewWeapon->getPosXInSquare();
	ptBattleArrangeWeapon.COORDINATE_Y = previewWeapon->getPosYInSquare();
	ptBattleArrangeWeapon.POS_X = previewWeapon->getAdpPosXWithAbsoluteValue();
	ptBattleArrangeWeapon.POS_Y = previewWeapon->getAdpPosYWithAbsoluteValue();
	ptBattleArrangeWeapon.SPEED = previewWeapon->getPropertyWp().SPEED;
	ptBattleArrangeWeapon.TROOPS_IN = userInstance->getTroopsIn();

	BYTE WriteBuffer[MAX_BUFFER_LENGTH] = { 0, };
	CNetworkSession* networkSession = CNetworkInstance::getInstance()->getNetworkSession();
	networkSession->WritePacket(PT_BATTLE_ARRANGE_WEAPON,
		WriteBuffer,
		WRITE_PT_BATTLE_ARRANGE_WEAPON(WriteBuffer, ptBattleArrangeWeapon));

	this->removeChild(previewWeapon);
}

// 布设兵力预览函数
// 与 onTouchCancelled 配合使用
void LayerBattleFieldDB::previewWeaponWithAbsolutePosCancelled()
{
	this->removeChildByName("previewWeapon");
}

// 布设对方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
// 坐标需要转换一下 将武器由 从下向上飞行 转换为 从上向下飞行
void LayerBattleFieldDB::arrangeEnemyWeaponWithAbsolutePos(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
{
	// 根据玩家当前属于蓝方还是红方 重新计算加入武器在客户端战场态势显示中的位置坐标
	CUserInstance* userInstance = CUserInstance::getInstance();
	if (userInstance->getTroopsIn() == TROOPS_BLUE) {
		posX = posX;
		posY = posY;
	}
	else if (userInstance->getTroopsIn() == TROOPS_RED) {
		posX = posX;
		posY = 2060 - posY;
	}

	Node* enemyWeaponToArrange = NULL;

	// 坐标转换
	//posY = 2060 - posY;

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		enemyWeaponToArrange = BFW_OPPO_FighterPlane::createWithAbsolutePos(IMG_URL_WEAPON_FIGHTER_PLANE_OPPO, posX, posY);
		break;

	case WP_TYPE_BOMBING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_BombingPlane::createWithAbsolutePos(IMG_URL_WEAPON_BOMBING_PLANE_OPPO, posX, posY);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		enemyWeaponToArrange = BFW_OPPO_AntiAirCraftMissile::createWithAbsolutePos(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OPPO, posX, posY);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_EarlyWarningPlane::createWithAbsolutePos(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OPPO, posX, posY);
		break;

	case WP_TYPE_FLAK:
		enemyWeaponToArrange = BFW_OPPO_Flak::createWithAbsolutePos(IMG_URL_WEAPON_FLAK_OPPO, posX, posY);
		break;

	case WP_TYPE_JAMMING_PLANE:
		enemyWeaponToArrange = BFW_OPPO_JammingPlane::createWithAbsolutePos(IMG_URL_WEAPON_JAMMING_PLANE_OPPO, posX, posY);
		break;

	case WP_TYPE_RADAR:
		enemyWeaponToArrange = BFW_OPPO_Radar::createWithAbsolutePos(IMG_URL_WEAPON_RADAR_OPPO, posX, posY);
		break;

	case WP_TYPE_8:
		enemyWeaponToArrange = BFW_OPPO_8::createWithAbsolutePos(IMG_URL_WEAPON_8_OPPO, posX, posY);
		break;

	case WP_TYPE_9:
		enemyWeaponToArrange = BFW_OPPO_9::createWithAbsolutePos(IMG_URL_WEAPON_9_OPPO, posX, posY);
		break;

	case WP_TYPE_10:
		enemyWeaponToArrange = BFW_OPPO_10::createWithAbsolutePos(IMG_URL_WEAPON_10_OPPO, posX, posY);
		break;

	case WP_TYPE_11:
		enemyWeaponToArrange = BFW_OPPO_11::createWithAbsolutePos(IMG_URL_WEAPON_11_OPPO, posX, posY);
		break;
	}
	this->addChild(enemyWeaponToArrange, 3, weaponTag);
	enemyWeaponToArrange->scheduleUpdate();
}

// 布设本方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
void LayerBattleFieldDB::arrangeOwnWeaponWithAbsolutePos(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
{
	// 根据玩家当前属于蓝方还是红方 重新计算加入武器在客户端战场态势显示中的位置坐标
	CUserInstance* userInstance = CUserInstance::getInstance();
	if (userInstance->getTroopsIn() == TROOPS_BLUE) {
		posX = posX;
		posY = posY;
	}
	else if (userInstance->getTroopsIn() == TROOPS_RED) {
		posX = posX;
		posY = 2060 - posY;
	}

	Node* ownWeaponToArrange = NULL;

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		ownWeaponToArrange = BFW_FighterPlane::createWithAbsolutePos(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, posX, posY);
		break;

	case WP_TYPE_BOMBING_PLANE:
		ownWeaponToArrange = BFW_BombingPlane::createWithAbsolutePos(IMG_URL_WEAPON_BOMBING_PLANE_OWN, posX, posY);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		ownWeaponToArrange = BFW_AntiAirCraftMissile::createWithAbsolutePos(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, posX, posY);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		ownWeaponToArrange = BFW_EarlyWarningPlane::createWithAbsolutePos(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, posX, posY);
		break;

	case WP_TYPE_FLAK:
		ownWeaponToArrange = BFW_Flak::createWithAbsolutePos(IMG_URL_WEAPON_FLAK_OWN, posX, posY);
		break;

	case WP_TYPE_JAMMING_PLANE:
		ownWeaponToArrange = BFW_JammingPlane::createWithAbsolutePos(IMG_URL_WEAPON_JAMMING_PLANE_OWN, posX, posY);
		break;

	case WP_TYPE_RADAR:
		ownWeaponToArrange = BFW_Radar::createWithAbsolutePos(IMG_URL_WEAPON_RADAR_OWN, posX, posY);
		break;

	case WP_TYPE_8:
		ownWeaponToArrange = BFW_8::createWithAbsolutePos(IMG_URL_WEAPON_8_OWN, posX, posY);
		break;

	case WP_TYPE_9:
		ownWeaponToArrange = BFW_9::createWithAbsolutePos(IMG_URL_WEAPON_9_OWN, posX, posY);
		break;

	case WP_TYPE_10:
		ownWeaponToArrange = BFW_10::createWithAbsolutePos(IMG_URL_WEAPON_10_OWN, posX, posY);
		break;

	case WP_TYPE_11:
		ownWeaponToArrange = BFW_11::createWithAbsolutePos(IMG_URL_WEAPON_11_OWN, posX, posY);
		break;
	}
	this->addChild(ownWeaponToArrange, 3, weaponTag);
	ownWeaponToArrange->scheduleUpdate();
}