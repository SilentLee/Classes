#include "BattleFieldWeapon_OPPO.h"

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithPosInSquare(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithPosInSquare(fileName.c_str(), posX, posY, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

BattleFieldWeapon_OPPO* BattleFieldWeapon_OPPO::createWithAbsolutePos(std::string fileName, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	BattleFieldWeapon_OPPO* ret = new BattleFieldWeapon_OPPO();
	if (ret && ret->initWithAbsolutePos(fileName.c_str(), posX, posY, weaponType))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������
bool BattleFieldWeapon_OPPO::initWithPosInSquare(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	// ���뿨�Ʋ���
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);

	// �����ʼ��
	CG_Sprite::initWithPosInSquare(filename, posX, posY);
	this->setPosInSquare(posX, posY);
	setPropertyWp(propertyWp);

	// ��ʼ����������
	initPhysicsBody();

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

bool BattleFieldWeapon_OPPO::initWithAbsolutePos(const std::string& filename, int posX, int posY, ENUM_WEAPON_TYPE weaponType)
{
	// ���뿨�Ʋ���
	PROPERTY_WP propertyWp = CU_CardLoader::getCardParam(weaponType);

	// �����ʼ��
	CG_Sprite::initWithAbsolutePos(filename, posX, posY);
	setPropertyWp(propertyWp);

	// ��ʼ����������
	initPhysicsBody();

	// ����ʱ���� update ��Ч
	// �ڽ��յ�������������Ϣ�Ĵ������н� update ����Ϊ��Ч
	this->unscheduleUpdate();

	return true;
}

// ��ʼ���������Բ���
void BattleFieldWeapon_OPPO::initPhysicsBody()
{
	//auto body = PhysicsBody::createCircle(this->getContentSize().width / 2);
	auto body = PhysicsBody::createBox(this->getContentSize());
	//body->setGravityEnable(false);

	body->setCategoryBitmask(BIT_MASK_CATEGORY_FIGHTER_PLANE); // �趨�����������
	body->setCollisionBitmask(BIT_MASK_COLLISION_FIGHTER_PLANE); // �趨��ײ���� ִ����ײ��Ӧ
	body->setContactTestBitmask(BIT_MASK_CONTACT_TEST_FIGHTER_PLANE); // �趨�Ӵ����� ִ����ײ�¼�
	this->setPhysicsBody(body);
}

// ��ȡս������
Vec2 BattleFieldWeapon_OPPO::getCoordinateInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF;
}

float BattleFieldWeapon_OPPO::getCoordinateXInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.x;
}

float BattleFieldWeapon_OPPO::getCoordinateYInBF()
{
	// ˢ��ս������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	pos.add(Vec2(0, -3 * BATTLE_FIELD_SQUARE_WIDTH));
	int mCoordinateXInBF = pos.x / BATTLE_FIELD_SQUARE_WIDTH;
	int mCoordinateYInBF = pos.y / BATTLE_FIELD_SQUARE_WIDTH;
	mCoordinateInBF = Vec2(mCoordinateXInBF, mCoordinateYInBF);

	return mCoordinateInBF.y;
}

// ���÷�������
void BattleFieldWeapon_OPPO::setPosInSquare(float posX, float posY)
{
	// ��ȡȫ����Ļ��������
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// ���������������������Ļ�ײ������� 3 �� 5 ������֮��
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 3), BATTLE_FIELD_SQUARE_WIDTH * PosAdjustFactor * 5);
	
	// ��������ɵ�������
	CG_ResolutionAdapter::setPosInSquare(posX, posY);
}

void BattleFieldWeapon_OPPO::setPosXInSquare(float posX)
{
	CG_ResolutionAdapter::setPosXInSquare(posX);
}

void BattleFieldWeapon_OPPO::setPosYInSquare(float posY)
{
	float PosAdjustFactor = CG_ResolutionAdapter::getPosAdjustFactor();

	// ���������������������Ļ�ײ������� 3 �� 5 ������֮��
	posY = min(max(posY, BATTLE_FIELD_SQUARE_WIDTH * 3), BATTLE_FIELD_SQUARE_WIDTH * 5);

	// ��������ɵ�������
	CG_ResolutionAdapter::setPosYInSquare(posY);
}

// ������������
void BattleFieldWeapon_OPPO::setPropertyWp(PROPERTY_WP propertyWp)
{
	memcpy(&mPropertyWp, &propertyWp, sizeof(PROPERTY_WP));
}
// ��ȡ��������
PROPERTY_WP BattleFieldWeapon_OPPO::getPropertyWp()
{
	return mPropertyWp;
}

// ���º���
void BattleFieldWeapon_OPPO::update(float dt)
{
	// ���·���λ��
	//Vec2 pos = this->getAdpPosWithRelativeValue();
	//this->setAdpPosWithRelativeValue(pos.x, pos.y - mPropertyWp.SPEED);

	// ���·���λ��
	// �˴�ʹ�þ�������
	Vec2 pos = this->getAdpPosWithAbsoluteValue();
	this->setAdpPosWithAbsoluteValue(pos.x, pos.y - mPropertyWp.SPEED);

	this->setRotation(0);

	log("CoordinateX = %d, CoordinateY = %d", (int)this->getCoordinateXInBF(), (int)this->getCoordinateYInBF());

	return;
}