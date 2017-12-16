#include "LayerBattleTouch.h"

LayerBattleTouch* LayerBattleTouch::create()
{
	LayerBattleTouch* ret = new LayerBattleTouch();
	if (ret && ret->init());
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleTouch::init()
{
	LayerEx::init();
	initTouchMode(this);
	// ��ʼ������
	initCards();
	return true;
};

// ���ô���ģʽ
void LayerBattleTouch::initTouchMode(LayerBattleTouch* layerTouchDB)
{
	layerTouchDB->setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ALL_AT_ONCE);
}

void LayerBattleTouch::initCards()
{
	// ����ѡ�񿪹���0
	mCardBtnSwitch = BTN_CARD_NONE;

	// ���ؿ���
	for (int i = CARD_TYPE_FIGHTER_PLANE; i <= NUM_CARDS_IN_GROUP; i++)
	{
		S_CARD_STRUCT_BATTLE card = S_CARD_STRUCT_BATTLE{ (ENUM_CARD_TYPE)i, CARD_STATUS_FREE };
		mStructCards.push_back(card);
	}

	// ϴ��
	random_shuffle(mStructCards.begin(), mStructCards.end());

	// ����
	for (int i = 0; i < NUM_CARD_BUTTONS; i++)
	{
		// �˴�Ӧ�� create �����е��ò����г��ֵ���ֵ �� 356 162 96 �����ɺ궨��Ĳ��� ���ں���ֱ�Ӹ���
		mBtnCards[i] = BtnCard::create(mStructCards[i].CARD_TYPE, 356 + i * 162, 96);
		mBtnCards[i]->setCardType(mStructCards[i].CARD_TYPE);
		mStructCards[i].CARD_STATUS = CARD_STATUS_OCCUPIED;
		mBtnCards[i]->addClickEventListener(CC_CALLBACK_0(LayerBattleTouch::BtnCardCallback, this, i));
		this->addChild(mBtnCards[i], 1, i);
	}

	// ������һ�ſ�����ʾ��
	mNextCard = Sprite::create(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
	// �˴�Ӧ�� setPosition �����е��ò����г��ֵ���ֵ �� 108 96 �����ɺ궨��Ĳ��� ���ں���ֱ�Ӹ���
	mNextCard->setPosition(108, 96);
	mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;
	this->addChild(mNextCard, 1, "nextCard");
}

