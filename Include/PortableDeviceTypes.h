/*+@@file@@----------------------------------------------------------------*//*!
 \file		PortableDeviceTypes.h
 \par Description 
            Extension and update of headers for PellesC compiler suite.
 \par Project: 
            PellesC Headers extension
 \date		Created  on Sat Jul  9 19:51:05 2016
 \date		Modified on Sat Jul  9 19:51:05 2016
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
#ifndef __PortableDeviceTypes_h__
#define __PortableDeviceTypes_h__
#if __POCC__ >= 500
#pragma once
#endif
#ifndef __IWpdSerializer_FWD_DEFINED__
#define __IWpdSerializer_FWD_DEFINED__
typedef interface IWpdSerializer IWpdSerializer;
#endif
#ifndef __IPortableDeviceValues_FWD_DEFINED__
#define __IPortableDeviceValues_FWD_DEFINED__
typedef interface IPortableDeviceValues IPortableDeviceValues;
#endif
#ifndef __IPortableDeviceKeyCollection_FWD_DEFINED__
#define __IPortableDeviceKeyCollection_FWD_DEFINED__
typedef interface IPortableDeviceKeyCollection IPortableDeviceKeyCollection;
#endif
#ifndef __IPortableDevicePropVariantCollection_FWD_DEFINED__
#define __IPortableDevicePropVariantCollection_FWD_DEFINED__
typedef interface IPortableDevicePropVariantCollection IPortableDevicePropVariantCollection;
#endif
#ifndef __IPortableDeviceValuesCollection_FWD_DEFINED__
#define __IPortableDeviceValuesCollection_FWD_DEFINED__
typedef interface IPortableDeviceValuesCollection IPortableDeviceValuesCollection;
#endif
#ifndef __WpdSerializer_FWD_DEFINED__
#define __WpdSerializer_FWD_DEFINED__
typedef struct WpdSerializer WpdSerializer;
#endif
#ifndef __PortableDeviceValues_FWD_DEFINED__
#define __PortableDeviceValues_FWD_DEFINED__
typedef struct PortableDeviceValues PortableDeviceValues;
#endif
#ifndef __PortableDeviceKeyCollection_FWD_DEFINED__
#define __PortableDeviceKeyCollection_FWD_DEFINED__
typedef struct PortableDeviceKeyCollection PortableDeviceKeyCollection;
#endif
#ifndef __PortableDevicePropVariantCollection_FWD_DEFINED__
#define __PortableDevicePropVariantCollection_FWD_DEFINED__
typedef struct PortableDevicePropVariantCollection PortableDevicePropVariantCollection;
#endif
#ifndef __PortableDeviceValuesCollection_FWD_DEFINED__
#define __PortableDeviceValuesCollection_FWD_DEFINED__
typedef struct PortableDeviceValuesCollection PortableDeviceValuesCollection;
#endif
#include <oaidl.h>
#include <ocidl.h>
#include <propsys.h>
#if (_WIN32_WINNT >= 0x0501)
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceTypes_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceTypes_0000_0000_v0_0_s_ifspec;
#ifndef __IWpdSerializer_INTERFACE_DEFINED__
#define __IWpdSerializer_INTERFACE_DEFINED__
extern const IID IID_IWpdSerializer;
typedef struct IWpdSerializerVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IWpdSerializer * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IWpdSerializer * This);
	ULONG(STDMETHODCALLTYPE * Release) (IWpdSerializer * This);
	HRESULT(STDMETHODCALLTYPE * GetIPortableDeviceValuesFromBuffer) (IWpdSerializer * This, BYTE * pBuffer, DWORD dwInputBufferLength, IPortableDeviceValues ** ppParams);
	HRESULT(STDMETHODCALLTYPE * WriteIPortableDeviceValuesToBuffer) (IWpdSerializer * This, DWORD dwOutputBufferLength, IPortableDeviceValues * pResults, BYTE * pBuffer, DWORD * pdwBytesWritten);
	HRESULT(STDMETHODCALLTYPE * GetBufferFromIPortableDeviceValues) (IWpdSerializer * This, IPortableDeviceValues * pSource, BYTE ** ppBuffer, DWORD * pdwBufferSize);
	HRESULT(STDMETHODCALLTYPE * GetSerializedSize) (IWpdSerializer * This, IPortableDeviceValues * pSource, DWORD * pdwSize);
	END_INTERFACE
}  IWpdSerializerVtbl;
interface IWpdSerializer
{
	CONST_VTBL struct IWpdSerializerVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IWpdSerializer_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IWpdSerializer_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IWpdSerializer_Release(This)( (This)->lpVtbl -> Release(This) )
#define IWpdSerializer_GetIPortableDeviceValuesFromBuffer(This,pBuffer,dwInputBufferLength,ppParams)( (This)->lpVtbl -> GetIPortableDeviceValuesFromBuffer(This,pBuffer,dwInputBufferLength,ppParams) )
#define IWpdSerializer_WriteIPortableDeviceValuesToBuffer(This,dwOutputBufferLength,pResults,pBuffer,pdwBytesWritten)( (This)->lpVtbl -> WriteIPortableDeviceValuesToBuffer(This,dwOutputBufferLength,pResults,pBuffer,pdwBytesWritten) )
#define IWpdSerializer_GetBufferFromIPortableDeviceValues(This,pSource,ppBuffer,pdwBufferSize)( (This)->lpVtbl -> GetBufferFromIPortableDeviceValues(This,pSource,ppBuffer,pdwBufferSize) )
#define IWpdSerializer_GetSerializedSize(This,pSource,pdwSize)( (This)->lpVtbl -> GetSerializedSize(This,pSource,pdwSize) )
#endif
#endif
#ifndef __IPortableDeviceValues_INTERFACE_DEFINED__
#define __IPortableDeviceValues_INTERFACE_DEFINED__
extern const IID IID_IPortableDeviceValues;
typedef struct IPortableDeviceValuesVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IPortableDeviceValues * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IPortableDeviceValues * This);
	ULONG(STDMETHODCALLTYPE * Release) (IPortableDeviceValues * This);
	HRESULT(STDMETHODCALLTYPE * GetCount) (IPortableDeviceValues * This, DWORD * pcelt);
	HRESULT(STDMETHODCALLTYPE * GetAt) (IPortableDeviceValues * This, const DWORD index, PROPERTYKEY * pKey, PROPVARIANT * pValue);
	HRESULT(STDMETHODCALLTYPE * SetValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const PROPVARIANT * pValue);
	HRESULT(STDMETHODCALLTYPE * GetValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, PROPVARIANT * pValue);
	HRESULT(STDMETHODCALLTYPE * SetStringValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, LPCWSTR Value);
	HRESULT(STDMETHODCALLTYPE * GetStringValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, LPWSTR * pValue);
	HRESULT(STDMETHODCALLTYPE * SetUnsignedIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const ULONG Value);
	HRESULT(STDMETHODCALLTYPE * GetUnsignedIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, ULONG * pValue);
	HRESULT(STDMETHODCALLTYPE * SetSignedIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const LONG Value);
	HRESULT(STDMETHODCALLTYPE * GetSignedIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, LONG * pValue);
	HRESULT(STDMETHODCALLTYPE * SetUnsignedLargeIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const ULONGLONG Value);
	HRESULT(STDMETHODCALLTYPE * GetUnsignedLargeIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, ULONGLONG * pValue);
	HRESULT(STDMETHODCALLTYPE * SetSignedLargeIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const LONGLONG Value);
	HRESULT(STDMETHODCALLTYPE * GetSignedLargeIntegerValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, LONGLONG * pValue);
	HRESULT(STDMETHODCALLTYPE * SetFloatValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const FLOAT Value);
	HRESULT(STDMETHODCALLTYPE * GetFloatValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, FLOAT * pValue);
	HRESULT(STDMETHODCALLTYPE * SetErrorValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const HRESULT Value);
	HRESULT(STDMETHODCALLTYPE * GetErrorValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, HRESULT * pValue);
	HRESULT(STDMETHODCALLTYPE * SetKeyValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, REFPROPERTYKEY Value);
	HRESULT(STDMETHODCALLTYPE * GetKeyValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, PROPERTYKEY * pValue);
	HRESULT(STDMETHODCALLTYPE * SetBoolValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, const BOOL Value);
	HRESULT(STDMETHODCALLTYPE * GetBoolValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, BOOL * pValue);
	HRESULT(STDMETHODCALLTYPE * SetIUnknownValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IUnknown * pValue);
	HRESULT(STDMETHODCALLTYPE * GetIUnknownValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IUnknown ** ppValue);
	HRESULT(STDMETHODCALLTYPE * SetGuidValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, REFGUID Value);
	HRESULT(STDMETHODCALLTYPE * GetGuidValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, GUID * pValue);
	HRESULT(STDMETHODCALLTYPE * SetBufferValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, BYTE * pValue, DWORD cbValue);
	HRESULT(STDMETHODCALLTYPE * GetBufferValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, BYTE ** ppValue, DWORD * pcbValue);
	HRESULT(STDMETHODCALLTYPE * SetIPortableDeviceValuesValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceValues * pValue);
	HRESULT(STDMETHODCALLTYPE * GetIPortableDeviceValuesValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceValues ** ppValue);
	HRESULT(STDMETHODCALLTYPE * SetIPortableDevicePropVariantCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDevicePropVariantCollection * pValue);
	HRESULT(STDMETHODCALLTYPE * GetIPortableDevicePropVariantCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDevicePropVariantCollection ** ppValue);
	HRESULT(STDMETHODCALLTYPE * SetIPortableDeviceKeyCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceKeyCollection * pValue);
	HRESULT(STDMETHODCALLTYPE * GetIPortableDeviceKeyCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceKeyCollection ** ppValue);
	HRESULT(STDMETHODCALLTYPE * SetIPortableDeviceValuesCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceValuesCollection * pValue);
	HRESULT(STDMETHODCALLTYPE * GetIPortableDeviceValuesCollectionValue) (IPortableDeviceValues * This, REFPROPERTYKEY key, IPortableDeviceValuesCollection ** ppValue);
	HRESULT(STDMETHODCALLTYPE * RemoveValue) (IPortableDeviceValues * This, REFPROPERTYKEY key);
	HRESULT(STDMETHODCALLTYPE * CopyValuesFromPropertyStore) (IPortableDeviceValues * This, IPropertyStore * pStore);
	HRESULT(STDMETHODCALLTYPE * CopyValuesToPropertyStore) (IPortableDeviceValues * This, IPropertyStore * pStore);
	HRESULT(STDMETHODCALLTYPE * Clear) (IPortableDeviceValues * This);
	END_INTERFACE
}  IPortableDeviceValuesVtbl;
interface IPortableDeviceValues
{
	CONST_VTBL struct IPortableDeviceValuesVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPortableDeviceValues_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IPortableDeviceValues_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IPortableDeviceValues_Release(This)( (This)->lpVtbl -> Release(This) )
#define IPortableDeviceValues_GetCount(This,pcelt)( (This)->lpVtbl -> GetCount(This,pcelt) )
#define IPortableDeviceValues_GetAt(This,index,pKey,pValue)( (This)->lpVtbl -> GetAt(This,index,pKey,pValue) )
#define IPortableDeviceValues_SetValue(This,key,pValue)( (This)->lpVtbl -> SetValue(This,key,pValue) )
#define IPortableDeviceValues_GetValue(This,key,pValue)( (This)->lpVtbl -> GetValue(This,key,pValue) )
#define IPortableDeviceValues_SetStringValue(This,key,Value)( (This)->lpVtbl -> SetStringValue(This,key,Value) )
#define IPortableDeviceValues_GetStringValue(This,key,pValue)( (This)->lpVtbl -> GetStringValue(This,key,pValue) )
#define IPortableDeviceValues_SetUnsignedIntegerValue(This,key,Value)( (This)->lpVtbl -> SetUnsignedIntegerValue(This,key,Value) )
#define IPortableDeviceValues_GetUnsignedIntegerValue(This,key,pValue)( (This)->lpVtbl -> GetUnsignedIntegerValue(This,key,pValue) )
#define IPortableDeviceValues_SetSignedIntegerValue(This,key,Value)( (This)->lpVtbl -> SetSignedIntegerValue(This,key,Value) )
#define IPortableDeviceValues_GetSignedIntegerValue(This,key,pValue)( (This)->lpVtbl -> GetSignedIntegerValue(This,key,pValue) )
#define IPortableDeviceValues_SetUnsignedLargeIntegerValue(This,key,Value)( (This)->lpVtbl -> SetUnsignedLargeIntegerValue(This,key,Value) )
#define IPortableDeviceValues_GetUnsignedLargeIntegerValue(This,key,pValue)( (This)->lpVtbl -> GetUnsignedLargeIntegerValue(This,key,pValue) )
#define IPortableDeviceValues_SetSignedLargeIntegerValue(This,key,Value)( (This)->lpVtbl -> SetSignedLargeIntegerValue(This,key,Value) )
#define IPortableDeviceValues_GetSignedLargeIntegerValue(This,key,pValue)( (This)->lpVtbl -> GetSignedLargeIntegerValue(This,key,pValue) )
#define IPortableDeviceValues_SetFloatValue(This,key,Value)( (This)->lpVtbl -> SetFloatValue(This,key,Value) )
#define IPortableDeviceValues_GetFloatValue(This,key,pValue)( (This)->lpVtbl -> GetFloatValue(This,key,pValue) )
#define IPortableDeviceValues_SetErrorValue(This,key,Value)( (This)->lpVtbl -> SetErrorValue(This,key,Value) )
#define IPortableDeviceValues_GetErrorValue(This,key,pValue)( (This)->lpVtbl -> GetErrorValue(This,key,pValue) )
#define IPortableDeviceValues_SetKeyValue(This,key,Value)( (This)->lpVtbl -> SetKeyValue(This,key,Value) )
#define IPortableDeviceValues_GetKeyValue(This,key,pValue)( (This)->lpVtbl -> GetKeyValue(This,key,pValue) )
#define IPortableDeviceValues_SetBoolValue(This,key,Value)( (This)->lpVtbl -> SetBoolValue(This,key,Value) )
#define IPortableDeviceValues_GetBoolValue(This,key,pValue)( (This)->lpVtbl -> GetBoolValue(This,key,pValue) )
#define IPortableDeviceValues_SetIUnknownValue(This,key,pValue)( (This)->lpVtbl -> SetIUnknownValue(This,key,pValue) )
#define IPortableDeviceValues_GetIUnknownValue(This,key,ppValue)( (This)->lpVtbl -> GetIUnknownValue(This,key,ppValue) )
#define IPortableDeviceValues_SetGuidValue(This,key,Value)( (This)->lpVtbl -> SetGuidValue(This,key,Value) )
#define IPortableDeviceValues_GetGuidValue(This,key,pValue)( (This)->lpVtbl -> GetGuidValue(This,key,pValue) )
#define IPortableDeviceValues_SetBufferValue(This,key,pValue,cbValue)( (This)->lpVtbl -> SetBufferValue(This,key,pValue,cbValue) )
#define IPortableDeviceValues_GetBufferValue(This,key,ppValue,pcbValue)( (This)->lpVtbl -> GetBufferValue(This,key,ppValue,pcbValue) )
#define IPortableDeviceValues_SetIPortableDeviceValuesValue(This,key,pValue)( (This)->lpVtbl -> SetIPortableDeviceValuesValue(This,key,pValue) )
#define IPortableDeviceValues_GetIPortableDeviceValuesValue(This,key,ppValue)( (This)->lpVtbl -> GetIPortableDeviceValuesValue(This,key,ppValue) )
#define IPortableDeviceValues_SetIPortableDevicePropVariantCollectionValue(This,key,pValue)( (This)->lpVtbl -> SetIPortableDevicePropVariantCollectionValue(This,key,pValue) )
#define IPortableDeviceValues_GetIPortableDevicePropVariantCollectionValue(This,key,ppValue)( (This)->lpVtbl -> GetIPortableDevicePropVariantCollectionValue(This,key,ppValue) )
#define IPortableDeviceValues_SetIPortableDeviceKeyCollectionValue(This,key,pValue)( (This)->lpVtbl -> SetIPortableDeviceKeyCollectionValue(This,key,pValue) )
#define IPortableDeviceValues_GetIPortableDeviceKeyCollectionValue(This,key,ppValue)( (This)->lpVtbl -> GetIPortableDeviceKeyCollectionValue(This,key,ppValue) )
#define IPortableDeviceValues_SetIPortableDeviceValuesCollectionValue(This,key,pValue)( (This)->lpVtbl -> SetIPortableDeviceValuesCollectionValue(This,key,pValue) )
#define IPortableDeviceValues_GetIPortableDeviceValuesCollectionValue(This,key,ppValue)( (This)->lpVtbl -> GetIPortableDeviceValuesCollectionValue(This,key,ppValue) )
#define IPortableDeviceValues_RemoveValue(This,key)( (This)->lpVtbl -> RemoveValue(This,key) )
#define IPortableDeviceValues_CopyValuesFromPropertyStore(This,pStore)( (This)->lpVtbl -> CopyValuesFromPropertyStore(This,pStore) )
#define IPortableDeviceValues_CopyValuesToPropertyStore(This,pStore)( (This)->lpVtbl -> CopyValuesToPropertyStore(This,pStore) )
#define IPortableDeviceValues_Clear(This)( (This)->lpVtbl -> Clear(This) )
#endif
#endif
#ifndef __IPortableDeviceKeyCollection_INTERFACE_DEFINED__
#define __IPortableDeviceKeyCollection_INTERFACE_DEFINED__
extern const IID IID_IPortableDeviceKeyCollection;
typedef struct IPortableDeviceKeyCollectionVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IPortableDeviceKeyCollection * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IPortableDeviceKeyCollection * This);
	ULONG(STDMETHODCALLTYPE * Release) (IPortableDeviceKeyCollection * This);
	HRESULT(STDMETHODCALLTYPE * GetCount) (IPortableDeviceKeyCollection * This, DWORD * pcElems);
	HRESULT(STDMETHODCALLTYPE * GetAt) (IPortableDeviceKeyCollection * This, const DWORD dwIndex, PROPERTYKEY * pKey);
	HRESULT(STDMETHODCALLTYPE * Add) (IPortableDeviceKeyCollection * This, REFPROPERTYKEY Key);
	HRESULT(STDMETHODCALLTYPE * Clear) (IPortableDeviceKeyCollection * This);
	HRESULT(STDMETHODCALLTYPE * RemoveAt) (IPortableDeviceKeyCollection * This, const DWORD dwIndex);
	END_INTERFACE
}  IPortableDeviceKeyCollectionVtbl;
interface IPortableDeviceKeyCollection
{
	CONST_VTBL struct IPortableDeviceKeyCollectionVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPortableDeviceKeyCollection_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IPortableDeviceKeyCollection_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IPortableDeviceKeyCollection_Release(This)( (This)->lpVtbl -> Release(This) )
#define IPortableDeviceKeyCollection_GetCount(This,pcElems)( (This)->lpVtbl -> GetCount(This,pcElems) )
#define IPortableDeviceKeyCollection_GetAt(This,dwIndex,pKey)( (This)->lpVtbl -> GetAt(This,dwIndex,pKey) )
#define IPortableDeviceKeyCollection_Add(This,Key)( (This)->lpVtbl -> Add(This,Key) )
#define IPortableDeviceKeyCollection_Clear(This)( (This)->lpVtbl -> Clear(This) )
#define IPortableDeviceKeyCollection_RemoveAt(This,dwIndex)( (This)->lpVtbl -> RemoveAt(This,dwIndex) )
#endif
#endif
#ifndef __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__
#define __IPortableDevicePropVariantCollection_INTERFACE_DEFINED__
extern const IID IID_IPortableDevicePropVariantCollection;
typedef struct IPortableDevicePropVariantCollectionVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IPortableDevicePropVariantCollection * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IPortableDevicePropVariantCollection * This);
	ULONG(STDMETHODCALLTYPE * Release) (IPortableDevicePropVariantCollection * This);
	HRESULT(STDMETHODCALLTYPE * GetCount) (IPortableDevicePropVariantCollection * This, DWORD * pcElems);
	HRESULT(STDMETHODCALLTYPE * GetAt) (IPortableDevicePropVariantCollection * This, const DWORD dwIndex, PROPVARIANT * pValue);
	HRESULT(STDMETHODCALLTYPE * Add) (IPortableDevicePropVariantCollection * This, const PROPVARIANT * pValue);
	HRESULT(STDMETHODCALLTYPE * GetType) (IPortableDevicePropVariantCollection * This, VARTYPE * pvt);
	HRESULT(STDMETHODCALLTYPE * ChangeType) (IPortableDevicePropVariantCollection * This, const VARTYPE vt);
	HRESULT(STDMETHODCALLTYPE * Clear) (IPortableDevicePropVariantCollection * This);
	HRESULT(STDMETHODCALLTYPE * RemoveAt) (IPortableDevicePropVariantCollection * This, const DWORD dwIndex);
	END_INTERFACE
}  IPortableDevicePropVariantCollectionVtbl;
interface IPortableDevicePropVariantCollection
{
	CONST_VTBL struct IPortableDevicePropVariantCollectionVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPortableDevicePropVariantCollection_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IPortableDevicePropVariantCollection_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IPortableDevicePropVariantCollection_Release(This)( (This)->lpVtbl -> Release(This) )
#define IPortableDevicePropVariantCollection_GetCount(This,pcElems)( (This)->lpVtbl -> GetCount(This,pcElems) )
#define IPortableDevicePropVariantCollection_GetAt(This,dwIndex,pValue)( (This)->lpVtbl -> GetAt(This,dwIndex,pValue) )
#define IPortableDevicePropVariantCollection_Add(This,pValue)( (This)->lpVtbl -> Add(This,pValue) )
#define IPortableDevicePropVariantCollection_GetType(This,pvt)( (This)->lpVtbl -> GetType(This,pvt) )
#define IPortableDevicePropVariantCollection_ChangeType(This,vt)( (This)->lpVtbl -> ChangeType(This,vt) )
#define IPortableDevicePropVariantCollection_Clear(This)( (This)->lpVtbl -> Clear(This) )
#define IPortableDevicePropVariantCollection_RemoveAt(This,dwIndex)( (This)->lpVtbl -> RemoveAt(This,dwIndex) )
#endif
#endif
#ifndef __IPortableDeviceValuesCollection_INTERFACE_DEFINED__
#define __IPortableDeviceValuesCollection_INTERFACE_DEFINED__
extern const IID IID_IPortableDeviceValuesCollection;
typedef struct IPortableDeviceValuesCollectionVtbl
{
	BEGIN_INTERFACE
	HRESULT(STDMETHODCALLTYPE * QueryInterface) (IPortableDeviceValuesCollection * This, REFIID riid, void **ppvObject);
	ULONG(STDMETHODCALLTYPE * AddRef) (IPortableDeviceValuesCollection * This);
	ULONG(STDMETHODCALLTYPE * Release) (IPortableDeviceValuesCollection * This);
	HRESULT(STDMETHODCALLTYPE * GetCount) (IPortableDeviceValuesCollection * This, DWORD * pcElems);
	HRESULT(STDMETHODCALLTYPE * GetAt) (IPortableDeviceValuesCollection * This, const DWORD dwIndex, IPortableDeviceValues ** ppValues);
	HRESULT(STDMETHODCALLTYPE * Add) (IPortableDeviceValuesCollection * This, IPortableDeviceValues * pValues);
	HRESULT(STDMETHODCALLTYPE * Clear) (IPortableDeviceValuesCollection * This);
	HRESULT(STDMETHODCALLTYPE * RemoveAt) (IPortableDeviceValuesCollection * This, const DWORD dwIndex);
	END_INTERFACE
}  IPortableDeviceValuesCollectionVtbl;
interface IPortableDeviceValuesCollection
{
	CONST_VTBL struct IPortableDeviceValuesCollectionVtbl *lpVtbl;
};
#ifdef COBJMACROS
#define IPortableDeviceValuesCollection_QueryInterface(This,riid,ppvObject)( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) )
#define IPortableDeviceValuesCollection_AddRef(This)( (This)->lpVtbl -> AddRef(This) )
#define IPortableDeviceValuesCollection_Release(This)( (This)->lpVtbl -> Release(This) )
#define IPortableDeviceValuesCollection_GetCount(This,pcElems)( (This)->lpVtbl -> GetCount(This,pcElems) )
#define IPortableDeviceValuesCollection_GetAt(This,dwIndex,ppValues)( (This)->lpVtbl -> GetAt(This,dwIndex,ppValues) )
#define IPortableDeviceValuesCollection_Add(This,pValues)( (This)->lpVtbl -> Add(This,pValues) )
#define IPortableDeviceValuesCollection_Clear(This)( (This)->lpVtbl -> Clear(This) )
#define IPortableDeviceValuesCollection_RemoveAt(This,dwIndex)( (This)->lpVtbl -> RemoveAt(This,dwIndex) )
#endif
#endif
#ifndef __PortableDeviceTypesLib_LIBRARY_DEFINED__
#define __PortableDeviceTypesLib_LIBRARY_DEFINED__
extern const IID LIBID_PortableDeviceTypesLib;
extern const CLSID CLSID_WpdSerializer;
extern const CLSID CLSID_PortableDeviceValues;
extern const CLSID CLSID_PortableDeviceKeyCollection;
extern const CLSID CLSID_PortableDevicePropVariantCollection;
extern const CLSID CLSID_PortableDeviceValuesCollection;
#endif
#endif
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceTypes_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceTypes_0000_0005_v0_0_s_ifspec;
unsigned long __RPC_USER BSTR_UserSize(unsigned long *, unsigned long, BSTR *);
unsigned char *__RPC_USER BSTR_UserMarshal(unsigned long *, unsigned char *, BSTR *);
unsigned char *__RPC_USER BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR *);
void __RPC_USER BSTR_UserFree(unsigned long *, BSTR *);
unsigned long __RPC_USER LPSAFEARRAY_UserSize(unsigned long *, unsigned long, LPSAFEARRAY *);
unsigned char *__RPC_USER LPSAFEARRAY_UserMarshal(unsigned long *, unsigned char *, LPSAFEARRAY *);
unsigned char *__RPC_USER LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY *);
void __RPC_USER LPSAFEARRAY_UserFree(unsigned long *, LPSAFEARRAY *);
unsigned long __RPC_USER BSTR_UserSize64(unsigned long *, unsigned long, BSTR *);
unsigned char *__RPC_USER BSTR_UserMarshal64(unsigned long *, unsigned char *, BSTR *);
unsigned char *__RPC_USER BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR *);
void __RPC_USER BSTR_UserFree64(unsigned long *, BSTR *);
unsigned long __RPC_USER LPSAFEARRAY_UserSize64(unsigned long *, unsigned long, LPSAFEARRAY *);
unsigned char *__RPC_USER LPSAFEARRAY_UserMarshal64(unsigned long *, unsigned char *, LPSAFEARRAY *);
unsigned char *__RPC_USER LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY *);
void __RPC_USER LPSAFEARRAY_UserFree64(unsigned long *, LPSAFEARRAY *);
#endif
