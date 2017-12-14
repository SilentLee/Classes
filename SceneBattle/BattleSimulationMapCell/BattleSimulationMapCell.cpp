#include "BattleSimulationMapCell.h"

//// ��������
//CBattleSimulationMapCell* CBattleSimulationMapCell::createWithAbsolutePos(float posX, float posY)
//{
//	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();
//	
//	if (ret && ret->initWithAbsolutePos(posX, posY))
//	{
//		ret->autorelease();
//		return ret;
//	}
//	CC_SAFE_DELETE(ret);
//	return nullptr;
//}

// �������� ʹ�÷����ͼ����
CBattleSimulationMapCell* CBattleSimulationMapCell::createWithCoordinate(int coordinateX, int coordinateY)
{
	CBattleSimulationMapCell* ret = new CBattleSimulationMapCell();

	float posX = (coordinateX + 0.5) * WIDTH_OF_MAP_CELL;
	float posY = (coordinateY + 0, 5) * WIDTH_OF_MAP_CELL;

	if (ret && ret->initWithAbsolutePos(posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
// ��ս����ʾ����ϵ�½��������趨 1920 * 1080
bool CBattleSimulationMapCell::initWithAbsolutePos(float posX, float posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(CU_ImgLoader::getFogImg(1).c_str(), posX, posY);

	// ����ս������ķ�������
	mCoordinate.x = posX / WIDTH_OF_MAP_CELL;
	mCoordinate.y = posY / WIDTH_OF_MAP_CELL;

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