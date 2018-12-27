#pragma once
#include "afxwin.h"


// CInsurance �Ի���

class CInsurance : public CDialogEx
{
	DECLARE_DYNAMIC(CInsurance)

public:
	CInsurance(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInsurance();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSURANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
	int m_nChooseGroup = 0;
	double m_dMoneyCount = 0.0;
	double m_dCount;
	double m_dGJJBase;
	double m_dGJJRate;
	double m_dSBBase;
	CComboBox m_comboxCity;
};
