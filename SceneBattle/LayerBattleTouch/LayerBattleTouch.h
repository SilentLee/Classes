#pragma once

#include "cocos2d.h"
#include "LayerEx.h"

USING_NS_CC;
using namespace std;

class LayerBattleTouch : public LayerEx
{
public:
	static LayerBattleTouch* create();
	bool init();
	void initTouchMode(LayerBattleTouch* layerTouchDB);

	// 触控回调函数
	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);
};