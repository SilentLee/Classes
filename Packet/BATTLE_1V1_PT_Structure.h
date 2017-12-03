#pragma once
#include "DataType.h"

typedef struct _S_PT_BATTLE_1V1_SEARCH_ROOM
{
} S_PT_BATTLE_1V1_SEARCH_ROOM;

typedef struct _S_PT_BATTLE_1V1_SEARCH_ROOM_SUCC_U
{
	DWORD_PTR ROOM_ID;
	INT ROOM_STATUS;
	INT CURRENT_USER_COUNT;
} S_PT_BATTLE_1V1_SEARCH_ROOM_SUCC_U;

typedef struct _S_PT_BATTLE_1V1_SEARCH_ROOM_FAIL_U
{
	DWORD ERROR_CODE;
} S_PT_BATTLE_1V1_SEARCH_ROOM_FAIL_U;

typedef struct _S_PT_BATTLE_1V1_START_GAME_M
{
	INT64 START_TIME;
	INT ROOM_STATUS;
} S_PT_BATTLE_1V1_START_GAME_M;

typedef struct _S_PT_BATTLE_1V1_ARRANGE_CARD
{
	INT CARD_TYPE;
	INT COORDINATE_X;
	INT COORDINATE_Y;
	FLOAT POS_X;
	FLOAT POS_Y;
	INT SPEED;
} S_PT_BATTLE_1V1_ARRANGE_CARD;

typedef struct _S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U
{
	INT CARD_TYPE;
	INT COORDINATE_X;
	INT COORDINATE_Y;
	FLOAT POS_X;
	FLOAT POS_Y;
	INT SPEED;
} S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U;

typedef struct _S_PT_BATTLE_1V1_ARRANGE_CARD_FAIL_U
{
	DWORD ERROR_CODE;
} S_PT_BATTLE_1V1_ARRANGE_CARD_FAIL_U;

