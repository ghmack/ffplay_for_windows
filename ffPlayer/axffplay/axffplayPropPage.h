#pragma once

// axffplayPropPage.h : CaxffplayPropPage ����ҳ���������


// CaxffplayPropPage : �й�ʵ�ֵ���Ϣ������� axffplayPropPage.cpp��

class CaxffplayPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CaxffplayPropPage)
	DECLARE_OLECREATE_EX(CaxffplayPropPage)

// ���캯��
public:
	CaxffplayPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_AXFFPLAY };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

