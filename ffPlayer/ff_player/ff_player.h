
// ff_player.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cff_playerApp:
// �йش����ʵ�֣������ ff_player.cpp
//

class Cff_playerApp : public CWinApp
{
public:
	Cff_playerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cff_playerApp theApp;