#pragma once

// axffplayCtrl.h : CaxffplayCtrl ActiveX 控件类的声明。


// CaxffplayCtrl : 有关实现的信息，请参阅 axffplayCtrl.cpp。

#include <atlcom.h>
#include "DlgURL.h"
#include "ffplay.h"

#define  IDR_MENU_ONE_TEXT			"Menu1"
#define  IDR_MENU_FILEOPEN_TEXT		"打开文件"
#define  IDR_MENU_URLOPEN_TEXT		"打开URL"
#define  IDR_MENU_FULLSCREEN_TEXT	"全屏/恢复"
#define  IDR_MENU_PAUSED_TEXT		"暂停/继续"
#define  IDR_MENU_STOP_TEXT			"停止"

#define  IDR_MENU_ONE				10000
#define  IDR_MENU_FILEOPEN			10001
#define  IDR_MENU_URLOPEN			10002
#define  IDR_MENU_FULLSCREEN		10003
#define  IDR_MENU_PAUSED			10004
#define  IDR_MENU_STOP				10005


class CDlgFScreen;
class CaxffplayCtrl;

class CDlgFScreen : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFScreen)

public:
	CDlgFScreen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFScreen();

	// 对话框数据
	enum { IDD = IDD_FSCREEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

	virtual BOOL OnInitDialog();


public:
	void* m_pOcx;
	CStatic* m_pStatic;
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};


class CaxffplayCtrl : public COleControl
{
	DECLARE_DYNCREATE(CaxffplayCtrl)

// 构造函数
public:
	CaxffplayCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	 

public:
	void swithFullScreen(bool bFullScreen);

// 实现
protected:
	~CaxffplayCtrl();

	BEGIN_OLEFACTORY(CaxffplayCtrl)        // 类工厂和 guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR *);
	END_OLEFACTORY(CaxffplayCtrl)

	DECLARE_OLETYPELIB(CaxffplayCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CaxffplayCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CaxffplayCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
protected:
	ULONG Play(LPCTSTR sName);

	enum 
	{
		dispidStop = 2L,
		dispidPlay = 1L
	};
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

public:
	void* m_ffPlayContext;
	HWND m_hwdParent;
	bool m_fullscreen;
	int m_srcX;
	int m_srcY;
	int m_srcW;
	int m_srcH;
	RECT m_rect;
	WINDOWPLACEMENT m_winPlace;
	CDlgFScreen* m_dlgScreen;
	CStatic* m_Static;

	CMenu* m_rMemu;
	static bool m_bFFPlayInit ;

	CString TestFile;

public:

	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);


	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
protected:
	LONG Stop(void);
public:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	void MenuPop()
	{
		//m_rMemu->EnableMenuItem(IDR_MENU_FILEOPEN,MF_ENABLED);
		CPoint pt ;
		GetCursorPos(&pt);
		int ret = m_rMemu->TrackPopupMenu(TPM_RETURNCMD |TPM_NONOTIFY| TPM_RIGHTBUTTON,pt.x,pt.y,this);
		OutputDebugString (TestFile);
		switch(ret)
		{
		case IDR_MENU_FILEOPEN:
			{
				CFileDialog dlgFile(TRUE);
				if(dlgFile.DoModal()==IDOK)
				{
					Play(dlgFile.GetPathName());

				}
			}
			
			break;
		case IDR_MENU_URLOPEN:
			{
				CDlgURL dlgUrl(NULL);
				if(dlgUrl.DoModal()==IDOK)
				{
					if(dlgUrl.m_szUrl != "")
					{
						Play(dlgUrl.m_szUrl);
					}
				}

			}
			break;
		case IDR_MENU_PAUSED:
			{
				ffplay_paused(m_ffPlayContext);
			}
			break;
		case IDR_MENU_STOP:
			{
				Stop();
			}
			break;
		case IDR_MENU_FULLSCREEN:
			{
				swithFullScreen(!m_fullscreen);
			}
			break;
		default:
			break;
		}
		
	}
};




