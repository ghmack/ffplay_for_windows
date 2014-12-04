#pragma once

// axffplayPropPage.h : CaxffplayPropPage 属性页类的声明。


// CaxffplayPropPage : 有关实现的信息，请参阅 axffplayPropPage.cpp。

class CaxffplayPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CaxffplayPropPage)
	DECLARE_OLECREATE_EX(CaxffplayPropPage)

// 构造函数
public:
	CaxffplayPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_AXFFPLAY };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

