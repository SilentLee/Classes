#pragma once
#include "LibBattlefieldWeaponOppoInclude.h"

class BFW_OPPO_FighterPlane : public BFW_OPPO_BasicClass
{
public:
	static BFW_OPPO_FighterPlane* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_OPPO_FighterPlane* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_OPPO_FighterPlane* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_OPPO_FighterPlane* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// µ÷¶Èº¯Êý
	//virtual void update(float dt);
};