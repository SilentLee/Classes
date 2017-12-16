#pragma once

#include "cocos2d.h"
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "LibBattleFieldGraphApi.h"
#include "LayerEx.h"
#include <vector>
#include "BtnCard.h"

USING_NS_CC;
using namespace std;

typedef struct _CARD_STRUCT_BATTLE
{
public:
	ENUM_CARD_TYPE CARD_TYPE;
	int CARD_STATUS;
} S_CARD_STRUCT_BATTLE;

class LayerBattleTouch : public LayerEx
{
private:
	int mCardBtnSwitch;
public:
	//S_CARD_STRUCT_DOUBLE_BATTLE mCards[NUM_CARDS_IN_GROUP];
	vector<S_CARD_STRUCT_BATTLE> mStructCards;
	BtnCard* mBtnCards[NUM_CARD_BUTTONS];
	Sprite* mNextCard;

public:
	static LayerBattleTouch* create();
	bool init();
	void initTouchMode(LayerBattleTouch* layerTouchDB);

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