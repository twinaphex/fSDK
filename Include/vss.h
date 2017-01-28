/*+@@file@@----------------------------------------------------------------*//*!
 \file		vss.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sun Sep  4 18:49:19 2016
 \date		Modified on Sun Sep  4 18:49:19 2016
 \author	frankie
\*//*-@@file@@----------------------------------------------------------------*/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif
#include <rpc.h>
#include <rpcndr.h>
#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif
#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif
#ifndef __vss_h__
#define __vss_h__
#if __POCC__ >= 500
#pragma once
#endif
#ifndef __IVssEnumObject_FWD_DEFINED__
#define __IVssEnumObject_FWD_DEFINED__
typedef interface IVssEnumObject IVssEnumObject;
#endif
#ifndef __IVssAsync_FWD_DEFINED__
#define __IVssAsync_FWD_DEFINED__
typedef interface IVssAsync IVssAsync;
#endif
#include <oaidl.h>
#include <ocidl.h>
#pragma pack(push, 8)
#include <vsserror.h>
typedef enum _VSS_OBJECT_TYPE
{
	VSS_OBJECT_UNKNOWN = 0,
	VSS_OBJECT_NONE = (VSS_OBJECT_UNKNOWN + 1),
	VSS_OBJECT_SNAPSHOT_SET = (VSS_OBJECT_NONE + 1),
	VSS_OBJECT_SNAPSHOT = (VSS_OBJECT_SNAPSHOT_SET + 1),
	VSS_OBJECT_PROVIDER = (VSS_OBJECT_SNAPSHOT + 1),
	VSS_OBJECT_TYPE_COUNT = (VSS_OBJECT_PROVIDER + 1)
} VSS_OBJECT_TYPE;
typedef enum _VSS_OBJECT_TYPE *PVSS_OBJECT_TYPE;
typedef enum _VSS_SNAPSHOT_STATE
{
	VSS_SS_UNKNOWN = 0,
	VSS_SS_PREPARING = (VSS_SS_UNKNOWN + 1),
	VSS_SS_PROCESSING_PREPARE = (VSS_SS_PREPARING + 1),
	VSS_SS_PREPARED = (VSS_SS_PROCESSING_PREPARE + 1),
	VSS_SS_PROCESSING_PRECOMMIT = (VSS_SS_PREPARED + 1),
	VSS_SS_PRECOMMITTED = (VSS_SS_PROCESSING_PRECOMMIT + 1),
	VSS_SS_PROCESSING_COMMIT = (VSS_SS_PRECOMMITTED + 1),
	VSS_SS_COMMITTED = (VSS_SS_PROCESSING_COMMIT + 1),
	VSS_SS_PROCESSING_POSTCOMMIT = (VSS_SS_COMMITTED + 1),
	VSS_SS_PROCESSING_PREFINALCOMMIT = (VSS_SS_PROCESSING_POSTCOMMIT + 1),
	VSS_SS_PREFINALCOMMITTED = (VSS_SS_PROCESSING_PREFINALCOMMIT + 1),
	VSS_SS_PROCESSING_POSTFINALCOMMIT = (VSS_SS_PREFINALCOMMITTED + 1),
	VSS_SS_CREATED = (VSS_SS_PROCESSING_POSTFINALCOMMIT + 1),
	VSS_SS_ABORTED = (VSS_SS_CREATED + 1),
	VSS_SS_DELETED = (VSS_SS_ABORTED + 1),
	VSS_SS_POSTCOMMITTED = (VSS_SS_DELETED + 1),
	VSS_SS_COUNT = (VSS_SS_POSTCOMMITTED + 1)
} VSS_SNAPSHOT_STATE;
typedef enum _VSS_SNAPSHOT_STATE *PVSS_SNAPSHOT_STATE;
typedef enum _VSS_VOLUME_SNAPSHOT_ATTRIBUTES
{
	VSS_VOLSNAP_ATTR_PERSISTENT = 0x1,
	VSS_VOLSNAP_ATTR_NO_AUTORECOVERY = 0x2,
	VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE = 0x4,
	VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE = 0x8,
	VSS_VOLSNAP_ATTR_NO_WRITERS = 0x10,
	VSS_VOLSNAP_ATTR_TRANSPORTABLE = 0x20,
	VSS_VOLSNAP_ATTR_NOT_SURFACED = 0x40,
	VSS_VOLSNAP_ATTR_NOT_TRANSACTED = 0x80,
	VSS_VOLSNAP_ATTR_HARDWARE_ASSISTED = 0x10000,
	VSS_VOLSNAP_ATTR_DIFFERENTIAL = 0x20000,
	VSS_VOLSNAP_ATTR_PLEX = 0x40000,
	VSS_VOLSNAP_ATTR_IMPORTED = 0x80000,
	VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY = 0x100000,
	VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY = 0x200000,
	VSS_VOLSNAP_ATTR_AUTORECOVER = 0x400000,
	VSS_VOLSNAP_ATTR_ROLLBACK_RECOVERY = 0x800000,
	VSS_VOLSNAP_ATTR_DELAYED_POSTSNAPSHOT = 0x1000000,
	VSS_VOLSNAP_ATTR_TXF_RECOVERY = 0x2000000
} VSS_VOLUME_SNAPSHOT_ATTRIBUTES;
typedef enum _VSS_VOLUME_SNAPSHOT_ATTRIBUTES *PVSS_VOLUME_SNAPSHOT_ATTRIBUTES;
typedef enum _VSS_SNAPSHOT_CONTEXT
{
	VSS_CTX_BACKUP = 0,
	VSS_CTX_FILE_SHARE_BACKUP = VSS_VOLSNAP_ATTR_NO_WRITERS,
	VSS_CTX_NAS_ROLLBACK = ((VSS_VOLSNAP_ATTR_PERSISTENT | VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE) | VSS_VOLSNAP_ATTR_NO_WRITERS),
	VSS_CTX_APP_ROLLBACK = (VSS_VOLSNAP_ATTR_PERSISTENT | VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE),
	VSS_CTX_CLIENT_ACCESSIBLE = (((VSS_VOLSNAP_ATTR_PERSISTENT | VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE) | VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE) | VSS_VOLSNAP_ATTR_NO_WRITERS),
	VSS_CTX_CLIENT_ACCESSIBLE_WRITERS = ((VSS_VOLSNAP_ATTR_PERSISTENT | VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE) | VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE),
	VSS_CTX_ALL = 0xffffffff
} VSS_SNAPSHOT_CONTEXT;
typedef enum _VSS_SNAPSHOT_CONTEXT *PVSS_SNAPSHOT_CONTEXT;
typedef enum _VSS_PROVIDER_CAPABILITIES
{
	VSS_PRV_CAPABILITY_LEGACY = 0x1,
	VSS_PRV_CAPABILITY_COMPLIANT = 0x2,
	VSS_PRV_CAPABILITY_LUN_REPOINT = 0x4,
	VSS_PRV_CAPABILITY_LUN_RESYNC = 0x8,
	VSS_PRV_CAPABILITY_OFFLINE_CREATION = 0x10,
	VSS_PRV_CAPABILITY_MULTIPLE_IMPORT = 0x20,
	VSS_PRV_CAPABILITY_RECYCLING = 0x40,
	VSS_PRV_CAPABILITY_PLEX = 0x80,
	VSS_PRV_CAPABILITY_DIFFERENTIAL = 0x100,
	VSS_PRV_CAPABILITY_CLUSTERED = 0x200
} VSS_PROVIDER_CAPABILITIES;
typedef enum _VSS_PROVIDER_CAPABILITIES *PVSS_PROVIDER_CAPABILITIES;
typedef enum _VSS_HARDWARE_OPTIONS
{
	VSS_BREAKEX_FLAG_MASK_LUNS = 0x1,
	VSS_BREAKEX_FLAG_MAKE_READ_WRITE = 0x2,
	VSS_BREAKEX_FLAG_REVERT_IDENTITY_ALL = 0x4,
	VSS_BREAKEX_FLAG_REVERT_IDENTITY_NONE = 0x8,
	VSS_ONLUNSTATECHANGE_NOTIFY_READ_WRITE = 0x100,
	VSS_ONLUNSTATECHANGE_NOTIFY_LUN_PRE_RECOVERY = 0x200,
	VSS_ONLUNSTATECHANGE_NOTIFY_LUN_POST_RECOVERY = 0x400,
	VSS_ONLUNSTATECHANGE_DO_MASK_LUNS = 0x800
} VSS_HARDWARE_OPTIONS;
typedef enum _VSS_HARDWARE_OPTIONS *PVSS_HARDWARE_OPTIONS;
typedef enum _VSS_RECOVERY_OPTIONS
{
	VSS_RECOVERY_REVERT_IDENTITY_ALL = 0x100,
	VSS_RECOVERY_NO_VOLUME_CHECK = 0x200
} VSS_RECOVERY_OPTIONS;
typedef enum _VSS_RECOVERY_OPTIONS *PVSS_RECOVERY_OPTIONS;
typedef enum _VSS_WRITER_STATE
{
	VSS_WS_UNKNOWN = 0,
	VSS_WS_STABLE = (VSS_WS_UNKNOWN + 1),
	VSS_WS_WAITING_FOR_FREEZE = (VSS_WS_STABLE + 1),
	VSS_WS_WAITING_FOR_THAW = (VSS_WS_WAITING_FOR_FREEZE + 1),
	VSS_WS_WAITING_FOR_POST_SNAPSHOT = (VSS_WS_WAITING_FOR_THAW + 1),
	VSS_WS_WAITING_FOR_BACKUP_COMPLETE = (VSS_WS_WAITING_FOR_POST_SNAPSHOT + 1),
	VSS_WS_FAILED_AT_IDENTIFY = (VSS_WS_WAITING_FOR_BACKUP_COMPLETE + 1),
	VSS_WS_FAILED_AT_PREPARE_BACKUP = (VSS_WS_FAILED_AT_IDENTIFY + 1),
	VSS_WS_FAILED_AT_PREPARE_SNAPSHOT = (VSS_WS_FAILED_AT_PREPARE_BACKUP + 1),
	VSS_WS_FAILED_AT_FREEZE = (VSS_WS_FAILED_AT_PREPARE_SNAPSHOT + 1),
	VSS_WS_FAILED_AT_THAW = (VSS_WS_FAILED_AT_FREEZE + 1),
	VSS_WS_FAILED_AT_POST_SNAPSHOT = (VSS_WS_FAILED_AT_THAW + 1),
	VSS_WS_FAILED_AT_BACKUP_COMPLETE = (VSS_WS_FAILED_AT_POST_SNAPSHOT + 1),
	VSS_WS_FAILED_AT_PRE_RESTORE = (VSS_WS_FAILED_AT_BACKUP_COMPLETE + 1),
	VSS_WS_FAILED_AT_POST_RESTORE = (VSS_WS_FAILED_AT_PRE_RESTORE + 1),
	VSS_WS_FAILED_AT_BACKUPSHUTDOWN = (VSS_WS_FAILED_AT_POST_RESTORE + 1),
	VSS_WS_COUNT = (VSS_WS_FAILED_AT_BACKUPSHUTDOWN + 1)
} VSS_WRITER_STATE;
typedef enum _VSS_WRITER_STATE *PVSS_WRITER_STATE;
typedef enum _VSS_BACKUP_TYPE
{
	VSS_BT_UNDEFINED = 0,
	VSS_BT_FULL = (VSS_BT_UNDEFINED + 1),
	VSS_BT_INCREMENTAL = (VSS_BT_FULL + 1),
	VSS_BT_DIFFERENTIAL = (VSS_BT_INCREMENTAL + 1),
	VSS_BT_LOG = (VSS_BT_DIFFERENTIAL + 1),
	VSS_BT_COPY = (VSS_BT_LOG + 1),
	VSS_BT_OTHER = (VSS_BT_COPY + 1)
} VSS_BACKUP_TYPE;
typedef enum _VSS_BACKUP_TYPE *PVSS_BACKUP_TYPE;
typedef enum _VSS_RESTORE_TYPE
{
	VSS_RTYPE_UNDEFINED = 0,
	VSS_RTYPE_BY_COPY = (VSS_RTYPE_UNDEFINED + 1),
	VSS_RTYPE_IMPORT = (VSS_RTYPE_BY_COPY + 1),
	VSS_RTYPE_OTHER = (VSS_RTYPE_IMPORT + 1)
} VSS_RESTORE_TYPE;
typedef enum _VSS_RESTORE_TYPE *PVSS_RESTORE_TYPE;
typedef enum _VSS_ROLLFORWARD_TYPE
{
	VSS_RF_UNDEFINED = 0,
	VSS_RF_NONE = (VSS_RF_UNDEFINED + 1),
	VSS_RF_ALL = (VSS_RF_NONE + 1),
	VSS_RF_PARTIAL = (VSS_RF_ALL + 1)
} VSS_ROLLFORWARD_TYPE;
typedef enum _VSS_ROLLFORWARD_TYPE *PVSS_ROLLFORWARD_TYPE;
typedef enum _VSS_PROVIDER_TYPE
{
	VSS_PROV_UNKNOWN = 0,
	VSS_PROV_SYSTEM = 1,
	VSS_PROV_SOFTWARE = 2,
	VSS_PROV_HARDWARE = 3
} VSS_PROVIDER_TYPE;
typedef enum _VSS_PROVIDER_TYPE *PVSS_PROVIDER_TYPE;
typedef enum _VSS_APPLICATION_LEVEL
{
	VSS_APP_UNKNOWN = 0,
	VSS_APP_SYSTEM = 1,
	VSS_APP_BACK_END = 2,
	VSS_APP_FRONT_END = 3,
	VSS_APP_SYSTEM_RM = 4,
	VSS_APP_AUTO = -1
} VSS_APPLICATION_LEVEL;
typedef enum _VSS_APPLICATION_LEVEL *PVSS_APPLICATION_LEVEL;
typedef enum _VSS_SNAPSHOT_COMPATIBILITY
{
	VSS_SC_DISABLE_DEFRAG = 0x1,
	VSS_SC_DISABLE_CONTENTINDEX = 0x2
} VSS_SNAPSHOT_COMPATIBILITY;
typedef enum _VSS_SNAPSHOT_PROPERTY_ID
{
	VSS_SPROPID_UNKNOWN = 0,
	VSS_SPROPID_SNAPSHOT_ID = 0x1,
	VSS_SPROPID_SNAPSHOT_SET_ID = 0x2,
	VSS_SPROPID_SNAPSHOTS_COUNT = 0x3,
	VSS_SPROPID_SNAPSHOT_DEVICE = 0x4,
	VSS_SPROPID_ORIGINAL_VOLUME = 0x5,
	VSS_SPROPID_ORIGINATING_MACHINE = 0x6,
	VSS_SPROPID_SERVICE_MACHINE = 0x7,
	VSS_SPROPID_EXPOSED_NAME = 0x8,
	VSS_SPROPID_EXPOSED_PATH = 0x9,
	VSS_SPROPID_PROVIDER_ID = 0xa,
	VSS_SPROPID_SNAPSHOT_ATTRIBUTES = 0xb,
	VSS_SPROPID_CREATION_TIMESTAMP = 0xc,
	VSS_SPROPID_STATUS = 0xd
} VSS_SNAPSHOT_PROPERTY_ID;
typedef enum _VSS_SNAPSHOT_PROPERTY_ID *PVSS_SNAPSHOT_PROPERTY_ID;
typedef enum _VSS_FILE_SPEC_BACKUP_TYPE
{
	VSS_FSBT_FULL_BACKUP_REQUIRED = 0x1,
	VSS_FSBT_DIFFERENTIAL_BACKUP_REQUIRED = 0x2,
	VSS_FSBT_INCREMENTAL_BACKUP_REQUIRED = 0x4,
	VSS_FSBT_LOG_BACKUP_REQUIRED = 0x8,
	VSS_FSBT_FULL_SNAPSHOT_REQUIRED = 0x100,
	VSS_FSBT_DIFFERENTIAL_SNAPSHOT_REQUIRED = 0x200,
	VSS_FSBT_INCREMENTAL_SNAPSHOT_REQUIRED = 0x400,
	VSS_FSBT_LOG_SNAPSHOT_REQUIRED = 0x800,
	VSS_FSBT_ALL_BACKUP_REQUIRED = 0xf,
	VSS_FSBT_ALL_SNAPSHOT_REQUIRED = 0xf00
} VSS_FILE_SPEC_BACKUP_TYPE;
typedef enum _VSS_FILE_SPEC_BACKUP_TYPE *PVSS_FILE_SPEC_BACKUP_TYPE;
typedef enum _VSS_BACKUP_SCHEMA
{
	VSS_BS_UNDEFINED = 0,
	VSS_BS_DIFFERENTIAL = 0x1,
	VSS_BS_INCREMENTAL = 0x2,
	VSS_BS_EXCLUSIVE_INCREMENTAL_DIFFERENTIAL = 0x4,
	VSS_BS_LOG = 0x8,
	VSS_BS_COPY = 0x10,
	VSS_BS_TIMESTAMPED = 0x20,
	VSS_BS_LAST_MODIFY = 0x40,
	VSS_BS_LSN = 0x80,
	VSS_BS_WRITER_SUPPORTS_NEW_TARGET = 0x100,
	VSS_BS_WRITER_SUPPORTS_RESTORE_WITH_MOVE = 0x200,
	VSS_BS_INDEPENDENT_SYSTEM_STATE = 0x400,
	VSS_BS_ROLLFORWARD_RESTORE = 0x1000,
	VSS_BS_RESTORE_RENAME = 0x2000,
	VSS_BS_AUTHORITATIVE_RESTORE = 0x4000,
	VSS_BS_WRITER_SUPPORTS_PARALLEL_RESTORES = 0x8000
} VSS_BACKUP_SCHEMA;
typedef enum _VSS_BACKUP_SCHEMA *PVSS_BACKUP_SCHEMA;
typedef GUID VSS_ID;
typedef WCHAR *VSS_PWSZ;
typedef LONGLONG VSS_TIMESTAMP;
typedef struct _VSS_SNAPSHOT_PROP
{
	VSS_ID m_SnapshotId;
	VSS_ID m_SnapshotSetId;
	LONG m_lSnapshotsCount;
	VSS_PWSZ m_pwszSnapshotDeviceObject;
	VSS_PWSZ m_pwszOriginalVolumeName;
	VSS_PWSZ m_pwszOriginatingMachine;
	VSS_PWSZ m_pwszServiceMachine;
	VSS_PWSZ m_pwszExposedName;
	VSS_PWSZ m_pwszExposedPath;
	VSS_ID m_ProviderId;
	LONG m_lSnapshotAttributes;
	VSS_TIMESTAMP m_tsCreationTimestamp;
	VSS_SNAPSHOT_STATE m_eStatus;
} VSS_SNAPSHOT_PROP;
typedef struct _VSS_SNAPSHOT_PROP *PVSS_SNAPSHOT_PROP;
typedef struct _VSS_PROVIDER_PROP
{
	VSS_ID m_ProviderId;
	VSS_PWSZ m_pwszProviderName;
	VSS_PROVIDER_TYPE m_eProviderType;
	VSS_PWSZ m_pwszProviderVersion;
	VSS_ID m_ProviderVersionId;
	CLSID m_ClassId;
} VSS_PROVIDER_PROP;
typedef struct _VSS_PROVIDER_PROP *PVSS_PROVIDER_PROP;
typedef union __MIDL___MIDL_itf_vss_0000_0000_0001
{
	VSS_SNAPSHOT_PROP Snap;
	VSS_PROVIDER_PROP Prov;
} VSS_OBJECT_UNION;
typedef struct _VSS_OBJECT_PROP
{
	VSS_OBJECT_TYPE Type;
	VSS_OBJECT_UNION Obj;
} VSS_OBJECT_PROP;
typedef struct _VSS_OBJECT_PROP *PVSS_OBJECT_PROP;
extern RPC_IF_HANDLE __MIDL_itf_vss_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vss_0000_0000_v0_0_s_ifspec;
#ifndef __IVssEnumObject_INTERFACE_DEFINED__
#define __IVssEnumObject_INTERFACE_DEFINED__
extern const IID IID_IVssEnumObject;
typedef struct IVssEnumObjectVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IVssEnumObject * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IVssEnumObject * This);
	ULONG(STDMETHODCALLTYPE * Release) (IVssEnumObject * This);
	HRESULT(STDMETHODCALLTYPE * Next) (IVssEnumObject * This, ULONG celt, VSS_OBJECT_PROP * rgelt, ULONG * pceltFetched);
	HRESULT(STDMETHODCALLTYPE * Skip) (IVssEnumObject * This, ULONG celt);
	HRESULT(STDMETHODCALLTYPE * Reset) (IVssEnumObject * This);
	HRESULT(STDMETHODCALLTYPE * Clone) (IVssEnumObject * This, IVssEnumObject ** ppenum);
	END_INTERFACE
}  IVssEnumObjectVtbl;
interface IVssEnumObject
{
	CONST_VTBL struct IVssEnumObjectVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IVssEnumObject_QueryInterface(This,riid,ppvObject) ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IVssEnumObject_AddRef(This) ( (This)->lpVtbl -> AddRef(This) )
#define IVssEnumObject_Release(This) ( (This)->lpVtbl -> Release(This) )
#define IVssEnumObject_Next(This,celt,rgelt,pceltFetched) ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) )
#define IVssEnumObject_Skip(This,celt) ( (This)->lpVtbl -> Skip(This,celt) )
#define IVssEnumObject_Reset(This) ( (This)->lpVtbl -> Reset(This) )
#define IVssEnumObject_Clone(This,ppenum) ( (This)->lpVtbl -> Clone(This,ppenum) )
#endif
#endif
#ifndef __IVssAsync_INTERFACE_DEFINED__
#define __IVssAsync_INTERFACE_DEFINED__
extern const IID IID_IVssAsync;
typedef struct IVssAsyncVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IVssAsync * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IVssAsync * This);
	ULONG(STDMETHODCALLTYPE * Release) (IVssAsync * This);
	HRESULT(STDMETHODCALLTYPE * Cancel) (IVssAsync * This);
	HRESULT(STDMETHODCALLTYPE * Wait) (IVssAsync * This, DWORD dwMilliseconds);
	HRESULT(STDMETHODCALLTYPE * QueryStatus) (IVssAsync * This, HRESULT * pHrResult, INT * pReserved);
	END_INTERFACE
}  IVssAsyncVtbl;
interface IVssAsync
{
	CONST_VTBL struct IVssAsyncVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IVssAsync_QueryInterface(This,riid,ppvObject) ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IVssAsync_AddRef(This) ( (This)->lpVtbl -> AddRef(This) )
#define IVssAsync_Release(This) ( (This)->lpVtbl -> Release(This) )
#define IVssAsync_Cancel(This) ( (This)->lpVtbl -> Cancel(This) )
#define IVssAsync_Wait(This,dwMilliseconds) ( (This)->lpVtbl -> Wait(This,dwMilliseconds) )
#define IVssAsync_QueryStatus(This,pHrResult,pReserved) ( (This)->lpVtbl -> QueryStatus(This,pHrResult,pReserved) )
#endif
#endif
#pragma pack(pop)
extern RPC_IF_HANDLE __MIDL_itf_vss_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vss_0000_0002_v0_0_s_ifspec;
#endif
