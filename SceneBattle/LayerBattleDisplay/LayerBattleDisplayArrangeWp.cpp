#include "LayerBattleDisplay.h"
#include "BattleFieldWeapon_OWN.h"
#include "LibBattleFieldGraphApi.h"
#include "BattleFieldWeapon_OPPO.h"
#include "GlobalInstanceApi.h"

// 布设兵力预览函数
// 与 onTouchBegan 配合使用
void LayerBattleDisplay::previewWeaponWithPositionOnBegan(int weaponType, int posX, int posY)
{
	Node* previewWeapon = NULL;

	Vec2 position = Vec2(posX, posY);

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, position, WP_TYPE_FIGHTER_PLANE);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_BOMBING_PLANE:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_BOMBING_PLANE_OWN, position, WP_TYPE_BOMBING_PLANE);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, position, WP_TYPE_EARLY_WARNING_PLANE);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_FLAK:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_FLAK_OWN, position, WP_TYPE_FLAK);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_JAMMING_PLANE:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_JAMMING_PLANE_OWN, position, WP_TYPE_JAMMING_PLANE);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_RADAR:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_RADAR_OWN, position, WP_TYPE_RADAR);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_8:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_8_OWN, position, WP_TYPE_8);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_9:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_9_OWN, position, WP_TYPE_9);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_10:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_10_OWN, position, WP_TYPE_10);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_11:
		previewWeapon = BattleFieldWeapon_OWN::createWithLocalOperationPosData(IMG_URL_WEAPON_11_OWN, position, WP_TYPE_11);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;
	}

	previewWeapon->setOpacity(150);
}

// 布设兵力预览函数
// 与 onTouchMoved 配合使用
void LayerBattleDisplay::previewWeaponWithPositionOnMoved(float posX, float posY)
{
	BattleFieldWeapon_OWN* previewWeapon = (BattleFieldWeapon_OWN*)this->getChildByName("previewWeapon");
	previewWeapon->setOpacity(150);
	// 在移动拟布设武器时 首先计算当前武器的战场态势仿真坐标
	int coordinateX = (int)(posX / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	int coordinateY = (int)(posY / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	// 在 SetCoordinate 中设置战场态势仿真坐标 
	// 同时在 SetCoordinate 中更新修正后的战场态势显示坐标 posX posY
	previewWeapon->SetCoordinate(Vec2(coordinateX, coordinateY));
}

// 布设兵力预览函数
// 与 onTouchEnded 配合使用
void LayerBattleDisplay::previewWeaponWithPositionOnEnded()
{
	CUserInstance* userInstance = CUserInstance::getInstance();

	BattleFieldWeapon_OWN* previewWeapon = (BattleFieldWeapon_OWN*)this->getChildByName("previewWeapon");

	S_PT_BATTLE_ARRANGE_WEAPON ptBattleArrangeWeapon;
	memset(&ptBattleArrangeWeapon, 0, sizeof(ptBattleArrangeWeapon));


	// 发送此时布设的卡牌
	ptBattleArrangeWeapon.WEAPON_TYPE = previewWeapon->GetPropertyWp().WP_TYPE;
	ptBattleArrangeWeapon.COORDINATE_X = previewWeapon->GetCoordinate().x;
	ptBattleArrangeWeapon.COORDINATE_Y = previewWeapon->GetCoordinate().y;
	ptBattleArrangeWeapon.POS_X = previewWeapon->getPosition().x;
	ptBattleArrangeWeapon.POS_Y = previewWeapon->getPosition().y;
	ptBattleArrangeWeapon.SPEED = previewWeapon->GetPropertyWp().SPEED;
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
void LayerBattleDisplay::previewWeaponWithPositionCancelled()
{
	this->removeChildByName("previewWeapon");
}

// 布设对方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
// 坐标需要转换一下 将武器由 从下向上飞行 转换为 从上向下飞行
void LayerBattleDisplay::arrangeEnemyWeaponWithPosition(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
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

	Vec2 position = Vec2(posX, posY);

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_FIGHTER_PLANE_OPPO, position, WP_TYPE_FIGHTER_PLANE);
		break;

	case WP_TYPE_BOMBING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_BOMBING_PLANE_OPPO, position, WP_TYPE_BOMBING_PLANE);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OPPO, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OPPO, position, WP_TYPE_EARLY_WARNING_PLANE);
		break;

	case WP_TYPE_FLAK:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_FLAK_OPPO, position, WP_TYPE_FLAK);
		break;

	case WP_TYPE_JAMMING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_JAMMING_PLANE_OPPO, position, WP_TYPE_JAMMING_PLANE);
		break;

	case WP_TYPE_RADAR:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_RADAR_OPPO, position, WP_TYPE_RADAR);
		break;

	case WP_TYPE_8:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_8_OPPO, position, WP_TYPE_8);
		break;

	case WP_TYPE_9:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_9_OPPO, position, WP_TYPE_9);
		break;

	case WP_TYPE_10:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_10_OPPO, position, WP_TYPE_10);
		break;

	case WP_TYPE_11:
		enemyWeaponToArrange = BattleFieldWeapon_OPPO::createWithRecvServerPosData(IMG_URL_WEAPON_11_OPPO, position, WP_TYPE_11);
		break;
	}
	this->addChild(enemyWeaponToArrange, 3, weaponTag);
	enemyWeaponToArrange->scheduleUpdate();
}

// 布设本方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
void LayerBattleDisplay::arrangeOwnWeaponWithPosition(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
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

	Vec2 position = Vec2(posX, posY);

	Node* ownWeaponToArrange = NULL;

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, position, WP_TYPE_FIGHTER_PLANE);
		break;

	case WP_TYPE_BOMBING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_BOMBING_PLANE_OWN, position, WP_TYPE_BOMBING_PLANE);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, position, WP_TYPE_EARLY_WARNING_PLANE);
		break;

	case WP_TYPE_FLAK:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_FLAK_OWN, position, WP_TYPE_FLAK);
		break;

	case WP_TYPE_JAMMING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_JAMMING_PLANE_OWN, position, WP_TYPE_JAMMING_PLANE);
		break;

	case WP_TYPE_RADAR:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_RADAR_OWN, position, WP_TYPE_RADAR);
		break;

	case WP_TYPE_8:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_8_OWN, position, WP_TYPE_8);
		break;

	case WP_TYPE_9:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_9_OWN, position, WP_TYPE_9);
		break;

	case WP_TYPE_10:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_10_OWN, position, WP_TYPE_10);
		break;

	case WP_TYPE_11:
		ownWeaponToArrange = BattleFieldWeapon_OWN::createWithRecvServerPosData(IMG_URL_WEAPON_11_OWN, position, WP_TYPE_11);
		break;
	}
	this->addChild(ownWeaponToArrange, 3, weaponTag);
	ownWeaponToArrange->scheduleUpdate();
}