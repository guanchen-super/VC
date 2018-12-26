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
	DECLARE_MESSAGE_MAP()

public:
	const double GetWXYIItemCount() const;
	const double GetOtherItemCount() const;

private:
	int m_nCurSelTab = 0;
	double m_dWXYJCount;
	double m_dOtherCount;
	CDialogEx* m_pDlgTab[5];
public:
	CTabCtrl m_tabCtrl;
	CHouse m_house;
	CParents m_parents;
	CInsurance m_Insurance;
	CAdultEducation m_adultEducation;
	CChildrenEducation m_childrenEducation;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
};
