#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;

// λ������Ӧ��������
static float PosAdjustFactor;
// �ߴ�����Ӧ��������
static float SizeAdjustFactor;
// ��Ļ���ӳߴ�
static cocos2d::Size VisibleSize;

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

	// �ߴ�ת��
	void sizeAdp();

	// ���þ�����������
	void setAdpPosWithAbsoluteValue(int posX, int posY);
	void setAdpPosXWithAbsoluteValue(int posX);
	void setAdpPosYWithAbsoluteValue(int posY);

	// ���������������
	void setAdpPosWithRelativeValue(float posX, float posY);
	void setAdpPosXWithRelativeValue(float posX);
	void setAdpPosYWithRelativeValue(float posY);

	// ���þ����豸����
	void setRealPosWithAbsoluteValue(int posX, int posY);
	void setRealPosXWithAbsoluteValue(int posX);
	void setRealPosYWithAbsoluteValue(int posY);

	// ���÷�������
	virtual void setPosInSquare(float posX, float posY);
	virtual void setPosXInSquare(float posX);
	virtual void setPosYInSquare(float posY);

	// �����������ߴ�
	void setSizeAdp(float scale);

	// ��ȡ������������
	Vec2 getAdpPosWithAbsoluteValue();
	float getAdpPosXWithAbsoluteValue();
	float getAdpPosYWithAbsoluteValue();

	// ��ȡ�����������
	Vec2 getAdpPosWithRelativeValue();
	float getAdpPosXWithRelativeValue();
	float getAdpPosYWithRelativeValue();

	// ��ȡ�����豸����
	Vec2 getRealPosWithAbsoluteValue();
	float getRealPosXWithAbsoluteValue();
	float getRealPosYWithAbsoluteValue();

	// ��ȡ��������
	virtual Vec2 getPosInSquare();
	virtual int getPosXInSquare();
	virtual int getPosYInSquare();
};