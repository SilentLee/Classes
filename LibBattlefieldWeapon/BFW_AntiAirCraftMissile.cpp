#include "BFW_AntiAirCraftMissile.h"

BFW_AntiAirCraftMissile* BFW_AntiAirCraftMissile::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_AntiAirCraftMissile* ret = new BFW_AntiAirCraftMissile();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AntiAirCraftMissile* BFW_AntiAirCraftMissile::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_AntiAirCraftMissile* ret = new BFW_AntiAirCraftMissile();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AntiAirCraftMissile* BFW_AntiAirCraftMissile::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_AntiAirCraftMissile* ret = new BFW_AntiAirCraftMissile();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_AntiAirCraftMissile* BFW_AntiAirCraftMissile::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_AntiAirCraftMissile* ret = new BFW_AntiAirCraftMissile();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_AntiAirCraftMissile::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ����ؿյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_ANTI_AIRCRAFT_MISSILE);

	// �����ʼ��
	BFW_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_AntiAirCraftMissile::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ����ؿյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_ANTI_AIRCRAFT_MISSILE);

	// �����ʼ��
	BFW_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_AntiAirCraftMissile::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ����ؿյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_ANTI_AIRCRAFT_MISSILE);

	// �����ʼ��
	BFW_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_AntiAirCraftMissile::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ����ؿյ�������
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_ANTI_AIRCRAFT_MISSILE);

	// �����ʼ��
	BFW_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_AntiAirCraftMissile::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_BOMBING_PLANE); // �趨�����������
	body->setCollisionBitmask(BIT_MASK_COLLISION_BOMBING_PLANE); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_BOMBING_PLANE); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}

//// ���Ⱥ���
//void BFW_AntiAirCraftMissile::update(float dt)
//{
//	// ���÷ɻ��н�
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_BOMBING_PLANE);
//	this->setRotation(0);
//	return;
//}