
// SalaryCompareDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

// CSalaryCompareDlg �Ի���
class CSalaryCompareDlg : public CDialogEx
{
// ����
public:
	CSalaryCompareDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SALARYCOMPARE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
