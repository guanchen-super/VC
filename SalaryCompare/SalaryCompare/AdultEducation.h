#pragma once
#include "afxwin.h"


// CAdultEducation 对话框

class CAdultEducation : public CDialogEx
{
	DECLARE_DYNAMIC(CAdultEducation)

public:
	CAdultEducation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdultEducation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADULT_EDUCATION };
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
	const double GetCount();

private:
	CComboBox m_comboxXL;
	CComboBox m_comboxZY;	
	int m_nChooseGroup;
};
