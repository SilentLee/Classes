#pragma once
#include "LayerEx.h"
#include <vector>
#include "BtnCard.h"

USING_NS_CC;

typedef struct _CARD_STRUCT_BATTLE
{
public:
	ENUM_CARD_TYPE CARD_TYPE;
	int CARD_STATUS;
} S_CARD_STRUCT_BATTLE;

class LayerBattleButton : public LayerEx
{
public:
	static LayerBattleButton* create();
	bool init();


private:
	// 当前点选的卡牌按钮
	int mCardBtnSwitch;

public:
	vector<S_CARD_STRUCT_BATTLE> mStructCards;
	BtnCard* mBtnCards[NUM_CARD_BUTTONS];
	Sprite* mNextCard;	

public:
	// 初始化卡牌
	void initCards();
	// 卡牌按钮回调函数
	void BtnCardCallback(int key);
	// 出牌处理函数
	int discard();

// 存取函数
public:
	int getCardBtnSwitch() { return mCardBtnSwitch; };
	int getCardType() { return mBtnCards[mCardBtnSwitch]->getCardType(); };
};