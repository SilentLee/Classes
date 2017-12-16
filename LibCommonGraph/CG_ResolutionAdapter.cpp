#include "CG_ResolutionAdapter.h"

CG_ResolutionAdapter::CG_ResolutionAdapter()
{
	node = NULL;
}

CG_ResolutionAdapter::~CG_ResolutionAdapter()
{
	// ����� �ڴ�й© �� Ѱַ���� �Ŀ���
	node = NULL;
}

float CG_ResolutionAdapter::getPosAdjustFactor() 
{ 
	//float posAdjustFactor = PosAdjustFactor;
	//return posAdjustFactor;
	return PosAdjustFactor;
}

float CG_ResolutionAdapter::getSizeAdjustFactor() 
{ 
	//float sizeAdjustFactor = SizeAdjustFactor;
	//return sizeAdjustFactor;
	return SizeAdjustFactor;
}

void CG_ResolutionAdapter::init()
{
	// ��ȡ��Ļ���ӷֱ���
	Size VisibleSize = Director::getInstance()->getVisibleSize();

	SizeAdjustFactor = VisibleSize.width / designResolutionSize.width;
	PosAdjustFactor = VisibleSize.width / designResolutionSize.width;

	log("�ֱ�����������ʼ���ɹ�");
}

// �ߴ�ת��
void CG_ResolutionAdapter::sizeAdp()
{
	node->setScale(SizeAdjustFactor);
}

// ���þ�������
void CG_ResolutionAdapter::setAdpPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX * PosAdjustFactor, posY * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY * PosAdjustFactor);
}

// �����������
void CG_ResolutionAdapter::setAdpPosWithRelativeValue(float posX, float posY)
{
	node->setPosition(posX * designResolutionSize.width * PosAdjustFactor, posY * designResolutionSize.height * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosXWithRelativeValue(float posX)
{
	node->setPositionX(posX * designResolutionSize.width * PosAdjustFactor);
}

void CG_ResolutionAdapter::setAdpPosYWithRelativeValue(float posY)
{
	node->setPositionY(posY * designResolutionSize.height * PosAdjustFactor);
}

// ���þ����豸�ߴ�
void CG_ResolutionAdapter::setRealPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX, posY);
}

void CG_ResolutionAdapter::setRealPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX);
}

void CG_ResolutionAdapter::setRealPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY);
}

// ���÷�������
void CG_ResolutionAdapter::setPosInSquare(float posX, float posY)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH) + 0.5) * BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor;
	float rectPosY = ((int)(posY / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH) + 0.5) * BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor;
	node->setPosition(rectPosX, rectPosY);
}

void CG_ResolutionAdapter::setPosXInSquare(float posX)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH) + 0.5) * BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor;
	node->setPositionX(rectPosX);
}

void CG_ResolutionAdapter::setPosYInSquare(float posY)
{
	float rectPosY = ((int)(posY / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH) + 0.5) * BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor;
	node->setPositionY(rectPosY);
}

// ������Գߴ�
void CG_ResolutionAdapter::setSizeAdp(float scale)
{
	node->setScale(scale * SizeAdjustFactor);
}

// ��ȡ������������
Vec2 CG_ResolutionAdapter::getAdpPosWithAbsoluteValue()
{
	float posX = node->getPositionX() / PosAdjustFactor;
	float posY = node->getPositionY() / PosAdjustFactor;
	return Vec2(posX, posY);
}

float CG_ResolutionAdapter::getAdpPosXWithAbsoluteValue()
{
	return node->getPositionX() / PosAdjustFactor;
}

float CG_ResolutionAdapter::getAdpPosYWithAbsoluteValue()
{
	return node->getPositionY() / PosAdjustFactor;
}

// ��ȡ�����������
Vec2 CG_ResolutionAdapter::getAdpPosWithRelativeValue()
{
	float posX = node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
	float posY = node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
	return Vec2(posX, posY);
}

float CG_ResolutionAdapter::getAdpPosXWithRelativeValue()
{
	return node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
}

float CG_ResolutionAdapter::getAdpPosYWithRelativeValue()
{
	return node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
}

// ��ȡ�����豸�ߴ�
Vec2 CG_ResolutionAdapter::getRealPosWithAbsoluteValue()
{
	return node->getPosition();
}

float CG_ResolutionAdapter::getRealPosXWithAbsoluteValue()
{
	return node->getPositionX();
}

float CG_ResolutionAdapter::getRealPosYWithAbsoluteValue()
{
	return node->getPositionY();
}

// ��ȡ��������
Vec2 CG_ResolutionAdapter::getPosInSquare()
{
	int PosXInSquare = node->getPositionX() / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH;
	int PosYInSquare = node->getPositionY() / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH;
	return Vec2(PosXInSquare, PosYInSquare);
}

int CG_ResolutionAdapter::getPosXInSquare()
{
	int PosXInSquare = node->getPositionX() / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH;
	return PosXInSquare;
}

int CG_ResolutionAdapter::getPosYInSquare()
{
	int PosYInSquare = node->getPositionY() / PosAdjustFactor / BATTLE_FIELD_SQUARE_WIDTH;
	return PosYInSquare;
}