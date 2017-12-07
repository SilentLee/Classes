#pragma once
#include "DataType.h"

typedef struct _S_PT_BATTLE_SEARCH_ROOM
{
	INT ROOM_TYPE;
} S_PT_BATTLE_SEARCH_ROOM;

typedef struct _S_PT_BATTLE_SEARCH_ROOM_SUCC_U
{
	DWORD_PTR ROOM_ID;
	INT ROOM_TYPE;
	INT ROOM_STATUS;
	INT CURRENT_USER_COUNT;
} S_PT_BATTLE_SEARCH_ROOM_SUCC_U;

typedef struct _S_PT_BATTLE_SEARCH_ROOM_FAIL_U
{
	DWORD ERROR_CODE;
} S_PT_BATTLE_SEARCH_ROOM_FAIL_U;

typedef struct _S_PT_BATTLE_START_GAME_M
{
	INT ROOM_TYPE;
	INT64 START_TIME;
	INT ROOM_STATUS;
} S_PT_BATTLE_START_GAME_M;

typedef struct _S_PT_BATTLE_ARRANGE_WEAPON
{
	INT WEAPON_TYPE;
	INT COORDINATE_X;
	INT COORDINATE_Y;
	FLOAT POS_X;
	FLOAT POS_Y;
	INT SPEED;
} S_PT_BATTLE_ARRANGE_WEAPON;

typedef struct _S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U
{
	INT WEAPON_TYPE;
	INT COORDINATE_X;
	INT COORDINATE_Y;
	FLOAT POS_X;
	FLOAT POS_Y;
	INT SPEED;
} S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U;

typedef struct _S_PT_BATTLE_ARRANGE_WEAPON_FAIL_U
{
	DWORD ERROR_CODE;
} S_PT_BATTLE_ARRANGE_WEAPON_FAIL_U;

typedef struct _S_PT_BATTLE_UPDATE_SITUATION_M
{
	INT REMAINING_GAME_TIME;
	INT BLUE_TROOPS_DATA_LENGTH;
	INT RED_TROOPS_DATA_LENGTH;
	INT BLUE_TROOPS_ACTION_DATA_LENGTH;
	INT RED_TROOPS_ACTION_DATA_LENGTH;
	BYTE DATA[4000];
} S_PT_BATTLE_UPDATE_SITUATION_M;

