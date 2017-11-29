#pragma once
#include "LibBattlefieldWeaponInclude.h"

class BFW_10 : public BFW_BasicClass
{
public:
	static BFW_10* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_10* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_10* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_10* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// ���Ⱥ���
	//virtual void update(float dt);
};