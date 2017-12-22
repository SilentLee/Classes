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
// 卡牌类型
private:
	int mCardType;

public:
	// 创建函数
	static BtnCard* create(ENUM_CARD_TYPE cardType, float posX, float posY);
	// 初始化函数
	bool init(ENUM_CARD_TYPE cardType, float posX, float posY);
	// 松开按钮的回调函数
	virtual void onPressStateChangedToNormal();
	// 按下按钮的回调函数
	virtual void onPressStateChangedToPressed();
	// 设置按钮图片
	void setButtonImage(std::string filename);

// 存取函数
public:
	void setCardType(int cardType) { mCardType = cardType; };
	int getCardType() { return mCardType; };
};
