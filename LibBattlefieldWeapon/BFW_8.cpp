#include "BFW_8.h"

BFW_8* BFW_8::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_8* ret = new BFW_8();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_8* BFW_8::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_8* ret = new BFW_8();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_8* BFW_8::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_8* ret = new BFW_8();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_8* BFW_8::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_8* ret = new BFW_8();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_8::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ���뿨��8����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_8);

	// �����ʼ��
	BFW_BasicClass::initWithPosInSquare(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_8::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ���뿨��8����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_8);

	// �����ʼ��
	BFW_BasicClass::initWithAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_8::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ���뿨��8����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_8);

	// �����ʼ��
	BFW_BasicClass::initWithRelativePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_8::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ���뿨��8����
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(CARD_TYPE_8);

	// �����ʼ��
	BFW_BasicClass::initWithRealAbsolutePos(filename, posX, posY, propertyWp);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_8::initPhysicsBody()
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
//void BFW_8::update(float dt)
//{
//	// ���ÿ���8����
//	Vec2 pos = this->getAdpPosWithRelativeValue();
//	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_TYPE_8);
//	this->setRotation(0);
//	return;
//}