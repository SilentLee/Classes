#include "NetworkSession.h"
#include "OutputProc.h"

VOID CNetworkSession::RecvData()
{
	DWORD		protocol = 0;
	BYTE		packet[MAX_BUFFER_LENGTH] = {0, };
	DWORD		packetLength = 0;
    
    //CUserInstance* userInstance = CUserInstance::getInstance();
    //S_USER_ACCOUNT_INFO* userAccountInfo = CUserInstance::getInstance()->getUserAccountInfo();

    while (true) {
		memset(packet, 0, sizeof(packet));
        
		int result = Recv((char*)mPacketBuffer, sizeof(mPacketBuffer), 0);
        
        if (result <= 0) {
			printf("Server Disconnect\n");
			break;
		}

		mRemainLength = mRemainLength + result;

		//printf("\nSize of data received from Server is %d", result);
		if(GetPacket(protocol, packet, packetLength)) {
			printf("GetPacket success\n");
		}

		log("##Analize Result:\n");
        
        switch(protocol)
        {
		// BattleProctocol
		case PT_BATTLE_SEARCH_ROOM_SUCC_U:
			onPT_BATTLE_SEARCH_ROOM_SUCC_U(packet);
			break;

		case PT_BATTLE_ARRANGE_WEAPON_SUCC_U:
			onPT_ARRANGE_WEAPON_SUCC_U(packet);
			break;

		case PT_BATTLE_START_GAME_M:
			onPT_BATTLE_START_GAME_M(packet);
			break;

		case PT_BATTLE_UPDATE_SITUATION_M:
			onPT_BATTLE_UPDATE_SITUATION_M(packet);
			break;




//            // 用户登录或注册消息
//            // 1. PT_VISITOR_REGIST_SUCC_U
//            case PT_VISITOR_REGIST_SUCC_U:
//                onPT_VISITOR_REGIST_SUCC_U(packet);
//                break;
//                    
//            // 2. PT_USER_NAME_REGIST_SUCC_U
//            case PT_USER_NAME_REGIST_SUCC_U:
//                onPT_USER_NAME_REGIST_SUCC_U(packet);
//                break;
//                    
//            // 3. PT_BIND_ACCOUNT_REGIST_SUCC_U
//            case PT_BIND_ACCOUNT_REGIST_SUCC_U:
//                onPT_BIND_ACCOUNT_REGIST_SUCC_U(packet);
//                break;
//                    
//            // 4. PT_CELLPHONE_NO_REGIST_SUCC_U
//            case PT_CELLPHONE_NO_REGIST_SUCC_U:
//                onPT_CELLPHONE_NO_REGIST_SUCC_U(packet);
//                break;
//                
//            // 5. PT_USER_NAME_LOGIN_SUCC_U
//            case PT_USER_NAME_LOGIN_SUCC_U:
//                onPT_USER_NAME_LOGIN_SUCC_U(packet);
//                break;
//                    
//            // 6. PT_BIND_ACCOUNT_LOGIN_SUCC_U
//            case PT_BIND_ACCOUNT_LOGIN_SUCC_U:
//                onPT_BIND_ACCOUNT_LOGIN_SUCC_U(packet);
//                break;
//                    
//            // 7. PT_CELLPHONE_NO_LOGIN_SUCC_U
//            case PT_CELLPHONE_NO_LOGIN_SUCC_U:
//                onPT_CELLPHONE_NO_LOGIN_SUCC_U(packet);
//                break;
//                    
//            // 8. PT_VISITOR_DEFAULT_LOGIN_SUCC_U
//            case PT_VISITOR_DEFAULT_LOGIN_SUCC_U:
//                onPT_VISITOR_DEFAULT_LOGIN_SUCC_U(packet);
//                break;
//                
//            // 用户信息更改
//            // 12. PT_ADD_NICKNAME_SUCC_U
//            case PT_ADD_NICKNAME_SUCC_U:
//                onPT_ADD_NICKNAME_SUCC_U(packet);
//                break;
//                
//            // 13. PT_ADD_BIND_ACCOUNT_SUCC_U
//            case PT_ADD_BIND_ACCOUNT_SUCC_U:
//                onPT_ADD_BIND_ACCOUNT_SUCC_U(packet);
//                break;
//                
//            // 14. PT_ADD_CELLPHONE_NO_SUCC_U
//            case PT_ADD_CELLPHONE_NO_SUCC_U:
//                onPT_ADD_CELLPHONE_NO_SUCC_U(packet);
//                break;
//                
//            // 15. PT_UPDATE_PASSWORD_SUCC_U
//            case PT_UPDATE_PASSWORD_SUCC_U:
//                onPT_UPDATE_PASSWORD_SUCC_U(packet);
//                break;
//                
//            // 16. PT_UPDATE_NICKNAME_SUCC_U
//            case PT_UPDATE_NICKNAME_SUCC_U:
//                onPT_UPDATE_NICKNAME_SUCC_U(packet);
//                break;
//                    
//            // 17. PT_UPDATE_CELLPHONE_NO_SUCC_U
//            case PT_UPDATE_CELLPHONE_NO_SUCC_U:
//                onPT_UPDATE_CELLPHONE_NO_SUCC_U(packet);
//                break;
//                    
//            // 18. PT_UPDATE_RECORD_SUCC_U
//            case PT_UPDATE_RECORD_SUCC_U:
//                onPT_UPDATE_RECORD_SUCC_U(packet);
//                break;
//                
//            // 用户交易信息
//            case PT_BUY_COINS_SUCC_U:
//                onPT_BUY_COINS_SUCC_U(packet);
//                break;
//                
//            case PT_BUY_DIAMONDS_SUCC_U:
//                onPT_BUY_DIAMONDS_SUCC_U(packet);
//                break;
//                
//            case PT_BUY_CARDS_SUCC_U:
//                onPT_BUY_CARDS_SUCC_U(packet);
//                break;
//                
//            case PT_OPEN_SUPPLY_CHEST_SUCC_U:
//                onPT_OPEN_SUPPLY_CHEST_SUCC_U(packet);
//                break;
//                
//            case PT_LOAD_CARDS_ON_SALE_SUCC_U:
//                onPT_LOAD_CARDS_ON_SALE_SUCC_U(packet);
//                break;
//                
//            case PT_UPGRADE_CARD_SUCC_U:
//                onPT_UPGRADE_CARD_SUCC_U(packet);
//                break;
//                
//            case PT_ACQUIRE_CHEST_SUCC_U:
//                onPT_ACQUIRE_CHEST_SUCC_U(packet);
//                break;
//                
//            // 二人死斗 游戏房间搜索信息
//            case PT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U:
//                onPT_DOUBLE_BATTLE_SEARCH_ROOM_SUCC_U(packet);
//                break;
//                
//            // 二人死斗 更新玩家列表
//            case PT_DOUBLE_BATTLE_UPDATE_USER_LIST_M:
//                onPT_DOUBLE_BATTLE_UPDATE_USER_LIST_M(packet);
//                break;
//                
//            // 二人死斗 游戏开始
//            case PT_DOUBLE_BATTLE_START_GAME_M:
//                onPT_DOUBLE_BATTLE_START_GAME_M(packet);
//                break;
//                
//            // 二人死斗 游戏结束消息
//            case PT_DOUBLE_BATTLE_END_M:
//                onPT_DOUBLE_BATTLE_END_M(packet);
//                break;
//                
//            // 二人死斗 插入飞机 成功
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_SUCC_M(packet);
//                break;
//                
//            // 二人死斗 插入飞机 成功
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_PLANE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_PLANE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_PLANE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_STEALTH_PLANE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_STEALTH_PLANE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_STEALTH_PLANE_FAIL_U(packet);
//                break;
//                
//            // 处理从服务器传来的武器布设消息
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_SUCC_M(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_SUCC_M(packet);
//                break;
//                
//            // 插入武器失败消息
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_ANTI_STEALTH_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_ANTI_STEALTH_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_ANTI_STEALTH_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_MISSILE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_MISSILE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_MISSILE_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_RADAR_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_SENIOR_CANNONBALL_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_MIDDLE_CANNONBALL_FAIL_U(packet);
//                break;
//                
//            case PT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U:
//                onPT_DOUBLE_BATTLE_INSERT_JUNIOR_CANNONBALL_FAIL_U(packet);
//                break;
//                
//                
//                // 二人死斗 游戏时间等 定时更新信息
//            case PT_DOUBLE_BATTLE_UPDATE_U:
//                onPT_DOUBLE_BATTLE_UPDATE_U(packet);
//                break;
//                
////            // 从服务器端接收飞机被击毁的消息
////            case PT_DOUBLE_BATTLE_PLANE_DOWN_M:
////                onPT_DOUBLE_BATTLE_PLANE_DOWN_M(packet);
////                break;
        }
    }
    Close();
}







































