#pragma once
#include "Global.h"
#include "DataType.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
class CCriticalSection
{
public:
	CCriticalSection(VOID)
	{
		InitializeCriticalSection(&mSync);
	}

	~CCriticalSection(VOID)
	{
		DeleteCriticalSection(&mSync);
	}

	inline VOID Enter(VOID)
	{
		EnterCriticalSection(&mSync);
	}

	inline VOID Leave(VOID)
	{
		LeaveCriticalSection(&mSync);
	}

private:
	CRITICAL_SECTION	mSync;
};
#else
#include <pthread.h>

class CCriticalSection
{
public:
	CCriticalSection(VOID)
	{
		pthread_mutex_init(&mutex, NULL);
	}

	~CCriticalSection(VOID)
	{
		pthread_mutex_destroy(&mutex);
	}

	inline VOID Enter(VOID)
	{
		pthread_mutex_lock(&mutex);
	}

	inline VOID Leave(VOID)
	{
		pthread_mutex_unlock(&mutex);
	}

private:
	pthread_mutex_t mutex;
};
#endif
