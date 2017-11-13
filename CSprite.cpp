#include "CSprite.h"

CSprite* CSprite::createSpriteWithAbsolutePos(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithRelativePos(std::string fileName, float posX, float posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CSprite* CSprite::createSpriteWithPosInSquare(std::string fileName, int posX, int posY)
{
	CSprite* ret = new CSprite();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CSprite::initWithAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	Sprite::initWithFile(filename);

	// ����ê��
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ���ڳߴ�
	this->sizeAdp();
	// ��������
	this->setAdpPosWithAbsoluteValue(posX, posY);

	// �����ʼ��
	return true;
}

bool CSprite::initWithRelativePos(const std::string& filename, float posX, float posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	Sprite::initWithFile(filename);

	// ����ê��
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ���ڳߴ�
	this->sizeAdp();
	// ��������
	this->setAdpPosWithRelativeValue(posX, posY);

	return true;
}
bool CSprite::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	Sprite::initWithFile(filename);

	// ����ê��
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ���ڳߴ�
	this->sizeAdp();
	// ��������
	this->setRealPosWithAbsoluteValue(posX, posY);

	// �����ʼ��
	return true;
}

bool CSprite::initWithPosInSquare(const std::string& filename, int posX, int posY)
{
	// ��������ʼ��
	node = this;

	// �����ʼ��
	Sprite::initWithFile(filename);

	// ����ê��
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// ���ڳߴ�
	this->sizeAdp();
	// ��������
	this->setPosInSquare(posX, posY);

	// �����ʼ��
	return true;
}