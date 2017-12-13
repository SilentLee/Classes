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
			LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");
			
			layerBattleField->previewWeaponWithAbsolutePosOnBegan(discardType, posX, posY);
		}
	}
}

void LayerBattleTouch::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
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

		LayerBattleField* layerBattleField = (LayerBattleField*)this->getParent()->getChildByName("layerBattleField");

		// ��ȡ��ս���м�������������� ͸���� λ��
		layerBattleField->previewWeaponWithAbsolutePosOnMoved(posX, posY);
	}
}

void LayerBattleTouch::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
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

// ���ƴ�����
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