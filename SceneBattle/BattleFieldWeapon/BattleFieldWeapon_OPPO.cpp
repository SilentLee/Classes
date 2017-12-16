#include "BattleFieldWeapon_OPPO.h"

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithCoordinate(fileName.c_str(), coordinate, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithPosition(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BattleFieldWeapon_OPPO::initWithCoordinate(std::string fileName, Vec2 coordinate, ENUM_WEAPON_TYPE weaponType)
{
	// �����ʼ��
	Sprite::initWithFile(fileName);
	// ����ê��Ϊ Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// �� ս��̬�Ʒ����ͼ���� ת��Ϊ ս��̬����ʾ��ͼ����
	float posX = (coordinate.x + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (coordinate.y + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	// ����������ս��̬����ʾ��ͼ�е�λ��
	this->setPosition(posX, posY);

	// ������������
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);
	SetPropertyWp(propertyWp);
	// ����λ�ò���
	mCoordinate = coordinate;

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BattleFieldWeapon_OPPO::initWithPosition(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	// �����ʼ��
	Sprite::initWithFile(fileName);
	// ����ê��Ϊ Vec2::ANCHOR_MIDDLE
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);

	// �� ս��̬����ʾ��ͼ���� �� ս��̬�Ʒ����ͼ���� ����
	mCoordinate.x = (int)position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	mCoordinate.y = (int)position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	float posX = (mCoordinate.x + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	float posY = (mCoordinate.y + 0.5) * WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

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

// ���º���
void BattleFieldWeapon_OPPO::update(float dt)
{
	// ����ս��̬����ʾ��ͼ����
	Vec2 position = this->getPosition();
	this->setPosition(position.x, position.y - mPropertyWp.SPEED);

	// ����ս��̬�Ʒ����ͼ����
	mCoordinate.x = (int)position.x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	mCoordinate.y = (int)position.y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}