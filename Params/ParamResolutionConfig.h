#pragma once

#include "cocos2d.h"

// 游戏调试分辨率
static cocos2d::Size debugResolutionSize = cocos2d::Size(270, 480);
// 游戏设计分辨率
static cocos2d::Size designResolutionSize = cocos2d::Size(1080, 1920);

// Windows调试使用的缩放因子
static float frameSizeFactor = 1.5f;

// 二人死斗 战场方格幅度
#define SQUARE_WIDTH_DOUBLE_BATTLE				54