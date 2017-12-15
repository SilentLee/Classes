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
	// ��������ʼ��
	node = this;

	// ����ս����ʾ����ϵ�µ�����
	float posX = (coordinateX + 0.5) * WIDTH_OF_MAP_CELL;
	float posY = (coordinateY + 0.5) * WIDTH_OF_MAP_CELL;

	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(CU_ImgLoader::getFogImg(1).c_str(), posX, posY);

	// ����ս�������ͼ��С �Ե�ͼ�����������
	float SizeFactor = WIDTH_OF_MAP_CELL / this->getContentSize().width;
	this->setSizeAdp(SizeFactor);

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