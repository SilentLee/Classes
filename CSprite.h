#pragma once

#include "GraphicLibIncludes.h"

USING_NS_CC;

class CSprite : public Sprite, public ResolutionAdapter
{
public:
	static CSprite* createSpriteWithAbsolutePos(std::string fileName, int posX, int posY);
	static CSprite* createSpriteWithRelativePos(std::string fileName, float posX, float posY);
	static CSprite* createSpriteWithRealAbsolutePos(std::string fileName, int posX, int posY);
	static CSprite* createSpriteWithPosInSquare(std::string fileName, int posX, int posY);

	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
};