#include "WpFighterPlane.h"

WpFighterPlane* WpFighterPlane::createWpFighterPlaneWithPosInSquare(std::string fileName, int posX, int posY)
{
	WpFighterPlane* ret = new WpFighterPlane();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

WpFighterPlane* WpFighterPlane::createWpFighterPlaneWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	WpFighterPlane* ret = new WpFighterPlane();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

WpFighterPlane* WpFighterPlane::createWpFighterPlaneWithAbsolutePos(std::string fileName, int posX, int posY)
{
	WpFighterPlane* ret = new WpFighterPlane();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

WpFighterPlane* WpFighterPlane::createWpFighterPlaneWithRelativePos(std::string fileName, float posX, float posY)
{
	WpFighterPlane* ret = new WpFighterPlane();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool WpFighterPlane::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CSprite::initWithPosInSquare(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool WpFighterPlane::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CSprite::initWithAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool WpFighterPlane::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// �����ʼ��
	CSprite::initWithRelativePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

bool WpFighterPlane::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// �����ʼ��
	CSprite::initWithRealAbsolutePos(filename, posX, posY);

	initPhysicsBody();

	// ���� update ��Ч
	this->unscheduleUpdate();

	return true;
}

void WpFighterPlane::initPhysicsBody()
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
void WpFighterPlane::update(float dt)
{
	Vec2 pos = this->getAdpPosWithRelativeValue();
	this->setAdpPosWithRelativeValue(pos.x, pos.y + PARAM_SPEED_FIGHTER_PLANE);
	this->setRotation(0);
	return;
}