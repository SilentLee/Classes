#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// BattleFieldWeapon ����
// Coordinate Ϊ ս��̬�Ʒ����ͼ����
// Position Ϊ ս��̬����ʾ��ͼ����
// Coordinate ���� Position �ĸı��ˢ��

class BattleFieldWeapon_OWN : public Sprite
{
private:
	// ��������
	PROPERTY_WP mPropertyWp;
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size mSizeInSimulationMap;

// ���ɺ���
public:
	// ʹ�ñ��ز�������
	static BattleFieldWeapon_OWN* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�÷�������������
	static BattleFieldWeapon_OWN* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

// ��ʼ������
public:
	// ʹ�ñ��ز�������
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�÷�������������
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ��ʼ��������ս��̬�Ʒ����ͼ�еĴ�С
	void initSizeInSimulationMap();

// ���º���
public:
	//virtual void update(float dt);

public:
	// ��ȡս��̬�Ʒ����ͼ����
	Vec2 GetCoordinate();
// ��Ϊ����
public:
	// �ƶ�
	void Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// ̽��
	void Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// ����
	void Attack();
	// ������
	int BeAttacked();

// ��ȡ����
public:
	// ��������
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size GetSizeInSimulationMap();
};