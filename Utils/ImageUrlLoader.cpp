#include "ImageUrlLoader.h"

static map<string, string> ImageUrls;
static map<int, string> FogImageUrls;
static map<int, string> CardImageUrls;

void ImageUrlLoader::loadImageUrls()
{
	// 加载云彩图片
	FogImageUrls.insert(make_pair(0, IMAGE_URL_FOG_0));
	FogImageUrls.insert(make_pair(1, IMAGE_URL_FOG_1));
	FogImageUrls.insert(make_pair(2, IMAGE_URL_FOG_2));
	FogImageUrls.insert(make_pair(3, IMAGE_URL_FOG_3));
	FogImageUrls.insert(make_pair(4, IMAGE_URL_FOG_4));

	// 加载对战卡牌
	CardImageUrls.insert(make_pair(CARD_TYPE_ANTI_AIRCRAFT_MISSILE, IMAGE_URL_CARD_ANTI_AIRCRAFT_MISSILE));
	CardImageUrls.insert(make_pair(CARD_TYPE_BOMBING_PLANE, IMAGE_URL_CARD_BOMBING_PLANE));
	CardImageUrls.insert(make_pair(CARD_TYPE_EARLY_WARNING_PLANE, IMAGE_URL_CARD_EARLY_WARNING_PLANE));
	CardImageUrls.insert(make_pair(CARD_TYPE_FIGHTER_PLANE, IMAGE_URL_CARD_FIGHTER_PLANE));
	CardImageUrls.insert(make_pair(CARD_TYPE_FLAK, IMAGE_URL_CARD_FLAK));
	CardImageUrls.insert(make_pair(CARD_TYPE_JAMMING_PLANE, IMAGE_URL_CARD_JAMMING_PLANE));
	CardImageUrls.insert(make_pair(CARD_TYPE_RADAR, IMAGE_URL_CARD_RADAR));
	CardImageUrls.insert(make_pair(CARD_TYPE_8, IMAGE_URL_CARD_8));
	CardImageUrls.insert(make_pair(CARD_TYPE_9, IMAGE_URL_CARD_9));
	CardImageUrls.insert(make_pair(CARD_TYPE_10, IMAGE_URL_CARD_10));
	CardImageUrls.insert(make_pair(CARD_TYPE_11, IMAGE_URL_CARD_11));

	// 加载对战场景背景
	ImageUrls.insert(make_pair(IMAGE_URL_DB_SCENE_BG, IMAGE_URL_DB_SCENE_BG));
	// 加载对战防线
	ImageUrls.insert(make_pair(IMAGE_URL_DEFENSE_LINE, IMAGE_URL_DEFENSE_LINE));
	// 加载对战武器图片
	ImageUrls.insert(make_pair(IMAGE_URL_WEAPON_FIGHTER_PLANE_OWN, IMAGE_URL_WEAPON_FIGHTER_PLANE_OWN));
	ImageUrls.insert(make_pair(IMAGE_URL_WEAPON_BOMBING_PLANE_OWN, IMAGE_URL_WEAPON_BOMBING_PLANE_OWN));
	ImageUrls.insert(make_pair(IMAGE_URL_WEAPON_FIGHTER_PLANE_OPPO, IMAGE_URL_WEAPON_FIGHTER_PLANE_OPPO));
	ImageUrls.insert(make_pair(IMAGE_URL_WEAPON_BOMBING_PLANE_OPPO, IMAGE_URL_WEAPON_BOMBING_PLANE_OPPO));
}

string ImageUrlLoader::getImageUrl(string key)
{ 
	return ImageUrls.find(key)->second; 
}

string ImageUrlLoader::getFogImageUrl(int key)
{ 
	return FogImageUrls.find(key)->second;
}

string ImageUrlLoader::getCardImageUrls(int key)
{
	return CardImageUrls.find(key)->second;
}