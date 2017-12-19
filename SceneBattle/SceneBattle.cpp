#include "SceneBattle.h"
#include "SimpleAudioEngine.h"
#include "LayerBattleBackground.h"
#include "LayerBattleButton.h"

USING_NS_CC;

Scene* SceneBattle::createScene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* phyWorld = scene->getPhysicsWorld();
	phyWorld->setGravity(Vec2(0, 0));
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float factor = visibleSize.width / designResolutionSize.width;

	// 创建场景背景
	LayerBattleBackground* layerBattleBackground = LayerBattleBackground::create();
	scene->addChild(layerBattleBackground);

	// 创建按钮层
	LayerBattleButton* layerBattleButton = LayerBattleButton::create();
	scene->addChild(layerBattleButton, 1, "layerBattleButton");

	// 创建仿真层
	//LayerBattleSimulation* layerBattleSimulation = LayerBattleSimulation::create();
	//layerBattleSimulation->setPosition(0, 54 * 4 * factor);
	//scene->addChild(layerBattleSimulation, 2, "layerBattleSimulation");

	// 创建显示层
	LayerBattleSituation* layerBattleSituation = LayerBattleSituation::create();
	layerBattleSituation->setPosition(0, 54 * 4 * factor);
	scene->addChild(layerBattleSituation, 3, "layerBattleSituation");

	// 创建触控层
	LayerBattleTouch* layerBattleTouch = LayerBattleTouch::create();
	layerBattleTouch->setPosition(0, 54 * 4 * factor);
	scene->addChild(layerBattleTouch, 4, "layerTouchDB");

	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SceneBattle::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }	

    return true;
}
