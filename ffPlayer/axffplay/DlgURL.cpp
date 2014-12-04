// DlgURL.cpp : 实现文件
//

#include "stdafx.h"
#include "axffplay.h"
#include "DlgURL.h"
#include "afxdialogex.h"


// CDlgURL 对话框

IMPLEMENT_DYNAMIC(CDlgURL, CDialogEx)

CDlgURL::CDlgURL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgURL::IDD, pParent)
{

}

CDlgURL::~CDlgURL()
{
}

void CDlgURL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgURL, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgURL::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgURL::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgURL 消息处理程序


void CDlgURL::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	this->GetDlgItemText(IDC_EDIT_URL,m_szUrl);
	CDialogEx::OnOK();
}


void CDlgURL::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_szUrl = "";
	CDialogEx::OnCancel();
}
