#pragma once
#include "LayerEx.h"
#include "RoomInstance.h"
#include "NetworkInstance.h"

class LayerSelectButton : public LayerEx
{
public:
	static LayerSelectButton * create();
	bool init();

// ��ť�ص�����
public:
	void BtnStartCallback(ROOM_TYPE roomType);

	// ���º���
public:
	void UpdateToBattle(float dt);
};