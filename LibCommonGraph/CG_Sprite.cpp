#include "CG_Sprite.h"

CG_Sprite* CG_Sprite::createWithAbsolutePos(std::string fileName, int posX, int posY)
{
	CG_Sprite* ret = new CG_Sprite();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CG_Sprite* CG_Sprite::createWithRelativePos(std::string fileName, float posX, float posY)
{
	CG_Sprite* ret = new CG_Sprite();
	if (ret && ret->initWithRelativePos(fileName, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CG_Sprite* CG_Sprite::createWithRealAbsolutePos(std::string fileName, int posX, int posY)
{
	CG_Sprite* ret = new CG_Sprite();
	if (ret && ret->initWithRealAbsolutePos(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

CG_Sprite* CG_Sprite::createWithPosInSquare(std::string fileName, int posX, int posY)
{
	CG_Sprite* ret = new CG_Sprite();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CG_Sprite::initWithAbsolutePos(const std::string& filename, int posX, int posY)
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

	return true;
}

bool CG_Sprite::initWithRelativePos(const std::string& filename, float posX, float posY)
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
bool CG_Sprite::initWithRealAbsolutePos(const std::string& filename, int posX, int posY)
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

	return true;
}

bool CG_Sprite::initWithPosInSquare(const std::string& filename, int posX, int posY)
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

	return true;
}