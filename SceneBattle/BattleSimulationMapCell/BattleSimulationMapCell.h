#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

// 战场模拟地图方格宽度
#define WIDTH_OF_MAP_CELL			54.0f

// 战场模拟
#define WIDTH_OF_BATTLE_SIMULATION_MAP			20
#define HEIGHT_OF_BATTLE_SIMULATION_MAP		30

#define WIDTH_OF_BATTLE_DISPLAY							1080.0f
#define HEIGHT_OF_BATTLE_DISPLAY							1620.0f

typedef struct _S_HERTZ_WAVE {
	// 电平
	float LEVEL;
	// 发射平台武器标签
	int TAG;
	// 发射方向
	int DIRECTION_FROM;
} S_HERTZ_WAVE;

class CBattleSimulationMapCell : public CG_Sprite
{
private:
	// 地图方格坐标
	Vec2 mCoordinate;
	// 处于当前方格空间中的武器类型
	ENUM_WEAPON_TYPE mWeaponType;
	// 处于当前方格空间中的武器标签
	int mWeaponTag;
	// 蓝方面对的战争迷雾使能
	bool mFogAgainstBlueEn;
	// 红方面对的战争迷雾使能
	bool mFogAgainstRedEn;
	// 充斥于当前方格空间中的电磁波序列
	vector<S_HERTZ_WAVE> mHertzWaveVec;

public:
	// 创建函数
	//static CBattleSimulationMapCell* createWithAbsolutePos(float posX, float posY);
	static CBattleSimulationMapCell* createWithCoordinate(int coordinateX, int coordinateY);
	// 初始化函数
	// 在战场显示坐标系下进行坐标设定 1920 * 1080
	bool initWithAbsolutePos(float posX, float posY);

// 存取函数
public:
	void SetCoordinate(Vec2 coordinate) { mCoordinate = coordinate; };
	Vec2 GetCoordinate() { return mCoordinate; };

	void SetWeaponType(ENUM_WEAPON_TYPE weaponType) { mWeaponType = weaponType; };
	ENUM_WEAPON_TYPE GetWeaponTYpe() { return mWeaponType; };

	void SetWeaponTag(int weaponTag) { mWeaponTag = weaponTag; };
	int GetWeaponTag() { return mWeaponTag; };

	void SetFogAgainstBlueEn(bool fogAgainstBlueEn) { mFogAgainstBlueEn = fogAgainstBlueEn; };
	int GetFogAgainstBlueEn() { return mFogAgainstBlueEn; };

	void SegFogAgainstRedEn(bool fogAgainstRedEn) { mFogAgainstRedEn = fogAgainstRedEn; };
	int GetFogAgainstRedEn() { return mFogAgainstRedEn; };
};