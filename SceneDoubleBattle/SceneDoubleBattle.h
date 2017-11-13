#pragma once

#include "cocos2d.h"
#include "..\Classes\GraphicLib\ApiGraphicLib.h"
#include "..\Classes\Utils\ApiUtils.h"
#include "..\Classes\SceneDoubleBattle\LayerBattleFieldDB.h"
#include "..\Classes\SceneDoubleBattle\LayerTouchDB.h"

class SceneDoubleBattle : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneDoubleBattle);
};
