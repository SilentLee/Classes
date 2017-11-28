#include "BFW_OPPO_Radar.h"

BFW_OPPO_Radar* BFW_OPPO_Radar::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_OPPO_Radar* ret = new BFW_OPPO_Radar();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_Radar* BFW_OPPO_Radar::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_Radar* ret = new BFW_OPPO_Radar();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_Radar* BFW_OPPO_Radar::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_Radar* ret = new BFW_OPPO_Radar();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_Radar* BFW_OPPO_Radar::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_OPPO_Radar* ret = new BFW_OPPO_Radar();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_OPPO_Radar::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ������Ż�����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_RADAR);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_Radar::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ������Ż�����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_RADAR);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_Radar::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ������Ż�����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_RADAR);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_Radar::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ������Ż�����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_RADAR);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_OPPO_Radar::initPhysicsBody()
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
//void BFW_Radar::update(float dt)
//{
//	// ���ø��Ż�����
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_RADAR);
//	this->setRotation(0);
//	return;
//}