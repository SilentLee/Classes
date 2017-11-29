#pragma once
#include "LibBattlefieldWeaponInclude.h"

class BFW_AntiAirCraftMissile : public BFW_BasicClass
{
public:
	static BFW_AntiAirCraftMissile* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_AntiAirCraftMissile* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_AntiAirCraftMissile* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_AntiAirCraftMissile* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// µ÷¶Èº¯Êý
	//virtual void update(float dt);
};