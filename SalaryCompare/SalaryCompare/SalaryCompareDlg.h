
// SalaryCompareDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

// CSalaryCompareDlg 对话框
class CSalaryCompareDlg : public CDialogEx
{
// 构造
public:
	CSalaryCompareDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SALARYCOMPARE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedOther();
	afx_msg void OnBnClickedCalculate();
	void getForwardSalary(const double dSalary, double * salaryCount);
	void getAfterwardSalary(const double dSalary, const double dInsurance, const double dDiscounts, double * salaryCount);
	int getLevel(const double dSalary, bool bNew = false);
	DECLARE_MESSAGE_MAP()

private:
	double m_taxRate[7];
	__int64 m_oldMinus[7];
	__int64 m_newMinus[7];

	double m_dWXYJMoney = 0.0;
	double m_dOtherMoney = 0.0;

	CListCtrl m_listCtrl;
	double m_dSalary;
};
