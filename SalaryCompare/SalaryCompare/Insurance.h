#pragma once


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
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

	DECLARE_MESSAGE_MAP()
public:
	const double GetCount();

private:
	CString m_strGJJBase;	// ��������ɻ���
	CString m_strGJJRate;	// ��������ɱ���
	CString m_strSBBase;	// �籣���ɻ���

	int m_nChooseGroup = 0;
	double m_dMoneyCount = 0.0;
	double m_dCount;
};
