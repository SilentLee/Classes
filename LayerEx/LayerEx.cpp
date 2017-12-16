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

	// ��ȡ��Ļ���ӷֱ���
	mVisibleSize = Director::getInstance()->getVisibleSize();
	// ������������
	mSizeAdjustFactor = mVisibleSize.width / designResolutionSize.width;

	// transTouch ������ê��Ϊ ANCHOR_BOTTOM_LEFT ת������׼ȷ��
	this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);

	this->setScale(mSizeAdjustFactor);

	return true;
}

// ê��Ϊ ANCHOR_BOTTOM_LEFT
// ���ݵ�ǰ Layer ������ ת�� touch ����
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