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

	// 初始化卡牌
	initCards();

	return true;
}

void LayerBattleButton::initCards()
{
	// 卡牌选择开关置0
	mCardBtnSwitch = BTN_CARD_NONE;

	// 加载卡组
	for (int i = CARD_TYPE_FIGHTER_PLANE; i <= NUM_CARDS_IN_GROUP; i++)
	{
		S_CARD_STRUCT_BATTLE card = S_CARD_STRUCT_BATTLE{ (ENUM_CARD_TYPE)i, CARD_STATUS_FREE };
		mStructCards.push_back(card);
	}

	// 洗牌
	random_shuffle(mStructCards.begin(), mStructCards.end());

	// 发牌
	for (int i = 0; i < NUM_CARD_BUTTONS; i++)
	{
		// 此处应将 create 函数中调用参数中出现的数值 即 356 162 96 更换成宏定义的参数 便于后期直接更改
		mBtnCards[i] = BtnCard::create(mStructCards[i].CARD_TYPE, 356 + i * 162, 96);
		mBtnCards[i]->setCardType(mStructCards[i].CARD_TYPE);
		mStructCards[i].CARD_STATUS = CARD_STATUS_OCCUPIED;
		mBtnCards[i]->addClickEventListener(CC_CALLBACK_0(LayerBattleButton::BtnCardCallback, this, i));
		this->addChild(mBtnCards[i], 1, i);
	}

	// 创建下一张卡牌显示栏
	mNextCard = Sprite::create(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
	// 此处应将 setPosition 函数中调用参数中出现的数值 即 108 96 更换成宏定义的参数 便于后期直接更改
	mNextCard->setPosition(108, 96);
	mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;
	this->addChild(mNextCard, 1, "nextCard");
}

void LayerBattleButton::BtnCardCallback(int key)
{
	mCardBtnSwitch = key;
}

// 出牌处理函数
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
			// 将使用过的卡牌放置到队尾
			S_CARD_STRUCT_BATTLE cardStruct = S_CARD_STRUCT_BATTLE{ mStructCards[i].CARD_TYPE, CARD_STATUS_FREE };
			mStructCards.erase(mStructCards.begin() + i);
			mStructCards.push_back(cardStruct);

			// 将下一张卡牌放置到卡牌选择按钮中
			mBtnCards[mCardBtnSwitch]->setCardType(mStructCards[NUM_CARD_BUTTONS - 1].CARD_TYPE);
			mStructCards[NUM_CARD_BUTTONS - 1].CARD_STATUS = CARD_STATUS_OCCUPIED;
			mBtnCards[mCardBtnSwitch]->setButtonImage(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS - 1].CARD_TYPE).c_str());

			// 设置下一张卡牌
			mNextCard->setTexture(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
			mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;

			// 洗牌
			random_shuffle(mStructCards.begin() + NUM_CARD_BUTTONS + 1, mStructCards.end() - NUM_CARD_USED_CARD);
			break;
		}
	}

	mCardBtnSwitch = BTN_CARD_NONE;

	return discardType;
}