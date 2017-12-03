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

	// 按钮回调函数
public:
	void BtnStartCallback();

// 更新函数
public:
	void UpdateToBattle(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(SceneSelect);
};
