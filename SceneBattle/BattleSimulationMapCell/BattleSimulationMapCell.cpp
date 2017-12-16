#include "BattleSimulationMapCell.h"

// �������� ʹ�÷����ͼ����
CBattleSimulationMapCell* CBattleSimulationMapCell::createWithCoordinate(int coordinateX, int coordinateY)
{
	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();

	if (ret && ret->initWithCoordinate(coordinateX, coordinateY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
// ��ս����ʾ����ϵ�½��������趨 1920 * 1080
bool CBattleSimulationMapCell::initWithCoordinate(int coordinateX, int coordinateY)
{
	// ����ս����ʾ����ϵ�µ�����
	float posX = (coordinateX + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (coordinateY + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	//float posX = 540;
	//float posY = 960;

	// �����ʼ��
	Sprite::initWithFile(CU_ImgLoader::getFogImg(1).c_str());
	// ����λ��
	this->setPosition(posX, posY);

	// ����Ӧ���÷����С
	float sizeFactor = WIDTH_OF_BATTLE_SIMULATION_MAP_CELL / this->getContentSize().width;
	this->setScale(sizeFactor);

	// ����ս������ķ�������
	mCoordinate.x = coordinateX;
	mCoordinate.y = coordinateY;

	// ����λ�ڷ����������������
	mWeaponType = WP_TYPE_NONE;
	// ����λ�ڷ��������������ǩ
	mWeaponTag = -1;

	// ���ö�ս˫���ֱ���Ե�ս������
	mFogAgainstBlueEn = true;
	mFogAgainstRedEn = true;

	// ��յ�Ų����䶯̬����
	mHertzWaveVec.clear();

	return true;
}