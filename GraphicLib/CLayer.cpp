#include "CLayer.h"

CLayer* CLayer::createLayer()
{
	CLayer* ret = new CLayer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CLayer::init()
{
	return Layer::init();
}