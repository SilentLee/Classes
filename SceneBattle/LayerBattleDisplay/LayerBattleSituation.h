#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"
#include "LayerEx.h"
#include "BattleSimulationMapCell.h"

#define HEIGHT_OF_RANGE_TO_ARRANGE_WEAPON_ON_SIMULATION_MAP		5

USING_NS_CC;
extern class BattleFieldWeapon;

class LayerBattleSituation : public LayerEx
{
private:
	// ��ս˫��������ս���еı���
	vector<BattleFieldWeapon*> mWeaponsOwn;
	vector<BattleFieldWeapon*> mWeaponsOppo;

// ���ݷ������
private:
	// ս��̬�Ʒ����ͼ ����
	CBattleSimulationMapCell* mBattleSimulationMapCellArray[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP];
	// ս������ֽ���
	int mFrogLine[WIDTH_OF_BATTLE_SIMULATION_MAP];

// ��������
public:
	static LayerBattleSituation* create();

// ��ʼ������
public:
	// ��ʼ��ս��̬�Ʋ�
	bool init();
	// ��ʼ��ս��̬�Ʒ����ͼ
	void initBattleSimulationMap();
	// ��ʼ������
	void initDefenseLine();

// ���º���
public:
	// ����ս������
	void updateFrog(float dt);
	// ��������ս��̬�Ƹ������ݲ����¿ͻ���ս��̬����ʾ�ĸ��º��� ����ͬ��
	void updateBFSituation(float dt);
	// ����ս��̬�Ƹ��º��� ����ƽ��
	void updateLocalSituation(float dt);

// ������������
public:
	// ���������б�����������Ч��Ԥ������
	void previewWeaponWithPositionOnBegan(int weaponType, float posX, float posY);
	void previewWeaponWithPositionOnMoved(float posX, float posY);
	void previewWeaponWithPositionOnEnded();
	void previewWeaponWithPositionCancelled();
	// �Է��������躯��
	void arrangeEnemyWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// �����������躯��
	void arrangeOwnWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
};