#include "LayerTouchDB.h"
#include "LayerBattleFieldDB.h"

void LayerTouchDB::BtnCardCallback(int key)
{
	mCardBtnSwitch = key;
}

void LayerTouchDB::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
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
			LayerBattleFieldDB* layerBattleFieldDB = (LayerBattleFieldDB*)this->getParent()->getChildByName("layerBattleFieldDB");
			
			layerBattleFieldDB->arrangeWeaponWithAbsolutePos(discardType, posX, posY, mDiscardTimes);

			// 获取在战场中加入的武器并设置透明度
			CG_Sprite* weaponToArrange = (CG_Sprite*)layerBattleFieldDB->getChildByTag(mDiscardTimes);
			weaponToArrange->setOpacity(150);
			//weaponToArrange->setPosInSquare(posX, posY);
		}
	}
}

void LayerTouchDB::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
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

		LayerBattleFieldDB* layerBattleFieldDB = (LayerBattleFieldDB*)this->getParent()->getChildByName("layerBattleFieldDB");

		// 获取在战场中加入的武器并设置 透明度 位置
		CG_Sprite* weaponToArrange = (CG_Sprite*)layerBattleFieldDB->getChildByTag(mDiscardTimes);
		weaponToArrange->setOpacity(150);
		weaponToArrange->setPosInSquare(posX, posY);
	}
}

void LayerTouchDB::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
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

		LayerBattleFieldDB* layerBattleFieldDB = (LayerBattleFieldDB*)this->getParent()->getChildByName("layerBattleFieldDB");
		CG_Sprite* weaponToArrange = (CG_Sprite*)layerBattleFieldDB->getChildByTag(mDiscardTimes);
		weaponToArrange->setOpacity(255);
		//weaponToArrange->setRealPosWithAbsoluteValue(touch->getLocation().x, touch->getLocation().y);
		weaponToArrange->scheduleUpdate();

		// 出牌次数加1
		mDiscardTimes++;
	}
}

void LayerTouchDB::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	log("onTouchesCancelled");
	LayerBattleFieldDB* layerBattleFieldDB = (LayerBattleFieldDB*)this->getParent()->getChildByName("layerBattleFieldDB");
	layerBattleFieldDB->removeChildByTag(mDiscardTimes);
}

// 出牌处理函数
int LayerTouchDB::discard()
{
	if (mCardBtnSwitch == BTN_CARD_NONE)
	{
		log("No card selected!!!");
		return NO_TYPE;
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