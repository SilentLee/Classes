#include "SceneSelect.h"
#include "SimpleAudioEngine.h"
#include "LibCommonGraphApi.h"

USING_NS_CC;

Scene* SceneSelect::createScene()
{
	auto scene = SceneSelect::create();

	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SceneSelect::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	// 创建场景背景
	CG_Background* bgSelectScene = CG_Background::create(CU_ImgLoader::getImg(IMG_URL_SELECT_SCENE_BG).c_str());
	this->addChild(bgSelectScene);

	// 添加对战按钮
	CG_Button* BtnStart = CG_Button::createWithRelativePos(CU_ImgLoader::getImg(IMG_URL_BTN_START).c_str(), 0.5, 0.5);
	BtnStart->addClickEventListener(CC_CALLBACK_0(SceneSelect::BtnStartCallback, this));
	this->addChild(BtnStart);

	this->schedule(schedule_selector(SceneSelect::UpdateToBattle), 1 / 60);

	return true;
}
