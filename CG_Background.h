#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;
// test

class CG_Background : public Sprite, public CG_ResolutionAdapter
{
public:
	static CG_Background* create(std::string fileName);
	bool initWithFile(const std::string& filename);
};
