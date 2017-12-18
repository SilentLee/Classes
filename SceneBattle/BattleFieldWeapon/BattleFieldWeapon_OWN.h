#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h" 

// BattleFieldWeapon ����
// Coordinate Ϊ ս��̬�Ʒ����ͼ����
// Position Ϊ ս��̬����ʾ��ͼ����
// Coordinate ���� Position �ĸı��ˢ��

class BattleFieldWeapon_OWN : public Sprite
{
	// ��������
private:
	PROPERTY_WP mPropertyWp;

	// ս������
protected:
	Vec2 mCoordinate;

	// ���ɺ���
public:
	// ʹ��ս��̬�Ʒ����ͼ����Ĵ�������
	static BattleFieldWeapon_OWN* createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	// ʹ��ս��̬����ʾ��ͼλ�õĴ�������
	static BattleFieldWeapon_OWN* createWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// ��ʼ������
public:
	bool initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	bool initWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// ���º���
public:
	virtual void update(float dt);

public:
	// ��ȡս������
	void SetCoordinate(Vec2 coordinate);
	Vec2 GetCoordinate() { return mCoordinate; };

	// �������Դ�ȡ����
public:
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
};