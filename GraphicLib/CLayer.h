#pragma once

#include "GraphicLibIncludes.h"

USING_NS_CC;

class CLayer : public Layer, public ResolutionAdapter
{
public:
	static CLayer* createLayer();
	bool init();
};