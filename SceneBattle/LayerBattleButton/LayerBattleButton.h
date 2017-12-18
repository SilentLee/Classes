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
	// ��ǰ��ѡ�Ŀ��ư�ť
	int mCardBtnSwitch;

public:
	vector<S_CARD_STRUCT_BATTLE> mStructCards;
	BtnCard* mBtnCards[NUM_CARD_BUTTONS];
	Sprite* mNextCard;	

public:
	// ��ʼ������
	void initCards();
	// ���ư�ť�ص�����
	void BtnCardCallback(int key);
	// ���ƴ�����
	int discard();

// ��ȡ����
public:
	int getCardBtnSwitch() { return mCardBtnSwitch; };
	int getCardType() { return mBtnCards[mCardBtnSwitch]->getCardType(); };
};