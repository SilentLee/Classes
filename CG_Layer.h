#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;

// ������ cocos ���ṩ�� Layer ��ͬ
class CG_Layer : public Layer, public CG_ResolutionAdapter
{
public:
	static CG_Layer* create();
	bool init();
};