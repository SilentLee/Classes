#include "SceneSelect.h"
#include "GlobalInstanceApi.h"
#include "SceneDoubleBattle.h"

void SceneSelect::UpdateToBattle(float dt)
{
	CRoomInstance* roomInstance = CRoomInstance::getInstance();

	// �������������� ׼����ʼ��Ϸ
	if (roomInstance->getStatus() == RM_READY) {

	}
	// �������������� �ȴ��µ���ҽ���
	else if (roomInstance->getStatus() == RM_WAITING){

	}
	// ��Ϸ��ʼ ������Ϸ��ս����
	else if (roomInstance->getStatus() == RM_GAME_START) {
		roomInstance->setStatus(RM_GAME_IN_PROGRESS);
		auto director = Director::getInstance();
		auto SceneBattle = SceneDoubleBattle::createScene();
		director->pushScene(SceneBattle);
	}
}