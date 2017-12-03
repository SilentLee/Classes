#pragma once
#include "Stream.h"
#include "BATTLE_PT_Structure.h"

inline VOID READ_PT_BATTLE_SEARCH_ROOM(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadInt32(&parameter.ROOM_TYPE);
}

inline VOID READ_PT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM_SUCC_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadDWORD_PTR(&parameter.ROOM_ID);
	Stream->ReadInt32(&parameter.ROOM_TYPE);
	Stream->ReadInt32(&parameter.ROOM_STATUS);
	Stream->ReadInt32(&parameter.CURRENT_USER_COUNT);
}

inline VOID READ_PT_BATTLE_SEARCH_ROOM_FAIL_U(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM_FAIL_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadDWORD(&parameter.ERROR_CODE);
}

inline VOID READ_PT_BATTLE_START_GAME_M(BYTE *buffer, S_PT_BATTLE_START_GAME_M &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadInt32(&parameter.ROOM_TYPE);
	Stream->ReadInt64(&parameter.START_TIME);
	Stream->ReadInt32(&parameter.ROOM_STATUS);
}

inline VOID READ_PT_BATTLE_ARRANGE_CARD(BYTE *buffer, S_PT_BATTLE_ARRANGE_CARD &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadInt32(&parameter.CARD_TYPE);
	Stream->ReadInt32(&parameter.COORDINATE_X);
	Stream->ReadInt32(&parameter.COORDINATE_Y);
	Stream->ReadFloat(&parameter.POS_X);
	Stream->ReadFloat(&parameter.POS_Y);
	Stream->ReadInt32(&parameter.SPEED);
}

inline VOID READ_PT_BATTLE_ARRANGE_CARD_SUCC_U(BYTE *buffer, S_PT_BATTLE_ARRANGE_CARD_SUCC_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadInt32(&parameter.CARD_TYPE);
	Stream->ReadInt32(&parameter.COORDINATE_X);
	Stream->ReadInt32(&parameter.COORDINATE_Y);
	Stream->ReadFloat(&parameter.POS_X);
	Stream->ReadFloat(&parameter.POS_Y);
	Stream->ReadInt32(&parameter.SPEED);
}

inline VOID READ_PT_BATTLE_ARRANGE_CARD_FAIL_U(BYTE *buffer, S_PT_BATTLE_ARRANGE_CARD_FAIL_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->ReadDWORD(&parameter.ERROR_CODE);
}
