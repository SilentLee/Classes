#include "SceneSelect.h"
#include "SimpleAudioEngine.h"
#include "LayerSelectButton.h"
#include "LayerSelectBackground.h"

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
	LayerSelectBackground* layerSelectBackground = LayerSelectBackground::create();
	this->addChild(layerSelectBackground);

	// 创建按钮层
	LayerSelectButton* layerSelectButton = LayerSelectButton::create();
	this->addChild(layerSelectButton);

	return true;
}
