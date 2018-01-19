#pragma once
#include "cocos2d.h"

USING_NS_CC;

extern class CBattleField;

// 定义武器在战场态势仿真地图中的投影尺寸
#define SIZE_OF_ANTI_AIRCRAFT_MISSILE				Size(2, 2)
#define SIZE_OF_FLAK														Size(2, 2)
#define SIZE_OF_RADAR													Size(2, 2)
#define SIZE_OF_FIGHTER_PLANE								Size(2, 2)
#define SIZE_OF_BOMBING_PLANE								Size(2, 2)
#define SIZE_OF_EARLY_WARNING_PLANE				Size(2, 2)
#define SIZE_OF_JAMMING_PLANE								Size(2, 2)
#define SIZE_OF_TYPE_8													Size(2, 2)
#define SIZE_OF_TYPE_9													Size(2, 2)
#define SIZE_OF_TYPE_10												Size(2, 2)
#define SIZE_OF_TYPE_11												Size(2, 2)
#define SIZE_OF_TYPE_AAM											Size(2, 2)


// 武器类型
enum ENUM_WEAPON_TYPE {
	WP_TYPE_NONE = 0,
	// 以下为建筑类型武器 不能移动
	WP_TYPE_ANTI_AIRCRAFT_MISSILE,
	WP_TYPE_FLAK, // 高射炮
	WP_TYPE_RADAR,
	// 以下为飞机类型武器 可以移动
	WP_TYPE_FIGHTER_PLANE,
	WP_TYPE_BOMBING_PLANE,
	WP_TYPE_EARLY_WARNING_PLANE,
	WP_TYPE_JAMMING_PLANE,
	WP_TYPE_8,
	WP_TYPE_9,
	WP_TYPE_10,
	WP_TYPE_11,
	// 以下为机载类型武器 可以移动 不能布设
	WP_TYPE_AAM,
	WP_TYPE_END
};

// 武器移动状态
typedef enum ENUM_WEAPON_STATUS {
	WP_STATUS_NONE,
	WP_STATUS_STOP,
	WP_STATUS_MOVING,
	WP_STATUS_ATTACKING,
	WP_STATUS_DESTROIED
};

// 武器移动方向
typedef enum ENUM_MOVE_DIRECTION {
	ENUM_MOVE_DIRECTION_NONE = -1,
	ENUM_MOVE_DIRECTION_0 = 0,
	ENUM_MOVE_DIRECTION_45 = 45,
	ENUM_MOVE_DIRECTION_90 = 90,
	ENUM_MOVE_DIRECTION_135 = 135,
	ENUM_MOVE_DIRECTION_180 = 180,
	ENUM_MOVE_DIRECTION_225 = 225,
	ENUM_MOVE_DIRECTION_270 = 270,
	ENUM_MOVE_DIRECTION_315 = 315,
};

// 所属军队
typedef enum ENUM_TROOPS {
	TROOPS_NONE,
	TROOPS_BLUE,
	TROOPS_RED
};

// 武器属性
typedef struct _S_PROPERTY_WP
{
	ENUM_WEAPON_TYPE WP_TYPE;
	int LEVEL;
	float SPEED;
	int RANGE_DEC;
	int DP;
	int HP;
	int RANGE_FIRE;
} S_PROPERTY_WP;

// 敌我识别
// identification friend or foe
typedef enum ENUM_IFF {
	IFF_NONE,
	IFF_FRIEND,
	IFF_FOE
};

// 移动函数返回结果
typedef enum ENUM_STATUS_MOVE {
	// 移动操作未进行 即尚未调用 Move 函数
	STATUS_MOVE_WAITING = 0,
	// 移动操作进行中 即正在调用 Move 函数
	STATUS_MOVE_PROCESSING,
	// 移动操作完成 即已经调用过 Move 函数
	STATUS_MOVE_COMPLETE
};

// 装载服务器发送武器数据的结构体
typedef struct _S_WEAPON
{
	// 所属军队
	ENUM_TROOPS TROOP_IN;
	// 武器型号
	S_PROPERTY_WP PROPERTY_WP;
	// 武器在战场态势仿真地图中的大小
	Size SIZE_IN_SIMULATION_MAP;
	// 武器位置
	Vec2 POSITION_IN_SIMULATION_MAP;
	// 所处战场
	CBattleField* BATTLE_FIELD;
	// 每次刷新计算时的武器移动状态
	ENUM_STATUS_MOVE MOVE_STATUS;
	// 武器在战场中的标签序号
	int WEAPON_TAG;
} S_WEAPON;