#include "BFW_AAM.h"

BFW_AAM* BFW_AAM::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_AAM* ret = new BFW_AAM();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AAM* BFW_AAM::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_AAM* ret = new BFW_AAM();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AAM* BFW_AAM::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_AAM* ret = new BFW_AAM();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AAM* BFW_AAM::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_AAM* ret = new BFW_AAM();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_AAM::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ����տյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(WP_TYPE_AAM);

	// �����ʼ��
	BFW_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	// ����λ�ó�ʼ��
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_AAM::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ����տյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(WP_TYPE_AAM);

	// �����ʼ��
	BFW_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	// ����λ�ó�ʼ��
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_AAM::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ����տյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(WP_TYPE_AAM);

	// �����ʼ��
	BFW_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	// ����λ�ó�ʼ��
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

bool BFW_AAM::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ����տյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getAirborneWeaponParams(WP_TYPE_AAM);

	// �����ʼ��
	BFW_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	// ����λ�ó�ʼ��
	mFirePosition = Vec2(this->getAdpPosXWithAbsoluteValue(), this->getAdpPosYWithAbsoluteValue());

	initPhysicsBody();

	return true;
}

void BFW_AAM::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_FIGHTER_PLANE); // �趨�����������
	body->setCollisionBitmask(BIT_MASK_COLLISION_FIGHTER_PLANE); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_FIGHTER_PLANE); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}

//// ���Ⱥ���
//void BFW_AAM::update(float dt)
//{
//	// ����ս��������
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_AAM);
//	this->setRotation(0);
//	return;
//}

// ��ȡ����λ��
Vec2 BFW_AAM::getFirePosition()
{
	return mFirePosition;
}

int BFW_AAM::getFirePositionX()
{
	return mFirePosition.x;
}

int BFW_AAM::getFirePositionY()
{
	return mFirePosition.y;
}