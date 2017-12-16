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
	// 初始化卡牌
	initCards();
	return true;
};

// 设置触控模式
void LayerBattleTouch::initTouchMode(LayerBattleTouch* layerTouchDB)
{
	layerTouchDB->setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ALL_AT_ONCE);
}

void LayerBattleTouch::initCards()
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
		mBtnCards[i]->addClickEventListener(CC_CALLBACK_0(LayerBattleTouch::BtnCardCallback, this, i));
		this->addChild(mBtnCards[i], 1, i);
	}

	// 创建下一张卡牌显示栏
	mNextCard = Sprite::create(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str());
	// 此处应将 setPosition 函数中调用参数中出现的数值 即 108 96 更换成宏定义的参数 便于后期直接更改
	mNextCard->setPosition(108, 96);
	mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;
	this->addChild(mNextCard, 1, "nextCard");
}

