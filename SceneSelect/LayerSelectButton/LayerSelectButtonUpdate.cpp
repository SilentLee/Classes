#include "LayerSelectButton.h"
#include "SceneBattle.h"

void LayerSelectButton::UpdateToBattle(float dt)
{
	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// 房间内人数已满 准备开始游戏
	if (roomInstance->getRoomStatus() == RM_READY) {

	}
	// 房间内人数不足 等待新的玩家进入
	else if (roomInstance->getRoomStatus() == RM_WAITING) {

	}
	// 游戏开始 进入游戏对战界面
	else if (roomInstance->getRoomStatus() == RM_GAME_START) {
		roomInstance->setRoomStatus(RM_GAME_IN_PROGRESS);
		auto director = Director::getInstance();
		auto SceneBattle = SceneBattle::createScene();
		director->pushScene(SceneBattle);
	}
}