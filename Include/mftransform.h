/*+@@file@@----------------------------------------------------------------*//*!
 \file		mftransform.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sat Jul  9 22:07:20 2016
 \date		Modified on Sat Jul  9 22:07:20 2016
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
#ifndef __mftransform_h__
#define __mftransform_h__
#if __POCC__ >= 500
#pragma once
#endif
#ifndef __IMFTransform_FWD_DEFINED__
#define __IMFTransform_FWD_DEFINED__
typedef interface IMFTransform IMFTransform;
#endif
#include <mfobjects.h>
enum _MFT_INPUT_DATA_BUFFER_FLAGS
{
	MFT_INPUT_DATA_BUFFER_PLACEHOLDER = 0xffffffff
};
enum _MFT_OUTPUT_DATA_BUFFER_FLAGS
{
	MFT_OUTPUT_DATA_BUFFER_INCOMPLETE = 0x1000000,
	MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE = 0x100,
	MFT_OUTPUT_DATA_BUFFER_STREAM_END = 0x200,
	MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE = 0x300
};
enum _MFT_INPUT_STATUS_FLAGS
{
	MFT_INPUT_STATUS_ACCEPT_DATA = 0x1
};
enum _MFT_OUTPUT_STATUS_FLAGS
{
	MFT_OUTPUT_STATUS_SAMPLE_READY = 0x1
};
enum _MFT_INPUT_STREAM_INFO_FLAGS
{
	MFT_INPUT_STREAM_WHOLE_SAMPLES = 0x1,
	MFT_INPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER = 0x2,
	MFT_INPUT_STREAM_FIXED_SAMPLE_SIZE = 0x4,
	MFT_INPUT_STREAM_HOLDS_BUFFERS = 0x8,
	MFT_INPUT_STREAM_DOES_NOT_ADDREF = 0x100,
	MFT_INPUT_STREAM_REMOVABLE = 0x200,
	MFT_INPUT_STREAM_OPTIONAL = 0x400,
	MFT_INPUT_STREAM_PROCESSES_IN_PLACE = 0x800
};
enum _MFT_OUTPUT_STREAM_INFO_FLAGS
{
	MFT_OUTPUT_STREAM_WHOLE_SAMPLES = 0x1,
	MFT_OUTPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER = 0x2,
	MFT_OUTPUT_STREAM_FIXED_SAMPLE_SIZE = 0x4,
	MFT_OUTPUT_STREAM_DISCARDABLE = 0x8,
	MFT_OUTPUT_STREAM_OPTIONAL = 0x10,
	MFT_OUTPUT_STREAM_PROVIDES_SAMPLES = 0x100,
	MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES = 0x200,
	MFT_OUTPUT_STREAM_LAZY_READ = 0x400,
	MFT_OUTPUT_STREAM_REMOVABLE = 0x800
};
enum _MFT_SET_TYPE_FLAGS
{
	MFT_SET_TYPE_TEST_ONLY = 0x1
};
enum _MFT_PROCESS_OUTPUT_FLAGS
{
	MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER = 0x1
};
enum _MFT_PROCESS_OUTPUT_STATUS
{
	MFT_PROCESS_OUTPUT_STATUS_NEW_STREAMS = 0x100
};
enum _MFT_DRAIN_TYPE
{
	MFT_DRAIN_PRODUCE_TAILS = 0,
	MFT_DRAIN_NO_TAILS = 0x1
};
#define MFT_STREAMS_UNLIMITED       0xFFFFFFFF
#define MFT_OUTPUT_BOUND_LOWER_UNBOUNDED MINLONGLONG
#define MFT_OUTPUT_BOUND_UPPER_UNBOUNDED MAXLONGLONG
typedef enum _MFT_MESSAGE_TYPE
{
	 MFT_MESSAGE_COMMAND_FLUSH = 0,
	MFT_MESSAGE_COMMAND_DRAIN = 0x1,
	MFT_MESSAGE_SET_D3D_MANAGER = 0x2,
	MFT_MESSAGE_DROP_SAMPLES = 0x3,
	MFT_MESSAGE_NOTIFY_BEGIN_STREAMING = 0x10000000,
	MFT_MESSAGE_NOTIFY_END_STREAMING = 0x10000001,
	MFT_MESSAGE_NOTIFY_END_OF_STREAM = 0x10000002,
	MFT_MESSAGE_NOTIFY_START_OF_STREAM = 0x10000003,
	MFT_MESSAGE_COMMAND_MARKER = 0x20000000
} MFT_MESSAGE_TYPE;
typedef struct _MFT_INPUT_STREAM_INFO
{
	LONGLONG hnsMaxLatency;
	DWORD dwFlags;
	DWORD cbSize;
	DWORD cbMaxLookahead;
	DWORD cbAlignment;
} MFT_INPUT_STREAM_INFO;
typedef struct _MFT_OUTPUT_STREAM_INFO
{
	DWORD dwFlags;
	DWORD cbSize;
	DWORD cbAlignment;
} MFT_OUTPUT_STREAM_INFO;
typedef struct _MFT_OUTPUT_DATA_BUFFER
{
	DWORD dwStreamID;
	IMFSample *pSample;
	DWORD dwStatus;
	IMFCollection *pEvents;
} MFT_OUTPUT_DATA_BUFFER;
typedef struct _MFT_OUTPUT_DATA_BUFFER *PMFT_OUTPUT_DATA_BUFFER;
#ifdef MFT_UNIQUE_METHOD_NAMES
#define GetStreamLimits         MFTGetStreamLimits
#define GetStreamCount          MFTGetStreamCount
#define GetStreamIDs            MFTGetStreamIDs
#define GetInputStreamInfo      MFTGetInputStreamInfo
#define GetOutputStreamInfo     MFTGetOutputStreamInfo
#define DeleteInputStream       MFTDeleteInputStream
#define AddInputStreams         MFTAddInputStreams
#define GetInputAvailableType   MFTGetInputAvailableType
#define GetOutputAvailableType  MFTGetOutputAvailableType
#define SetInputType            MFTSetInputType
#define SetOutputType           MFTSetOutputType
#define GetInputCurrentType     MFTGetInputCurrentType
#define GetOutputCurrentType    MFTGetOutputCurrentType
#define GetInputStatus          MFTGetInputStatus
#define GetOutputStatus         MFTGetOutputStatus
#define SetOutputBounds         MFTSetOutputBounds
#define ProcessEvent            MFTProcessEvent
#define ProcessMessage          MFTProcessMessage
#define ProcessInput            MFTProcessInput
#define ProcessOutput           MFTProcessOutput
#endif
extern RPC_IF_HANDLE __MIDL_itf_mftransform_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mftransform_0000_0000_v0_0_s_ifspec;
#ifndef __IMFTransform_INTERFACE_DEFINED__
#define __IMFTransform_INTERFACE_DEFINED__
extern const IID IID_IMFTransform;
typedef struct IMFTransformVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IMFTransform * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IMFTransform * This);
	ULONG(STDMETHODCALLTYPE * Release) (IMFTransform * This);
	HRESULT(STDMETHODCALLTYPE * GetStreamLimits) (IMFTransform * This, DWORD * pdwInputMinimum, DWORD * pdwInputMaximum, DWORD * pdwOutputMinimum, DWORD * pdwOutputMaximum);
	HRESULT(STDMETHODCALLTYPE * GetStreamCount) (IMFTransform * This, DWORD * pcInputStreams, DWORD * pcOutputStreams);
	HRESULT(STDMETHODCALLTYPE * GetStreamIDs) (IMFTransform * This, DWORD dwInputIDArraySize, DWORD * pdwInputIDs, DWORD dwOutputIDArraySize, DWORD * pdwOutputIDs);
	HRESULT(STDMETHODCALLTYPE * GetInputStreamInfo) (IMFTransform * This, DWORD dwInputStreamID, MFT_INPUT_STREAM_INFO * pStreamInfo);
	HRESULT(STDMETHODCALLTYPE * GetOutputStreamInfo) (IMFTransform * This, DWORD dwOutputStreamID, MFT_OUTPUT_STREAM_INFO * pStreamInfo);
	HRESULT(STDMETHODCALLTYPE * GetAttributes) (IMFTransform * This, IMFAttributes ** pAttributes);
	HRESULT(STDMETHODCALLTYPE * GetInputStreamAttributes) (IMFTransform * This, DWORD dwInputStreamID, IMFAttributes ** pAttributes);
	HRESULT(STDMETHODCALLTYPE * GetOutputStreamAttributes) (IMFTransform * This, DWORD dwOutputStreamID, IMFAttributes ** pAttributes);
	HRESULT(STDMETHODCALLTYPE * DeleteInputStream) (IMFTransform * This, DWORD dwStreamID);
	HRESULT(STDMETHODCALLTYPE * AddInputStreams) (IMFTransform * This, DWORD cStreams, DWORD * adwStreamIDs);
	HRESULT(STDMETHODCALLTYPE * GetInputAvailableType) (IMFTransform * This, DWORD dwInputStreamID, DWORD dwTypeIndex, IMFMediaType ** ppType);
	HRESULT(STDMETHODCALLTYPE * GetOutputAvailableType) (IMFTransform * This, DWORD dwOutputStreamID, DWORD dwTypeIndex, IMFMediaType ** ppType);
	HRESULT(STDMETHODCALLTYPE * SetInputType) (IMFTransform * This, DWORD dwInputStreamID, IMFMediaType * pType, DWORD dwFlags);
	HRESULT(STDMETHODCALLTYPE * SetOutputType) (IMFTransform * This, DWORD dwOutputStreamID, IMFMediaType * pType, DWORD dwFlags);
	HRESULT(STDMETHODCALLTYPE * GetInputCurrentType) (IMFTransform * This, DWORD dwInputStreamID, IMFMediaType ** ppType);
	HRESULT(STDMETHODCALLTYPE * GetOutputCurrentType) (IMFTransform * This, DWORD dwOutputStreamID, IMFMediaType ** ppType);
	HRESULT(STDMETHODCALLTYPE * GetInputStatus) (IMFTransform * This, DWORD dwInputStreamID, DWORD * pdwFlags);
	HRESULT(STDMETHODCALLTYPE * GetOutputStatus) (IMFTransform * This, DWORD * pdwFlags);
	HRESULT(STDMETHODCALLTYPE * SetOutputBounds) (IMFTransform * This, LONGLONG hnsLowerBound, LONGLONG hnsUpperBound);
	HRESULT(STDMETHODCALLTYPE * ProcessEvent) (IMFTransform * This, DWORD dwInputStreamID, IMFMediaEvent * pEvent);
	HRESULT(STDMETHODCALLTYPE * ProcessMessage) (IMFTransform * This, MFT_MESSAGE_TYPE eMessage, ULONG_PTR ulParam);
	HRESULT(STDMETHODCALLTYPE * ProcessInput) (IMFTransform * This, DWORD dwInputStreamID, IMFSample * pSample, DWORD dwFlags);
	HRESULT(STDMETHODCALLTYPE * ProcessOutput) (IMFTransform * This, DWORD dwFlags, DWORD cOutputBufferCount, MFT_OUTPUT_DATA_BUFFER * pOutputSamples, DWORD * pdwStatus);
	END_INTERFACE
}  IMFTransformVtbl;
interface IMFTransform
{
	CONST_VTBL struct IMFTransformVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IMFTransform_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IMFTransform_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IMFTransform_Release(This)( (This)->lpVtbl -> Release(This) )
#define IMFTransform_GetStreamLimits(This,pdwInputMinimum,pdwInputMaximum,pdwOutputMinimum,pdwOutputMaximum)( (This)->lpVtbl -> GetStreamLimits(This,pdwInputMinimum,pdwInputMaximum,pdwOutputMinimum,pdwOutputMaximum) )
#define IMFTransform_GetStreamCount(This,pcInputStreams,pcOutputStreams)( (This)->lpVtbl -> GetStreamCount(This,pcInputStreams,pcOutputStreams) )
#define IMFTransform_GetStreamIDs(This,dwInputIDArraySize,pdwInputIDs,dwOutputIDArraySize,pdwOutputIDs)( (This)->lpVtbl -> GetStreamIDs(This,dwInputIDArraySize,pdwInputIDs,dwOutputIDArraySize,pdwOutputIDs) )
#define IMFTransform_GetInputStreamInfo(This,dwInputStreamID,pStreamInfo)( (This)->lpVtbl -> GetInputStreamInfo(This,dwInputStreamID,pStreamInfo) )
#define IMFTransform_GetOutputStreamInfo(This,dwOutputStreamID,pStreamInfo)( (This)->lpVtbl -> GetOutputStreamInfo(This,dwOutputStreamID,pStreamInfo) )
#define IMFTransform_GetAttributes(This,pAttributes)( (This)->lpVtbl -> GetAttributes(This,pAttributes) )
#define IMFTransform_GetInputStreamAttributes(This,dwInputStreamID,pAttributes)( (This)->lpVtbl -> GetInputStreamAttributes(This,dwInputStreamID,pAttributes) )
#define IMFTransform_GetOutputStreamAttributes(This,dwOutputStreamID,pAttributes)( (This)->lpVtbl -> GetOutputStreamAttributes(This,dwOutputStreamID,pAttributes) )
#define IMFTransform_DeleteInputStream(This,dwStreamID)( (This)->lpVtbl -> DeleteInputStream(This,dwStreamID) )
#define IMFTransform_AddInputStreams(This,cStreams,adwStreamIDs)( (This)->lpVtbl -> AddInputStreams(This,cStreams,adwStreamIDs) )
#define IMFTransform_GetInputAvailableType(This,dwInputStreamID,dwTypeIndex,ppType)( (This)->lpVtbl -> GetInputAvailableType(This,dwInputStreamID,dwTypeIndex,ppType) )
#define IMFTransform_GetOutputAvailableType(This,dwOutputStreamID,dwTypeIndex,ppType)( (This)->lpVtbl -> GetOutputAvailableType(This,dwOutputStreamID,dwTypeIndex,ppType) )
#define IMFTransform_SetInputType(This,dwInputStreamID,pType,dwFlags)( (This)->lpVtbl -> SetInputType(This,dwInputStreamID,pType,dwFlags) )
#define IMFTransform_SetOutputType(This,dwOutputStreamID,pType,dwFlags)( (This)->lpVtbl -> SetOutputType(This,dwOutputStreamID,pType,dwFlags) )
#define IMFTransform_GetInputCurrentType(This,dwInputStreamID,ppType)( (This)->lpVtbl -> GetInputCurrentType(This,dwInputStreamID,ppType) )
#define IMFTransform_GetOutputCurrentType(This,dwOutputStreamID,ppType)( (This)->lpVtbl -> GetOutputCurrentType(This,dwOutputStreamID,ppType) )
#define IMFTransform_GetInputStatus(This,dwInputStreamID,pdwFlags)( (This)->lpVtbl -> GetInputStatus(This,dwInputStreamID,pdwFlags) )
#define IMFTransform_GetOutputStatus(This,pdwFlags)( (This)->lpVtbl -> GetOutputStatus(This,pdwFlags) )
#define IMFTransform_SetOutputBounds(This,hnsLowerBound,hnsUpperBound)( (This)->lpVtbl -> SetOutputBounds(This,hnsLowerBound,hnsUpperBound) )
#define IMFTransform_ProcessEvent(This,dwInputStreamID,pEvent)( (This)->lpVtbl -> ProcessEvent(This,dwInputStreamID,pEvent) )
#define IMFTransform_ProcessMessage(This,eMessage,ulParam)( (This)->lpVtbl -> ProcessMessage(This,eMessage,ulParam) )
#define IMFTransform_ProcessInput(This,dwInputStreamID,pSample,dwFlags)( (This)->lpVtbl -> ProcessInput(This,dwInputStreamID,pSample,dwFlags) )
#define IMFTransform_ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputSamples,pdwStatus)( (This)->lpVtbl -> ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputSamples,pdwStatus) )
#endif
#endif
#if (WINVER >= _WIN32_WINNT_WIN7)
typedef struct _STREAM_MEDIUM
{
	GUID gidMedium;
	UINT32 unMediumInstance;
} STREAM_MEDIUM;
typedef struct _STREAM_MEDIUM *PSTREAM_MEDIUM;
#endif
#ifdef MFT_UNIQUE_METHOD_NAMES
#undef GetStreamLimits
#undef GetStreamCount
#undef GetStreamIDs
#undef GetInputStreamInfo
#undef GetOutputStreamInfo
#undef DeleteInputStream
#undef AddInputStreams
#undef GetInputAvailableType
#undef GetOutputAvailableType
#undef SetInputType
#undef SetOutputType
#undef GetInputCurrentType
#undef GetOutputCurrentType
#undef GetInputStatus
#undef GetOutputStatus
#undef SetOutputBounds
#undef ProcessMessage
#undef ProcessInput
#undef ProcessOutput
#endif
#include <propkeydef.h>
#include <guiddef.h>
DEFINE_PROPERTYKEY(MFPKEY_CLSID, 0xc57a84c0, 0x1a80, 0x40a3, 0x97, 0xb5, 0x92, 0x72, 0xa4, 0x3, 0xc8, 0xae, 0x01);
DEFINE_PROPERTYKEY(MFPKEY_CATEGORY, 0xc57a84c0, 0x1a80, 0x40a3, 0x97, 0xb5, 0x92, 0x72, 0xa4, 0x3, 0xc8, 0xae, 0x02);
DEFINE_PROPERTYKEY(MFPKEY_EXATTRIBUTE_SUPPORTED, 0x456fe843, 0x3c87, 0x40c0, 0x94, 0x9d, 0x14, 0x9, 0xc9, 0x7d, 0xab, 0x2c, 0x01);
DEFINE_PROPERTYKEY(MFPKEY_MULTICHANNEL_CHANNEL_MASK, 0x58bdaf8c, 0x3224, 0x4692, 0x86, 0xd0, 0x44, 0xd6, 0x5c, 0x5b, 0xf8, 0x2b, 0x01);
DEFINE_GUID(MF_SA_D3D_AWARE, 0xeaa35c29, 0x775e, 0x488e, 0x9b, 0x61, 0xb3, 0x28, 0x3e, 0x49, 0x58, 0x3b);
DEFINE_GUID(MF_SA_REQUIRED_SAMPLE_COUNT, 0x18802c61, 0x324b, 0x4952, 0xab, 0xd0, 0x17, 0x6f, 0xf5, 0xc6, 0x96, 0xff);
#if (WINVER >= _WIN32_WINNT_WIN7)
DEFINE_GUID(MF_TRANSFORM_ASYNC, 0xf81a699a, 0x649a, 0x497d, 0x8c, 0x73, 0x29, 0xf8, 0xfe, 0xd6, 0xad, 0x7a);
DEFINE_GUID(MF_TRANSFORM_ASYNC_UNLOCK, 0xe5666d6b, 0x3422, 0x4eb6, 0xa4, 0x21, 0xda, 0x7d, 0xb1, 0xf8, 0xe2, 0x7);
DEFINE_GUID(MF_TRANSFORM_FLAGS_Attribute, 0x9359bb7e, 0x6275, 0x46c4, 0xa0, 0x25, 0x1c, 0x1, 0xe4, 0x5f, 0x1a, 0x86);
DEFINE_GUID(MF_TRANSFORM_CATEGORY_Attribute, 0xceabba49, 0x506d, 0x4757, 0xa6, 0xff, 0x66, 0xc1, 0x84, 0x98, 0x7e, 0x4e);
DEFINE_GUID(MFT_TRANSFORM_CLSID_Attribute, 0x6821c42b, 0x65a4, 0x4e82, 0x99, 0xbc, 0x9a, 0x88, 0x20, 0x5e, 0xcd, 0xc);
DEFINE_GUID(MFT_INPUT_TYPES_Attributes, 0x4276c9b1, 0x759d, 0x4bf3, 0x9c, 0xd0, 0xd, 0x72, 0x3d, 0x13, 0x8f, 0x96);
DEFINE_GUID(MFT_OUTPUT_TYPES_Attributes, 0x8eae8cf3, 0xa44f, 0x4306, 0xba, 0x5c, 0xbf, 0x5d, 0xda, 0x24, 0x28, 0x18);
DEFINE_GUID(MFT_ENUM_HARDWARE_URL_Attribute, 0x2fb866ac, 0xb078, 0x4942, 0xab, 0x6c, 0x0, 0x3d, 0x5, 0xcd, 0xa6, 0x74);
DEFINE_GUID(MFT_FRIENDLY_NAME_Attribute, 0x314ffbae, 0x5b41, 0x4c95, 0x9c, 0x19, 0x4e, 0x7d, 0x58, 0x6f, 0xac, 0xe3);
DEFINE_GUID(MFT_CONNECTED_STREAM_ATTRIBUTE, 0x71eeb820, 0xa59f, 0x4de2, 0xbc, 0xec, 0x38, 0xdb, 0x1d, 0xd6, 0x11, 0xa4);
DEFINE_GUID(MFT_CONNECTED_TO_HW_STREAM, 0x34e6e728, 0x6d6, 0x4491, 0xa5, 0x53, 0x47, 0x95, 0x65, 0xd, 0xb9, 0x12);
DEFINE_GUID(MFT_PREFERRED_OUTPUTTYPE_Attribute, 0x7e700499, 0x396a, 0x49ee, 0xb1, 0xb4, 0xf6, 0x28, 0x2, 0x1e, 0x8c, 0x9d);
DEFINE_GUID(MFT_PROCESS_LOCAL_Attribute, 0x543186e4, 0x4649, 0x4e65, 0xb5, 0x88, 0x4a, 0xa3, 0x52, 0xaf, 0xf3, 0x79);
DEFINE_GUID(MFT_PREFERRED_ENCODER_PROFILE, 0x53004909, 0x1ef5, 0x46d7, 0xa1, 0x8e, 0x5a, 0x75, 0xf8, 0xb5, 0x90, 0x5f);
DEFINE_GUID(MFT_HW_TIMESTAMP_WITH_QPC_Attribute, 0x8d030fb8, 0xcc43, 0x4258, 0xa2, 0x2e, 0x92, 0x10, 0xbe, 0xf8, 0x9b, 0xe4);
DEFINE_GUID(MFT_FIELDOFUSE_UNLOCK_Attribute, 0x8ec2e9fd, 0x9148, 0x410d, 0x83, 0x1e, 0x70, 0x24, 0x39, 0x46, 0x1a, 0x8e);
DEFINE_GUID(MFT_CODEC_MERIT_Attribute, 0x88a7cb15, 0x7b07, 0x4a34, 0x91, 0x28, 0xe6, 0x4c, 0x67, 0x3, 0xc4, 0xd3);
DEFINE_GUID(MFT_ENUM_TRANSCODE_ONLY_ATTRIBUTE, 0x111ea8cd, 0xb62a, 0x4bdb, 0x89, 0xf6, 0x67, 0xff, 0xcd, 0xc2, 0x45, 0x8b);
STDAPI MFCreateTransformActivate(IMFActivate **ppActivate);
#endif
extern RPC_IF_HANDLE __MIDL_itf_mftransform_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mftransform_0000_0001_v0_0_s_ifspec;
#endif
