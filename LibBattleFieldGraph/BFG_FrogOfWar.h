#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

class BFG_FrogOfWar : public CG_Sprite
{
public:
	static BFG_FrogOfWar* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFG_FrogOfWar* createWithRelativePos(std::string fileName, float posX, float posY); // 当前使用
	static BFG_FrogOfWar* createWithRealAbsolutePos(std::string fileName, int posX, int posY);
	static BFG_FrogOfWar* createWithPosInSquare(std::string fileName, int posX, int posY);

	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
};