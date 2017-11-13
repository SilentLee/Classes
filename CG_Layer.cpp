#include "CG_Layer.h"

CG_Layer* CG_Layer::create()
{
	CG_Layer* ret = new CG_Layer();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CG_Layer::init()
{
	return Layer::init();
}