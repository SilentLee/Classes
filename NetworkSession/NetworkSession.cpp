//#include "stdafx.h"
#include "NetworkSession.h"
#include "Crypt.h"
//#include "NetworkParams.h"
#include "Global.h"

CNetworkSession::CNetworkSession(void)
{
}


CNetworkSession::~CNetworkSession(void)
{
}

BOOL CNetworkSession::Begin()
{
	CThreadSync Sync;

	mCurrentPacketNumber = 0;
	memset(mPacketBuffer, 0, sizeof(mPacketBuffer));
	mLastReadPacketNumber = 0;
	mRemainLength = 0;
//	mRecvDataCompleteEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	if (!WriteQueue.Begin())
		return FALSE;

    
	if(!Init())
		return FALSE;

	if(!Create(AF_INET, SOCK_STREAM, 0))
		return FALSE;

//	if(!Create(AF_INET, SOCK_DGRAM, 0))
//		return FALSE;
	
	if(!Connect(IP_ADDRESS, IP_PORT))
		return FALSE;

	std::thread recvThread = std::thread(&CNetworkSession::RecvData, this);
	recvThread.detach();

	return TRUE;
}

BOOL CNetworkSession::End()
{
	CThreadSync Sync;

	if (!WriteQueue.End())
		return FALSE;

	Close();

	return TRUE;
}

BOOL CNetworkSession::WritePacket(DWORD protocol, const BYTE *packet, DWORD packetLength)
{
	CThreadSync Sync;

	if (!packet)
		return FALSE;

	// LENGTH(4) | PACKET_NUMBER(4) | PROTOCOL(4) | DATA (4084)
	DWORD PacketLength = sizeof(DWORD)/*LENGTH*/ + 
		sizeof(DWORD)/*PACKETNUMBER*/ + 
		sizeof(DWORD)/*PROTOCOL*/ + 
		packetLength;

	if (PacketLength >= MAX_BUFFER_LENGTH)
		return FALSE;

	mCurrentPacketNumber++;

	BYTE TempBuffer[MAX_BUFFER_LENGTH] = {0,};
    
	memcpy(TempBuffer, &PacketLength, sizeof(DWORD));
	
	memcpy(TempBuffer + 
		sizeof(DWORD)/*LENGTH*/, 
		&mCurrentPacketNumber, sizeof(DWORD));
	
	memcpy(TempBuffer + 
		sizeof(DWORD)/*LENGTH*/ + 
		sizeof(DWORD)/*PACKETNUMBER*/, 
		&protocol, sizeof(DWORD));

	memcpy(TempBuffer + 
		sizeof(DWORD)/*LENGTH*/ + 
		sizeof(DWORD)/*PACKETNUMBER*/ +
		sizeof(DWORD)/*PROTOCOL*/,
		packet, packetLength);

	CCrypt::Encrypt(TempBuffer + sizeof(DWORD), TempBuffer + sizeof(DWORD), PacketLength - sizeof(DWORD));

	BYTE *WriteData = WriteQueue.Push(this, TempBuffer, PacketLength);
    
	if(Send((const char*)WriteData, PacketLength, 0)<0) 
	{
		return FALSE;
	}
	
	return TRUE;
}

BOOL CNetworkSession::GetPacket(DWORD &protocol, BYTE *packet, DWORD &packetLength)
{
	CThreadSync Sync;

	if (!packet)
		return FALSE;
    
	if (mRemainLength < sizeof(DWORD))
		return FALSE;

	INT PacketLength = 0;
	memcpy(&PacketLength, mPacketBuffer, sizeof(INT));

	if (PacketLength > MAX_BUFFER_LENGTH || PacketLength <= 0) // Invalid Packet
	{
		mRemainLength = 0;
		return FALSE;
	}
    
	if (PacketLength <= mRemainLength)
	{
		CCrypt::Decrypt(mPacketBuffer + sizeof(DWORD)/*LENGTH*/, 
			mPacketBuffer + sizeof(DWORD)/*LENGTH*/, 
			PacketLength - sizeof(DWORD)/*LENGTH*/);

		DWORD PacketNumber	= 0;
		DWORD Protocol		= 0;

		memcpy(&PacketNumber, mPacketBuffer + sizeof(DWORD)/*LENGTH*/, sizeof(DWORD)); // 获取数据包的编号
		memcpy(&Protocol, mPacketBuffer + 
			sizeof(DWORD)/*LENGTH*/ + 
			sizeof(DWORD)/*PACKETNUMBER*/, sizeof(DWORD));
        
		protocol		= Protocol;
		packetLength	= PacketLength - 
			sizeof(DWORD)/*LENGTH*/ - 
			sizeof(DWORD)/*PACKETNUMBER*/ - 
			sizeof(DWORD)/*PROTOCOL*/;

		memcpy(packet, mPacketBuffer + 
			sizeof(DWORD)/*LENGTH*/ + 
			sizeof(DWORD)/*PACKETNUMBER*/ + 
			sizeof(DWORD)/*PROTOCOL*/, packetLength);

		if (mRemainLength - PacketLength > 0)
			memmove(mPacketBuffer, mPacketBuffer + PacketLength, mRemainLength - PacketLength);

		mRemainLength -= PacketLength;

		if (mRemainLength <= 0)
		{
			mRemainLength = 0;
			memset(mPacketBuffer, 0, sizeof(mPacketBuffer));
		}

		if (PacketNumber <= mLastReadPacketNumber)
			return FALSE;
		else
		{
			mLastReadPacketNumber = PacketNumber;
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CNetworkSession::WriteComplete(VOID)
{
	CThreadSync Sync;

	return WriteQueue.Pop();
}