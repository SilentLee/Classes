//
//  DataType.h
//  originalProject
//
//  Created by 李熙良 on 17/1/14.
//
//

#ifndef DataType_h
#define DataType_h

#include "cocos2d.h"

//#define VOID void
//#define CHAR char
//#define INT int
//#define FLOAT float
//#define DWORD

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "WinDef.h"
#else
#define VOID void
#define FALSE false
#define TRUE true
#define BOOL bool

typedef unsigned int DWORD;
typedef unsigned int ULONG_PTR;

typedef char CHAR;
typedef int INT;
typedef float FLOAT;
//typedef unsigned long DWORD;
typedef wchar_t WCHAR;
//typedef unsigned long BYTE;
typedef long  LONG_PTR;
//typedef unsigned long  ULONG_PTR;
typedef ULONG_PTR  DWORD_PTR;
typedef unsigned short USHORT;
//typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned char UCHAR;
typedef short SHORT;
typedef CHAR* LPCSTR;
typedef char* LPSTR;
typedef wchar_t WCHAR;
typedef WCHAR* LPWSTR;
typedef WCHAR* LPCWSTR;

// ?????????
typedef long long __int64;
typedef signed long long INT64;
//typedef signed __int64 INT64;
#endif






#endif /* DataType_h */
