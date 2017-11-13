#include "BFW_BombingPlane.h"

BFW_BombingPlane* BFW_BombingPlane::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	BFW_BombingPlane* ret = new BFW_BombingPlane();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BombingPlane* BFW_BombingPlane::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_BombingPlane* ret = new BFW_BombingPlane();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BombingPlane* BFW_BombingPlane::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	BFW_BombingPlane* ret = new BFW_BombingPlane();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BFW_BombingPlane* BFW_BombingPlane::createWithRelativePos(std::string fileName, float posX, float posY)
{
	BFW_BombingPlane* ret = new BFW_BombingPlane();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BFW_BombingPlane::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithPosInSquare(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BombingPlane::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BombingPlane::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// �����ʼ��
	CG_Sprite::initWithRelativePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BFW_BombingPlane::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CG_Sprite::initWithRealAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void BFW_BombingPlane::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(0x0001); // �趨�����������
	body->setCollisionBitmask(0x0001); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(0x0011); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}

// ���Ⱥ���
void BFW_BombingPlane::update(float dt)
{
	Vec2 pos = this->getAdpPosWithRelativeValue();
	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_BOMBING_PLANE);
	this->setRotation(0);
	return;
}