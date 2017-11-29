#pragma once
#include "LibBattlefieldWeaponInclude.h"

class BFW_Radar : public BFW_BasicClass
{
public:
	static BFW_Radar* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_Radar* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_Radar* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_Radar* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// ���Ⱥ���
	//virtual void update(float dt);
};