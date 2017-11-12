#include <stdio.h>
#include "CBackground.h"

CBackground* CBackground::createBackground(std::string fileName)
{
	CBackground* ret = new CBackground();
	if (ret && ret->initWithFile(fileName.c_str()))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CBackground::initWithFile(const std::string& filename)
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