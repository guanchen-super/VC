// OtherItem.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "OtherItem.h"
#include "afxdialogex.h"


// COtherItem 对话框

IMPLEMENT_DYNAMIC(COtherItem, CDialogEx)

COtherItem::COtherItem(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OTHER_ITEM, pParent)
{

}

COtherItem::~COtherItem()
{
}

void COtherItem::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tabCtrl);
}

const double COtherItem::GetWXYIItemCount() const
{
	return m_dWXYJCount;
}

const double COtherItem::GetOtherItemCount() const
{
	return m_dOtherCount;
}


BEGIN_MESSAGE_MAP(COtherItem, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &COtherItem::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, &COtherItem::OnBnClickedOk)
END_MESSAGE_MAP()


// COtherItem 消息处理程序


BOOL COtherItem::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_tabCtrl.InsertItem(0, _T("五险一金"));
	m_tabCtrl.InsertItem(1, _T("子女教育"));
	m_tabCtrl.InsertItem(2, _T("租房房贷"));
	m_tabCtrl.InsertItem(3, _T("赡养老人"));
	m_tabCtrl.InsertItem(4, _T("继续教育"));

	CRect rc;
	m_tabCtrl.GetClientRect(&rc);
	rc.top += 20;

	m_Insurance.Create(IDD_INSURANCE, &m_tabCtrl);
	m_Insurance.MoveWindow(&rc);
	m_Insurance.ShowWindow(SW_SHOW);
	m_pDlgTab[0] = &m_Insurance;

	m_childrenEducation.Create(IDD_CHILDREN_EDUCATION, &m_tabCtrl);
	m_childrenEducation.MoveWindow(&rc);
	m_childrenEducation.ShowWindow(SW_HIDE);
	m_pDlgTab[1] = &m_childrenEducation;

	m_house.Create(IDD_HOUSE, &m_tabCtrl);
	m_house.MoveWindow(&rc);
	m_house.ShowWindow(SW_HIDE);
	m_pDlgTab[2] = &m_house;

	m_parents.Create(IDD_PARENTS, &m_tabCtrl);
	m_parents.MoveWindow(&rc);
	m_parents.ShowWindow(SW_HIDE);
	m_pDlgTab[3] = &m_parents;

	m_adultEducation.Create(IDD_ADULT_EDUCATION, &m_tabCtrl);
	m_adultEducation.MoveWindow(&rc);
	m_adultEducation.ShowWindow(SW_HIDE);
	m_pDlgTab[4] = &m_adultEducation;
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void COtherItem::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_pDlgTab[m_nCurSelTab]->ShowWindow(SW_HIDE);
	m_nCurSelTab = m_tabCtrl.GetCurSel();
	m_pDlgTab[m_nCurSelTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


void COtherItem::OnBnClickedOk()
{
	m_dWXYJCount = m_Insurance.GetCount();
	m_dOtherCount = m_childrenEducation.GetCount();
	m_dOtherCount += m_house.GetCount();
	m_dOtherCount += m_parents.GetCount();
	m_dOtherCount += m_adultEducation.GetCount();

	CDialogEx::OnOK();
}
