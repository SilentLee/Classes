#pragma once
#include "LayerEx.h"
#include "RoomInstance.h"
#include "NetworkInstance.h"

class LayerSelectButton : public LayerEx
{
public:
	static LayerSelectButton * create();
	bool init();

// 按钮回调函数
public:
	void BtnStartCallback(ROOM_TYPE roomType);

	// 更新函数
public:
	void UpdateToBattle(float dt);
};