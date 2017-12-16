#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"
#include "LayerEx.h"
#include "BattleSimulationMapCell.h"


USING_NS_CC;
extern class BattleFieldWeapon_OWN;

class LayerBattleDisplay : public LayerEx
{
private:
	// ս������
	//BFG_FrogOfWar* mFrogOfWarArray[WIDTH_OF_BATTLE_SIMULATION_MAP][WIDTH_OF_BATTLE_SIMULATION_MAP];

	// ��ս˫��������ս���еı���
	vector<BattleFieldWeapon_OWN*> mWeaponsOwn;
	vector<BattleFieldWeapon_OWN*> mWeaponsOppo;

	// ս������ֽ���
	int mFrogLine[BATTLE_FIELD_WIDTH_IN_SQUARE];

public:
	static LayerBattleDisplay* create();
	bool init();

public:
	void addDefenseLine();

	// ���º���
	//virtual void updateFrog(float dt);
	virtual void updateBFSituation(float dt);

	// Ԥ��������������Ч������
	void previewWeaponWithPositionOnBegan(int weaponType, int posX, int posY);
	void previewWeaponWithPositionOnMoved(float posX, float posY);
	void previewWeaponWithPositionOnEnded();
	void previewWeaponWithPositionCancelled();

	// ���öԷ���������
	void arrangeEnemyWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// ���ñ�����������
	void arrangeOwnWeaponWithPosition(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);

};