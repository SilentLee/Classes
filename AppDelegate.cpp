#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SceneBattle.h"
#include "SceneSelect.h"
#include "GlobalInstanceApi.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("TileSkyClnt", cocos2d::Rect(0, 0, debugResolutionSize.width, debugResolutionSize.height));
		glview->setFrameZoomFactor(frameSizeFactor);
#else
        glview = GLViewImpl::create("TileSkyClnt");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

	// 分辨率适配器初始化
	CG_ResolutionAdapter::init();

	// 加载图片资源路径
	CU_ImgLoader::loadImg();

	// 加载卡牌及机载武器参数
	CU_CardLoader::loadCardParams();
	CU_CardLoader::loadAirborneWeaponParams();

	// 连接服务器
	if (!connectServer()) 
		log("连接服务器失败");

	CNetworkInstance* networkInstance = CNetworkInstance::getInstance();
	networkInstance->setNetworkSession(mNetWorkSession);

    register_all_packages();

	// 创建游戏入口场景
    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	//auto scene = SceneDoubleBattle::createScene();
	auto scene = SceneSelect::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

// 服务器连接函数
bool AppDelegate::connectServer()
{
	mNetWorkSession = new CNetworkSession();
	if (!mNetWorkSession->Begin())
		return false;
	return true;
}

