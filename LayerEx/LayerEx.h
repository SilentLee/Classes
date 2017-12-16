#pragma once
#include "cocos2d.h"
#include "ParamResolutionConfig.h"

USING_NS_CC;

class LayerEx : public Layer
{
private:
	// 尺寸自适应调节因子
	float mSizeAdjustFactor;
	// 屏幕可视尺寸
	Size mVisibleSize;

public:
	static LayerEx * create();
	bool init();
	Vec2 transTouch(Touch* touch);

// 存取函数
public:
	float GetSizeAdjustFactor() { return mSizeAdjustFactor; };
	Size GetVisibleSize() { return mVisibleSize; };
};