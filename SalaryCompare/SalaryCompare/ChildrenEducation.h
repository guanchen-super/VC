#pragma once
#include "afxwin.h"


// CChildrenEducation 对话框

class CChildrenEducation : public CDialogEx
{
	DECLARE_DYNAMIC(CChildrenEducation)

public:
	CChildrenEducation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChildrenEducation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHILDREN_EDUCATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	const int GetCount();

private:
	CComboBox m_comboxChildren;
	CComboBox m_comboxMoney;
};
