/*+@@file@@----------------------------------------------------------------*//*!
 \file		wlanihv.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sun Sep  4 23:12:57 2016
 \date		Modified on Sun Sep  4 23:12:57 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#ifndef __WLAN_IHV_H__
#define __WLAN_IHV_H__
#if __POCC__ >= 500
#pragma once
#endif
#include <windot11.h>
#include <wlclient.h>
#include <l2cmn.h>
#include <WlanIhvTypes.h>
#include <dot1x.h>
typedef struct _DOT11EXT_APIS DOT11EXT_APIS, *PDOT11EXT_APIS;
typedef struct _DOT11EXT_IHV_HANDLERS DOT11EXT_IHV_HANDLERS, *PDOT11EXT_IHV_HANDLERS;
typedef struct _DOT11EXT_VIRTUAL_STATION_APIS DOT11EXT_VIRTUAL_STATION_APIS, *PDOT11EXT_VIRTUAL_STATION_APIS;
typedef struct _DOT11_IHV_VERSION_INFO
{
   DWORD    dwVerMin;
   DWORD    dwVerMax;
} DOT11_IHV_VERSION_INFO, *PDOT11_IHV_VERSION_INFO;
typedef enum _DOT11EXT_IHV_CONNECTION_PHASE
{
   connection_phase_any,
   connection_phase_initial_connection,
   connection_phase_post_l3_connection
} DOT11EXT_IHV_CONNECTION_PHASE, *PDOT11EXT_IHV_CONNECTION_PHASE;
typedef struct _DOT11EXT_IHV_UI_REQUEST
{
   DWORD    dwSessionId;
   GUID     guidUIRequest;
   CLSID    UIPageClsid;
   DWORD    dwByteCount;
   BYTE*    pvUIRequest;
} DOT11EXT_IHV_UI_REQUEST, *PDOT11EXT_IHV_UI_REQUEST;
typedef enum _DOT11_MSONEX_RESULT
{
    DOT11_MSONEX_SUCCESS,
    DOT11_MSONEX_FAILURE,
    DOT11_MSONEX_IN_PROGRESS
} DOT11_MSONEX_RESULT, *PDOT11_MSONEX_RESULT;
typedef struct _DOT11_EAP_RESULT 
{
   UINT32 dwFailureReasonCode;
   EAP_ATTRIBUTES* pAttribArray;
} DOT11_EAP_RESULT, *PDOT11_EAP_RESULT;
typedef struct _DOT11_MSONEX_RESULT_PARAMS
{
    ONEX_AUTH_STATUS Dot11OnexAuthStatus;
    ONEX_REASON_CODE Dot11OneXReasonCode;
    PBYTE pbMPPESendKey;
    DWORD dwMPPESendKeyLen;
    PBYTE pbMPPERecvKey;
    DWORD dwMPPERecvKeyLen;
    PDOT11_EAP_RESULT pDot11EapResult;
} DOT11_MSONEX_RESULT_PARAMS, *PDOT11_MSONEX_RESULT_PARAMS;
typedef struct _DOT11EXT_IHV_CONNECTIVITY_PROFILE
{
    LPWSTR pszXmlFragmentIhvConnectivity;
} DOT11EXT_IHV_CONNECTIVITY_PROFILE, *PDOT11EXT_IHV_CONNECTIVITY_PROFILE;
typedef struct _DOT11EXT_IHV_SECURITY_PROFILE
{
	LPWSTR pszXmlFragmentIhvSecurity;
	BOOL bUseMSOnex;
} DOT11EXT_IHV_SECURITY_PROFILE, *PDOT11EXT_IHV_SECURITY_PROFILE;
typedef struct _DOT11EXT_IHV_DISCOVERY_PROFILE
{
    DOT11EXT_IHV_CONNECTIVITY_PROFILE   IhvConnectivityProfile;
    DOT11EXT_IHV_SECURITY_PROFILE       IhvSecurityProfile;
} DOT11EXT_IHV_DISCOVERY_PROFILE, *PDOT11EXT_IHV_DISCOVERY_PROFILE;
typedef struct _DOT11EXT_IHV_DISCOVERY_PROFILE_LIST
{
	DWORD dwCount;
	PDOT11EXT_IHV_DISCOVERY_PROFILE pIhvDiscoveryProfiles;
} DOT11EXT_IHV_DISCOVERY_PROFILE_LIST, *PDOT11EXT_IHV_DISCOVERY_PROFILE_LIST;
typedef enum _DOT11EXT_IHV_INDICATION_TYPE
{
    IndicationTypeNicSpecificNotification,
    IndicationTypePmkidCandidateList,
    IndicationTypeTkipMicFailure,
    IndicationTypePhyStateChange,
    IndicationTypeLinkQuality
} DOT11EXT_IHV_INDICATION_TYPE, *PDOT11EXT_IHV_INDICATION_TYPE;
#define DOT11EXT_PSK_MAX_LENGTH 64
typedef struct _DOT11EXT_VIRTUAL_STATION_AP_PROPERTY
{
    DOT11_SSID              dot11SSID;
    DOT11_AUTH_ALGORITHM    dot11AuthAlgo;
    DOT11_CIPHER_ALGORITHM  dot11CipherAlgo;
    BOOL                    bIsPassPhrase;
    DWORD                   dwKeyLength;
    UCHAR                   ucKeyData[DOT11EXT_PSK_MAX_LENGTH];
} DOT11EXT_VIRTUAL_STATION_AP_PROPERTY, *PDOT11EXT_VIRTUAL_STATION_AP_PROPERTY;
#define WDIAG_IHV_WLAN_ID_FLAG_SECURITY_ENABLED               0x00000001
typedef struct _WDIAG_IHV_WLAN_ID
{
	WCHAR strProfileName[MS_MAX_PROFILE_NAME_LENGTH];
	DOT11_SSID Ssid;
	DOT11_BSS_TYPE BssType;
	DWORD dwFlags;
	DWORD dwReasonCode;
} WDIAG_IHV_WLAN_ID, *PWDIAG_IHV_WLAN_ID;
typedef DWORD(WINAPI * DOT11EXT_ALLOCATE_BUFFER) (DWORD dwByteCount, LPVOID * ppvBuffer);
typedef VOID(WINAPI * DOT11EXT_FREE_BUFFER) (LPVOID pvMemory);
typedef DWORD(WINAPI * DOT11EXT_SET_PROFILE_CUSTOM_USER_DATA) (HANDLE hDot11SvcHandle, HANDLE hConnectSession, DWORD dwSessionID, DWORD dwDataSize, LPVOID pvData);
typedef DWORD(WINAPI *DOT11EXT_GET_PROFILE_CUSTOM_USER_DATA) (HANDLE hDot11SvcHandle, HANDLE hConnectSession, DWORD dwSessionID, DWORD *pdwDataSize, LPVOID *ppvData);
typedef DWORD(WINAPI *DOT11EXT_SET_CURRENT_PROFILE) (HANDLE hDot11SvcHandle, HANDLE hConnectSession, PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile, PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile);
typedef DWORD(WINAPI *DOT11EXT_SEND_UI_REQUEST) (HANDLE hDot11SvcHandle, PDOT11EXT_IHV_UI_REQUEST pIhvUIRequest);
typedef DWORD(WINAPI *DOT11EXT_PRE_ASSOCIATE_COMPLETION) (HANDLE hDot11SvcHandle, HANDLE hConnectSession, DWORD dwReasonCode, DWORD dwWin32Error);
typedef DWORD(WINAPI *DOT11EXT_POST_ASSOCIATE_COMPLETION) (HANDLE hDot11SvcHandle, HANDLE hSecuritySessionID, PDOT11_MAC_ADDRESS pPeer, DWORD dwReasonCode, DWORD dwWin32Error);
typedef DWORD(WINAPI *DOT11EXT_SEND_NOTIFICATION) (HANDLE hDot11SvcHandle, PL2_NOTIFICATION_DATA pNotificationData);
typedef DWORD(WINAPI *DOT11EXT_SEND_PACKET) (HANDLE hDot11SvcHandle, ULONG uPacketLen, LPVOID pvPacket, HANDLE hSendCompletion);
typedef DWORD(WINAPI *DOT11EXT_SET_ETHERTYPE_HANDLING) (HANDLE hDot11SvcHandle, ULONG uMaxBackLog, ULONG uNumOfExemption, PDOT11_PRIVACY_EXEMPTION pExemption, ULONG uNumOfRegistration, USHORT *pusRegistration);
typedef DWORD(WINAPI *DOT11EXT_SET_AUTH_ALGORITHM) (HANDLE hDot11SvcHandle, DWORD dwAuthAlgo);
typedef DWORD(WINAPI *DOT11EXT_SET_UNICAST_CIPHER_ALGORITHM) (HANDLE hDot11SvcHandle, DWORD dwUnicastCipherAlgo);
typedef DWORD(WINAPI *DOT11EXT_SET_MULTICAST_CIPHER_ALGORITHM) (HANDLE hDot11SvcHandle, DWORD dwMulticastCipherAlgo);
typedef DWORD(WINAPI *DOT11EXT_SET_DEFAULT_KEY) (HANDLE hDot11SvcHandle, PDOT11_CIPHER_DEFAULT_KEY_VALUE pKey, DOT11_DIRECTION dot11Direction);
typedef DWORD(WINAPI *DOT11EXT_SET_KEY_MAPPING_KEY) (HANDLE hDot11SvcHandle, PDOT11_CIPHER_KEY_MAPPING_KEY_VALUE pKey);
typedef DWORD(WINAPI *DOT11EXT_SET_DEFAULT_KEY_ID) (HANDLE hDot11SvcHandle, ULONG uDefaultKeyId);
typedef DWORD(WINAPI *DOT11EXT_SET_EXCLUDE_UNENCRYPTED) (HANDLE hDot11SvcHandle, BOOL bExcludeUnencrypted);
typedef DWORD(WINAPI *DOT11EXT_NIC_SPECIFIC_EXTENSION) (HANDLE hDot11SvcHandle, DWORD dwInBufferSize, LPVOID pvInBuffer, DWORD *pdwOutBufferSize, LPVOID pvOutBuffer);
typedef DWORD(WINAPI *DOT11EXT_ONEX_START) (HANDLE hDot11SvcHandle, EAP_ATTRIBUTES *pEapAttributes);
typedef DWORD(WINAPI *DOT11EXT_ONEX_STOP) (HANDLE hDot11SvcHandle);
typedef DWORD(WINAPI *DOT11EXT_PROCESS_ONEX_PACKET) (HANDLE hDot11SvcHandle, DWORD dwInPacketSize, LPVOID pvInPacket);
typedef DWORD(WINAPI *DOT11EXT_REQUEST_VIRTUAL_STATION) (HANDLE hDot11PrimaryHandle, LPVOID pvReserved);
typedef DWORD(WINAPI *DOT11EXT_RELEASE_VIRTUAL_STATION) (HANDLE hDot11PrimaryHandle, LPVOID pvReserved);
typedef DWORD(WINAPI *DOT11EXT_QUERY_VIRTUAL_STATION_PROPERTIES) (HANDLE hDot11SvcHandle, BOOL *pbIsVirtualStation, GUID *pgPrimary, LPVOID pvReserved);
typedef DWORD(WINAPI *DOT11EXT_SET_VIRTUAL_STATION_AP_PROPERTIES) (HANDLE hDot11SvcHandle, HANDLE hConnectSession, DWORD dwNumProperties, PDOT11EXT_VIRTUAL_STATION_AP_PROPERTY pProperties, LPVOID pvReserved);
#define  IHV_VERSION_FUNCTION_NAME  "Dot11ExtIhvGetVersionInfo"
#define  IHV_INIT_FUNCTION_NAME     "Dot11ExtIhvInitService"
#define  IHV_INIT_VS_FUNCTION_NAME  "Dot11ExtIhvInitVirtualStation"
typedef DWORD(WINAPI *DOT11EXTIHV_GET_VERSION_INFO) (PDOT11_IHV_VERSION_INFO pDot11IHVVersionInfo);
typedef DWORD(WINAPI *DOT11EXTIHV_INIT_SERVICE) (DWORD dwVerNumUsed, PDOT11EXT_APIS pDot11ExtAPI, LPVOID pvReserved, PDOT11EXT_IHV_HANDLERS pDot11IHVHandlers);
typedef DWORD(WINAPI *DOT11EXTIHV_INIT_VIRTUAL_STATION) (PDOT11EXT_VIRTUAL_STATION_APIS pDot11ExtVSAPI, LPVOID pvReserved);
typedef VOID(WINAPI *DOT11EXTIHV_DEINIT_SERVICE) (VOID);
typedef DWORD(WINAPI *DOT11EXTIHV_INIT_ADAPTER) (PDOT11_ADAPTER pDot11Adapter, HANDLE hDot11SvcHandle, PHANDLE phIhvExtAdapter);
typedef VOID(WINAPI *DOT11EXTIHV_DEINIT_ADAPTER) (HANDLE hIhvExtAdapter);
typedef DWORD(WINAPI *DOT11EXTIHV_PERFORM_PRE_ASSOCIATE) (HANDLE hIhvExtAdapter, HANDLE hConnectSession, PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams, PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile, PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile, PDOT11_BSS_LIST pConnectableBssid, PDWORD pdwReasonCode);
typedef DWORD(WINAPI *DOT11EXTIHV_ADAPTER_RESET) (HANDLE hIhvExtAdapter);
typedef DWORD(WINAPI *DOT11EXTIHV_PERFORM_POST_ASSOCIATE) (HANDLE hIhvExtAdapter, HANDLE hSecuritySessionID, PDOT11_PORT_STATE pPortState, ULONG uDot11AssocParamsBytes, PDOT11_ASSOCIATION_COMPLETION_PARAMETERS pDot11AssocParams);
typedef DWORD(WINAPI *DOT11EXTIHV_STOP_POST_ASSOCIATE) (HANDLE hIhvExtAdapter, PDOT11_MAC_ADDRESS pPeer, DOT11_ASSOC_STATUS dot11AssocStatus);
typedef DWORD(WINAPI *DOT11EXTIHV_VALIDATE_PROFILE) (HANDLE hIhvExtAdapter, PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams, PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile, PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile, PDWORD pdwReasonCode);
typedef DWORD(WINAPI *DOT11EXTIHV_PERFORM_CAPABILITY_MATCH) (HANDLE hIhvExtAdapter, PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams, PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile, PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile, PDOT11_BSS_LIST pConnectableBssid, PDWORD pdwReasonCode);
typedef DWORD(WINAPI *DOT11EXTIHV_CREATE_DISCOVERY_PROFILES) (HANDLE hIhvExtAdapter, BOOL bInsecure, PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams, PDOT11_BSS_LIST pConnectableBssid, PDOT11EXT_IHV_DISCOVERY_PROFILE_LIST pIhvDiscoveryProfileList, PDWORD pdwReasonCode);
typedef DWORD(WINAPI *DOT11EXTIHV_PROCESS_SESSION_CHANGE) (ULONG uEventType, PWTSSESSION_NOTIFICATION pSessionNotification);
typedef DWORD(WINAPI *DOT11EXTIHV_RECEIVE_INDICATION) (HANDLE hIhvExtAdapter, DOT11EXT_IHV_INDICATION_TYPE indicationType, ULONG uBufferLength, LPVOID pvBuffer);
typedef DWORD(WINAPI *DOT11EXTIHV_RECEIVE_PACKET) (HANDLE hIhvExtAdapter, DWORD dwInBufferSize, LPVOID pvInBuffer);
typedef DWORD(WINAPI *DOT11EXTIHV_SEND_PACKET_COMPLETION) (HANDLE hSendCompletion);
typedef DWORD(WINAPI *DOT11EXTIHV_IS_UI_REQUEST_PENDING) (GUID guidUIRequest, PBOOL pbIsRequestPending);
typedef DWORD(WINAPI *DOT11EXTIHV_PROCESS_UI_RESPONSE) (GUID guidUIRequest, DWORD dwByteCount, LPVOID pvResponseBuffer);
typedef DWORD(WINAPI *DOT11EXTIHV_QUERY_UI_REQUEST) (HANDLE hIhvExtAdapter, DOT11EXT_IHV_CONNECTION_PHASE connectionPhase, PDOT11EXT_IHV_UI_REQUEST *ppIhvUIRequest);
typedef DWORD(WINAPI *DOT11EXTIHV_ONEX_INDICATE_RESULT) (HANDLE hIhvExtAdapter, DOT11_MSONEX_RESULT msOneXResult, PDOT11_MSONEX_RESULT_PARAMS pDot11MsOneXResultParams);
typedef DWORD(WINAPI *DOT11EXTIHV_CONTROL) (HANDLE hIhvExtAdapter, DWORD dwInBufferSize, PBYTE pInBuffer, DWORD dwOutBufferSize, PBYTE pOutBuffer, PDWORD pdwBytesReturned);
struct _DOT11EXT_APIS
{
   DOT11EXT_ALLOCATE_BUFFER                     Dot11ExtAllocateBuffer;
   DOT11EXT_FREE_BUFFER                         Dot11ExtFreeBuffer;
   DOT11EXT_SET_PROFILE_CUSTOM_USER_DATA        Dot11ExtSetProfileCustomUserData;
   DOT11EXT_GET_PROFILE_CUSTOM_USER_DATA        Dot11ExtGetProfileCustomUserData;
   DOT11EXT_SET_CURRENT_PROFILE                 Dot11ExtSetCurrentProfile;
   DOT11EXT_SEND_UI_REQUEST                     Dot11ExtSendUIRequest;
   DOT11EXT_PRE_ASSOCIATE_COMPLETION            Dot11ExtPreAssociateCompletion;
   DOT11EXT_POST_ASSOCIATE_COMPLETION           Dot11ExtPostAssociateCompletion;
   DOT11EXT_SEND_NOTIFICATION                   Dot11ExtSendNotification;
   DOT11EXT_SEND_PACKET                         Dot11ExtSendPacket;
   DOT11EXT_SET_ETHERTYPE_HANDLING              Dot11ExtSetEtherTypeHandling;
   DOT11EXT_SET_AUTH_ALGORITHM                  Dot11ExtSetAuthAlgorithm;
   DOT11EXT_SET_UNICAST_CIPHER_ALGORITHM        Dot11ExtSetUnicastCipherAlgorithm;
   DOT11EXT_SET_MULTICAST_CIPHER_ALGORITHM      Dot11ExtSetMulticastCipherAlgorithm;
   DOT11EXT_SET_DEFAULT_KEY                     Dot11ExtSetDefaultKey;
   DOT11EXT_SET_KEY_MAPPING_KEY                 Dot11ExtSetKeyMappingKey;
   DOT11EXT_SET_DEFAULT_KEY_ID                  Dot11ExtSetDefaultKeyId;
   DOT11EXT_NIC_SPECIFIC_EXTENSION              Dot11ExtNicSpecificExtension;
   DOT11EXT_SET_EXCLUDE_UNENCRYPTED             Dot11ExtSetExcludeUnencrypted;
   DOT11EXT_ONEX_START                          Dot11ExtStartOneX;
   DOT11EXT_ONEX_STOP                           Dot11ExtStopOneX;
   DOT11EXT_PROCESS_ONEX_PACKET                 Dot11ExtProcessSecurityPacket;
};
struct _DOT11EXT_IHV_HANDLERS
{
   DOT11EXTIHV_DEINIT_SERVICE                   Dot11ExtIhvDeinitService;
   DOT11EXTIHV_INIT_ADAPTER                     Dot11ExtIhvInitAdapter;
   DOT11EXTIHV_DEINIT_ADAPTER                   Dot11ExtIhvDeinitAdapter;
   DOT11EXTIHV_PERFORM_PRE_ASSOCIATE            Dot11ExtIhvPerformPreAssociate;
   DOT11EXTIHV_ADAPTER_RESET                    Dot11ExtIhvAdapterReset;
   DOT11EXTIHV_PERFORM_POST_ASSOCIATE           Dot11ExtIhvPerformPostAssociate;
   DOT11EXTIHV_STOP_POST_ASSOCIATE              Dot11ExtIhvStopPostAssociate;
   DOT11EXTIHV_VALIDATE_PROFILE                 Dot11ExtIhvValidateProfile;
   DOT11EXTIHV_PERFORM_CAPABILITY_MATCH         Dot11ExtIhvPerformCapabilityMatch;
   DOT11EXTIHV_CREATE_DISCOVERY_PROFILES        Dot11ExtIhvCreateDiscoveryProfiles;
   DOT11EXTIHV_PROCESS_SESSION_CHANGE           Dot11ExtIhvProcessSessionChange;
   DOT11EXTIHV_RECEIVE_INDICATION               Dot11ExtIhvReceiveIndication;
   DOT11EXTIHV_RECEIVE_PACKET                   Dot11ExtIhvReceivePacket;
   DOT11EXTIHV_SEND_PACKET_COMPLETION           Dot11ExtIhvSendPacketCompletion;
   DOT11EXTIHV_IS_UI_REQUEST_PENDING            Dot11ExtIhvIsUIRequestPending;
   DOT11EXTIHV_PROCESS_UI_RESPONSE              Dot11ExtIhvProcessUIResponse;
   DOT11EXTIHV_QUERY_UI_REQUEST                 Dot11ExtIhvQueryUIRequest;
   DOT11EXTIHV_ONEX_INDICATE_RESULT             Dot11ExtIhvOnexIndicateResult;
   DOT11EXTIHV_CONTROL                          Dot11ExtIhvControl;
};
struct _DOT11EXT_VIRTUAL_STATION_APIS
{
    DOT11EXT_REQUEST_VIRTUAL_STATION                Dot11ExtRequestVirtualStation;
    DOT11EXT_RELEASE_VIRTUAL_STATION                Dot11ExtReleaseVirtualStation;
    DOT11EXT_QUERY_VIRTUAL_STATION_PROPERTIES       Dot11ExtQueryVirtualStationProperties;
    DOT11EXT_SET_VIRTUAL_STATION_AP_PROPERTIES      Dot11ExtSetVirtualStationAPProperties;
};
#endif