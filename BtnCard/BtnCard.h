#pragma once
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "LibCommonUtilsApi.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace std;

class BtnCard : public Button
{
// ��������
private:
	int mCardType;

public:
	// ��������
	static BtnCard* create(ENUM_CARD_TYPE cardType, float posX, float posY);
	// ��ʼ������
	bool init(ENUM_CARD_TYPE cardType, float posX, float posY);
	// �ɿ���ť�Ļص�����
	virtual void onPressStateChangedToNormal();
	// ���°�ť�Ļص�����
	virtual void onPressStateChangedToPressed();
	// ���ð�ťͼƬ
	void setButtonImage(std::string filename);

// ��ȡ����
public:
	void setCardType(int cardType) { mCardType = cardType; };
	int getCardType() { return mCardType; };
};
