#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;

// 功能与 cocos 中提供的 Layer 相同
class CG_Layer : public Layer, public CG_ResolutionAdapter
{
public:
	static CG_Layer* create();
	bool init();
};