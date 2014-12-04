

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Jul 14 10:04:11 2014
 */
/* Compiler settings for axffplay.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __axffplayidl_h__
#define __axffplayidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___Daxffplay_FWD_DEFINED__
#define ___Daxffplay_FWD_DEFINED__
typedef interface _Daxffplay _Daxffplay;
#endif 	/* ___Daxffplay_FWD_DEFINED__ */


#ifndef ___DaxffplayEvents_FWD_DEFINED__
#define ___DaxffplayEvents_FWD_DEFINED__
typedef interface _DaxffplayEvents _DaxffplayEvents;
#endif 	/* ___DaxffplayEvents_FWD_DEFINED__ */


#ifndef __axffplay_FWD_DEFINED__
#define __axffplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class axffplay axffplay;
#else
typedef struct axffplay axffplay;
#endif /* __cplusplus */

#endif 	/* __axffplay_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __axffplayLib_LIBRARY_DEFINED__
#define __axffplayLib_LIBRARY_DEFINED__

/* library axffplayLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_axffplayLib;

#ifndef ___Daxffplay_DISPINTERFACE_DEFINED__
#define ___Daxffplay_DISPINTERFACE_DEFINED__

/* dispinterface _Daxffplay */
/* [uuid] */ 


EXTERN_C const IID DIID__Daxffplay;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("05CC2E8A-00D7-497C-ABCB-A736E16B3D2C")
    _Daxffplay : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DaxffplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Daxffplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Daxffplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Daxffplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Daxffplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Daxffplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Daxffplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Daxffplay * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DaxffplayVtbl;

    interface _Daxffplay
    {
        CONST_VTBL struct _DaxffplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Daxffplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Daxffplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Daxffplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Daxffplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Daxffplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Daxffplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Daxffplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Daxffplay_DISPINTERFACE_DEFINED__ */


#ifndef ___DaxffplayEvents_DISPINTERFACE_DEFINED__
#define ___DaxffplayEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DaxffplayEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DaxffplayEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("51AED315-84E5-4FB1-B1AC-52ECC590CB4A")
    _DaxffplayEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DaxffplayEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DaxffplayEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DaxffplayEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DaxffplayEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DaxffplayEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DaxffplayEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DaxffplayEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DaxffplayEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DaxffplayEventsVtbl;

    interface _DaxffplayEvents
    {
        CONST_VTBL struct _DaxffplayEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DaxffplayEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DaxffplayEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DaxffplayEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DaxffplayEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DaxffplayEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DaxffplayEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DaxffplayEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DaxffplayEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_axffplay;

#ifdef __cplusplus

class DECLSPEC_UUID("0C7F59EB-3BA1-41A0-A370-DAA68B118D39")
axffplay;
#endif
#endif /* __axffplayLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


