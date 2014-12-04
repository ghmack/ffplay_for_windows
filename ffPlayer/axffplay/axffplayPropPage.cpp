// axffplayPropPage.cpp : CaxffplayPropPage 属性页类的实现。

#include "stdafx.h"
#include "axffplay.h"
#include "axffplayPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CaxffplayPropPage, COlePropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CaxffplayPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CaxffplayPropPage, "AXFFPLAY.axffplayPropPage.1",
	0xd52e4b6c, 0x5d3c, 0x45f3, 0xba, 0x2d, 0xf7, 0x61, 0x3b, 0x8a, 0x33, 0x11)



// CaxffplayPropPage::CaxffplayPropPageFactory::UpdateRegistry -
// 添加或移除 CaxffplayPropPage 的系统注册表项

BOOL CaxffplayPropPage::CaxffplayPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_AXFFPLAY_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CaxffplayPropPage::CaxffplayPropPage - 构造函数

CaxffplayPropPage::CaxffplayPropPage() :
	COlePropertyPage(IDD, IDS_AXFFPLAY_PPG_CAPTION)
{
}



// CaxffplayPropPage::DoDataExchange - 在页和属性间移动数据

void CaxffplayPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CaxffplayPropPage 消息处理程序
