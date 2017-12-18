#include "BattleFieldWeapon_OWN.h"

// �������� ʹ�ñ��ز�������
BattleFieldWeapon_OWN* BattleFieldWeapon_OWN::createWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OWN* ret = new BattleFieldWeapon_OWN();
	if (ret && ret->initWithLocalOperationData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
// �������� ʹ�÷�������������
BattleFieldWeapon_OWN* BattleFieldWeapon_OWN::createWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OWN* ret = new BattleFieldWeapon_OWN();
	if (ret && ret->initWithRecvServerData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������ ʹ�ñ��ز�������
bool BattleFieldWeapon_OWN::initWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// �����ʼ��
	Sprite::initWithFile(fileName);
	// ����ê��Ϊ Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// ����ս��̬����ʾ����
	float posX = ((int)(position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = ((int)(position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL) + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	// ����������ս��̬����ʾ��ͼ�е�λ��
	this->setPosition(posX, posY);

	// ���ؿ��Ʋ���
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
	SetPropertyWp(propertyWp);

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

// ��ʼ������ ʹ�÷�������������
bool BattleFieldWeapon_OWN::initWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// �����ʼ��
	Sprite::initWithFile(fileName);
	// ����ê��Ϊ Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// ����������ս��̬����ʾ��ͼ�е�λ��
	this->setPosition(position.x, position.y);

	// ���ؿ��Ʋ���
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
	SetPropertyWp(propertyWp);

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

// ���º���
void BattleFieldWeapon_OWN::update(float dt)
{
	// ����ս��̬����ʾ��ͼ����
	Vec2 position = this->getPosition();
	this->setPosition(position.x, position.y + mPropertyWp.SPEED);

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}

Vec2 BattleFieldWeapon_OWN::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}