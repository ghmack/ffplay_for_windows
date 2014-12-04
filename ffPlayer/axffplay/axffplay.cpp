// axffplay.cpp : CaxffplayApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "axffplay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CaxffplayApp theApp;

const GUID CDECL _tlid = { 0x208A1A33, 0x2E59, 0x46C8, { 0xA8, 0x30, 0x5D, 0xCD, 0x14, 0x98, 0x51, 0xF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CaxffplayApp::InitInstance - DLL 初始化

BOOL CaxffplayApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
		m_test = 111111;
	}

	return bInit;
}



// CaxffplayApp::ExitInstance - DLL 终止

int CaxffplayApp::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
