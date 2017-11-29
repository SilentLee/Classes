#pragma once
#include "LibBattlefieldWeaponInclude.h"

class BFW_JammingPlane : public BFW_BasicClass
{
public:
	static BFW_JammingPlane* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_JammingPlane* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_JammingPlane* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_JammingPlane* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// µ÷¶Èº¯Êý
	//virtual void update(float dt);
};