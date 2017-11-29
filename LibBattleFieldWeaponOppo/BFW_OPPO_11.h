#pragma once
#pragma once
#include "LibBattlefieldWeaponOppoInclude.h"

class BFW_OPPO_11 : public BFW_OPPO_BasicClass
{
public:
	static BFW_OPPO_11* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_OPPO_11* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_OPPO_11* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_OPPO_11* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// ���Ⱥ���
	//virtual void update(float dt);
};