#pragma once

#include "LibBattlefieldWeaponInclude.h"

class BFW_AAM : public BFW_BasicClass
{
private:
	Vec2 mFirePosition;
public:
	static BFW_AAM* createWithPosInSquare(std::string fileName, int posX, int posY);
	static BFW_AAM* createWithAbsolutePos(std::string fileName, int posX, int posY);
	static BFW_AAM* createWithRelativePos(std::string fileName, float posX, float posY);
	static BFW_AAM* createWithRealAbsolutePos(std::string fileName, int posX, int posY);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY);
	bool initWithRelativePos(const std::string& filename, float posX, float posY);
	bool initWithRealAbsolutePos(const std::string& filename, int posX, int posY);

	void initPhysicsBody();

	//// 调度函数
	//virtual void update(float dt);

public:
	// 获取发射位置
	Vec2 getFirePosition();
	int getFirePositionX();
	int getFirePositionY();

};