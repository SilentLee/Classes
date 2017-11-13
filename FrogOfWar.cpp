#include "FrogOfWar.h"

FrogOfWar* FrogOfWar::createFrogOfWarWithAbsolutePos(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithRelativePos(std::string fileName, float posX, float posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

FrogOfWar* FrogOfWar::createFrogOfWarWithPosInSquare(std::string fileName, int posX, int posY)
{
	FrogOfWar* ret = new FrogOfWar();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool FrogOfWar::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	CSprite::initWithAbsolutePos(filename, posX, posY);

	// ��ʼ����������
	initPhysicsBody();

	return true;
}

bool FrogOfWar::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	CSprite::initWithRelativePos(filename, posX, posY);

	// ��ʼ����������
	initPhysicsBody();

	return true;
}

bool FrogOfWar::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	CSprite::initWithRealAbsolutePos(filename, posX, posY);

	// ��ʼ����������
	initPhysicsBody();

	return true;
}

bool FrogOfWar::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	CSprite::initWithPosInSquare(filename, posX, posY);

	return true;
}

void FrogOfWar::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(0x0001); // �趨�����������
	body->setCollisionBitmask(0x0001); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(0x0011); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}