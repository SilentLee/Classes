#pragma once
#include <windows.h>
//
typedef enum BATTLE_1V1_PROTOCOL
{
	BATTLE_1V1_PT_VERSION	= 0x4000000,

	PT_BATTLE_1V1_SEARCH_ROOM,
	/*
	*/
	PT_BATTLE_1V1_SEARCH_ROOM_SUCC_U,
	/*
	DWORD_PTR		:		ROOM_ID
	INT							:		ROOM_STATUS
	INT							:		CURRENT_USER_COUNT
	*/
	PT_BATTLE_1V1_SEARCH_ROOM_FAIL_U,
	/*
	DWORD					:		ERROR_CODE
	*/
	PT_BATTLE_1V1_ARRANGE_CARD,
	/*
	INT							:	CARD_TYPE
	INT							:	COORDINATE_X
	INT							:	COORDINATE_Y
	FLOAT					:	POS_X
	FLOAT					:	POS_Y
	INT							:	SPEED
	*/
	PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U,
	/*
	INT							:	CARD_TYPE
	INT							:	COORDINATE_X
	INT							:	COORDINATE_Y
	FLOAT					:	POS_X
	FLOAT					:	POS_Y
	INT							:	SPEED
	*/
	PT_BATTLE_1V1_ARRANGE_CARD_FAIL_U,
	/*
	DWORD					:		ERROR_CODE
	*/

	BATTLE_1V1_PT_END
};
