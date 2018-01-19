#pragma once
#include "cocos2d.h"

USING_NS_CC;

extern class CBattleField;

// ����������ս��̬�Ʒ����ͼ�е�ͶӰ�ߴ�
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


// ��������
enum ENUM_WEAPON_TYPE {
	WP_TYPE_NONE = 0,
	// ����Ϊ������������ �����ƶ�
	WP_TYPE_ANTI_AIRCRAFT_MISSILE,
	WP_TYPE_FLAK, // ������
	WP_TYPE_RADAR,
	// ����Ϊ�ɻ��������� �����ƶ�
	WP_TYPE_FIGHTER_PLANE,
	WP_TYPE_BOMBING_PLANE,
	WP_TYPE_EARLY_WARNING_PLANE,
	WP_TYPE_JAMMING_PLANE,
	WP_TYPE_8,
	WP_TYPE_9,
	WP_TYPE_10,
	WP_TYPE_11,
	// ����Ϊ������������ �����ƶ� ���ܲ���
	WP_TYPE_AAM,
	WP_TYPE_END
};

// �����ƶ�״̬
typedef enum ENUM_WEAPON_STATUS {
	WP_STATUS_NONE,
	WP_STATUS_STOP,
	WP_STATUS_MOVING,
	WP_STATUS_ATTACKING,
	WP_STATUS_DESTROIED
};

// �����ƶ�����
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

// ��������
typedef enum ENUM_TROOPS {
	TROOPS_NONE,
	TROOPS_BLUE,
	TROOPS_RED
};

// ��������
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

// ����ʶ��
// identification friend or foe
typedef enum ENUM_IFF {
	IFF_NONE,
	IFF_FRIEND,
	IFF_FOE
};

// �ƶ��������ؽ��
typedef enum ENUM_STATUS_MOVE {
	// �ƶ�����δ���� ����δ���� Move ����
	STATUS_MOVE_WAITING = 0,
	// �ƶ����������� �����ڵ��� Move ����
	STATUS_MOVE_PROCESSING,
	// �ƶ�������� ���Ѿ����ù� Move ����
	STATUS_MOVE_COMPLETE
};

// װ�ط����������������ݵĽṹ��
typedef struct _S_WEAPON
{
	// ��������
	ENUM_TROOPS TROOP_IN;
	// �����ͺ�
	S_PROPERTY_WP PROPERTY_WP;
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size SIZE_IN_SIMULATION_MAP;
	// ����λ��
	Vec2 POSITION_IN_SIMULATION_MAP;
	// ����ս��
	CBattleField* BATTLE_FIELD;
	// ÿ��ˢ�¼���ʱ�������ƶ�״̬
	ENUM_STATUS_MOVE MOVE_STATUS;
	// ������ս���еı�ǩ���
	int WEAPON_TAG;
} S_WEAPON;