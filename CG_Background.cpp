#include <stdio.h>
#include "CG_Background.h"

CG_Background* CG_Background::create(std::string fileName)
{
	CG_Background* ret = new CG_Background();
	if (ret && ret->initWithFile(fileName.c_str()))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CG_Background::initWithFile(const std::string& filename)
{
	// 适配器初始化
	node = this;

	// 父类初始化
	Sprite::initWithFile(filename);
	
	// 设置锚点
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// 调节尺寸
	this->sizeAdp();
	// 设置坐标
	this->setAdpPosWithRelativeValue(0.5, 0.5);

	return true;
}