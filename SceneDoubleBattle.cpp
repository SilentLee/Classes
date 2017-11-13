#include "SceneDoubleBattle.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SceneDoubleBattle::createScene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* phyWorld = scene->getPhysicsWorld();
	phyWorld->setGravity(Vec2(0, 0));

	// 创建场景背景
	CG_Background* bgDoubleBattleScene = CG_Background::create(CU_ImgLoader::getImg(IMG_URL_DB_SCENE_BG).c_str());
	scene->addChild(bgDoubleBattleScene);

	// 创建对战层
	LayerBattleFieldDB* layerBattleFieldDB = LayerBattleFieldDB::create();
	scene->addChild(layerBattleFieldDB, 1, "layerBattleFieldDB");

	// 创建触控层
	LayerTouchDB* layerTouchDB = LayerTouchDB::create();
	scene->addChild(layerTouchDB, 2, "layerTouchDB");

	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SceneDoubleBattle::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }	

	//// 创建场景背景
	//CBackground* bgDoubleBattleScene = CBackground::createBackground(ImageUrlLoader::getImageUrl(IMAGE_URL_DB_SCENE_BG).c_str());
	//this->addChild(bgDoubleBattleScene);

	//// 创建对战层
	//LayerBattleFieldDB* layerBattleFieldDB = LayerBattleFieldDB::create();
	//this->addChild(layerBattleFieldDB, 1, "layerBattleFieldDB");

	//// 创建触控层
	//LayerTouchDB* layerTouchDB = LayerTouchDB::create();
	//this->addChild(layerTouchDB, 2, "layerTouchDB");

    return true;
}
