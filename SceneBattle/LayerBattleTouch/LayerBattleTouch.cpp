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
	Layer::init();
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
		S_CARD_STRUCT_DOUBLE_BATTLE card = S_CARD_STRUCT_DOUBLE_BATTLE{ i, CARD_STATUS_FREE };
		mStructCards.push_back(card);
	}

	// 洗牌
	random_shuffle(mStructCards.begin(), mStructCards.end());

	// 发牌
	for (int i = 0; i < NUM_CARD_BUTTONS; i++)
	{
		mBtnCards[i] = BFG_BtnCard::createWithRelativePos(mStructCards[i].CARD_TYPE, 0.33 + i * 0.15, 0.05);
		mBtnCards[i]->setCardType(mStructCards[i].CARD_TYPE);
		mStructCards[i].CARD_STATUS = CARD_STATUS_OCCUPIED;
		mBtnCards[i]->addClickEventListener(CC_CALLBACK_0(LayerBattleTouch::BtnCardCallback, this, i));
		this->addChild(mBtnCards[i], 1, i);
	}

	// 创建下一张卡牌显示栏
	mNextCard = CG_Sprite::createWithRelativePos(CU_ImgLoader::getCardImg(mStructCards[NUM_CARD_BUTTONS].CARD_TYPE).c_str(), 0.1, 0.05);
	mStructCards[NUM_CARD_BUTTONS].CARD_STATUS = CARD_STATUS_NEXT_CARD;
	this->addChild(mNextCard, 1, "nextCard");
}

