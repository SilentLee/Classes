#include "LayerSelectButton.h"
#include "CU_ImgLoader.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace std;

LayerSelectButton* LayerSelectButton::create()
{
	LayerSelectButton* ret = new LayerSelectButton();
	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerSelectButton::init()
{
	LayerEx::init();

	// 添加对战按钮
	Button* BtnStart = Button::create(CU_ImgLoader::getImg(IMG_URL_BTN_START).c_str());
	BtnStart->setPosition(Vec2(540, 960));
	BtnStart->addClickEventListener(CC_CALLBACK_0(LayerSelectButton::BtnStartCallback, this, RM_TYPE_1V1));
	this->addChild(BtnStart);

	this->schedule(schedule_selector(LayerSelectButton::UpdateToBattle), 1 / 60);

	return true;
}