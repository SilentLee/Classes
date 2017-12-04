#pragma once

// 武器类型
enum ENUM_WEAPON_TYPE {
	WP_TYPE_NONE = 0,

	/************以下为建筑类型武器 不能移动*************/
	WP_TYPE_ANTI_AIRCRAFT_MISSILE,
	WP_TYPE_FLAK, // 高射炮
	WP_TYPE_RADAR,

	/************以下为飞机类型武器 可以移动*************/
	WP_TYPE_FIGHTER_PLANE,
	WP_TYPE_BOMBING_PLANE,
	WP_TYPE_EARLY_WARNING_PLANE,
	WP_TYPE_JAMMING_PLANE,
	WP_TYPE_8,
	WP_TYPE_9,
	WP_TYPE_10,
	WP_TYPE_11,
	WP_TYPE_END
};