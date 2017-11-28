#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;

// 位置自适应调节因子
static float PosAdjustFactor;
// 尺寸自适应调节因子
static float SizeAdjustFactor;
// 屏幕可视尺寸
static Size VisibleSize;

class CG_ResolutionAdapter
{
protected:
	Node* node;

public:
	CG_ResolutionAdapter();
	~CG_ResolutionAdapter();

public:
	float getPosAdjustFactor();
	float getSizeAdjustFactor();

public:
	static void init();

	// 尺寸转换
	void sizeAdp();

	// 设置绝对适配坐标
	void setAdpPosWithAbsoluteValue(int posX, int posY);
	void setAdpPosXWithAbsoluteValue(int posX);
	void setAdpPosYWithAbsoluteValue(int posY);

	// 设置相对适配坐标
	void setAdpPosWithRelativeValue(float posX, float posY);
	void setAdpPosXWithRelativeValue(float posX);
	void setAdpPosYWithRelativeValue(float posY);

	// 设置绝对设备坐标
	void setRealPosWithAbsoluteValue(int posX, int posY);
	void setRealPosXWithAbsoluteValue(int posX);
	void setRealPosYWithAbsoluteValue(int posY);

	// 设置方格坐标
	virtual void setPosInSquare(float posX, float posY);
	virtual void setPosXInSquare(float posX);
	virtual void setPosYInSquare(float posY);

	// 设置相对适配尺寸
	void setSizeAdp(float scale);

	// 获取绝对适配坐标
	Vec2 getAdpPosWithAbsoluteValue();
	float getAdpPosXWithAbsoluteValue();
	float getAdpPosYWithAbsoluteValue();

	// 获取相对适配坐标
	Vec2 getAdpPosWithRelativeValue();
	float getAdpPosXWithRelativeValue();
	float getAdpPosYWithRelativeValue();

	// 获取绝对设备坐标
	Vec2 getRealPosWithAbsoluteValue();
	float getRealPosXWithAbsoluteValue();
	float getRealPosYWithAbsoluteValue();

	// 获取方格坐标
	virtual Vec2 getPosInSquare();
	virtual int getPosXInSquare();
	virtual int getPosYInSquare();
};