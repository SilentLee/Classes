#include "LayerSelectButton.h"
#include "SceneBattle.h"

void LayerSelectButton::UpdateToBattle(float dt)
{
	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// �������������� ׼����ʼ��Ϸ
	if (roomInstance->getRoomStatus() == RM_READY) {

	}
	// �������������� �ȴ��µ���ҽ���
	else if (roomInstance->getRoomStatus() == RM_WAITING) {

	}
	// ��Ϸ��ʼ ������Ϸ��ս����
	else if (roomInstance->getRoomStatus() == RM_GAME_START) {
		roomInstance->setRoomStatus(RM_GAME_IN_PROGRESS);
		auto director = Director::getInstance();
		auto SceneBattle = SceneBattle::createScene();
		director->pushScene(SceneBattle);
	}
}