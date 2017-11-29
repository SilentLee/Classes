//
//  RecvProcForPurchase.cpp
//  originalProject
//
//  Created by 李熙良 on 17/2/27.
//
//

#include <stdio.h>
#include "NetworkSession.h"
#include "UserInstance.h"
#include "FileConfigUtil.h"
//#include "PURCHASE_PT_ConstValue.h"
#include "GameCtrlParams.h"
#include "DataInstance.h"
#include "PurchaseInstance.h"

void CNetworkSession::onPT_ACQUIRE_CHEST_SUCC_U(BYTE *packet)
{
    printf("Protocol is: PT_ACQUIRE_CHEST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_CHEST_INFO* userChestInfo = userInstance->getUserChestInfo();
    
    READ_PACKET(PT_ACQUIRE_CHEST_SUCC_U);
    
    switch(recvData.CHEST_TYPE)
    {
        case WIN_REWARDS_1:
            userChestInfo->WIN_REWARDS_1_NUM = 1;
            userChestInfo->WIN_REWARDS_1_UNLOCK_TIME = recvData.UNLOCK_TIME;
            break;
            
        case WIN_REWARDS_2:
            userChestInfo->WIN_REWARDS_2_NUM = 1;
            userChestInfo->WIN_REWARDS_2_UNLOCK_TIME = recvData.UNLOCK_TIME;
            break;
            
        case WIN_REWARDS_3:
            userChestInfo->WIN_REWARDS_3_NUM = 1;
            userChestInfo->WIN_REWARDS_3_UNLOCK_TIME = recvData.UNLOCK_TIME;
            break;

        case WIN_REWARDS_4:
            userChestInfo->WIN_REWARDS_4_NUM = 1;
            userChestInfo->WIN_REWARDS_4_UNLOCK_TIME = recvData.UNLOCK_TIME;
            break;
            
        case WIN_REWARDS_5:
            userChestInfo->WIN_REWARDS_5_NUM = 1;
            userChestInfo->WIN_REWARDS_5_UNLOCK_TIME = recvData.UNLOCK_TIME;
            break;
            
        case STAR_REWARDS:
            
            
            
            userChestInfo->STAR_REWARDS_NUM = 1;
            userChestInfo->LAST_STAR_REWARDS_ACQUIRE_TIME = recvData.ACQUIRE_TIME;
            break;
            
        case FREE_REWARDS:
            userChestInfo->FREE_REWARDS_NUM = 1;
            userChestInfo->LAST_FREE_REWARDS_ACQUIRE_TIME = recvData.ACQUIRE_TIME;
            break;
    }
}

void CNetworkSession::onPT_UPGRADE_CARD_SUCC_U(BYTE *packet)
{
    printf("Protocol is: PT_UPGRADE_CARD_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_EQUIPMENT_INFO* userEquipmentInfo = CUserInstance::getInstance()->getUserEquipmentInfo();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_UPGRADE_CARD_SUCC_U);
    
    switch(recvData.CARD_TYPE)
    {
        case JUNIOR_PLANE:
            userEquipmentInfo->JUNIOR_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_PLANE:
            userEquipmentInfo->MIDDLE_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_PLANE:
            userEquipmentInfo->SENIOR_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case JUNIOR_STEALTH_PLANE:
            userEquipmentInfo->JUNIOR_STEALTH_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_STEALTH_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_STEALTH_PLANE:
            userEquipmentInfo->MIDDLE_STEALTH_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_STEALTH_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_STEALTH_PLANE:
            userEquipmentInfo->SENIOR_STEALTH_PLANE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_STEALTH_PLANE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_ANTI_STEALTH_RADAR:
            userEquipmentInfo->SENIOR_ANTI_STEALTH_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_ANTI_STEALTH_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_ANTI_STEALTH_RADAR:
            userEquipmentInfo->MIDDLE_ANTI_STEALTH_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_ANTI_STEALTH_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case JUNIOR_ANTI_STEALTH_RADAR:
            userEquipmentInfo->JUNIOR_ANTI_STEALTH_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_ANTI_STEALTH_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_MISSILE:
            userEquipmentInfo->SENIOR_MISSILE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_MISSILE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_MISSILE:
            userEquipmentInfo->MIDDLE_MISSILE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_MISSILE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case JUNIOR_MISSILE:
            userEquipmentInfo->JUNIOR_MISSILE_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_MISSILE_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_RADAR:
            userEquipmentInfo->SENIOR_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_RADAR:
            userEquipmentInfo->MIDDLE_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case JUNIOR_RADAR:
            userEquipmentInfo->JUNIOR_RADAR_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_RADAR_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case SENIOR_CANNONBALL:
            userEquipmentInfo->SENIOR_CANNONBALL_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->SENIOR_CANNONBALL_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case MIDDLE_CANNONBALL:
            userEquipmentInfo->MIDDLE_CANNONBALL_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->MIDDLE_CANNONBALL_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
            
        case JUNIOR_CANNONBALL:
            userEquipmentInfo->JUNIOR_CANNONBALL_LEVEL = recvData.CARD_LEVEL;
            userAccountInfo->COINS -= recvData.CARD_UPGRADE_COST;
            userEquipmentInfo->JUNIOR_CANNONBALL_CARD_NUM -= recvData.CARD_NUM_UPGRADE_NEED;
            break;
    }
    userInstance->setAccountInfoUpdated(true);
    userInstance->setEquipmentInfoUpdated(true);
    userInstance->setUpdateBtnCardOperation(true);
}

void CNetworkSession::onPT_LOAD_CARDS_ON_SALE_SUCC_U(BYTE *packet)
{
    printf("Protocol is: PT_LOAD_CARDS_ON_SALE_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    CPurchaseInstance* purchaseInstance = CPurchaseInstance::getInstance();
    READ_PACKET(PT_LOAD_CARDS_ON_SALE_SUCC_U);
    
    memcpy(purchaseInstance->getPtLoadCardsOnSaleSuccU(), &recvData, sizeof(S_PT_LOAD_CARDS_ON_SALE_SUCC_U));
    userInstance->setLoginFlag(LOAD_CARDS_ON_SALE_SUCC);
    
    userInstance->setEquipmentInfoUpdated(true);
}

void CNetworkSession::onPT_BUY_COINS_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_BUY_COINS_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_BUY_COINS_SUCC_U);
    
    userAccountInfo->COINS += recvData.COINS;
    userAccountInfo->DIAMONDS -= recvData.DIAMONDS;
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
}

void CNetworkSession::onPT_BUY_DIAMONDS_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_BUY_DIAMONDS_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_BUY_DIAMONDS_SUCC_U);
    
    userAccountInfo->DIAMONDS += recvData.DIAMONDS;
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
}

void CNetworkSession::onPT_BUY_CARDS_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_BUY_CARDS_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_BUY_CARDS_SUCC_U);
    
    userAccountInfo->COINS -= recvData.COINS;
    loadRecvCard(recvData.CARD_TYPE, recvData.CARD_NUM);
    
    FileConfigUtil::write("userEquipmentTest.txt", userInstance->getUserEquipmentInfo(), sizeof(S_USER_EQUIPMENT_INFO));
    userInstance->setAccountInfoUpdated(true);
    userInstance->setEquipmentInfoUpdated(true);
}

void CNetworkSession::onPT_OPEN_SUPPLY_CHEST_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_OPEN_SUPPLY_CHEST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    S_USER_CHEST_INFO* userChestInfo = CUserInstance::getInstance()->getUserChestInfo();
    
    READ_PACKET(PT_OPEN_SUPPLY_CHEST_SUCC_U);
    
    userAccountInfo->COINS += recvData.COINS;
    userAccountInfo->DIAMONDS += recvData.DIAMONDS;
    
    switch(recvData.CHEST_TYPE)
    {
        case WIN_REWARDS_1:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_WIN_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_WIN_REWARDS;
            userChestInfo->WIN_REWARDS_1_NUM = recvData.CHEST_NUM;
            break;
            
        case WIN_REWARDS_2:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_WIN_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_WIN_REWARDS;
            userChestInfo->WIN_REWARDS_2_NUM = recvData.CHEST_NUM;
            break;
            
        case WIN_REWARDS_3:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_WIN_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_WIN_REWARDS;
            userChestInfo->WIN_REWARDS_3_NUM = recvData.CHEST_NUM;
            break;
            
        case WIN_REWARDS_4:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_WIN_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_WIN_REWARDS;
            userChestInfo->WIN_REWARDS_4_NUM = recvData.CHEST_NUM;
            break;
            
        case WIN_REWARDS_5:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_WIN_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_WIN_REWARDS;
            userChestInfo->WIN_REWARDS_5_NUM = recvData.CHEST_NUM;
            break;
            
        case STAR_REWARDS:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_STAR_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_STAR_REWARDS;
            userChestInfo->STAR_REWARDS_NUM = recvData.CHEST_NUM;
            userChestInfo->STAR_NUM = recvData.STAR_NUM;
            break;
            
        case FREE_REWARDS:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_FREE_REWARDS);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_FREE_REWARDS;
            userChestInfo->FREE_REWARDS_NUM = recvData.CHEST_NUM;
            break;
            
        case SUPPLY_CHEST_SMALL:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_SUPPLY_CHEST_SMALL);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_SUPPLY_CHEST_SMALL;
            break;
            
        case SUPPLY_CHEST_MIDDLE:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_SUPPLY_CHEST_MIDDLE);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_SUPPLY_CHEST_MIDDLE;
            break;
            
        case SUPPLY_CHEST_LARGE:
            loadCardsInRecvChest(recvData, KINDS_OF_CARD_IN_SUPPLY_CHEST_LARGE);
            userAccountInfo->DIAMONDS -= DIAMONDS_COST_FOR_SUPPLY_CHEST_LARGE;
            break;
    }
    
    CDataInstance* dataInstance = CDataInstance::getInstance();
    dataInstance->setPtOpenSupplyChestSuccU(&recvData);
    
    FileConfigUtil::write("userEquipmentTest.txt", userInstance->getUserEquipmentInfo(), sizeof(S_USER_EQUIPMENT_INFO));
    userInstance->setAccountInfoUpdated(true);
    userInstance->setSupplyChestLoaded(true);
}

void CNetworkSession::loadRecvCard(int cardType, int cardNum)
{
    S_USER_EQUIPMENT_INFO* userEquipmentInfo = CUserInstance::getInstance()->getUserEquipmentInfo();
    
    switch(cardType)
    {
        case JUNIOR_PLANE:
            userEquipmentInfo->JUNIOR_PLANE_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_PLANE:
            userEquipmentInfo->MIDDLE_PLANE_CARD_NUM += cardNum;
            break;
            
        case SENIOR_PLANE:
            userEquipmentInfo->SENIOR_PLANE_CARD_NUM += cardNum;
            break;
            
        case JUNIOR_STEALTH_PLANE:
            userEquipmentInfo->JUNIOR_STEALTH_PLANE_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_STEALTH_PLANE:
            userEquipmentInfo->MIDDLE_STEALTH_PLANE_CARD_NUM += cardNum;
            break;
            
        case SENIOR_STEALTH_PLANE:
            userEquipmentInfo->SENIOR_STEALTH_PLANE_CARD_NUM += cardNum;
            break;
            
        case SENIOR_ANTI_STEALTH_RADAR:
            userEquipmentInfo->SENIOR_ANTI_STEALTH_RADAR_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_ANTI_STEALTH_RADAR:
            userEquipmentInfo->MIDDLE_ANTI_STEALTH_RADAR_CARD_NUM += cardNum;
            break;
            
        case JUNIOR_ANTI_STEALTH_RADAR:
            userEquipmentInfo->JUNIOR_ANTI_STEALTH_RADAR_CARD_NUM += cardNum;
            break;
            
        case SENIOR_MISSILE:
            userEquipmentInfo->SENIOR_MISSILE_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_MISSILE:
            userEquipmentInfo->MIDDLE_MISSILE_CARD_NUM += cardNum;
            break;
            
        case JUNIOR_MISSILE:
            userEquipmentInfo->JUNIOR_MISSILE_CARD_NUM += cardNum;
            break;
            
        case SENIOR_RADAR:
            userEquipmentInfo->SENIOR_RADAR_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_RADAR:
            userEquipmentInfo->MIDDLE_RADAR_CARD_NUM += cardNum;
            break;
            
        case JUNIOR_RADAR:
            userEquipmentInfo->JUNIOR_RADAR_CARD_NUM += cardNum;
            break;
            
        case SENIOR_CANNONBALL:
            userEquipmentInfo->SENIOR_CANNONBALL_CARD_NUM += cardNum;
            break;
            
        case MIDDLE_CANNONBALL:
            userEquipmentInfo->MIDDLE_CANNONBALL_CARD_NUM += cardNum;
            break;
            
        case JUNIOR_CANNONBALL:
            userEquipmentInfo->JUNIOR_CANNONBALL_CARD_NUM += cardNum;
            break;
    }
}

void CNetworkSession::loadCardsInRecvChest(S_PT_OPEN_SUPPLY_CHEST_SUCC_U ptOpenSupplyChestSuccU, int kindsOfCards)
{
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_1_TYPE, ptOpenSupplyChestSuccU.CARD_1_NUM);
    if(kindsOfCards == 1) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_2_TYPE, ptOpenSupplyChestSuccU.CARD_2_NUM);
    if(kindsOfCards == 2) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_3_TYPE, ptOpenSupplyChestSuccU.CARD_3_NUM);
    if(kindsOfCards == 3) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_4_TYPE, ptOpenSupplyChestSuccU.CARD_4_NUM);
    if(kindsOfCards == 4) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_5_TYPE, ptOpenSupplyChestSuccU.CARD_5_NUM);
    if(kindsOfCards == 5) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_6_TYPE, ptOpenSupplyChestSuccU.CARD_6_NUM);
    if(kindsOfCards == 6) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_7_TYPE, ptOpenSupplyChestSuccU.CARD_7_NUM);
    if(kindsOfCards == 7) return;
    
    loadRecvCard(ptOpenSupplyChestSuccU.CARD_8_TYPE, ptOpenSupplyChestSuccU.CARD_8_NUM);
    if(kindsOfCards == 8) return;
    
}





























