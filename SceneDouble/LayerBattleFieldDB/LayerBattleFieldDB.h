#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"


USING_NS_CC;
extern class BFW_BasicClass;

class LayerBattleFieldDB : public Layer
{
private:
	// ս������
	BFG_FrogOfWar* mFrogOfWarArray[BATTLE_FIELD_WIDTH_IN_SQUARE][BATTLE_FIELD_HEIGHT_IN_SQUARE];

	// ��ս˫��������ս���еı���
	vector<BFW_BasicClass*> mWeaponsOwn;
	vector<BFW_BasicClass*> mWeaponsOppo;

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

	// ���ñ�����������
	void arrangeWeaponWithAbsolutePosOnBegan(int weaponType, int posX, int posY, int discardTimes);
	void arrangeWeaponWithAbsolutePosOnMoved(float posX, float posY, int mDiscardTimes);
	void arrangeWeaponWithAbsolutePosOnEnded(int discardTimes);
	void arrangeWeaponWithAbsolutePosCancelled(int discardTimes);

	// ���öԷ���������
	void arrangeEnemyWeaponWithAbsolutePos(int weaponType, int posX, int posY, int enemyDiscardTimes);
};