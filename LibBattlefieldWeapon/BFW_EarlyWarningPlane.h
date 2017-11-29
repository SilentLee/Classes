#pragma once
#include "LibBattlefieldWeaponInclude.h"

class BFW_EarlyWarningPlane : public BFW_BasicClass
{
public:
	static BFW_EarlyWarningPlane* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_EarlyWarningPlane* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_EarlyWarningPlane* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_EarlyWarningPlane* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// µ÷¶Èº¯Êý
	//virtual void update(float dt);
};