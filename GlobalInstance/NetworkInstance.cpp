#include <stdio.h>
#include "NetworkInstance.h"

USING_NS_CC;

CNetworkInstance* CNetworkInstance::networkInstance = NULL;

CNetworkInstance::CNetworkInstance() {

}

CNetworkInstance::~CNetworkInstance() {

}

bool CNetworkInstance::init() {

	return true;
}

CNetworkInstance* CNetworkInstance::getInstance()
{
	if (NULL == networkInstance) {
		networkInstance = new CNetworkInstance();
		networkInstance->init();
		networkInstance->mSendBuf = new CStream();
	}
	networkInstance->setSendBuf();
	return networkInstance;
}