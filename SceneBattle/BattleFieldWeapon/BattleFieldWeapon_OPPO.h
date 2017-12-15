#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

class BattleFieldWeapon_OPPO : public CG_Sprite
{
// ��������
private:
	PROPERTY_WP mPropertyWp;

	// ս������
protected:
	Vec2 mCoordinate;

// ���ɺ���
public:
	static BattleFieldWeapon_OPPO* createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	static BattleFieldWeapon_OPPO* createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

// ��ʼ������
public:
	bool initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

	// ��ʼ���������Բ���
	void initPhysicsBody();

// ���º���
public:
	virtual void update(float dt);

public:
	// ��ȡս������
	Vec2 getCoordinate();
	float getCoordinateX();
	float getCoordinateY();

	// ���÷�������
	void setPosInSquare(float posX, float posY);
	void setPosXInSquare(float posX);
	void setPosYInSquare(float posY);

	// �������Դ�ȡ����
public:
	void setPropertyWp(PROPERTY_WP propertyWp);
	PROPERTY_WP getPropertyWp();
};