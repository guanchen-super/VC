#pragma once
#include "afxwin.h"


// CInsurance 对话框

class CInsurance : public CDialogEx
{
	DECLARE_DYNAMIC(CInsurance)

public:
	CInsurance(bool & bChange, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsurance();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSURANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	DECLARE_MESSAGE_MAP()
public:
	const double GetCount();

private:
	bool & m_bChange;
	int m_nChooseGroup = 0;
	double m_dMoneyCount = 0.0;
	double m_dCount;
	double m_dGJJBase;
	double m_dGJJRate;
	double m_dSBBase;
	CComboBox m_comboxCity;
};
