#pragma once

// axffplay.h : axffplay.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CaxffplayApp : �й�ʵ�ֵ���Ϣ������� axffplay.cpp��

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

