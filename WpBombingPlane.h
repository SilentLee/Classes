#pragma once
#include "ApiGraphicLib.h"
#include "ImageUrlLoader.h"

class WpBombingPlane : public CSprite
{
public:
	static WpBombingPlane* createWpBombingPlaneWithPosInSquare(std::string fileName, int posX, int posY);
	static WpBombingPlane* createWpBombingPlaneWithAbsolutePos(std::string fileName, int posX, int posY);
	static WpBombingPlane* createWpBombingPlaneWithRelativePos(std::string fileName, float posX, float posY);
	static WpBombingPlane* createWpBombingPlaneWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	// µ÷¶Èº¯Êý
	virtual void update(float dt);
};