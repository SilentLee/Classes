#pragma once
#include "cocos2d.h"
#include "Global.h"
#include "MultiThreadSync.h"
#include "Crypt.h"
#include "CircularQueue.h"
#include "ODSocket.h"
#include "ProtocolHeader.h"

#define READ_PACKET(PROTOCOL)\
S_##PROTOCOL recvData;\
memset(&recvData, 0 , sizeof(S_##PROTOCOL));\
READ_##PROTOCOL(packet, recvData);

USING_NS_CC;

class CNetworkSession : public ODSocket, public CMultiThreadSync<CNetworkSession>
{
public:
	DWORD				mCurrentPacketNumber;
	CCircularQueue		WriteQueue;
    
	DWORD			mLastReadPacketNumber;
    BYTE				mPacketBuffer[MAX_BUFFER_LENGTH * 3];
    INT					mRemainLength;
    
public:
	CNetworkSession(void);
	~CNetworkSession(void);

	BOOL		Begin();
	BOOL		End();

	BOOL		WritePacket(DWORD protocol, const BYTE *packet, DWORD packetLength);
	BOOL		WriteComplete(VOID);
	BOOL		GetPacket(DWORD &protocol, BYTE *packet, DWORD &packetLength);
	VOID		RecvData();
public:
	// RecvProc1v1
	void onPT_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet);
	void onPT_ARRANGE_WEAPON_SUCC_M(BYTE* packet);
	void onPT_BATTLE_START_GAME_M(BYTE* packet);
	void onPT_BATTLE_UPDATE_SITUATION_M(BYTE* packet);

    // 从服务器接收数据后的处理函数
    // 注册
//    void onPT_VISITOR_REGIST_SUCC_U(BYTE* packet);
//    void onPT_USER_NAME_REGIST_SUCC_U(BYTE* packet);
//    void onPT_BIND_ACCOUNT_REGIST_SUCC_U(BYTE* packet);
//    void onPT_CELLPHONE_NO_REGIST_SUCC_U(BYTE* packet);
//    
//    // 登录
//    void onPT_USER_NAME_LOGIN_SUCC_U(BYTE* packet);
//    void onPT_BIND_ACCOUNT_LOGIN_SUCC_U(BYTE* packet);
//    void onPT_CELLPHONE_NO_LOGIN_SUCC_U(BYTE* packet);
//    void onPT_VISITOR_DEFAULT_LOGIN_SUCC_U(BYTE* packet);
//    
//    // 更改用户信息
//    void onPT_ADD_NICKNAME_SUCC_U(BYTE* packet);
//    void onPT_ADD_BIND_ACCOUNT_SUCC_U(BYTE* packet);
//    void onPT_ADD_CELLPHONE_NO_SUCC_U(BYTE* packet);
//    void onPT_UPDATE_PASSWORD_SUCC_U(BYTE* packet);
//    void onPT_UPDATE_NICKNAME_SUCC_U(BYTE* packet);
//    void onPT_UPDATE_CELLPHONE_NO_SUCC_U(BYTE* packet);
//    void onPT_UPDATE_RECORD_SUCC_U(BYTE* packet);
//    
//    // 后勤补给
//    void onPT_BUY_COINS_SUCC_U(BYTE* packet);
//    void onPT_BUY_DIAMONDS_SUCC_U(BYTE* packet);
//    void onPT_BUY_CARDS_SUCC_U(BYTE* packet);
//    void onPT_OPEN_SUPPLY_CHEST_SUCC_U(BYTE* packet);
//    void onPT_UPGRADE_CARD_SUCC_U(BYTE* packet);
//    void onPT_ACQUIRE_CHEST_SUCC_U(BYTE* packet);
//    
//    // 接收信息
//    void onPT_LOAD_CARDS_ON_SALE_SUCC_U(BYTE* packet);
//    
//    // 二人死斗
//    void onPT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_UPDATE_USER_LIST_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_START_GAME_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_UPDATE_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_END_M(BYTE* packet);
//    
//    // 接收服务器布设飞机成功信息
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M(BYTE* packet);
//    
//    // 接收服务器布设飞机失败信息
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U(BYTE* packet);
//    
//    // 接收服务器端布设武器信息
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M(BYTE* packet);
//    
//    // 插入武器失败消息
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U(BYTE* packet);
//    void onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U(BYTE* packet);
//    
////    // 接收服务器端飞机坠落消息
////    void onPT_DOUBLE_BATTLE_ON_PLANE_FALL_M(BYTE* packet);
//    
////    // 接收服务器端飞机被击毁的消息
////    void onPT_DOUBLE_BATTLE_PLANE_DOWN_M(BYTE* packet);
//    
//    // 处理辅助函数
//    // 接收玩家购买的卡牌
//    void loadRecvCard(int cardType, int cardNum);
//    // 接收玩家得到的补给箱
//    void loadCardsInRecvChest(S_PT_OPEN_SUPPLY_CHEST_SUCC_U ptOpenSupplyChestSuccU, int kindsOfCards);
};































