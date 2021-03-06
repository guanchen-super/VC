#pragma once
#include "afxcmn.h"
#include "House.h"
#include "Parents.h"
#include "Insurance.h"
#include "AdultEducation.h"
#include "ChildrenEducation.h"

// COtherItem 对话框

class COtherItem : public CDialogEx
{
	DECLARE_DYNAMIC(COtherItem)

public:
	COtherItem(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COtherItem();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OTHER_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedOk();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	DECLARE_MESSAGE_MAP()

public:
	const double GetWXYIItemCount() const;
	const double GetOtherItemCount() const;

private:
	bool m_bChange = true;
	int m_nCurSelTab = 0;
	double m_dWXYJCount;
	double m_dOtherCount;
	CDialogEx* m_pDlgTab[5];
public:
	CTabCtrl m_tabCtrl;
	CToolTipCtrl m_tipCtrl;
	std::shared_ptr<CHouse> m_spHouse = nullptr;
	std::shared_ptr<CParents> m_spParents = nullptr;
	std::shared_ptr<CInsurance> m_spInsurance = nullptr;
	std::shared_ptr<CAdultEducation> m_spAdultEducation = nullptr;
	std::shared_ptr<CChildrenEducation> m_spChildrenEducation = nullptr;
};
