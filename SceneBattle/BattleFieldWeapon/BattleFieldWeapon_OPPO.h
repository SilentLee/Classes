#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// BattleFieldWeapon ����
// Coordinate Ϊ ս��̬�Ʒ����ͼ����
// Position Ϊ ս��̬����ʾ��ͼ����
// Coordinate ���� Position �ĸı��ˢ��

class BattleFieldWeapon_OPPO : public Sprite
{
private:
	// ��������
	PROPERTY_WP mPropertyWp;
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size mWeaponSize;

protected:

// ���ɺ���
public:
	// ʹ�ñ��ز�������
	static BattleFieldWeapon_OPPO* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�÷�������������
	static BattleFieldWeapon_OPPO* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

// ��ʼ������
public:
	// ʹ�ñ��ز�������
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�÷�������������
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ��ʼ��������ս��̬�Ʒ����ͼ�еĴ�С
	void initWeaponSize();

// ���º���
public:
	virtual void update(float dt);

public:
	// ��ȡս��̬�Ʒ����ͼ����
	Vec2 GetCoordinate();

// ��ȡ����
public:
	// ��������
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size GetWeaponSize();
};