#include "BattleFieldWeapon.h"

// �������� ʹ�ñ��ز�������
BattleFieldWeapon* BattleFieldWeapon::createWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
{
	BattleFieldWeapon* ret = new BattleFieldWeapon();
	if (ret && ret->initWithLocalOperationData(fileName.c_str(), position, weaponType, IFF))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
// �������� ʹ�÷�������������
BattleFieldWeapon* BattleFieldWeapon::createWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
{
	BattleFieldWeapon* ret = new BattleFieldWeapon();
	if (ret && ret->initWithRecvServerData(fileName.c_str(), position, weaponType, IFF))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

// ��ʼ������ ʹ�ñ��ز�������
bool BattleFieldWeapon::initWithLocalOperationData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
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
	initSizeInSimulationMap();

	// �趨����
	mIFF = IFF;

	return true;
}

// ��ʼ������ ʹ�÷�������������
bool BattleFieldWeapon::initWithRecvServerData(std::string fileName, Vec2 position, ENUM_WEAPON_TYPE weaponType, ENUM_IFF IFF)
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
	initSizeInSimulationMap();

	// �趨����ʶ��
	mIFF = IFF;

	return true;
}

// ����������ս��̬�Ʒ����ͼ�еĳߴ�
void BattleFieldWeapon::initSizeInSimulationMap()
{
	Size weaponSize = this->getContentSize();

	int weaponSizeWidth = weaponSize.width / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int weaponSizeHeight = weaponSize.height / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	mSizeInSimulationMap = Size(weaponSizeWidth, weaponSizeHeight);
}

// ��ȡս��̬�Ʒ����ͼ����
Vec2 BattleFieldWeapon::GetCoordinate()
{
	int coordinateX = this->getPosition().x / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;
	int coordinateY = this->getPosition().y / WIDTH_OF_BATTLE_SIMULATION_MAP_CELL;

	return Vec2(coordinateX, coordinateY);
}

// ��ȡ������ս��̬�Ʒ����ͼ�еĴ�С
Size BattleFieldWeapon::GetSizeInSimulationMap()
{
	return mSizeInSimulationMap;
}

// ��Ϊ����
// �ƶ�����
void BattleFieldWeapon::Move(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// ��ȡ������ս��̬�Ʒ����ͼ�е�����
	Vec2 Coordinate = this->GetCoordinate();
	// ���õ�ͼ�����е�������ǩ
	BattleSimulationMapCellArray[(int)Coordinate.x][(int)Coordinate.y]->resetWeaponTag();

	// ��ȡ��ǰս��̬����ʾ����
	float posX = this->getPositionX();
	float posY = this->getPositionY();

	// �жϵ�ǰ������������ �����ƶ����ս��̬����ʾ����
	if (mIFF == IFF_FRIEND) {
		// �������ڱ��� ����Ļ�·����Ϸ����� �����Խ�� HEIGHT_OF_BATTLE_DISPLAY_MAP
		posY = min(HEIGHT_OF_BATTLE_DISPLAY_MAP, posY + mPropertyWp.SPEED);
	}
	else if (mIFF == IFF_FOE) {
		// �������ڶԷ� ����Ļ�Ϸ����·����� ��С����Խ�� 0
		posY = max(0.0f, posY - mPropertyWp.SPEED);
	}

	// �����ƶ����ս��̬����ʾ����
	this->setPosition(Vec2(posX, posY));
	// �ƶ����ٴζ�ȡ������ս��̬�Ʒ����ͼ�е�����
	Coordinate = this->GetCoordinate();
	// ����ս��̬�Ʒ����ͼ�ж�Ӧ�ķ��������������ǩ
	BattleSimulationMapCellArray[(int)Coordinate.x][(int)Coordinate.y]->SetWeaponTag(this->getTag());
}
// ̽�⺯��
void BattleFieldWeapon::Detect(CBattleSimulationMapCell* (&BattleSimulationMapCellArray)[WIDTH_OF_BATTLE_SIMULATION_MAP][HEIGHT_OF_BATTLE_SIMULATION_MAP])
{
	// ��ȡս��̬�Ʒ�������
	Vec2 Coordinate = this->GetCoordinate();
	int DetectDistance = mPropertyWp.RANGE_DEC;
	// ����̽�ⷶΧ
	int BorderlineLeft = Coordinate.x - mSizeInSimulationMap.width / 2 - mPropertyWp.RANGE_DEC;
	int BorderlineRight = Coordinate.x + mSizeInSimulationMap.width / 2 + mPropertyWp.RANGE_DEC;
	int BorderlineBottom = Coordinate.y - mSizeInSimulationMap.height / 2 - mPropertyWp.RANGE_DEC;
	int BorderlineTop = Coordinate.y + mSizeInSimulationMap.height / 2 + mPropertyWp.RANGE_DEC;

	// ����ս��̬�Ʒ����ͼ�д���̽�������е�ÿһ����
	for (int indexX = BorderlineLeft; indexX <= BorderlineRight; indexX++) {
		for (int indexY = BorderlineBottom; indexY <= BorderlineTop; indexY++) {
			// ��ǰ��������ս��̬�Ʒ����ͼ�е�����
			int mapCellX = indexX;
			int mapCellY = indexY;
			// ��̽����������ĵ�������ս��̬�Ʒ����ͼ��Χ��
			mapCellX = max(0, min(indexX, WIDTH_OF_BATTLE_SIMULATION_MAP - 1));
			mapCellY = max(0, min(indexY, HEIGHT_OF_BATTLE_SIMULATION_MAP - 1));

			BattleSimulationMapCellArray[mapCellX][mapCellY]->setVisible(false);
		}
	}
}
// ��������
void BattleFieldWeapon::Attack()
{

}
// ����������
int BattleFieldWeapon::BeAttacked()
{
	return 0;
}