
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
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void getForwardSalary(const double dSalary, double * salaryCount);
	void getAfterwardSalary(const double dSalary, const double dInsurance, const double dDiscounts, double * salaryCount);
	int getLevel(const double dSalary, bool bNew = false);
	DECLARE_MESSAGE_MAP()
public:
	double m_taxRate[7];
	__int64 m_oldMinus[7];
	__int64 m_newMinus[7];

	CString m_strSalary;
	CString m_strInsurance;
	afx_msg void OnBnClickedCalculate();
	CListCtrl m_listCtrl;
};
