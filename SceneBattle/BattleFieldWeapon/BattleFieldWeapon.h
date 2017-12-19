#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

using namespace std;

// ����ʶ��
// identification friend or foe
typedef enum ENUM_IFF {
	IFF_NONE,
	IFF_FRIEND,
	IFF_FOE
};

// BattleFieldWeapon ����
// Coordinate Ϊ ս��̬�Ʒ����ͼ����
// Position Ϊ ս��̬����ʾ��ͼ����
// Coordinate ���� Position �ĸı��ˢ��

class BattleFieldWeapon : public Sprite
{
private:
	// ��������
	PROPERTY_WP mPropertyWp;
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size mSizeInSimulationMap;
	// ����ʶ���־
	ENUM_IFF mIFF;

// ���ɺ���
public:
	// ʹ�ñ��ز�������
	static BattleFieldWeapon* createWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
	// ʹ�÷�������������
	static BattleFieldWeapon* createWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);

// ��ʼ������
public:
	// ʹ�ñ��ز�������
	bool initWithLocalOperationData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
	// ʹ�÷�������������
	bool initWithRecvServerData(string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF);
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
	// �ƶ�����
	void Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// ̽�⺯��
	void Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP]);
	// ��������
	void Attack();
	// ����������
	int BeAttacked();

// ��ȡ����
public:
	// ��������
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
	// ������ս��̬�Ʒ����ͼ�еĴ�С
	Size GetSizeInSimulationMap();
	// ����ʶ���־
	void SetIFF(ENUM_IFF IFF) { mIFF = IFF; };
	ENUM_IFF GetIFF() { return mIFF; };
};