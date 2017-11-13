#include "LayerTouchDB.h"
#include "LayerBattleFieldDB.h"

void LayerTouchDB::BtnCardCallback(int key)
{
	mCardBtnSwitch = key;
}

void LayerTouchDB::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch began");

	// ����δѡ���� �����˳�
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

			// ��ȡ��ս���м��������������͸����
			CG_Sprite* weaponToArrange = (CG_Sprite*)layerBattleFieldDB->getChildByTag(mDiscardTimes);
			weaponToArrange->setOpacity(150);
			//weaponToArrange->setPosInSquare(posX, posY);
		}
	}
}

void LayerTouchDB::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch move");

	// ����δѡ���� �����˳�
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

		// ��ȡ��ս���м�������������� ͸���� λ��
		CG_Sprite* weaponToArrange = (CG_Sprite*)layerBattleFieldDB->getChildByTag(mDiscardTimes);
		weaponToArrange->setOpacity(150);
		weaponToArrange->setPosInSquare(posX, posY);
	}
}

void LayerTouchDB::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch end");

	// ����δѡ���� �����˳�
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

		// ���ƴ�����1
		mDiscardTimes++;
	}
}

void LayerTouchDB::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	log("onTouchesCancelled");
	LayerBattleFieldDB* layerBattleFieldDB = (LayerBattleFieldDB*)this->getParent()->getChildByName("layerBattleFieldDB");
	layerBattleFieldDB->removeChildByTag(mDiscardTimes);
}

// ���ƴ�����
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
			// ��ʹ�ù��Ŀ��Ʒ��õ���β
			S_CARD_STRUCT_DOUBLE_BATTLE cardStruct = S_CARD_STRUCT_DOUBLE_BATTLE{ mStructCards[i].CARD_TYPE, CARD_STATUS_FREE };
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