#pragma once


// CDlgURL 对话框

class CDlgURL : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgURL)

public:
	// 对话框数据
	enum { IDD = IDD_DIALOGURL };

	CDlgURL(CWnd* pParent = NULL);  // 标准构造函数
	virtual ~CDlgURL();



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	

public:
	CString m_szUrl;

};
