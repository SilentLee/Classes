#pragma once

#include "cocos2d.h"
#include "..\Classes\GraphicLib\ApiGraphicLib.h"
#include "..\Classes\Utils\ApiUtils.h"
#include "BtnCardDB.h"
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
	int mDiscardTimes;
public:
	//S_CARD_STRUCT_DOUBLE_BATTLE mCards[NUM_CARDS_IN_GROUP];
	vector<S_CARD_STRUCT_DOUBLE_BATTLE> mStructCards;
	BtnCardDB* mBtnCards[NUM_CARD_BUTTONS];
	CSprite* mNextCard;

public:
	static LayerTouchDB* create();
	bool init();
	void initTouchMode(LayerTouchDB* layerTouchDB);

	// ��ʼ������
	void initCards();

	// ���ػص�����
	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);

	// ���ư�ť�ص�����
	void BtnCardCallback(int key);

	// ���ƴ�����
	int discard();

};