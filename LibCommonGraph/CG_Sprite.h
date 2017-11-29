#pragma once

#include "LibCommonGraphIncludes.h"

USING_NS_CC;

class CG_Sprite : public Sprite, public CG_ResolutionAdapter
{
public:
	static CG_Sprite* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static CG_Sprite* createWithRelativePos(std::string fileName, float posX, float posY);
	static CG_Sprite* createWithRealAbsolutePos(std::string fileName, int posX, int posY);
	static CG_Sprite* createWithPosInSquare(std::string fileName, int posX, int posY);

	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
};