#include "BFW_BasicClass.h"

BFW_BasicClass* BFW_BasicClass::createWithPosInSquare(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_BasicClass* ret = new BFW_BasicClass();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BasicClass* BFW_BasicClass::createWithRealAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_BasicClass* ret = new BFW_BasicClass();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BasicClass* BFW_BasicClass::createWithAbsolutePos(std::string fileName, int posX, int posY, PROPERTY_WP propertyWp)
{
	BFW_BasicClass* ret = new BFW_BasicClass();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY, propertyWp))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BasicClass* BFW_BasicClass::createWithRelativePos(std::string fileName, float posX, float posY, PROPERTY_WP propertyWp)
{
	BFW_BasicClass* ret = new BFW_BasicClass();
	if (ret && ret->initWithRelativePos(fileName, posX, posY, propertyWp));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_BasicClass::initWithPosInSquare(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// �����ʼ��
	CG_Sprite::initWithPosInSquare(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BasicClass::initWithAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BasicClass::initWithRelativePos(const std::string& filename, float posX, float posY, PROPERTY_WP propertyWp)
{
	// �����ʼ��
	CG_Sprite::initWithRelativePos(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BasicClass::initWithRealAbsolutePos(const std::string& filename, int posX, int posY, PROPERTY_WP propertyWp)
{
	// �����ʼ��
	CG_Sprite::initWithRealAbsolutePos(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	return true;
}

// ��ȡս������
Vec2 BFW_BasicClass::getCoordinateInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF;
}

float BFW_BasicClass::getCoordinateXInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.x;
}

float BFW_BasicClass::getCoordinateYInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.y;
}

// ���÷�������
void BFW_BasicClass::setPosInSquare(float posX, float posY)
{
	// ��ȡȫ����Ļ��������
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// ���������������������Ļ�ײ������� 3 �� 5 ������֮��
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 3), BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 5);
	
	// ��������ɵ�������
	CG_ResolutionAdapter::setPosInSquare(posX, posY);
}

void BFW_BasicClass::setPosXInSquare(float posX)
{
	CG_ResolutionAdapter::setPosXInSquare(posX);
}

void BFW_BasicClass::setPosYInSquare(float posY)
{
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// ���������������������Ļ�ײ������� 3 �� 5 ������֮��
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * 3), BATTLE_FIELD_SQUARE_WIDTH * 5);

	// ��������ɵ�������
	CG_ResolutionAdapter::setPosYInSquare(posY);
}

// ������������
void BFW_BasicClass::setPropertyWp(PROPERTY_WP propertyWp)
{
	memcpy(&mPropertyWp, &propertyWp, sizeof(PROPERTY_WP));
}
// ��ȡ��������
PROPERTY_WP BFW_BasicClass::getPropertyWp()
{
	return mPropertyWp;
}

// ���º���
void BFW_BasicClass::update(float dt)
{
	// ���·���λ��
	Vec2 pos = this->getAdpPosWithRelativeValue();
	this->setAdpPosWithRelativeValue(pos.x, pos.y + mPropertyWp.SPEED);
	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->getCoordinateXInBF(), (int)this->getCoordinateYInBF());

	return;
}