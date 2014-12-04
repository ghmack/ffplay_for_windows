

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_axffplayLib,0x208A1A33,0x2E59,0x46C8,0xA8,0x30,0x5D,0xCD,0x14,0x98,0x51,0x0F);


MIDL_DEFINE_GUID(IID, DIID__Daxffplay,0x05CC2E8A,0x00D7,0x497C,0xAB,0xCB,0xA7,0x36,0xE1,0x6B,0x3D,0x2C);


MIDL_DEFINE_GUID(IID, DIID__DaxffplayEvents,0x51AED315,0x84E5,0x4FB1,0xB1,0xAC,0x52,0xEC,0xC5,0x90,0xCB,0x4A);


MIDL_DEFINE_GUID(CLSID, CLSID_axffplay,0x0C7F59EB,0x3BA1,0x41A0,0xA3,0x70,0xDA,0xA6,0x8B,0x11,0x8D,0x39);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



