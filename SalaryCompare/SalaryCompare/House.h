#pragma once
#include "afxwin.h"


// CHouse 对话框

class CHouse : public CDialogEx
{
	DECLARE_DYNAMIC(CHouse)

public:
	CHouse(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHouse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOUSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	DECLARE_MESSAGE_MAP()

public:
	const int GetCount();

private:
	int m_nMoneyCount;
	int m_nChooseGroup;
	CComboBox m_comboxRent;
	CComboBox m_comboxDeal;
};
