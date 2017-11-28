//
//  RecvProcForDoubleBattle.cpp
//  originalProject
//
//  Created by 李熙良 on 17/3/27.
//
//

#include <stdio.h>
#include "NetworkSession.h"
#include "RoomDoubleInstance.h"
#include "OperInfoInstance.h"
#include "GameCtrlParams.h"
#include "ErrInstance.h"
#include "MsgInstance.h"
#include "MapRefreshInfoInstance.h"
#include "PowerInstance.h"
#include "BattleFieldSituationInstance.h"

void CNetworkSession::onPT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U);
    
    CRoomDoubleInstance* roomDoubleInstance = CRoomDoubleInstance::getInstance();
    roomDoubleInstance->setRoomID(recvData.ROOM_ID);
    roomDoubleInstance->setCurrentUserCount(recvData.CURRENT_USER_COUNT);
    roomDoubleInstance->setStatus(recvData.ROOM_STATUS);
    
    if(roomDoubleInstance->getStatus() == RM_WAITING) {
        return;
    } else if(roomDoubleInstance->getStatus() == RM_READY) {
        return;
    }
}

void CNetworkSession::onPT_DOUBLE_BATTLE_UPDATE_USER_LIST_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_UPDATE_USER_LIST_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_UPDATE_USER_LIST_M);
    
    S_USER_ACCOUNT_INFO* userAccountInfo = (CUserInstance::getInstance())->getUserAccountInfo();
    CRoomDoubleInstance* roomDoubleInstance = CRoomDoubleInstance::getInstance();

    roomDoubleInstance->clearUserList();
    
    CHAR* Pointer = recvData.USER_LIST;
    int length = recvData.LENGTH;
    
    // 设置当前房间用户人数
    roomDoubleInstance->setCurrentUserCount(recvData.CURRENT_USER_COUNT);
    
    // 接收第一个用户信息
    if(length >= sizeof(S_DOUBLE_BATTLE_ROOM_USER)) {
        S_DOUBLE_BATTLE_ROOM_USER roomUserTemp;
        memcpy(&roomUserTemp, Pointer, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        if(roomUserTemp.USER_ID == userAccountInfo->USER_ID) {
            memcpy(roomDoubleInstance->getUserOwn(), &roomUserTemp, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        } else {
            memcpy(roomDoubleInstance->getUserOppo(), &roomUserTemp, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        }
        Pointer += sizeof(S_DOUBLE_BATTLE_ROOM_USER);
        length -= sizeof(S_DOUBLE_BATTLE_ROOM_USER);
    }
    
    // 接收第二个用户信息
    if(length >= sizeof(S_DOUBLE_BATTLE_ROOM_USER)) {
        S_DOUBLE_BATTLE_ROOM_USER roomUserTemp;
        memcpy(&roomUserTemp, Pointer, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        if(roomUserTemp.USER_ID == userAccountInfo->USER_ID) {
            memcpy(roomDoubleInstance->getUserOwn(), &roomUserTemp, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        } else {
            memcpy(roomDoubleInstance->getUserOppo(), &roomUserTemp, sizeof(S_DOUBLE_BATTLE_ROOM_USER));
        }
        Pointer += sizeof(S_DOUBLE_BATTLE_ROOM_USER);
        length -= sizeof(S_DOUBLE_BATTLE_ROOM_USER);
    }
    
    roomDoubleInstance->setUserListUpdated(true);
    
    CBattleFieldSituationInstance* battleFieldSituationInstance = CBattleFieldSituationInstance::getInstance();
    
    battleFieldSituationInstance->reset();
}

void CNetworkSession::onPT_DOUBLE_BATTLE_START_GAME_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_START_GAME_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_START_GAME_M);
    
    CRoomDoubleInstance* roomDoubleInstance = CRoomDoubleInstance::getInstance();
    roomDoubleInstance->setStatus(recvData.ROOM_STATUS);
//    roomDoubleInstance->setStartTime(recvData.START_TIME);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_END_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_END_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_END_M);
    
    CRoomDoubleInstance* roomDoubleInstance = CRoomDoubleInstance::getInstance();
    
    int userId1 = recvData.USER_ID_1;
    int userId2 = recvData.USER_ID_2;
    
    int numAlive1 = recvData.ALIVE_PLANES_1;
    int numAlive2 = recvData.ALIVE_PLANES_2;
    
    int numShotDown1 = recvData.SHOT_DOWN_PLANES_1;
    int numShotDown2 = recvData.SHOT_DOWN_PLANES_2;
    
    if(numAlive1 == 0 && numAlive2 > 0) {
        roomDoubleInstance->setGetDraw(false);
        roomDoubleInstance->setWinnerID(userId2);
    } else if(numAlive1 > 0 && numAlive2 == 0) {
        roomDoubleInstance->setGetDraw(false);
        roomDoubleInstance->setWinnerID(userId1);
    } else if(numAlive1 == numAlive2) {
        if(numShotDown1 == numShotDown2) {
            roomDoubleInstance->setGetDraw(true);
        } else if(numShotDown1 > numShotDown2) {
            roomDoubleInstance->setGetDraw(false);
            roomDoubleInstance->setWinnerID(userId1);
        } else if(numShotDown1 < numShotDown2) {
            roomDoubleInstance->setGetDraw(false);
            roomDoubleInstance->setWinnerID(userId2);
        }
    }
    
    roomDoubleInstance->setStatus(RM_GAME_ENDING);
    
    return;
}

// 接收服务器布设飞机成功信息
void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(MIDDLE_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(SENIOR_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_STEALTH_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(MIDDLE_STEALTH_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M(BYTE *packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(SENIOR_STEALTH_PLANE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setRotation(recvData.ROTATION);
    operInfoInstance->setHP(recvData.HP);
    operInfoInstance->setPlaneNo(recvData.PLANE_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

// 接收服务器布设飞机失败信息
void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

// 从服务器端接收到的武器布设消息
void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(SENIOR_ANTI_STEALTH_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDurationOfRadar(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(MIDDLE_ANTI_STEALTH_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_ANTI_STEALTH_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDurationOfRadar(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(SENIOR_MISSILE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPOLSION_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(MIDDLE_MISSILE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPOLSION_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_MISSILE);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPOLSION_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(SENIOR_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDurationOfRadar(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(MIDDLE_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDurationOfRadar(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_RADAR);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDurationOfRadar(recvData.DURATION);
    operInfoInstance->setRadarNo(recvData.RADAR_NO);
    
    operInfoInstance->setIsOperInfoRecv(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->resetOperInfoInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_CANNONBALL);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPLOSION_NO);
    
    if(recvData.NUM_SHOT_DOWN) {
        operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    }
    
    operInfoInstance->setIsOperInfoRecv(true);
    
    // 当有飞机被击落的时候
    if(recvData.NUM_SHOT_DOWN) {
        CMsgInstance* msgInstance = CMsgInstance::getInstance();
        msgInstance->setUserID(recvData.USER_ID);
        msgInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        msgInstance->setMsgCode(MSG_PLANES_DOWN);
        msgInstance->setRecvMsg(true);
    }
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->resetOperInfoInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_CANNONBALL);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPLOSION_NO);
    
    if(recvData.NUM_SHOT_DOWN) {
        operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    }
    
    operInfoInstance->setIsOperInfoRecv(true);
    
    // 当有飞机被击落的时候
    if(recvData.NUM_SHOT_DOWN) {
        CMsgInstance* msgInstance = CMsgInstance::getInstance();
        msgInstance->setUserID(recvData.USER_ID);
        msgInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        msgInstance->setMsgCode(MSG_PLANES_DOWN);
        msgInstance->setRecvMsg(true);
    }
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M);
    
    COperInfoInstance* operInfoInstance = COperInfoInstance::getInstance();
    
    operInfoInstance->resetOperInfoInstance();
    
    operInfoInstance->setUserID(recvData.USER_ID);
    operInfoInstance->setWeaponSwitch(JUNIOR_CANNONBALL);
    operInfoInstance->setX(recvData.X);
    operInfoInstance->setY(recvData.Y);
    operInfoInstance->setWidth(recvData.WIDTH);
    operInfoInstance->setLength(recvData.LENGTH);
    operInfoInstance->setDP(recvData.DP);
    
    operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
    operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    operInfoInstance->setExplosionNo(recvData.EXPLOSION_NO);
    
    if(recvData.NUM_SHOT_DOWN) {
        operInfoInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        operInfoInstance->setShotDownPlaneNoBuffer((int*)recvData.NO_SHOT_DOWN);
    }
    
    operInfoInstance->setIsOperInfoRecv(true);
    
    // 当有飞机被击落的时候
    if(recvData.NUM_SHOT_DOWN) {
        CMsgInstance* msgInstance = CMsgInstance::getInstance();
        msgInstance->setUserID(recvData.USER_ID);
        msgInstance->setNumShotDown(recvData.NUM_SHOT_DOWN);
        msgInstance->setMsgCode(MSG_PLANES_DOWN);
        msgInstance->setRecvMsg(true);
    }
}

void CNetworkSession::onPT_DOUBLE_BATTLE_UPDATE_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_UPDATE_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_UPDATE_U);
    
    // 在 roomDoubleInstance 中 更新时间
    CRoomDoubleInstance* roomDoubleInstance = CRoomDoubleInstance::getInstance();
    roomDoubleInstance->setCurrentTime(recvData.CURRENT_TIME);
    
    CMapRefreshInfoInstance* mapRefreshInfoInstance = CMapRefreshInfoInstance::getInstance();
    
    CPowerInstance* powerInstance = CPowerInstance::getInstance();
    
    // 在 mapRefreshInfoInstance 中更新能量信息
    int* powerBuffer = powerInstance->getPowerBuffer();
//    memcpy(powerBuffer, recvData.POWER_BUFFER, sizeof(int) * DEFAULT_POWER_BUFFER_LENGTH);
    int a[4] = {0,};
    memcpy(a, recvData.POWER_BUFFER, sizeof(int) * 4);
    
    if(a[0] == powerInstance->getUserId()) {
        powerInstance->setCurrentPower(a[1]);
    } else if(a[2] == powerInstance->getUserId()) {
        powerInstance->setCurrentPower(a[3]);
    }
    
    // 在 mapRefreshInfoInstance 中更新击落飞机信息
    if(recvData.FALL_PLANE_NUM) {
        mapRefreshInfoInstance->setNumFallPlane(recvData.FALL_PLANE_NUM);
        int* planeNoBuffer = mapRefreshInfoInstance->getFallPlaneNoBuffer();
        memcpy(planeNoBuffer, recvData.PLANE_NO_BUFFER, sizeof(int) * recvData.FALL_PLANE_NUM * 2);
        
        mapRefreshInfoInstance->setIsPlaneFall(true);
    }
    
    // 在 mapRefreshInfoInstance 中更新失效雷达信息
    if(recvData.DISABLE_RADAR_NUM) {
        mapRefreshInfoInstance->setNumDisableRadar(recvData.DISABLE_RADAR_NUM);
        int* disableRadarNoBuffer = mapRefreshInfoInstance->getDisableRadarNoBuffer();
        memcpy(disableRadarNoBuffer, recvData.RADAR_NO_BUFFER, sizeof(int) * recvData.DISABLE_RADAR_NUM * 2);
        
        mapRefreshInfoInstance->setIsRadarDisable(true);
    }
    
    // 在 mapRefreshInfoInstance 中更新爆炸消失信息
    if(recvData.DISAPPEAR_EXPLOSION_NUM) {
        mapRefreshInfoInstance->setNumExplosionDisappear(recvData.DISAPPEAR_EXPLOSION_NUM);
        int* explosionDisappearBuffer = mapRefreshInfoInstance->getExplosionDisappearNoBuffer();
        memcpy(explosionDisappearBuffer, recvData.EXPLOSION_NO_BUFFER, sizeof(int) * recvData.DISAPPEAR_EXPLOSION_NUM * 2);
        
        mapRefreshInfoInstance->setIsExplosionDisappear(true);
    }
}

// 插入武器失败消息
void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}

void CNetworkSession::onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U(BYTE* packet)
{
    printf("Protocol is: PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U\n");
    READ_PACKET(PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U);
    
    CErrInstance* errInstance = CErrInstance::getInstance();
    errInstance->setErrCode(recvData.ERROR_CODE);
    
    errInstance->setRecvErr(true);
}












