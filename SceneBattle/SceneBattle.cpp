#include "SceneBattle.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SceneBattle::createScene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* phyWorld = scene->getPhysicsWorld();
	phyWorld->setGravity(Vec2(0, 0));

	// 创建场景背景
	CG_Background* bgDoubleBattleScene = CG_Background::create(CU_ImgLoader::getImg(IMG_URL_DB_SCENE_BG).c_str());
	scene->addChild(bgDoubleBattleScene);

	// 创建仿真层
	LayerBattleSimulation* layerBattleSimulation = LayerBattleSimulation::create();
	scene->addChild(layerBattleSimulation, 1, "layerBattleSimulation");
	

	// 创建显示层
	LayerBattleDisplay* layerBattleDisplay = LayerBattleDisplay::create();
	scene->addChild(layerBattleDisplay, 2, "layerBattleDisplay");

	// 创建触控层
	LayerBattleTouch* layerBattleTouch = LayerBattleTouch::create();
	scene->addChild(layerBattleTouch, 3, "layerTouchDB");

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
