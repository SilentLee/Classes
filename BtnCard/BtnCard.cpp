#include "BtnCard.h"

// ��������
BtnCard* BtnCard::create(ENUM_CARD_TYPE cardType, float posX, float posY)
{
	BtnCard* ret = new BtnCard();
	if (ret && ret->init(cardType, posX, posY));
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BtnCard::init(ENUM_CARD_TYPE cardType, float posX, float posY)
{
	// ���ø����ʼ������
	Button::init(CU_ImgLoader::getCardImg(cardType).c_str());
	// ����λ��
	this->setPosition(Vec2(posX, posY));

	return true;
}

// �ɿ���ť�Ļص�����
void BtnCard::onPressStateChangedToNormal()
{
	this->setScale(1.0f);
}

// ���°�ť�Ļص�����
void BtnCard::onPressStateChangedToPressed()
{
	this->setScale(0.8f);
}

// ���ð�ťͼƬ
void BtnCard::setButtonImage(std::string filename)
{
	this->loadTextures(filename, filename, filename);
}