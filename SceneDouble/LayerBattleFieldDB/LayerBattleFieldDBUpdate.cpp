#include "LayerBattleFieldDB.h"
#include "LibBattlefieldWeaponApi.h"
#include "LibBattleFieldGraphApi.h"
#include "LibBattlefieldWeaponApi.h"
#include "OperInfoInstance.h"

// 更新函数
void LayerBattleFieldDB::updateFrog(float dt)
{
	// 计算迷雾分界线所在位置
	memset(mFrogLine, 0, sizeof(int) * BATTLE_FIELD_WIDTH_IN_SQUARE);

	for (int i = 0; i < mWeaponsOwn.size(); i++)
	{
		int posX = mWeaponsOwn[i]->getPosXInSquare();
		int posY = mWeaponsOwn[i]->getPosYInSquare();
		int rangeDec = mWeaponsOwn[i]->getPropertyWp().RANGE_DEC;

		mFrogLine[max(0, posX - 1)] = max(mFrogLine[max(0, posX - 1)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[posX] = max(mFrogLine[posX], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
		mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)] =
			max(mFrogLine[min(posX + 1, BATTLE_FIELD_WIDTH_IN_SQUARE)], posY + PARAM_RANGE_DEC_REVISE_VALUE + rangeDec);
	}

	// 设置战场迷雾显示范围
	for (int indexX = 0; indexX < BATTLE_FIELD_WIDTH_IN_SQUARE; indexX++)
	{
		for (int indexY = 0; indexY < BATTLE_FIELD_HEIGHT_IN_SQUARE; indexY++)
		{
			if (indexY <= mFrogLine[indexX])
			{
				mFrogOfWarArray[indexX][indexY]->setVisible(false);
			}
			else {
				mFrogOfWarArray[indexX][indexY]->setVisible(true);
			}
		}
	}

	// 用于测试迷雾功能的代码
	for (vector<BFW_BasicClass*>::iterator iter = mWeaponsOwn.begin(); iter != mWeaponsOwn.end(); iter++) {
		BFW_BasicClass* weapon = (BFW_BasicClass*)*iter;
		if (weapon->getPosYInSquare() == 10)
		{
			mWeaponsOwn.erase(iter);
			//weapon->retain();
			weapon->removeFromParent();
			return;
		}
	}
}

void LayerBattleFieldDB::updateBFSituation(float dt)
{
	log("LayerBattleFieldDB::updateBFSituation");

	COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
	if (operInfoInstance->getIsOperInfoRecv()) {
		S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U ptBattle1V1ArrangeCardSuccU = operInfoInstance->getPtBattle1V1ArrangeSuccU();
		operInfoInstance->setIsOperInfoRecv(false);
		log("load S_PT_BATTLE_1V1_ARRANGE_CARD_SUCC_U");

		int weaponType = ptBattle1V1ArrangeCardSuccU.CARD_TYPE;
		float posX = ptBattle1V1ArrangeCardSuccU.POS_X;
		float posY = ptBattle1V1ArrangeCardSuccU.POS_Y;

		arrangeEnemyWeaponWithAbsolutePos(weaponType, posX, posY, 1000);
	}
}