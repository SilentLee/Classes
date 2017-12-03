#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LayerBattleFieldDB.h"
#include "LayerTouchDB.h"

class SceneSelect : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// ��ť�ص�����
public:
	void BtnStartCallback();

// ���º���
public:
	void UpdateToBattle(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(SceneSelect);
};
