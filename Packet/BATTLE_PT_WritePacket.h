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
	Stream->WriteInt32(parameter.SIDE_IN_GAME);

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
	Stream->WriteInt32(parameter.TROOPS_IN);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_SUCC_M(BYTE *buffer, S_PT_BATTLE_ARRANGE_WEAPON_SUCC_M &parameter)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(parameter.WEAPON_TYPE);
	Stream->WriteInt32(parameter.WEAPON_TAG);
	Stream->WriteInt32(parameter.COORDINATE_X);
	Stream->WriteInt32(parameter.COORDINATE_Y);
	Stream->WriteFloat(parameter.POS_X);
	Stream->WriteFloat(parameter.POS_Y);
	Stream->WriteInt32(parameter.SPEED);
	Stream->WriteInt32(parameter.TROOPS_IN);

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
	Stream->WriteInt32(parameter.BLUE_TROOPS_DATA_LENGTH);
	Stream->WriteInt32(parameter.RED_TROOPS_DATA_LENGTH);
	Stream->WriteInt32(parameter.BLUE_TROOPS_ACTION_DATA_LENGTH);
	Stream->WriteInt32(parameter.RED_TROOPS_ACTION_DATA_LENGTH);
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

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE *buffer, DWORD_PTR room_id, INT room_type, INT room_status, INT current_user_count, INT side_in_game)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD_PTR(room_id);
	Stream->WriteInt32(room_type);
	Stream->WriteInt32(room_status);
	Stream->WriteInt32(current_user_count);
	Stream->WriteInt32(side_in_game);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_SEARCH_ROOM_FAIL_U(BYTE *buffer, DWORD error_code)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(error_code);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_START_GAME_M(BYTE *buffer, INT room_status)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(room_status);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON(BYTE *buffer, INT weapon_type, INT coordinate_x, INT coordinate_y, FLOAT pos_x, FLOAT pos_y, INT speed, INT troops_in)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(weapon_type);
	Stream->WriteInt32(coordinate_x);
	Stream->WriteInt32(coordinate_y);
	Stream->WriteFloat(pos_x);
	Stream->WriteFloat(pos_y);
	Stream->WriteInt32(speed);
	Stream->WriteInt32(troops_in);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_SUCC_M(BYTE *buffer, INT weapon_type, INT weapon_tag, INT coordinate_x, INT coordinate_y, FLOAT pos_x, FLOAT pos_y, INT speed, INT troops_in)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(weapon_type);
	Stream->WriteInt32(weapon_tag);
	Stream->WriteInt32(coordinate_x);
	Stream->WriteInt32(coordinate_y);
	Stream->WriteFloat(pos_x);
	Stream->WriteFloat(pos_y);
	Stream->WriteInt32(speed);
	Stream->WriteInt32(troops_in);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_ARRANGE_WEAPON_FAIL_U(BYTE *buffer, DWORD error_code)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteDWORD(error_code);

	return Stream->GetLength();
}

inline DWORD WRITE_PT_BATTLE_UPDATE_SITUATION_M(BYTE *buffer, INT remaining_game_time, INT blue_troops_data_length, INT red_troops_data_length, INT blue_troops_action_data_length, INT red_troops_action_data_length, BYTE *data)
{
	CStreamSP Stream;
	Stream->SetBuffer(buffer);

	Stream->WriteInt32(remaining_game_time);
	Stream->WriteInt32(blue_troops_data_length);
	Stream->WriteInt32(red_troops_data_length);
	Stream->WriteInt32(blue_troops_action_data_length);
	Stream->WriteInt32(red_troops_action_data_length);
	Stream->WriteBytes(data, 4000);

	return Stream->GetLength();
}

