#include "SceneSelect.h"
#include "GlobalInstanceApi.h"
#include "SceneDoubleBattle.h"
static int a = 0;
void SceneSelect::UpdateToBattle(float dt)
{
	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// �������������� ׼����ʼ��Ϸ
	if (roomInstance->getRoomStatus() == RM_READY) {

	}
	// �������������� �ȴ��µ���ҽ���
	else if (roomInstance->getRoomStatus() == RM_WAITING){

	}
	// ��Ϸ��ʼ ������Ϸ��ս����
	else if (roomInstance->getRoomStatus() == RM_GAME_START) {
		roomInstance->setRoomStatus(RM_GAME_IN_PROGRESS);
		auto director = Director::getInstance();
		auto SceneBattle = SceneDoubleBattle::createScene();
		director->pushScene(SceneBattle);
	}
}
