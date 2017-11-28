//
//  RecvProc.cpp
//  originalProject
//
//  Created by 李熙良 on 17/2/8.
//
//

#include <stdio.h>
#include "NetworkSession.h"
#include "UserInstance.h"
#include "FileConfigUtil.h"
//#include "PURCHASE_PT_ConstValue.h"
#include "GameCtrlParams.h"
#include "DataInstance.h"

void CNetworkSession::onPT_VISITOR_REGIST_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_VISITOR_REGIST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();

    READ_PACKET(PT_VISITOR_REGIST_SUCC_U);
//    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->loatUserInfo(&recvData);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_USER_NAME_REGIST_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_USER_NAME_REGIST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_USER_NAME_REGIST_SUCC_U);
    //    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->loatUserInfo(&recvData);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_BIND_ACCOUNT_REGIST_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_BIND_ACCOUNT_REGIST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_BIND_ACCOUNT_REGIST_SUCC_U);
    //    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->loatUserInfo(&recvData);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_CELLPHONE_NO_REGIST_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_CELLPHONE_NO_REGIST_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_CELLPHONE_NO_REGIST_SUCC_U);
    //    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->loatUserInfo(&recvData);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_USER_NAME_LOGIN_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_USER_NAME_LOGIN_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_USER_NAME_LOGIN_SUCC_U);
    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_BIND_ACCOUNT_LOGIN_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_BIND_ACCOUNT_LOGIN_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_BIND_ACCOUNT_LOGIN_SUCC_U);
    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_CELLPHONE_NO_LOGIN_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_CELLPHONE_NO_LOGIN_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_CELLPHONE_NO_LOGIN_SUCC_U);
    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_VISITOR_DEFAULT_LOGIN_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_VISITOR_DEFAULT_LOGIN_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_VISITOR_DEFAULT_LOGIN_SUCC_U);
    //    memcpy(userAccountInfo, &recvData, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->loatUserInfo(&recvData);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setLoginFlag(LOAD_USER_INFO_SUCC);
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUserAccountInfo(&recvData);
}

void CNetworkSession::onPT_ADD_NICKNAME_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_ADD_NICKNAME_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_ADD_NICKNAME_SUCC_U);
    
    memcpy(userAccountInfo->NICKNAME, recvData.NICKNAME, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputAddNicknameSuccInfo(recvData);
}

void CNetworkSession::onPT_ADD_BIND_ACCOUNT_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_ADD_BIND_ACCOUNT_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_ADD_BIND_ACCOUNT_SUCC_U);
    
    memcpy(userAccountInfo->BIND_ACCOUNT, recvData.BIND_ACCOUNT, 32);
    memcpy(userAccountInfo->BIND_ACCOUNT_TYPE, recvData.BIND_ACCOUNT_TYPE, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputAddBindAccountSuccInfo(recvData);
}

void CNetworkSession::onPT_ADD_CELLPHONE_NO_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_ADD_CELLPHONE_NO_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_ADD_CELLPHONE_NO_SUCC_U);
    
    memcpy(userAccountInfo->CELLPHONE_NO, recvData.CELLPHONE_NO, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputAddCellphoneNoSuccInfo(recvData);
}

void CNetworkSession::onPT_UPDATE_PASSWORD_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_UPDATE_PASSWORD_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_UPDATE_PASSWORD_SUCC_U);
    
    memcpy(userAccountInfo->PASSWORD, recvData.NEW_PASSWORD, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUpdatePasswordSuccInfo(recvData);
}

void CNetworkSession::onPT_UPDATE_NICKNAME_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_UPDATE_NICKNAME_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_UPDATE_NICKNAME_SUCC_U);
    memcpy(userAccountInfo->NICKNAME, recvData.NEW_NICKNAME, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUpdateNicknameSuccInfo(recvData);
}

void CNetworkSession::onPT_UPDATE_CELLPHONE_NO_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_UPDATE_CELLPHONE_NO_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_UPDATE_CELLPHONE_NO_SUCC_U);
    
    memcpy(userAccountInfo->CELLPHONE_NO, recvData.NEW_CELLPHONE_NO, 32);
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUpdateCellphoneNoSuccInfo(recvData);
}

void CNetworkSession::onPT_UPDATE_RECORD_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_UPDATE_RECORD_SUCC_U\n");
    CUserInstance* userInstance = CUserInstance::getInstance();
    S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();
    
    READ_PACKET(PT_UPDATE_RECORD_SUCC_U);
    
    userAccountInfo->INTEGRAL_POINTS = recvData.INTEGRAL_POINTS;
    userAccountInfo->LEVEL = recvData.LEVEL;
    userAccountInfo->DIAMONDS = recvData.DIAMONDS;
    userAccountInfo->COINS = recvData.COINS;
    userAccountInfo->WIN_TIMES = recvData.WIN_TIMES;
    userAccountInfo->BATTLE_TIMES = recvData.BATTLE_TIMES;
    userAccountInfo->WIN_RATE = recvData.WIN_RATE;
    userAccountInfo->SHOT_DOWN_PLANES = recvData.SHOT_DOWN_PLANES;
    userAccountInfo->SHOT_DOWN_JUNIOR_PLANES = recvData.SHOT_DOWN_JUNIOR_PLANES;
    userAccountInfo->SHOT_DOWN_MIDDLE_PLANES = recvData.SHOT_DOWN_MIDDLE_PLANES;
    userAccountInfo->SHOT_DOWN_SENIOR_PLANES = recvData.SHOT_DOWN_SENIOR_PLANES;
    
    FileConfigUtil::write("userInfoTest.txt", userAccountInfo, sizeof(S_USER_ACCOUNT_INFO));
    userInstance->setAccountInfoUpdated(true);
    
    COutputProc::OutputUpdateRecordSuccInfo(recvData);
}






























