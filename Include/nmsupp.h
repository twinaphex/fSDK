/*+@@file@@----------------------------------------------------------------*//*!
 \file		nmsupp.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sat Sep  3 17:33:12 2016
 \date		Modified on Sat Sep  3 17:33:12 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#if !defined(_NMSUPP_H)
#define _NMSUPP_H
#if __POCC__ >= 500
#pragma once
#endif
#pragma pack(1)
#define WINDOWS_VERSION_UNKNOWN     0
#define WINDOWS_VERSION_WIN32S      1
#define WINDOWS_VERSION_WIN32C      2
#define WINDOWS_VERSION_WIN32       3
#define FRAME_MASK_ETHERNET         ((BYTE) ~0x01)
#define FRAME_MASK_TOKENRING        ((BYTE) ~0x80)
#define FRAME_MASK_FDDI             ((BYTE) ~0x01)
typedef enum _ACCESSRIGHTS
{
    AccessRightsNoAccess,
    AccessRightsMonitoring,
    AccessRightsUserAccess,
    AccessRightsAllAccess
} ACCESSRIGHTS;
typedef ACCESSRIGHTS *PACCESSRIGHTS;
typedef LPVOID HPASSWORD;
#define HANDLE_TYPE_PASSWORD            MAKE_IDENTIFIER('P', 'W', 'D', '$')
typedef LPVOID HOBJECTHEAP;
typedef VOID(WINAPI *OBJECTPROC) (HOBJECTHEAP, LPVOID);
#pragma pack()
typedef struct _TIMER *HTIMER;
typedef VOID(WINAPI *BHTIMERPROC) (LPVOID);
extern HTIMER WINAPI BhSetTimer(BHTIMERPROC TimerProc, LPVOID InstData, DWORD TimeOut);
extern VOID WINAPI BhKillTimer(HTIMER hTimer);
extern LPVOID WINAPI BhAllocSystemMemory(DWORD nBytes);
extern LPVOID WINAPI BhFreeSystemMemory(LPVOID ptr);
extern LPVOID WINAPI BhGetNetworkRequestAddress(DWORD NalRequestType);
extern DWORD WINAPI BhGetLastError(VOID);
extern DWORD WINAPI BhSetLastError(DWORD Error);
extern HOBJECTHEAP WINAPI CreateObjectHeap(DWORD ObjectSize, OBJECTPROC ObjectProc);
extern HOBJECTHEAP WINAPI DestroyObjectHeap(HOBJECTHEAP hObjectHeap);
extern LPVOID WINAPI AllocObject(HOBJECTHEAP hObjectHeap);
extern LPVOID WINAPI FreeObject(HOBJECTHEAP hObjectHeap, LPVOID ObjectMemory);
extern DWORD WINAPI GrowObjectHeap(HOBJECTHEAP hObjectHeap, DWORD nObjects);
extern DWORD WINAPI GetObjectHeapSize(HOBJECTHEAP hObjectHeap);
extern VOID WINAPI PurgeObjectHeap(HOBJECTHEAP hObjectHeap);
extern LPVOID WINAPI AllocMemory(SIZE_T size);
extern LPVOID WINAPI ReallocMemory(LPVOID ptr, SIZE_T NewSize);
extern VOID WINAPI FreeMemory(LPVOID ptr);
extern VOID WINAPI TestMemory(LPVOID ptr);
extern SIZE_T WINAPI MemorySize(LPVOID ptr);
extern HANDLE WINAPI MemoryHandle(LPBYTE ptr);
extern HPASSWORD WINAPI CreatePassword(LPSTR password);
extern VOID WINAPI DestroyPassword(HPASSWORD hPassword);
extern ACCESSRIGHTS WINAPI ValidatePassword(HPASSWORD hPassword);
extern LPEXPRESSION WINAPI InitializeExpression(LPEXPRESSION Expression);
extern LPPATTERNMATCH WINAPI InitializePattern(LPPATTERNMATCH Pattern, LPVOID ptr, DWORD offset, DWORD length);
extern LPEXPRESSION WINAPI AndExpression(LPEXPRESSION Expression, LPPATTERNMATCH Pattern);
extern LPEXPRESSION WINAPI OrExpression(LPEXPRESSION Expression, LPPATTERNMATCH Pattern);
extern LPPATTERNMATCH WINAPI NegatePattern(LPPATTERNMATCH Pattern);
extern LPADDRESSTABLE WINAPI AdjustOperatorPrecedence(LPADDRESSTABLE AddressTable);
extern LPADDRESS WINAPI NormalizeAddress(LPADDRESS Address);
extern LPADDRESSTABLE WINAPI NormalizeAddressTable(LPADDRESSTABLE AddressTable);
extern HANDLE WINAPI BhOpenService(LPSTR ServiceName);
extern VOID WINAPI BhCloseService(HANDLE ServiceHandle);
extern DWORD WINAPI BhStartService(HANDLE ServiceHandle);
extern DWORD WINAPI BhStopService(HANDLE ServiceHandle);
extern DWORD WINAPI BhGetWindowsVersion(VOID);
extern BOOL WINAPI IsDaytona(VOID);
extern VOID _cdecl dprintf(LPSTR format, ...);
#endif
