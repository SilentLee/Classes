#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include"LayerBattleFieldDB.h"

class BattleFieldWeapon_OWN : public CG_Sprite
{
	// ��������
private:
	PROPERTY_WP mPropertyWp;
protected:
	Vec2 mCoordinateInBF;

	// ���º���
public:
	virtual void update(float dt);

public:
	static BattleFieldWeapon_OWN* createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	static BattleFieldWeapon_OWN* createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

	bool initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);
	bool initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType);

	// ��ʼ���������Բ���
	void initPhysicsBody();

public:
	// ��ȡս������
	Vec2 getCoordinateInBF();
	float getCoordinateXInBF();
	float getCoordinateYInBF();

	// ���÷�������
	void setPosInSquare(float posX, float posY);
	void setPosXInSquare(float posX);
	void setPosYInSquare(float posY);

	// �������Դ�ȡ����
public:
	void setPropertyWp(PROPERTY_WP propertyWp);
	PROPERTY_WP getPropertyWp();
};