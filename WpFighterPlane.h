#pragma once
#include "ApiGraphicLib.h"
#include "ImageUrlLoader.h"

class WpFighterPlane : public CSprite
{
public:
	static WpFighterPlane* createWpFighterPlaneWithPosInSquare(std::string fileName, int posX, int posY);
	static WpFighterPlane* createWpFighterPlaneWithAbsolutePos(std::string fileName, int posX, int posY);
	static WpFighterPlane* createWpFighterPlaneWithRelativePos(std::string fileName, float posX, float posY);
	static WpFighterPlane* createWpFighterPlaneWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	// µ÷¶Èº¯Êý
	virtual void update(float dt);
};