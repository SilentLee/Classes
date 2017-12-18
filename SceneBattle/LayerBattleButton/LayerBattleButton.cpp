#include "LayerBattleButton.h"

LayerBattleButton* LayerBattleButton::create()
{
	LayerBattleButton* ret = new LayerBattleButton();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleButton::init()
{
	LayerEx::init();

	// ��ʼ������
	initCards();

	return true;
}

void LayerBattleButton::initCards()
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
		mBtnCards[i]->addClickEventListener(CC_CALLBACK_0(LayerBattleButton::BtnCardCallback, this, i));
		this->addChild(mBtnCards[i], 1, i);
	}

	// ������һ�ſ�����ʾ��
	mNextCard = Sprite::create(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
	// �˴�Ӧ�� setPosition �����е��ò����г��ֵ���ֵ �� 108 96 �����ɺ궨��Ĳ��� ���ں���ֱ�Ӹ���
	mNextCard->setPosition(108, 96);
	mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;
	this->addChild(mNextCard, 1, "nextCard");
}

void LayerBattleButton::BtnCardCallback(int key)
{
	mCardBtnSwitch = key;
}

// ���ƴ�����
int LayerBattleButton::discard()
{
	if (mCardBtnSwitch == BTN_CARD_NONE)
	{
		log("No card selected!!!");
		return CARD_NO_TYPE;
	}

	int discardType = mBtnCards[mCardBtnSwitch]->getCardType();
	for (int i = 0; i < NUM_CARDS_IN_GROUP; i++)
	{
		if (discardType == mStructCards[i].CARD_TYPE)
		{
			// ��ʹ�ù��Ŀ��Ʒ��õ���β
			S_CARD_STRUCT_BATTLE cardStruct = S_CARD_STRUCT_BATTLE{ mStructCards[i].CARD_TYPE, CARD_STATUS_FREE };
			mStructCards.erase(mStructCards.begin() + i);
			mStructCards.push_back(cardStruct);

			// ����һ�ſ��Ʒ��õ�����ѡ��ť��
			mBtnCards[mCardBtnSwitch]->setCardType(mStructCards[NUM_CARD_BUTTONS - 1].CARD_TYPE);
			mStructCards[NUM_CARD_BUTTONS - 1].CARD_STATUS = CARD_STATUS_OCCUPIED;
			mBtnCards[mCardBtnSwitch]->setButtonImage(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS - 1].CARD_TYPE).c_str());

			// ������һ�ſ���
			mNextCard->setTexture(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
			mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;

			// ϴ��
			random_shuffle(mStructCards.begin() + NUM_CARD_BUTTONS + 1, mStructCards.end() - NUM_CARD_USED_CARD);
			break;
		}
	}

	mCardBtnSwitch = BTN_CARD_NONE;

	return discardType;
}