//#include "OutputProc.h"
//#include "DataType.h"
//#include "cocos2d.h"
//#include "UserInstance.h"
//
//USING_NS_CC;
//
//COutputProc::COutputProc(void)
//{
//}
//
//
//COutputProc::~COutputProc(void)
//{
//}
//
//VOID COutputProc::OutputUserAccountInfo(VOID *Object)
//{
//	S_USER_ACCOUNT_INFO* userAccountInfo = (S_USER_ACCOUNT_INFO*) Object;
//	log("1. USER_ID = %d\n", userAccountInfo->USER_ID);
//	log("2. NICKNAME = %s\n", userAccountInfo->NICKNAME);
//	log("3. PASSWORD = %s\n", userAccountInfo->PASSWORD);
//	log("4. BIND_ACCOUNT_TYPE = %s\n", userAccountInfo->BIND_ACCOUNT_TYPE);
//	log("5. BIND_ACCOUNT = %s\n", userAccountInfo->BIND_ACCOUNT);
//	log("6. CELLPHONE_NO = %s\n", userAccountInfo->CELLPHONE_NO);
//	log("7. INTEGRAL_POINTS = %d\n", userAccountInfo->INTEGRAL_POINTS);
//	log("8. LEVEL = %d\n", userAccountInfo->LEVEL);
//	log("9. DIAMONDS = %d\n", userAccountInfo->DIAMONDS);
//	log("10. COINS = %d\n", userAccountInfo->COINS);
//	log("11. WIN_TIMES = %d\n", userAccountInfo->WIN_TIMES);
//	log("12. BATTLE_TIMES = %d\n", userAccountInfo->BATTLE_TIMES);
//	log("13. WIN_RATE = %f\n", userAccountInfo->WIN_RATE);
//	log("14. SHOT_DOWN_PLANES = %d\n", userAccountInfo->SHOT_DOWN_PLANES);
//	log("15. SHOT_DOWN_JUNIOR_PLANES = %d\n", userAccountInfo->SHOT_DOWN_JUNIOR_PLANES);
//	log("16. SHOT_DOWN_MIDDLE_PLANES = %d\n", userAccountInfo->SHOT_DOWN_MIDDLE_PLANES);
//	log("17. SHOT_DOWN_SENIOR_PLANES = %d\n", userAccountInfo->SHOT_DOWN_SENIOR_PLANES);
//	log("18. SESSION_ID = %d\n", userAccountInfo->SESSION_ID);
//}
//
//VOID COutputProc::OutputAddNicknameSuccInfo(S_PT_ADD_NICKNAME_SUCC_U ptAddNicknameSuccU)
//{
//	log("1. NICKNAME = %s\n", ptAddNicknameSuccU.NICKNAME);
//}
//
//VOID COutputProc::OutputAddBindAccountSuccInfo(S_PT_ADD_BIND_ACCOUNT_SUCC_U ptAddBindAccountSuccU)
//{
//	log("1. BIND_ACCOUNT_TYPE = %s\n", ptAddBindAccountSuccU.BIND_ACCOUNT_TYPE);
//	log("2. BIND_ACCOUNT = %s\n", ptAddBindAccountSuccU.BIND_ACCOUNT);
//}
//
//VOID COutputProc::OutputAddCellphoneNoSuccInfo(S_PT_ADD_CELLPHONE_NO_SUCC_U ptAddCellphoneNoSuccU)
//{
//	log("1. CELLPHONE_NO = %s\n", ptAddCellphoneNoSuccU.CELLPHONE_NO);
//}
//
//VOID COutputProc::OutputUpdatePasswordSuccInfo(S_PT_UPDATE_PASSWORD_SUCC_U ptUpdatePasswordSuccU)
//{
//	log("1. NEW_PASSWORD = %s\n", ptUpdatePasswordSuccU.NEW_PASSWORD);
//}
//
//VOID COutputProc::OutputUpdateNicknameSuccInfo(S_PT_UPDATE_NICKNAME_SUCC_U ptUpdateNicknameSuccU)
//{
//	log("1. NEW_NICKNAME = %s\n", ptUpdateNicknameSuccU.NEW_NICKNAME);
//}
//
//VOID COutputProc::OutputUpdateCellphoneNoSuccInfo(S_PT_UPDATE_CELLPHONE_NO_SUCC_U ptUpdateCellphoneNoSuccInfo)
//{
//	log("1. NEW_CELLPHONE_NO = %s\n", ptUpdateCellphoneNoSuccInfo.NEW_CELLPHONE_NO);
//}
//
//VOID COutputProc::OutputUpdateRecordSuccInfo(S_PT_UPDATE_RECORD_SUCC_U ptUpdateRecordSuccU)
//{
//	log("1. INTEGRAL_POINTS = %d\n", ptUpdateRecordSuccU.INTEGRAL_POINTS);
//	log("2. LEVEL = %d\n", ptUpdateRecordSuccU.LEVEL);
//	log("3. DIAMONDS = %d\n", ptUpdateRecordSuccU.DIAMONDS);
//	log("4. COINS = %d\n", ptUpdateRecordSuccU.COINS);
//	log("5. WIN_TIMES = %d\n", ptUpdateRecordSuccU.WIN_TIMES);
//	log("6. BATTLE_TIMES = %d\n", ptUpdateRecordSuccU.BATTLE_TIMES);
//	log("7. WIN_RATE = %f\n", ptUpdateRecordSuccU.WIN_RATE);
//	log("8. SHOT_DOWN_PLANES = %d\n", ptUpdateRecordSuccU.SHOT_DOWN_PLANES);
//	log("9. SHOT_DOWN_JUNIOR_PLANES = %d\n", ptUpdateRecordSuccU.SHOT_DOWN_JUNIOR_PLANES);
//	log("10. SHOT_DOWN_MIDDLE_PLANES = %d\n", ptUpdateRecordSuccU.SHOT_DOWN_MIDDLE_PLANES);
//	log("11. SHOT_DOWN_SENIOR_PLANES = %d\n", ptUpdateRecordSuccU.SHOT_DOWN_SENIOR_PLANES);
//}