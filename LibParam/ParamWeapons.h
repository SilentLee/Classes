#pragma once

// ��������
enum ENUM_WEAPON_TYPE {
	WP_TYPE_NONE = 0,

	/************����Ϊ������������ �����ƶ�*************/
	WP_TYPE_ANTI_AIRCRAFT_MISSILE,
	WP_TYPE_FLAK, // ������
	WP_TYPE_RADAR,

	/************����Ϊ�ɻ��������� �����ƶ�*************/
	WP_TYPE_FIGHTER_PLANE,
	WP_TYPE_BOMBING_PLANE,
	WP_TYPE_EARLY_WARNING_PLANE,
	WP_TYPE_JAMMING_PLANE,
	WP_TYPE_8,
	WP_TYPE_9,
	WP_TYPE_10,
	WP_TYPE_11,

	/********����Ϊ������������ �����ƶ� ���ܲ���********/
	WP_TYPE_AAM,

	WP_TYPE_END
};

//enum airborneWeaponType {
//	AIRBORNE_WP_TYPE_BEGIN = WP_TYPE_END,
//	AIRBORNE_WP_TYPE_AAM
//};