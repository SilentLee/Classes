#include "LayerBattleSituation.h"
#include "BattleFieldWeapon.h"
#include "LibBattleFieldGraphApi.h"
#include "GlobalInstanceApi.h"

// 布设兵力预览函数
// 与 onTouchBegan 配合使用
void LayerBattleSituation::previewWeaponWithPositionOnBegan(int weaponType, float posX, float posY)
{
	Node* previewWeapon = NULL;

	// 将 posY 限制在允许防止武器的区域中
	posY = min(posY, HEIGHT_OF_RANGE_TO_ARRANGE_WEAPON_ON_SIMULATION_MAP * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	posY = max(posY, 0.0f);

	Vec2 position = Vec2(posX, posY);

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, position, WP_TYPE_FIGHTER_PLANE, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_BOMBING_PLANE:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_BOMBING_PLANE_OWN, position, WP_TYPE_BOMBING_PLANE, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, position, WP_TYPE_EARLY_WARNING_PLANE, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_FLAK:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_FLAK_OWN, position, WP_TYPE_FLAK, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_JAMMING_PLANE:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_JAMMING_PLANE_OWN, position, WP_TYPE_JAMMING_PLANE, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_RADAR:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_RADAR_OWN, position, WP_TYPE_RADAR, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_8:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_8_OWN, position, WP_TYPE_8, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_9:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_9_OWN, position, WP_TYPE_9, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_10:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_10_OWN, position, WP_TYPE_10, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;

	case WP_TYPE_11:
		previewWeapon = BattleFieldWeapon::createWithLocalOperationData(IMG_URL_WEAPON_11_OWN, position, WP_TYPE_11, IFF_FRIEND);
		this->addChild(previewWeapon, 0, "previewWeapon");
		break;
	}

	previewWeapon->setOpacity(150);
}

// 布设兵力预览函数
// 与 onTouchMoved 配合使用
void LayerBattleSituation::previewWeaponWithPositionOnMoved(float posX, float posY)
{
	BattleFieldWeapon* previewWeapon = (BattleFieldWeapon*)this->getChildByName("previewWeapon");
	previewWeapon->setOpacity(150);

	// 将 posY 限制在允许防止武器的区域中
	posY = min(posY, HEIGHT_OF_RANGE_TO_ARRANGE_WEAPON_ON_SIMULATION_MAP * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL);
	posY = max(posY, 0.0f);

	posX = ((int)(posX / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	posY = ((int)(posY / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	previewWeapon->setPosition(posX, posY);
}

// 布设兵力预览函数
// 与 onTouchEnded 配合使用
void LayerBattleSituation::previewWeaponWithPositionOnEnded()
{
	CUserInstance* userInstance = CUserInstance::getInstance();

	BattleFieldWeapon* previewWeapon = (BattleFieldWeapon*)this->getChildByName("previewWeapon");

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
void LayerBattleSituation::previewWeaponWithPositionCancelled()
{
	this->removeChildByName("previewWeapon");
}

// 布设对方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
// 坐标需要转换一下 将武器由 从下向上飞行 转换为 从上向下飞行
void LayerBattleSituation::arrangeEnemyWeaponWithPosition(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
{
	// 根据玩家当前属于蓝方还是红方 重新计算加入武器在客户端战场态势显示中的位置坐标
	CUserInstance* userInstance = CUserInstance::getInstance();
	if (userInstance->getTroopsIn() == TROOPS_BLUE) {
		posX = posX;
		posY = posY;
	}
	else if (userInstance->getTroopsIn() == TROOPS_RED) {
		posX = posX;
		posY = HEIGHT_OF_BATTLE_DISPLAY_MAP - posY;
	}

	BattleFieldWeapon* enemyWeaponToArrange = NULL;

	Vec2 position = Vec2(posX, posY);

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_FIGHTER_PLANE_OPPO, position, WP_TYPE_FIGHTER_PLANE, IFF_FOE);
		break;

	case WP_TYPE_BOMBING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_BOMBING_PLANE_OPPO, position, WP_TYPE_BOMBING_PLANE, IFF_FOE);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OPPO, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE, IFF_FOE);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OPPO, position, WP_TYPE_EARLY_WARNING_PLANE, IFF_FOE);
		break;

	case WP_TYPE_FLAK:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_FLAK_OPPO, position, WP_TYPE_FLAK, IFF_FOE);
		break;

	case WP_TYPE_JAMMING_PLANE:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_JAMMING_PLANE_OPPO, position, WP_TYPE_JAMMING_PLANE, IFF_FOE);
		break;

	case WP_TYPE_RADAR:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_RADAR_OPPO, position, WP_TYPE_RADAR, IFF_FOE);
		break;

	case WP_TYPE_8:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_8_OPPO, position, WP_TYPE_8, IFF_FOE);
		break;

	case WP_TYPE_9:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_9_OPPO, position, WP_TYPE_9, IFF_FOE);
		break;

	case WP_TYPE_10:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_10_OPPO, position, WP_TYPE_10, IFF_FOE);
		break;

	case WP_TYPE_11:
		enemyWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_11_OPPO, position, WP_TYPE_11, IFF_FOE);
		break;
	}
	// 将武器加入兵力存储数组
	mWeaponsOppo.push_back(enemyWeaponToArrange);
	// 将武器添加到战场态势显示层
	this->addChild(enemyWeaponToArrange, 3, weaponTag);
	//enemyWeaponToArrange->scheduleUpdate();
}

// 布设本方兵力函数
// 坐标幅度
// 宽度 1080
// 高度 1920
void LayerBattleSituation::arrangeOwnWeaponWithPosition(ENUM_TROOPS troops, int weaponType, int posX, int posY, int weaponTag)
{
	// 根据玩家当前属于蓝方还是红方 重新计算加入武器在客户端战场态势显示中的位置坐标
	CUserInstance* userInstance = CUserInstance::getInstance();
	if (userInstance->getTroopsIn() == TROOPS_BLUE) {
		posX = posX;
		posY = posY;
	}
	else if (userInstance->getTroopsIn() == TROOPS_RED) {
		posX = posX;
		posY = HEIGHT_OF_BATTLE_DISPLAY_MAP - posY;
	}

	Vec2 position = Vec2(posX, posY);

	BattleFieldWeapon* ownWeaponToArrange = NULL;

	switch (weaponType)
	{
	case WP_TYPE_FIGHTER_PLANE:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, position, WP_TYPE_FIGHTER_PLANE, IFF_FRIEND);
		break;

	case WP_TYPE_BOMBING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_BOMBING_PLANE_OWN, position, WP_TYPE_BOMBING_PLANE, IFF_FRIEND);
		break;

	case WP_TYPE_ANTI_AIRCRAFT_MISSILE:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_ANTI_AIRCRAFT_MISSILE_OWN, position, WP_TYPE_ANTI_AIRCRAFT_MISSILE, IFF_FRIEND);
		break;

	case WP_TYPE_EARLY_WARNING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_EARLY_WARNING_PLANE_OWN, position, WP_TYPE_EARLY_WARNING_PLANE, IFF_FRIEND);
		break;

	case WP_TYPE_FLAK:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_FLAK_OWN, position, WP_TYPE_FLAK, IFF_FRIEND);
		break;

	case WP_TYPE_JAMMING_PLANE:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_JAMMING_PLANE_OWN, position, WP_TYPE_JAMMING_PLANE, IFF_FRIEND);
		break;

	case WP_TYPE_RADAR:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_RADAR_OWN, position, WP_TYPE_RADAR, IFF_FRIEND);
		break;

	case WP_TYPE_8:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_8_OWN, position, WP_TYPE_8, IFF_FRIEND);
		break;

	case WP_TYPE_9:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_9_OWN, position, WP_TYPE_9, IFF_FRIEND);
		break;

	case WP_TYPE_10:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_10_OWN, position, WP_TYPE_10, IFF_FRIEND);
		break;

	case WP_TYPE_11:
		ownWeaponToArrange = BattleFieldWeapon::createWithRecvServerData(IMG_URL_WEAPON_11_OWN, position, WP_TYPE_11, IFF_FRIEND);
		break;
	}
	// 将武器加入兵力存储数组
	mWeaponsOwn.push_back(ownWeaponToArrange);
	// 将武器添加到战场态势显示层
	this->addChild(ownWeaponToArrange, 3, weaponTag);
	//ownWeaponToArrange->scheduleUpdate();
}