#include "LayerBattleTouch.h"
#include "LayerBattleSituation.h"
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
			LayerBattleSituation* layerBattleSituation = (LayerBattleSituation*)this->getParent()->getChildByName("layerBattleSituation");
			
			layerBattleSituation->previewWeaponWithPositionOnBegan(discardType, posX, posY);
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

		LayerBattleSituation* layerBattleSituation = (LayerBattleSituation*)this->getParent()->getChildByName("layerBattleSituation");

		// ��ȡ��ս���м�������������� ͸���� λ��
		layerBattleSituation->previewWeaponWithPositionOnMoved(posX, posY);
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

		LayerBattleSituation* layerBattleSituation = (LayerBattleSituation*)this->getParent()->getChildByName("layerBattleSituation");
		layerBattleSituation->previewWeaponWithPositionOnEnded();
	}
}

void LayerBattleTouch::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	log("onTouchesCancelled");
	LayerBattleSituation* layerBattleSituation = (LayerBattleSituation*)this->getParent()->getChildByName("layerBattleSituation");
	layerBattleSituation->previewWeaponWithPositionCancelled();
}