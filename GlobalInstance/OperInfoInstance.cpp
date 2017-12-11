//#include <stdio.h>
#include "OperInfoInstance.h"

COperInfoInstance* COperInfoInstance::operInfoInstance = NULL;

COperInfoInstance::COperInfoInstance()
{

}

COperInfoInstance::~COperInfoInstance()
{

}


bool COperInfoInstance::init()
{
	mIsOperInfoRecv = false;
	mIsBattleFieldSituationUpdate = false;

	return true;
}

COperInfoInstance* COperInfoInstance::getInstance()
{
	if (NULL == operInfoInstance) {
		operInfoInstance = new COperInfoInstance();
		operInfoInstance->init();
	}
	return operInfoInstance;
}

void COperInfoInstance::resetOperInfoInstance()
{
	mIsOperInfoRecv = false;
}