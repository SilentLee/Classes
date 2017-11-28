#pragma once
#include "LibBattlefieldWeaponOppoInclude.h"

class BFW_OPPO_Flak : public BFW_OPPO_BasicClass
{
public:
	static BFW_OPPO_Flak* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_OPPO_Flak* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_OPPO_Flak* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_OPPO_Flak* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// µ÷¶Èº¯Êý
	//virtual void update(float dt);
};