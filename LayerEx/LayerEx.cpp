#include "LayerEx.h"

USING_NS_CC;

LayerEx* LayerEx::create()
{
	LayerEx* ret = new LayerEx();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerEx::init()
{
	Layer::init();

	// 获取屏幕可视分辨率
	mVisibleSize = Director::getInstance()->getVisibleSize();
	// 计算缩放因子
	mSizeAdjustFactor = mVisibleSize.width / designResolutionSize.width;

	// transTouch 函数在锚点为 ANCHOR_BOTTOM_LEFT 转换才是准确的
	this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

	this->setScale(mSizeAdjustFactor);

	return true;
}

// 锚点为 ANCHOR_BOTTOM_LEFT
// 根据当前 Layer 缩放率 转换 touch 坐标
Vec2 LayerEx::transTouch(Touch* touch)
{
	if (this->getAnchorPoint() == Vec2::ANCHOR_BOTTOM_LEFT) {
		float ScaleFactor = this->getScale();
		float deltaX = this->getPositionX();
		float deltaY = this->getPositionY();

		float x = (touch->getLocation().x - deltaX) / ScaleFactor;
		float y = (touch->getLocation().y - deltaY) / ScaleFactor;

		return Vec2(x, y);
	}
	return Vec2(0, 0);
}