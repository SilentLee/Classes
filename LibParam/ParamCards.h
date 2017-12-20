#pragma once

// 卡牌数量设置
#define NUM_CARDS_IN_GROUP				10
#define NUM_CARD_BUTTONS					5
#define NUM_CARD_NEXT_CARD				1
#define NUM_CARD_USED_CARD				1

// 卡牌武器速度参数
#define PARAM_SPEED_FIGHTER_PLANE									3.0f
#define PARAM_SPEED_BOMBING_PLANE								3.0f
#define PARAM_SPEED_ANTI_AIRCRAFT_MISSILE					3.0f
#define PARAM_SPEED_EARLY_WARNING_PLANE					3.0f
#define PARAM_SPEED_FLAK														0.0f
#define PARAM_SPEED_JAMMING_PLANE									3.0f
#define PARAM_SPEED_RADAR													0.0f
#define PARAM_SPEED_TYPE_8													3.0f
#define PARAM_SPEED_TYPE_9													3.0f
#define PARAM_SPEED_TYPE_10													3.0f
#define PARAM_SPEED_TYPE_11													3.0f
//#define PARAM_SPEED_FIGHTER_PLANE								6.0f
//#define PARAM_SPEED_BOMBING_PLANE							6.0f
//#define PARAM_SPEED_ANTI_AIRCRAFT_MISSILE				6.0f
//#define PARAM_SPEED_EARLY_WARNING_PLANE				6.0f
//#define PARAM_SPEED_FLAK													0.0f
//#define PARAM_SPEED_JAMMING_PLANE								6.0f
//#define PARAM_SPEED_RADAR												0.0f
//#define PARAM_SPEED_TYPE_8												6.0f
//#define PARAM_SPEED_TYPE_9												6.0f
//#define PARAM_SPEED_TYPE_10												6.0f
//#define PARAM_SPEED_TYPE_11												6.0f

// 卡牌探测范围参数
#define PARAM_RANGE_DEC_REVISE_VALUE									-3
#define PARAM_RANGE_DEC_FIGHTER_PLANE								2
#define PARAM_RANGE_DEC_BOMBING_PLANE								2
#define PARAM_RANGE_DEC_ANTI_AIRCRAFT_MISSILE				0
#define PARAM_RANGE_DEC_EARLY_WARNING_PLANE				6
#define PARAM_RANGE_DEC_FLAK														2
#define PARAM_RANGE_DEC_JAMMING_PLANE								2
#define PARAM_RANGE_DEC_RADAR													5
#define PARAM_RANGE_DEC_TYPE_8												2
#define PARAM_RANGE_DEC_TYPE_9												2
#define PARAM_RANGE_DEC_TYPE_10												2
#define PARAM_RANGE_DEC_TYPE_11												2

// 卡牌射程参数
//#define PARAM_RANGE_FIRE_REVISE_VALUE									-3
#define PARAM_RANGE_FIRE_FIGHTER_PLANE								2
#define PARAM_RANGE_FIRE_BOMBING_PLANE								2
#define PARAM_RANGE_FIRE_ANTI_AIRCRAFT_MISSILE				2
#define PARAM_RANGE_FIRE_EARLY_WARNING_PLANE				0
#define PARAM_RANGE_FIRE_FLAK														2
#define PARAM_RANGE_FIRE_JAMMING_PLANE								0
#define PARAM_RANGE_FIRE_RADAR													0
#define PARAM_RANGE_FIRE_TYPE_8												0
#define PARAM_RANGE_FIRE_TYPE_9												0
#define PARAM_RANGE_FIRE_TYPE_10												0
#define PARAM_RANGE_FIRE_TYPE_11												0

// 卡牌生命值参数
#define PARAM_HP_FIGHTER_PLANE								10
#define PARAM_HP_BOMBING_PLANE								30
#define PARAM_HP_ANTI_AIRCRAFT_MISSILE				30
#define PARAM_HP_EARLY_WARNING_PLANE				30
#define PARAM_HP_FLAK													50
#define PARAM_HP_JAMMING_PLANE								30
#define PARAM_HP_RADAR												50
#define PARAM_HP_TYPE_8												30
#define PARAM_HP_TYPE_9												30
#define PARAM_HP_TYPE_10												30
#define PARAM_HP_TYPE_11												30


// 卡牌攻击值参数
#define PARAM_DP_FIGHTER_PLANE								6
#define PARAM_DP_BOMBING_PLANE							7
#define PARAM_DP_ANTI_AIRCRAFT_MISSILE				6
#define PARAM_DP_EARLY_WARNING_PLANE				0
#define PARAM_DP_FLAK													10
#define PARAM_DP_JAMMING_PLANE								0
#define PARAM_DP_RADAR												0
#define PARAM_DP_TYPE_8												3
#define PARAM_DP_TYPE_9												3
#define PARAM_DP_TYPE_10												3
#define PARAM_DP_TYPE_11												3

// 机载武器速度参数
#define PARAM_SPEED_AAM												0.003f

// 机载武器探测范围参数
#define PARAM_RANGE_DEC_AAM									2

// 机载武器射程参数
#define PARAM_RANGE_FIRE_AAM									4

// 机载武器生命值参数
#define PARAM_HP_AAM														0

// 机载武器攻击值参数
#define PARAM_DP_AAM														10

enum ENUM_CARD_TYPE {
	CARD_NO_TYPE = 0,

	/************以下为建筑类型武器 不能移动*************/
	CARD_TYPE_ANTI_AIRCRAFT_MISSILE,
	CARD_TYPE_FLAK,
	CARD_TYPE_RADAR,

	/************以下为飞机类型武器 可以移动*************/
	CARD_TYPE_FIGHTER_PLANE,
	CARD_TYPE_BOMBING_PLANE,
	CARD_TYPE_EARLY_WARNING_PLANE,
	CARD_TYPE_JAMMING_PLANE,
	CARD_TYPE_8,
	CARD_TYPE_9,
	CARD_TYPE_10,
	CARD_TYPE_11,
	CARD_TYPE_END
};

enum cardStatusInGaming {
	CARD_STATUS_NEXT_CARD = 0,
	CARD_STATUS_OCCUPIED,
	CARD_STATUS_FREE
};

enum BtnCardNo {
	BTN_CARD_NONE = -1,
	BTN_CARD_1,
	BTN_CARD_2,
	BTN_CARD_3,
	BTN_CARD_4,
	BTN_CARD_5
};