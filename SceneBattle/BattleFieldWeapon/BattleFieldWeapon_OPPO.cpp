#include "BattleFieldWeapon_OPPO.h"

// �������� ʹ�ñ��ز�������
BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithLocalOperationData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
// �������� ʹ�÷�������������
BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithRecvServerData(fileName.c_str(), position, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������ ʹ�ñ��ز�������
bool BattleFieldWeapon_OPPO::initWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
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

	// ��ʼ��ս��̬�Ʒ����ͼ�е�������С
	initWeaponSize();

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

// ��ʼ������ ʹ�÷�������������
bool BattleFieldWeapon_OPPO::initWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType)
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

	// ��ʼ��ս��̬�Ʒ����ͼ�е�������С
	initWeaponSize();

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}


// ��ʼ��������ս��̬�Ʒ����ͼ�еĳߴ�
void BattleFieldWeapon_OPPO::initWeaponSize()
{
	Size weaponSize = this->getContentSize();

	int weaponSizeWidth = weaponSize.width / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int weaponSizeHeight = weaponSize.height / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	mWeaponSize = Size(weaponSizeWidth, weaponSizeHeight);
}

// ���º���
void BattleFieldWeapon_OPPO::update(float dt)
{
	// ����ս��̬����ʾ��ͼ����
	float posX = this->getPositionX();
	float posY = this->getPositionY();
	posY = max(0.0f, posY - mPropertyWp.SPEED);
	this->setRotation(0);

	this->setPosition(Vec2(posX, posY));

	log("CoordinateX = %d, CoordinateY = %d", (int)this->GetCoordinate().x, (int)this->GetCoordinate().y);

	return;
}

// ��ȡս��̬�Ʒ����ͼ����
Vec2 BattleFieldWeapon_OPPO::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}

// ��ȡ������ս��̬�Ʒ����ͼ�еĴ�С
Size BattleFieldWeapon_OPPO::GetWeaponSize()
{
	return mWeaponSize;
}