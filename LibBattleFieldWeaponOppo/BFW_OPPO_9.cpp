#include "BFW_OPPO_9.h"

BFW_OPPO_9* BFW_OPPO_9::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_OPPO_9* ret = new BFW_OPPO_9();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_9* BFW_OPPO_9::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_9* ret = new BFW_OPPO_9();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_9* BFW_OPPO_9::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_OPPO_9* ret = new BFW_OPPO_9();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_OPPO_9* BFW_OPPO_9::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_OPPO_9* ret = new BFW_OPPO_9();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_OPPO_9::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ���뿨��9����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_9);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_9::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ���뿨��9����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_9);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_9::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ���뿨��9����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_9);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_OPPO_9::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ���뿨��9����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_9);

	// �����ʼ��
	BFW_OPPO_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_OPPO_9::initPhysicsBody()
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
//void BFW_9::update(float dt)
//{
//	// ���ÿ���9����
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_TYPE_9);
//	this->setRotation(0);
//	return;
//}