#pragma once
#include "LibCommonGraphApi.h"
#include "LibCommonUtilsApi.h"
#include "BattleSimulationMapCell.h"

class BattleFieldWeapon_OPPO : public Sprite
{
// ��������
private:
	PROPERTY_WP mPropertyWp;

	// ս������
protected:
	Vec2 mCoordinate;

// ���ɺ���
public:
	// ʹ��ս��̬�Ʒ����ͼ����Ĵ�������
	static BattleFieldWeapon_OPPO* createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	// ʹ�ñ��ز������ݵ�ս��̬����ʾ��ͼλ�õĴ�������
	static BattleFieldWeapon_OPPO* createWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�ý��ܷ��������ݵ�ս��̬����ʾ��ͼλ�õĴ�������
	static BattleFieldWeapon_OPPO* createWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

	// ��ʼ������
public:
	// ʹ��ս��̬�Ʒ����ͼ����ĳ�ʼ������
	bool initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType);
	// ʹ�ñ��ز������ݵ�ս��̬����ʾ��ͼλ�õĳ�ʼ������
	bool initWithLocalOperationPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);
	// ʹ�ý��ܷ��������ݵ�ս��̬����ʾ��ͼλ�õĳ�ʼ������
	bool initWithRecvServerPosData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType);

// ���º���
public:
	virtual void update(float dt);

public:
	// ��ȡս������
	void SetCoordinate(Vec2 coordinate) { mCoordinate = coordinate; };
	Vec2 GetCoordinate() { return mCoordinate; };

	// �������Դ�ȡ����
public:
	void SetPropertyWp(PROPERTY_WP propertyWp) { mPropertyWp = propertyWp; };
	PROPERTY_WP GetPropertyWp() { return mPropertyWp; };
};