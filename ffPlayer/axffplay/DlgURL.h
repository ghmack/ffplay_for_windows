#pragma once


// CDlgURL �Ի���

class CDlgURL : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgURL)

public:
	// �Ի�������
	enum { IDD = IDD_DIALOGURL };

	CDlgURL(CWnd* pParent = NULL);  // ��׼���캯��
	virtual ~CDlgURL();



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	

public:
	CString m_szUrl;

};
