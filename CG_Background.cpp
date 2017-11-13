#include <stdio.h>
#include "CG_Background.h"

CG_Background* CG_Background::create(std::string fileName)
{
	CG_Background* ret = new CG_Background();
	if (ret && ret->initWithFile(fileName.c_str()))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool CG_Background::initWithFile(const std::string& filename)
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