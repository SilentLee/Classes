#pragma once
#include "Stream.h"
#include "BATTLE_PT_Structure.h"

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.ROOM_TYPE);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM_SUCC_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD_PTR(parameter.ROOM_ID);
	Stream->WriteInt32(parameter.ROOM_TYPE);
	Stream->WriteInt32(parameter.ROOM_STATUS);
	Stream->WriteInt32(parameter.CURRENT_USER_COUNT);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_FAIL_U(BYTE *buffer, S_PT_BATTLE_SEARCH_ROOM_FAIL_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(parameter.ERROR_CODE);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_START_GAME_M(BYTE *buffer, S_PT_BATTLE_START_GAME_M &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.ROOM_TYPE);
	Stream->WriteInt64(parameter.START_TIME);
	Stream->WriteInt32(parameter.ROOM_STATUS);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON(BYTE *buffer, S_PT_BATTLE_ARRANGE_WEAPON &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.WEAPON_TYPE);
	Stream->WriteInt32(parameter.COORDINATE_X);
	Stream->WriteInt32(parameter.COORDINATE_Y);
	Stream->WriteFloat(parameter.POS_X);
	Stream->WriteFloat(parameter.POS_Y);
	Stream->WriteInt32(parameter.SPEED);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_SUCC_U(BYTE *buffer, S_PT_BATTLE_ARRANGE_WEAPON_SUCC_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.WEAPON_TYPE);
	Stream->WriteInt32(parameter.COORDINATE_X);
	Stream->WriteInt32(parameter.COORDINATE_Y);
	Stream->WriteFloat(parameter.POS_X);
	Stream->WriteFloat(parameter.POS_Y);
	Stream->WriteInt32(parameter.SPEED);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_FAIL_U(BYTE *buffer, S_PT_BATTLE_ARRANGE_WEAPON_FAIL_U &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(parameter.ERROR_CODE);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_UPDATE_SITUATION_M(BYTE *buffer, S_PT_BATTLE_UPDATE_SITUATION_M &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.REMAINING_GAME_TIME);
	Stream->WriteInt32(parameter.DATA_LENGTH);
	Stream->WriteBytes(parameter.DATA, 4000);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM(BYTE *buffer, INT room_type)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(room_type);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE *buffer, DWORD_PTR room_id, INT room_type, INT room_status, INT current_user_count)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD_PTR(room_id);
	Stream->WriteInt32(room_type);
	Stream->WriteInt32(room_status);
	Stream->WriteInt32(current_user_count);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_FAIL_U(BYTE *buffer, DWORD error_code)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(error_code);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_START_GAME_M(BYTE *buffer, INT room_type, INT64 start_time, INT room_status)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(room_type);
	Stream->WriteInt64(start_time);
	Stream->WriteInt32(room_status);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON(BYTE *buffer, INT weapon_type, INT coordinate_x, INT coordinate_y, FLOAT pos_x, FLOAT pos_y, INT speed)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(weapon_type);
	Stream->WriteInt32(coordinate_x);
	Stream->WriteInt32(coordinate_y);
	Stream->WriteFloat(pos_x);
	Stream->WriteFloat(pos_y);
	Stream->WriteInt32(speed);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_SUCC_U(BYTE *buffer, INT weapon_type, INT coordinate_x, INT coordinate_y, FLOAT pos_x, FLOAT pos_y, INT speed)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(weapon_type);
	Stream->WriteInt32(coordinate_x);
	Stream->WriteInt32(coordinate_y);
	Stream->WriteFloat(pos_x);
	Stream->WriteFloat(pos_y);
	Stream->WriteInt32(speed);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_FAIL_U(BYTE *buffer, DWORD error_code)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(error_code);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_UPDATE_SITUATION_M(BYTE *buffer, INT remaining_game_time, INT data_length, BYTE *data)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(remaining_game_time);
	Stream->WriteInt32(data_length);
	Stream->WriteBytes(data, 4000);

	return Stream->GetLength();
}

