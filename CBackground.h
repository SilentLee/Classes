#pragma once

#include "GraphicLibIncludes.h"

USING_NS_CC;
// test

class CBackground : public Sprite, public ResolutionAdapter
{
public:
	static CBackground* createBackground(std::string fileName);
	bool initWithFile(const std::string& filename);
};
