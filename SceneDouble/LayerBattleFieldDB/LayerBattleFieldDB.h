#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "Weapon.h"


USING_NS_CC;
extern class BattleFieldWeapon_OWN;

class LayerBattleFieldDB : public Layer
{
private:
	// ս������
	BFG_FrogOfWar* mFrogOfWarArray[BATTLE_FIELD_WIDTH_IN_SQUARE][BATTLE_FIELD_HEIGHT_IN_SQUARE];

	// ��ս˫��������ս���еı���
	vector<BattleFieldWeapon_OWN*> mWeaponsOwn;
	vector<BattleFieldWeapon_OWN*> mWeaponsOppo;

	// ս������ֽ���
	int mFrogLine[BATTLE_FIELD_WIDTH_IN_SQUARE];

public:
	static LayerBattleFieldDB* create();
	bool init();
	void onEnter();

	// ע��֪ͨ����
	void registNotification();

public:
	void addFog(float originX, float originY, int width, int height, float stepX, float stepY);
	void addDefenseLine();

	// ��ײ����¼�������
	bool onContact(PhysicsContact& contact);

	// ���º���
	virtual void updateFrog(float dt);
	virtual void updateBFSituation(float dt);

	// Ԥ��������������Ч������
	void previewWeaponWithAbsolutePosOnBegan(int weaponType, int posX, int posY);
	void previewWeaponWithAbsolutePosOnMoved(float posX, float posY);
	void previewWeaponWithAbsolutePosOnEnded();
	void previewWeaponWithAbsolutePosCancelled();

	// ���öԷ���������
	void arrangeEnemyWeaponWithAbsolutePos(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);
	// ���ñ�����������
	void arrangeOwnWeaponWithAbsolutePos(ENUM_TROOPS troopsIn, int weaponType, int posX, int posY, int weaponTag);

};