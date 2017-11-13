#pragma once

#include "cocos2d.h"
#include <string>
#include <map>
#include "LibParamApi.h"

using namespace std;
USING_NS_CC;

class CU_ImgLoader
{
public:
	static void loadImg();
	static string getFogImg(int key);
	static string getImg(string key);
	static string getCardImg(int key);
};