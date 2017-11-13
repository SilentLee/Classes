#include "ResolutionAdapter.h"

ResolutionAdapter::ResolutionAdapter()
{
	node = NULL;
}

ResolutionAdapter::~ResolutionAdapter()
{
	node = NULL;
}

void ResolutionAdapter::init()
{
	auto director = Director::getInstance();
	VisibleSize = director->getVisibleSize();

	SizeAdjustFactor = VisibleSize.width / designResolutionSize.width;
	PosAdjustFactor = VisibleSize.width / designResolutionSize.width;

	log("�ֱ�����������ʼ���ɹ�");
}

// �ߴ�ת��
void ResolutionAdapter::sizeAdp()
{
	node->setScale(SizeAdjustFactor);
}

// ���þ�������
void ResolutionAdapter::setAdpPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX * PosAdjustFactor, posY * PosAdjustFactor);
}

void ResolutionAdapter::setAdpPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX * PosAdjustFactor);
}

void ResolutionAdapter::setAdpPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY * PosAdjustFactor);
}

// �����������
void ResolutionAdapter::setAdpPosWithRelativeValue(float posX, float posY)
{
	node->setPosition(posX * designResolutionSize.width * PosAdjustFactor, posY * designResolutionSize.height * PosAdjustFactor);
}

void ResolutionAdapter::setAdpPosXWithRelativeValue(float posX)
{
	node->setPositionX(posX * designResolutionSize.width * PosAdjustFactor);
}

void ResolutionAdapter::setAdpPosYWithRelativeValue(float posY)
{
	node->setPositionY(posY * designResolutionSize.height * PosAdjustFactor);
}

// ���þ����豸�ߴ�
void ResolutionAdapter::setRealPosWithAbsoluteValue(int posX, int posY)
{
	node->setPosition(posX, posY);
}

void ResolutionAdapter::setRealPosXWithAbsoluteValue(int posX)
{
	node->setPositionX(posX);
}

void ResolutionAdapter::setRealPosYWithAbsoluteValue(int posY)
{
	node->setPositionY(posY);
}

// ���÷�������
void ResolutionAdapter::setPosInSquare(float posX, float posY)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	float rectPosY = ((int)(posY / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPosition(rectPosX, rectPosY);
}

void ResolutionAdapter::setPosXInSquare(float posX)
{
	float rectPosX = ((int)(posX / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPositionX(rectPosX);
}

void ResolutionAdapter::setPosYInSquare(float posY)
{
	float rectPosY = ((int)(posY / PosAdjustFactor / SQUARE_WIDTH_DOUBLE_BATTLE)) * SQUARE_WIDTH_DOUBLE_BATTLE * PosAdjustFactor;
	node->setPositionY(rectPosY);
}

// ������Գߴ�
void ResolutionAdapter::setSizeAdp(float scale)
{
	node->setScale(scale * SizeAdjustFactor);
}

// ��ȡ������������
Vec2 ResolutionAdapter::getAdpPosWithAbsoluteValue()
{
	float posX = node->getPositionX() / PosAdjustFactor;
	float posY = node->getPositionY() / PosAdjustFactor;
	return Vec2(posX, posY);
}

float ResolutionAdapter::getAdpPosXWithAbsoluteValue()
{
	return node->getPositionX() / PosAdjustFactor;
}

float ResolutionAdapter::getAdpPosYWithAbsoluteValue()
{
	return node->getPositionY() / PosAdjustFactor;
}

// ��ȡ�����������
Vec2 ResolutionAdapter::getAdpPosWithRelativeValue()
{
	float posX = node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
	float posY = node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
	return Vec2(posX, posY);
}

float ResolutionAdapter::getAdpPosXWithRelativeValue()
{
	return node->getPositionX() / designResolutionSize.width / PosAdjustFactor;
}

float ResolutionAdapter::getAdpPosYWithRelativeValue()
{
	return node->getPositionY() / designResolutionSize.height / PosAdjustFactor;
}

// ��ȡ�����豸�ߴ�
Vec2 ResolutionAdapter::getRealPosWithAbsoluteValue()
{
	return node->getPosition();
}

float ResolutionAdapter::getRealPosXWithAbsoluteValue()
{
	return node->getPositionX();
}

float ResolutionAdapter::getRealPosYWithAbsoluteValue()
{
	return node->getPositionY();
}

//// ��ȡ��������
//Vec2 ResolutionAdapter::getRectPos()
//{
//
//}
//
//int ResolutionAdapter::getRectPosX()
//{
//
//}
//
//int ResolutionAdapter::getRectPosY()
//{
//
//}