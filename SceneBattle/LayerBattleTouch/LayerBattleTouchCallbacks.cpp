#include "LayerBattleTouch.h"
#include "LayerBattleField.h"
#include "ProtocolHeader.h"

void LayerBattleTouch::BtnCardCallback(int key)
{
	mCardBtnSwitch = key;
}

void LayerBattleTouch::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch began");

	// 若尚未选择卡牌 函数退出
	if (mCardBtnSwitch == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;
		if (touch) {
			int posX = touch->getLocation().x;
			int posY = touch->getLocation().y;

			int discardType = mBtnCards[mCardBtnSwitch]->getCardType();
			LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");
			
			layerBattleField->previewWeaponWithAbsolutePosOnBegan(discardType, posX, posY);
		}
	}
}

void LayerBattleTouch::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch move");

	// 若尚未选择卡牌 函数退出
	if (mCardBtnSwitch == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;

		int posX = touch->getLocation().x;
		int posY = touch->getLocation().y;

		LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");

		// 获取在战场中加入的武器并设置 透明度 位置
		layerBattleField->previewWeaponWithAbsolutePosOnMoved(posX, posY);
	}
}

void LayerBattleTouch::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch end");

	// 若尚未选择卡牌 函数退出
	if (mCardBtnSwitch == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;

		int posX = touch->getLocation().x;
		int posY = touch->getLocation().y;

		int discardType = discard();

		LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");
		layerBattleField->previewWeaponWithAbsolutePosOnEnded();
	}
}

void LayerBattleTouch::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	log("onTouchesCancelled");
	LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");
	layerBattleField->previewWeaponWithAbsolutePosCancelled();
}

// 出牌处理函数
int LayerBattleTouch::discard()
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
			S_CARD_STRUCT_DOUBLE_BATTLE cardStruct = S_CARD_STRUCT_DOUBLE_BATTLE{ mStructCards[i].CARD_TYPE, CARD_STATUS_FREE };
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