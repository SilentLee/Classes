#include "LayerBattleTouch.h"
#include "LayerBattleDisplay.h"
#include "LayerBattleButton.h"
#include "ProtocolHeader.h"

void LayerBattleTouch::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch began");

	LayerBattleButton* layerBattleButton = (LayerBattleButton*)this->getParent()->getChildByName("layerBattleButton");

	// ����δѡ���� �����˳�
	if (layerBattleButton->getCardBtnSwitch() == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;
		if (touch) {
			float posX = transTouch(touch).x;
			float posY = transTouch(touch).y;

			int discardType = layerBattleButton->getCardType();
			LayerBattleDisplay* layerBattleDisplay = (LayerBattleDisplay*)this->getParent()->getChildByName("layerBattleDisplay");
			
			layerBattleDisplay->previewWeaponWithPositionOnBegan(discardType, posX, posY);
		}
	}
}

void LayerBattleTouch::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch move");

	LayerBattleButton* layerBattleButton = (LayerBattleButton*)this->getParent()->getChildByName("layerBattleButton");

	// ����δѡ���� �����˳�
	if (layerBattleButton->getCardBtnSwitch() == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;

		float posX = transTouch(touch).x;
		float posY = transTouch(touch).y;

		LayerBattleDisplay* layerBattleDisplay = (LayerBattleDisplay*)this->getParent()->getChildByName("layerBattleDisplay");

		// ��ȡ��ս���м�������������� ͸���� λ��
		layerBattleDisplay->previewWeaponWithPositionOnMoved(posX, posY);
	}
}

void LayerBattleTouch::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch end");

	LayerBattleButton* layerBattleButton = (LayerBattleButton*)this->getParent()->getChildByName("layerBattleButton");

	// ����δѡ���� �����˳�
	if (layerBattleButton->getCardBtnSwitch() == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;

		// ����ͬʱ������һ�Ŵ�������
		int discardType = layerBattleButton->discard();

		LayerBattleDisplay* layerBattleDisplay = (LayerBattleDisplay*)this->getParent()->getChildByName("layerBattleDisplay");
		layerBattleDisplay->previewWeaponWithPositionOnEnded();
	}
}

void LayerBattleTouch::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	log("onTouchesCancelled");
	LayerBattleDisplay* layerBattleDisplay = (LayerBattleDisplay*)this->getParent()->getChildByName("layerBattleDisplay");
	layerBattleDisplay->previewWeaponWithPositionCancelled();
}