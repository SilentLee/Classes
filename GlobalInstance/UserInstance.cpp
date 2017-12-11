
#include "UserInstance.h"

CUserInstance* CUserInstance::userInstance = NULL;

CUserInstance::CUserInstance()
{

}

CUserInstance::~CUserInstance()
{

}


bool CUserInstance::init()
{

	return true;
}

CUserInstance* CUserInstance::getInstance()
{
	if (NULL == userInstance) {
		userInstance = new CUserInstance();
		userInstance->init();
	}
	return userInstance;
}

void CUserInstance::resetUserInstance()
{

}