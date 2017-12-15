#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

// ս��ģ���ͼ������
#define WIDTH_OF_MAP_CELL			54.0f

// ս��ģ��
#define WIDTH_OF_BATTLE_SIMULATION_MAP			20
#define HEIGHT_OF_BATTLE_SIMULATION_MAP		30

#define WIDTH_OF_BATTLE_DISPLAY							1080.0f
#define HEIGHT_OF_BATTLE_DISPLAY							1620.0f

typedef struct _S_HERTZ_WAVE {
	// ��ƽ
	float LEVEL;
	// ����ƽ̨������ǩ
	int TAG;
	// ���䷽��
	int DIRECTION_FROM;
} S_HERTZ_WAVE;

class CBattleSimulationMapCell : public CG_Sprite
{
private:
	// ��ͼ��������
	Vec2 mCoordinate;
	// ���ڵ�ǰ����ռ��е���������
	ENUM_WEAPON_TYPE mWeaponType;
	// ���ڵ�ǰ����ռ��е�������ǩ
	int mWeaponTag;
	// ������Ե�ս������ʹ��
	bool mFogAgainstBlueEn;
	// �췽��Ե�ս������ʹ��
	bool mFogAgainstRedEn;
	// ����ڵ�ǰ����ռ��еĵ�Ų�����
	vector<S_HERTZ_WAVE> mHertzWaveVec;

public:
	// ��������
	static CBattleSimulationMapCell* createWithCoordinate(int coordinateX, int coordinateY);
	// ��ʼ������
	// ��ս����ʾ����ϵ�½��������趨 1920 * 1080
	bool initWithCoordinate(int coordinateX, int coordinateY);

// ��ȡ����
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