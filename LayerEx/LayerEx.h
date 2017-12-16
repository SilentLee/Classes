#pragma once
#include "cocos2d.h"
#include "ParamResolutionConfig.h"

USING_NS_CC;

class LayerEx : public Layer
{
private:
	// �ߴ�����Ӧ��������
	float mSizeAdjustFactor;
	// ��Ļ���ӳߴ�
	Size mVisibleSize;

public:
	static LayerEx * create();
	bool init();
	Vec2 transTouch(Touch* touch);

// ��ȡ����
public:
	float GetSizeAdjustFactor() { return mSizeAdjustFactor; };
	Size GetVisibleSize() { return mVisibleSize; };
};