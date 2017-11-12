#pragma once
#include "..\Classes\GraphicLib\ApiGraphicLib.h"
#include "..\Classes\Utils\ImageUrlLoader.h"
// ≤‚ ‘GitHub
class FrogOfWar : public CSprite
{
public:
	static FrogOfWar* createFrogOfWarWithAbsolutePos(std::string fileName, int posX, int posY);
	static FrogOfWar* createFrogOfWarWithRelativePos(std::string fileName, float posX, float posY);
	static FrogOfWar* createFrogOfWarWithRealAbsolutePos(std::string fileName, int posX, int posY);
	static FrogOfWar* createFrogOfWarWithPosInSquare(std::string fileName, int posX, int posY);

	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
};