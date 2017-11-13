#include "CU_ImgLoader.h"

static map<string, string> ImgUrls;
static map<int, string> FogImgUrls;
static map<int, string> CardImgUrls;

void CU_ImgLoader::loadImg()
{
	// 加载云彩图片
	FogImgUrls.insert(make_pair(0, IMG_URL_FOG_0));
	FogImgUrls.insert(make_pair(1, IMG_URL_FOG_1));
	FogImgUrls.insert(make_pair(2, IMG_URL_FOG_2));
	FogImgUrls.insert(make_pair(3, IMG_URL_FOG_3));
	FogImgUrls.insert(make_pair(4, IMG_URL_FOG_4));

	// 加载对战卡牌
	CardImgUrls.insert(make_pair(CARD_TYPE_ANTI_AIRCRAFT_MISSILE, IMG_URL_CARD_ANTI_AIRCRAFT_MISSILE));
	CardImgUrls.insert(make_pair(CARD_TYPE_BOMBING_PLANE, IMG_URL_CARD_BOMBING_PLANE));
	CardImgUrls.insert(make_pair(CARD_TYPE_EARLY_WARNING_PLANE, IMG_URL_CARD_EARLY_WARNING_PLANE));
	CardImgUrls.insert(make_pair(CARD_TYPE_FIGHTER_PLANE, IMG_URL_CARD_FIGHTER_PLANE));
	CardImgUrls.insert(make_pair(CARD_TYPE_FLAK, IMG_URL_CARD_FLAK));
	CardImgUrls.insert(make_pair(CARD_TYPE_JAMMING_PLANE, IMG_URL_CARD_JAMMING_PLANE));
	CardImgUrls.insert(make_pair(CARD_TYPE_RADAR, IMG_URL_CARD_RADAR));
	CardImgUrls.insert(make_pair(CARD_TYPE_8, IMG_URL_CARD_8));
	CardImgUrls.insert(make_pair(CARD_TYPE_9, IMG_URL_CARD_9));
	CardImgUrls.insert(make_pair(CARD_TYPE_10, IMG_URL_CARD_10));
	CardImgUrls.insert(make_pair(CARD_TYPE_11, IMG_URL_CARD_11));

	// 加载对战场景背景
	ImgUrls.insert(make_pair(IMG_URL_DB_SCENE_BG, IMG_URL_DB_SCENE_BG));
	// 加载对战防线
	ImgUrls.insert(make_pair(IMG_URL_DEFENSE_LINE, IMG_URL_DEFENSE_LINE));
	// 加载对战武器图片
	ImgUrls.insert(make_pair(IMG_URL_WEAPON_FIGHTER_PLANE_OWN, IMG_URL_WEAPON_FIGHTER_PLANE_OWN));
	ImgUrls.insert(make_pair(IMG_URL_WEAPON_BOMBING_PLANE_OWN, IMG_URL_WEAPON_BOMBING_PLANE_OWN));
	ImgUrls.insert(make_pair(IMG_URL_WEAPON_FIGHTER_PLANE_OPPO, IMG_URL_WEAPON_FIGHTER_PLANE_OPPO));
	ImgUrls.insert(make_pair(IMG_URL_WEAPON_BOMBING_PLANE_OPPO, IMG_URL_WEAPON_BOMBING_PLANE_OPPO));
}

string CU_ImgLoader::getImg(string key)
{ 
	return ImgUrls.find(key)->second;
}

string CU_ImgLoader::getFogImg(int key)
{ 
	return FogImgUrls.find(key)->second;
}

string CU_ImgLoader::getCardImg(int key)
{
	return CardImgUrls.find(key)->second;
}