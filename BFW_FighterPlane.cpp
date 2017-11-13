#include "BFW_FighterPlane.h"

BFW_FighterPlane* BFW_FighterPlane::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_FighterPlane* ret = new BFW_FighterPlane();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_FighterPlane* BFW_FighterPlane::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_FighterPlane* ret = new BFW_FighterPlane();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_FighterPlane* BFW_FighterPlane::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_FighterPlane* ret = new BFW_FighterPlane();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_FighterPlane* BFW_FighterPlane::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_FighterPlane* ret = new BFW_FighterPlane();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_FighterPlane::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithPosInSquare(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_FighterPlane::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_FighterPlane::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// �����ʼ��
	CG_Sprite::initWithRelativePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_FighterPlane::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithRealAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_FighterPlane::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_FIGHTER_PLANE); // �趨�����������
	body->setCollisionBitmask(BIT_MASK_COLLISION_FIGHTER_PLANE); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_FIGHTER_PLANE); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}

// ���Ⱥ���
void BFW_FighterPlane::update(float dt)
{
	Vec2 pos = this->getAdpPosWithRelativeValue();
	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_FIGHTER_PLANE);
	this->setRotation(0);
	return;
}