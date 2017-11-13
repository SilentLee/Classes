#pragma once
#include "ApiGraphicLib.h"
#include "ImageUrlLoader.h"

class FrogOfWar : public CSprite
{
public:
	static FrogOfWar* createFrogOfWarWithAbsolutePos(std::string fileName, int posX, int posY);
	static FrogOfWar* createFrogOfWarWithRelativePos(std::string fileName, float posX, float posY); // 当前使用
	static FrogOfWar* createFrogOfWarWithRealAbsolutePos(std::string fileName, int posX, int posY);
	static FrogOfWar* createFrogOfWarWithPosInSquare(std::string fileName, int posX, int posY);

	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithPosInSquare(const std::string& filename, int posX, int posY);

	// 初始化物理引擎
	void FrogOfWar::initPhysicsBody();
};