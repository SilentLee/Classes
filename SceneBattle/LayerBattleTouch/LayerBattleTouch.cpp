#include "LayerBattleTouch.h"

LayerBattleTouch* LayerBattleTouch::create()
{
	LayerBattleTouch* ret = new LayerBattleTouch();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleTouch::init()
{
	LayerEx::init();
	initTouchMode(this);
	
	return true;
};

// 设置触控模式
void LayerBattleTouch::initTouchMode(LayerBattleTouch* layerTouchDB)
{
	layerTouchDB->setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ALL_AT_ONCE);
}



