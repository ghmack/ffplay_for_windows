// axffplayCtrl.cpp : CaxffplayCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "axffplay.h"
#include "axffplayCtrl.h"
#include "axffplayPropPage.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
bool CaxffplayCtrl::m_bFFPlayInit = false;

IMPLEMENT_DYNCREATE(CaxffplayCtrl, COleControl)



// 消息映射

BEGIN_MESSAGE_MAP(CaxffplayCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDBLCLK()
ON_WM_SHOWWINDOW()
ON_WM_CTLCOLOR()
ON_WM_RBUTTONUP()
END_MESSAGE_MAP()



// 调度映射

BEGIN_DISPATCH_MAP(CaxffplayCtrl, COleControl)
	DISP_FUNCTION_ID(CaxffplayCtrl, "Play", dispidPlay, Play, VT_UI4, VTS_BSTR)
	DISP_FUNCTION_ID(CaxffplayCtrl, "Stop", dispidStop, Stop, VT_I4, VTS_NONE)
END_DISPATCH_MAP()



// 事件映射

BEGIN_EVENT_MAP(CaxffplayCtrl, COleControl)
END_EVENT_MAP()



// 属性页

// TODO: 按需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CaxffplayCtrl, 1)
	PROPPAGEID(CaxffplayPropPage::guid)
END_PROPPAGEIDS(CaxffplayCtrl)



// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CaxffplayCtrl, "AXFFPLAY.axffplayCtrl.1",
	0xc7f59eb, 0x3ba1, 0x41a0, 0xa3, 0x70, 0xda, 0xa6, 0x8b, 0x11, 0x8d, 0x39)



// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CaxffplayCtrl, _tlid, _wVerMajor, _wVerMinor)



// 接口 ID

const IID IID_Daxffplay = { 0x5CC2E8A, 0xD7, 0x497C, { 0xAB, 0xCB, 0xA7, 0x36, 0xE1, 0x6B, 0x3D, 0x2C } };
const IID IID_DaxffplayEvents = { 0x51AED315, 0x84E5, 0x4FB1, { 0xB1, 0xAC, 0x52, 0xEC, 0xC5, 0x90, 0xCB, 0x4A } };


// 控件类型信息

static const DWORD _dwaxffplayOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CaxffplayCtrl, IDS_AXFFPLAY, _dwaxffplayOleMisc)



// CaxffplayCtrl::CaxffplayCtrlFactory::UpdateRegistry -
// 添加或移除 CaxffplayCtrl 的系统注册表项

BOOL CaxffplayCtrl::CaxffplayCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_AXFFPLAY,
			IDB_AXFFPLAY,
			afxRegApartmentThreading,
			_dwaxffplayOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// 授权字符串

static const TCHAR _szLicFileName[] = _T("axffplay.lic");

static const WCHAR _szLicString[] = L"Copyright (c) 2013 ";



// CaxffplayCtrl::CaxffplayCtrlFactory::VerifyUserLicense -
// 检查是否存在用户许可证

BOOL CaxffplayCtrl::CaxffplayCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}



// CaxffplayCtrl::CaxffplayCtrlFactory::GetLicenseKey -
// 返回运行时授权密钥

BOOL CaxffplayCtrl::CaxffplayCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR *pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}



// CaxffplayCtrl::CaxffplayCtrl - 构造函数

CaxffplayCtrl::CaxffplayCtrl()
{
	InitializeIIDs(&IID_Daxffplay, &IID_DaxffplayEvents);
	// TODO: 在此初始化控件的实例数据。
	m_ffPlayContext=NULL;
	m_dlgScreen = NULL;
	m_Static = NULL;
}



// CaxffplayCtrl::~CaxffplayCtrl - 析构函数

CaxffplayCtrl::~CaxffplayCtrl()
{
	// TODO: 在此清理控件的实例数据。
}



// CaxffplayCtrl::OnDraw - 绘图函数

void CaxffplayCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: 用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH)));
	if(m_Static){

	}
	/*pdc->Ellipse(rcBounds);*/

}



// CaxffplayCtrl::DoPropExchange - 持久性支持

void CaxffplayCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}

HBRUSH CaxffplayCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = COleControl::OnCtlColor(pDC, pWnd, nCtlColor);
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255)); 
		return   (HBRUSH)::GetStockObject(BLACK_BRUSH);   
	}
	return hbr;

}

// CaxffplayCtrl::OnResetState - 将控件重置为默认状态

void CaxffplayCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO: 在此重置任意其他控件状态。
}



// CaxffplayCtrl 消息处理程序


ULONG CaxffplayCtrl::Play(LPCTSTR sName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	
	char* url[] = { "ffplay.exe" ,"d:\\wildlife.flv"};
	if (sName)
	{
		if (m_ffPlayContext)
		{
			Stop();
			m_ffPlayContext = NULL;
		}
		TestFile = sName;
		USES_CONVERSION;
		m_ffPlayContext = ffplay_create(W2A(sName),NULL);
		User_Param* param = ffplay_get_param(m_ffPlayContext);
		int cw =0, ch=0;
		this->GetControlSize(&cw,&ch);
		param->default_width = cw;
		param->default_height = ch;
		ffplay_set_hwnd(m_ffPlayContext,m_Static->GetSafeHwnd());
		/*User_Param* pParam = ffplay_get_param(is);
		USES_CONVERSION;
		strcpy((char*)pParam->input_filename, W2A(sName));*/
		ffplay_run(m_ffPlayContext);
	}	

	
	return 0;
}
void CaxffplayCtrl::OnShowWindow(BOOL bShow, UINT nStatus)
{
	COleControl::OnShowWindow(bShow, nStatus);

	// TODO: 在此处添加消息处理程序代码

	m_Static->SetParent(this);
	m_Static->ShowWindow(SW_SHOWNORMAL);
	
	//ffplay_set_hwnd(is,m_Static->GetSafeHwnd());
	RECT rc = {0};
	GetWindowRect(&rc);
	m_Static->MoveWindow(0,0,rc.right-rc.left,rc.bottom-rc.top);
	ffplay_onResize(m_ffPlayContext,rc.right-rc.left,rc.bottom-rc.top);
	//m_Static->Invalidate();
	return;

}



int CaxffplayCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_dlgScreen = new CDlgFScreen();
	m_dlgScreen->Create(IDD_FSCREEN,GetDesktopWindow());
	m_dlgScreen->m_pOcx = this;
	RECT rc = {0};
	m_Static = new CStatic();
	m_Static->Create(_T("Video"),0,rc,this,IDC_STATIC1);
	
	//::SetWindowLong(m_Static->GetSafeHwnd(),GWL_USERDATA,(LONG)this);
	m_fullscreen = false;
	
	// TODO:  在此添加您专用的创建代码
	if(!CaxffplayCtrl::m_bFFPlayInit)
	{
		ffplay_init();
		CaxffplayCtrl::m_bFFPlayInit = true;
	}
	
	/*is = ffplay_create("d:\\media\\X-MenDaysofFuturePast.avi",NULL);
	User_Param* param = ffplay_get_param(is);
	int cw =0, ch=0;
	this->GetControlSize(&cw,&ch);
	param->default_width = cw;
	param->default_height = ch;*/

	m_rMemu = new CMenu();
	m_rMemu->CreatePopupMenu();
	//m_rMemu->AppendMenu(MF_STRING,IDR_MENU_ONE,_T(IDR_MENU_ONE_TEXT));
	m_rMemu->AppendMenu(MF_STRING|MF_ENABLED,IDR_MENU_FILEOPEN,_T(IDR_MENU_FILEOPEN_TEXT));
	m_rMemu->AppendMenu(MF_SEPARATOR,NULL,_T(""));
	m_rMemu->AppendMenu(MF_STRING,IDR_MENU_URLOPEN,_T(IDR_MENU_URLOPEN_TEXT));
	m_rMemu->AppendMenu(MF_SEPARATOR,NULL,_T(""));
	m_rMemu->AppendMenu(MF_STRING,IDR_MENU_FULLSCREEN,_T(IDR_MENU_FULLSCREEN_TEXT));
	m_rMemu->AppendMenu(MF_SEPARATOR,NULL,_T(""));
	m_rMemu->AppendMenu(MF_STRING,IDR_MENU_PAUSED,_T(IDR_MENU_PAUSED_TEXT));
	m_rMemu->AppendMenu(MF_SEPARATOR,NULL,_T(""));
	m_rMemu->AppendMenu(MF_STRING,IDR_MENU_STOP,_T(IDR_MENU_STOP_TEXT));
	
	
	
	return 0;
}


void CaxffplayCtrl::OnSize(UINT nType, int cx, int cy)
{
	
	COleControl::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if(m_Static){
		m_Static->MoveWindow(0,0,cx,cy,TRUE);
		ffplay_onResize(m_ffPlayContext,cx,cy);

	}
}





void CaxffplayCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CaxffplayApp* pctrl = (CaxffplayApp*) ::AfxGetApp();
	
	
	COleControl::OnLButtonDblClk(nFlags, point);

		swithFullScreen(true);


	
}

void CaxffplayCtrl::swithFullScreen(bool bFullScreen)
{
	if(bFullScreen==m_fullscreen)
		return;
	if (bFullScreen)
	{
		/*HWND wndTask = ::FindWindow(_T("Shell_TrayWnd"),NULL);
		::ShowWindow(wndTask,SW_HIDE);*/
		int cx = ::GetSystemMetrics(SM_CXSCREEN); 
		int cy = ::GetSystemMetrics(SM_CYSCREEN); 
		this->GetWindowRect(&m_rect);
		ScreenToClient(&m_rect);
		m_dlgScreen->ShowWindow(SW_SHOWNORMAL);
		m_dlgScreen->SetWindowPos(CWnd::FromHandle(HWND_TOPMOST),0,0,cx,cy,0);
		m_Static->SetParent(m_dlgScreen);
		m_Static->MoveWindow(0,0,cx,cy,TRUE);
		if(m_ffPlayContext)
		ffplay_onResize(m_ffPlayContext,cx,cy);
		m_fullscreen = true;
	}
	else
	{
		m_dlgScreen->ShowWindow(SW_HIDE);
		m_Static->SetParent(this);
		m_Static->MoveWindow(m_rect.left,m_rect.top, m_rect.right-m_rect.left, m_rect.bottom-m_rect.top, 0);		
		HWND wndTask = ::FindWindow(_T("Shell_TrayWnd"),NULL);
		::ShowWindow(wndTask,SW_SHOWNORMAL);
		m_fullscreen = false;
	}
}






//void CaxffplayCtrl::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	
//}






IMPLEMENT_DYNAMIC(CDlgFScreen, CDialogEx)

	CDlgFScreen::CDlgFScreen(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgFScreen::IDD, pParent)
{
	
	m_pOcx = NULL;
}

CDlgFScreen::~CDlgFScreen()
{
}

void CDlgFScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgFScreen, CDialogEx)
	ON_WM_SIZE()
ON_WM_SHOWWINDOW()
ON_WM_LBUTTONDBLCLK()
ON_WM_CTLCOLOR()
ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CDlgFScreen 消息处理程序

void CDlgFScreen::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}




BOOL CDlgFScreen::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgFScreen::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

}










void CDlgFScreen::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_pOcx)
	{
		CaxffplayCtrl* pCtrl = (CaxffplayCtrl*)(m_pOcx);
		pCtrl->swithFullScreen(false);
	}
		
	CDialogEx::OnLButtonDblClk(nFlags, point);
}



HBRUSH CDlgFScreen::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255)); 
		return   (HBRUSH)::GetStockObject(BLACK_BRUSH);   
	}
	return hbr;

}

void CDlgFScreen::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (m_pOcx)
	{
		CaxffplayCtrl* pCtrl = (CaxffplayCtrl*)(m_pOcx);
		pCtrl->MenuPop();
	}
	CDialogEx::OnRButtonUp(nFlags, point);
}


LONG CaxffplayCtrl::Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	 OutputDebugString (TestFile);
	ffplay_stop(m_ffPlayContext);
	//Sleep(1000);
	m_ffPlayContext = NULL;
	this->m_Static->Invalidate();
	return 0;
}


void CaxffplayCtrl::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MenuPop();

	COleControl::OnRButtonUp(nFlags, point);
	
}
