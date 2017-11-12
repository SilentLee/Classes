#include <stdio.h>
#include "CBackground.h"

CBackground* CBackground::createBackground(std::string fileName)
{
	CBackground* ret = new CBackground();
	if (ret && ret->initWithFile(fileName.c_str()))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CBackground::initWithFile(const std::string& filename)
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
	this->setAdpPosWithRelativeValue(0.5, 0.5);

	return true;
}