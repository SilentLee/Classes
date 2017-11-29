#include "CU_CardLoader.h"

static map<int, PROPERTY_WP> cardParams;
static map<int, PROPERTY_WP> airborneWeaponParams;

void CU_CardLoader::loadCardParams()
{
	PROPERTY_WP propertyWp;

	// װ��ս�������Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_FIGHTER_PLANE;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_FIGHTER_PLANE;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_FIGHTER_PLANE;
	propertyWp.HP = PARAM_HP_FIGHTER_PLANE;
	propertyWp.DP = PARAM_DP_FIGHTER_PLANE;
	cardParams.insert(make_pair(CARD_TYPE_FIGHTER_PLANE, propertyWp));

	// װ�غ�ը�����Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_BOMBING_PLANE;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_BOMBING_PLANE;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_BOMBING_PLANE;
	propertyWp.HP = PARAM_HP_BOMBING_PLANE;
	propertyWp.DP = PARAM_DP_BOMBING_PLANE;
	cardParams.insert(make_pair(CARD_TYPE_BOMBING_PLANE, propertyWp));

	// װ�ط��յ������Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_ANTI_AIRCRAFT_MISSILE;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_ANTI_AIRCRAFT_MISSILE;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_ANTI_AIRCRAFT_MISSILE;
	propertyWp.HP = PARAM_HP_ANTI_AIRCRAFT_MISSILE;
	propertyWp.DP = PARAM_DP_ANTI_AIRCRAFT_MISSILE;
	cardParams.insert(make_pair(CARD_TYPE_ANTI_AIRCRAFT_MISSILE, propertyWp));

	// װ��Ԥ�������Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_EARLY_WARNING_PLANE;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_EARLY_WARNING_PLANE;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_EARLY_WARNING_PLANE;
	propertyWp.HP = PARAM_HP_EARLY_WARNING_PLANE;
	propertyWp.DP = PARAM_DP_EARLY_WARNING_PLANE;
	cardParams.insert(make_pair(CARD_TYPE_EARLY_WARNING_PLANE, propertyWp));

	// װ�ظ����ڿ��Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_FLAK;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_FLAK;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_FLAK;
	propertyWp.HP = PARAM_HP_FLAK;
	propertyWp.DP = PARAM_DP_FLAK;
	cardParams.insert(make_pair(CARD_TYPE_FLAK, propertyWp));

	// װ�ظ��Ż����Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_JAMMING_PLANE;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_JAMMING_PLANE;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_JAMMING_PLANE;
	propertyWp.HP = PARAM_HP_JAMMING_PLANE;
	propertyWp.DP = PARAM_DP_JAMMING_PLANE;
	cardParams.insert(make_pair(CARD_TYPE_JAMMING_PLANE, propertyWp));

	// װ���״￨�Ʋ���
	propertyWp.WP_TYPE = CARD_TYPE_RADAR;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_RADAR;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_RADAR;
	propertyWp.HP = PARAM_HP_RADAR;
	propertyWp.DP = PARAM_DP_RADAR;
	cardParams.insert(make_pair(CARD_TYPE_RADAR, propertyWp));

	// װ�ؿ���8����
	propertyWp.WP_TYPE = CARD_TYPE_8;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_TYPE_8;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_TYPE_8;
	propertyWp.HP = PARAM_HP_TYPE_8;
	propertyWp.DP = PARAM_DP_TYPE_8;
	cardParams.insert(make_pair(CARD_TYPE_8, propertyWp));

	// װ�ؿ���9����
	propertyWp.WP_TYPE = CARD_TYPE_9;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_TYPE_9;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_TYPE_9;
	propertyWp.HP = PARAM_HP_TYPE_9;
	propertyWp.DP = PARAM_DP_TYPE_9;
	cardParams.insert(make_pair(CARD_TYPE_9, propertyWp));

	// װ�ؿ���10����
	propertyWp.WP_TYPE = CARD_TYPE_10;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_TYPE_10;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_TYPE_10;
	propertyWp.HP = PARAM_HP_TYPE_10;
	propertyWp.DP = PARAM_DP_TYPE_10;
	cardParams.insert(make_pair(CARD_TYPE_10, propertyWp));

	// װ�ؿ���11����
	propertyWp.WP_TYPE = CARD_TYPE_11;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_TYPE_11;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_TYPE_11;
	propertyWp.HP = PARAM_HP_TYPE_11;
	propertyWp.DP = PARAM_DP_TYPE_11;
	cardParams.insert(make_pair(CARD_TYPE_11, propertyWp));
}

PROPERTY_WP CU_CardLoader::getCardParam(int key)
{
	return cardParams.find(key)->second;
}

void CU_CardLoader::loadAirborneWeaponParams()
{
	PROPERTY_WP propertyWp;

	// װ�ؿտյ�������
	propertyWp.WP_TYPE = AIRBORNE_WP_TYPE_AAM;
	propertyWp.LEVEL = 1;
	propertyWp.SPEED = PARAM_SPEED_AAM;
	propertyWp.RANGE_DEC = PARAM_RANGE_DEC_AAM;
	propertyWp.RANGE_FIRE = PARAM_RANGE_FIRE_AAM;
	propertyWp.DP = PARAM_DP_AAM;
	airborneWeaponParams.insert(make_pair(AIRBORNE_WP_TYPE_AAM, propertyWp));
}

PROPERTY_WP CU_CardLoader::getAirborneWeaponParams(int key)
{
	return airborneWeaponParams.find(key)->second;
}