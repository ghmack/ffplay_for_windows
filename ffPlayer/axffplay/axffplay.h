#pragma once

// axffplay.h : axffplay.DLL 的主头文件

#if !defined( __AFXCTL_H__ )
#error "在包括此文件之前包括“afxctl.h”"
#endif

#include "resource.h"       // 主符号


// CaxffplayApp : 有关实现的信息，请参阅 axffplay.cpp。

class CaxffplayApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();

	int m_test ;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

