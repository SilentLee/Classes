#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include <vector>

USING_NS_CC;
using namespace std;

typedef struct _CARD_STRUCT_DOUBLE_BATTLE
{
public:
	int CARD_TYPE;
	int CARD_STATUS;
} S_CARD_STRUCT_DOUBLE_BATTLE;

class LayerTouchDB : public Layer
{
private:
	int mCardBtnSwitch;
public:
	//S_CARD_STRUCT_DOUBLE_BATTLE mCards[NUM_CARDS_IN_GROUP];
	vector<S_CARD_STRUCT_DOUBLE_BATTLE> mStructCards;
	BFG_BtnCard* mBtnCards[NUM_CARD_BUTTONS];
	CG_Sprite* mNextCard;

public:
	static LayerTouchDB* create();
	bool init();
	void initTouchMode(LayerTouchDB* layerTouchDB);

	// 初始化卡牌
	void initCards();

	// 触控回调函数
	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

	// 卡牌按钮回调函数
	void BtnCardCallback(int key);

	// 出牌处理函数
	int discard();

};