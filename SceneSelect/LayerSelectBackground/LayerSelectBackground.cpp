#include "LayerSelectBackground.h"
#include "CU_ImgLoader.h"

LayerSelectBackground* LayerSelectBackground::create()
{
	LayerSelectBackground* ret = new LayerSelectBackground();

	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerSelectBackground::init()
{
	LayerEx::init();

	Sprite* Background = Sprite::create(CU_ImgLoader::getImg(IMG_URL_SELECT_SCENE_BG).c_str());
	Background->setPosition(Vec2(540, 960));
	this->addChild(Background);

	return true;
}