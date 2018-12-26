#pragma once


// CInsurance 对话框

class CInsurance : public CDialogEx
{
	DECLARE_DYNAMIC(CInsurance)

public:
	CInsurance(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInsurance();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSURANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();

	DECLARE_MESSAGE_MAP()
public:
	const double GetCount();

private:
	CString m_strGJJBase;	// 公积金缴纳基数
	CString m_strGJJRate;	// 公积金缴纳比例
	CString m_strSBBase;	// 社保缴纳基数

	int m_nChooseGroup = 0;
	double m_dMoneyCount = 0.0;
	double m_dCount;
};
