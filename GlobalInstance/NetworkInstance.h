#pragma once
#include "NetworkSession.h"
#include "Stream.h"

class CNetworkInstance
{
private:
	CNetworkInstance();
	virtual ~CNetworkInstance();
	bool init();

	static CNetworkInstance* networkInstance;
	CNetworkSession* mNetworkSession;
	CStream* mSendBuf;
public:
	static CNetworkInstance* getInstance();
	void setNetworkSession(CNetworkSession* networkSession) { mNetworkSession = networkSession; };
	CNetworkSession* getNetworkSession() { return mNetworkSession; };

	void setSendBuf() { mSendBuf->SetBuffer(); };
	CStream* getSendBuf() { return mSendBuf; };
};
