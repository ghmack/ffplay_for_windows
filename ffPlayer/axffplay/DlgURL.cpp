// DlgURL.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "axffplay.h"
#include "DlgURL.h"
#include "afxdialogex.h"


// CDlgURL �Ի���

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


// CDlgURL ��Ϣ�������


void CDlgURL::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->GetDlgItemText(IDC_EDIT_URL,m_szUrl);
	CDialogEx::OnOK();
}


void CDlgURL::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_szUrl = "";
	CDialogEx::OnCancel();
}
