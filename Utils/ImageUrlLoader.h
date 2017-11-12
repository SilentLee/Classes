#pragma once

#include "cocos2d.h"
#include <string>
#include <map>
#include "..\Classes\Params\ApiParam.h"

using namespace std;
USING_NS_CC;

class ImageUrlLoader
{
public:
	static void loadImageUrls();
	static string getFogImageUrl(int key);
	static string getImageUrl(string key);
	static string getCardImageUrls(int key);
};