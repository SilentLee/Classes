#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

class BFW_FighterPlane : public CG_Sprite
{
public:
	static BFW_FighterPlane* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_FighterPlane* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_FighterPlane* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_FighterPlane* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	// µ÷¶Èº¯Êý
	virtual void update(float dt);
};