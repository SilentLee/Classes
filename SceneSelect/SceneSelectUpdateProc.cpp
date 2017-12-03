#include "SceneSelect.h"
#include "GlobalInstanceApi.h"
#include "SceneDoubleBattle.h"

void SceneSelect::UpdateToBattle(float dt)
{
	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	if (roomInstance->getStatus() == RM_READY && roomInstance->getHasGameBegan() == false) {
		roomInstance->setHasGameBegan(true);

		auto director = Director::getInstance();
		auto SceneDoubleBattle = SceneDoubleBattle::createScene();
		director->pushScene(SceneDoubleBattle);
	}
}