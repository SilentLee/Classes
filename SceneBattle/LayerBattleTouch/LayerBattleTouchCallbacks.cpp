#include "LayerBattleTouch.h"
#include "LayerBattleSituation.h"
#include "LayerBattleButton.h"
#include "ProtocolHeader.h"

void LayerBattleTouch::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch began");

	LayerBattleButton* layerBattleButton = (LayerBattleButton*)this->getParent()->getChildByName("layerBattleButton");

	// 若尚未选择卡牌 函数退出
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

	// 若尚未选择卡牌 函数退出
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

		// 获取在战场中加入的武器并设置 透明度 位置
		layerBattleSituation->previewWeaponWithPositionOnMoved(posX, posY);
	}
}

void LayerBattleTouch::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	log("touch end");

	LayerBattleButton* layerBattleButton = (LayerBattleButton*)this->getParent()->getChildByName("layerBattleButton");

	// 若尚未选择卡牌 函数退出
	if (layerBattleButton->getCardBtnSwitch() == BTN_CARD_NONE)
	{
		return;
	}

	for (auto &item : touches)
	{
		auto touch = item;

		// 出牌同时计算下一张待出卡牌
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