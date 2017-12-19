#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"

// ս��ģ���ͼ������
#define WIDTH_OF_BATTLE_SIMULATION_MAP_CELL			27.0f
// ս��̬�Ʒ����ͼ���
#define WIDTH_OF_BATTLE_SIMULATION_MAP							40
// ս��̬�Ʒ����ͼ�߶�
#define HEIGHT_OF_BATTLE_SIMULATION_MAP						60
// ս��̬����ʾ��ͼ���
#define WIDTH_OF_BATTLE_DISPLAY_MAP								1080.0f
// ս��̬����ʾ��ͼ�߶�
#define HEIGHT_OF_BATTLE_DISPLAY_MAP								1620.0f

typedef struct _S_HERTZ_WAVE {
	// ��ƽ
	float LEVEL;
	// ����ƽ̨������ǩ
	int TAG;
	// ���䷽��
	int DIRECTION_FROM;
} S_HERTZ_WAVE;

class CBattleSimulationMapCell : public Sprite
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
	void resetWeaponTag() { mWeaponTag = -1; };

	void SetFogAgainstBlueEn(bool fogAgainstBlueEn) { mFogAgainstBlueEn = fogAgainstBlueEn; };
	int GetFogAgainstBlueEn() { return mFogAgainstBlueEn; };

	void SegFogAgainstRedEn(bool fogAgainstRedEn) { mFogAgainstRedEn = fogAgainstRedEn; };
	int GetFogAgainstRedEn() { return mFogAgainstRedEn; };
};