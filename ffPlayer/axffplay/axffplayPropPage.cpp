// axffplayPropPage.cpp : CaxffplayPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "axffplay.h"
#include "axffplayPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CaxffplayPropPage, COlePropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CaxffplayPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CaxffplayPropPage, "AXFFPLAY.axffplayPropPage.1",
	0xd52e4b6c, 0x5d3c, 0x45f3, 0xba, 0x2d, 0xf7, 0x61, 0x3b, 0x8a, 0x33, 0x11)



// CaxffplayPropPage::CaxffplayPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CaxffplayPropPage ��ϵͳע�����

BOOL CaxffplayPropPage::CaxffplayPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_AXFFPLAY_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CaxffplayPropPage::CaxffplayPropPage - ���캯��

CaxffplayPropPage::CaxffplayPropPage() :
	COlePropertyPage(IDD, IDS_AXFFPLAY_PPG_CAPTION)
{
}



// CaxffplayPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CaxffplayPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CaxffplayPropPage ��Ϣ�������
