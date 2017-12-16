#include "LayerBattleBackground.h"
#include "CU_ImgLoader.h"

LayerBattleBackground* LayerBattleBackground::create()
{
	LayerBattleBackground* ret = new LayerBattleBackground();

	if (ret && ret->init()) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool LayerBattleBackground::init()
{
	LayerEx::init();

	Sprite* Background = Sprite::create(CU_ImgLoader::getImg(IMG_URL_DB_SCENE_BG).c_str());
	Background->setPosition(Vec2(540, 960));
	this->addChild(Background);

	return true;
}