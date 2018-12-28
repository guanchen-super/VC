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
	, m_spHouse(std::make_shared<CHouse>(m_bChange))
	, m_spParents(std::make_shared<CParents>(m_bChange))
	, m_spInsurance(std::make_shared<CInsurance>(m_bChange))
	, m_spAdultEducation(std::make_shared<CAdultEducation>(m_bChange))
	, m_spChildrenEducation(std::make_shared<CChildrenEducation>(m_bChange))
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
	ON_WM_PAINT()
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

	m_spInsurance->Create(IDD_INSURANCE, &m_tabCtrl);
	m_spInsurance->MoveWindow(&rc);
	m_spInsurance->ShowWindow(SW_SHOW);
	m_pDlgTab[0] = m_spInsurance.get();

	m_spChildrenEducation->Create(IDD_CHILDREN_EDUCATION, &m_tabCtrl);
	m_spChildrenEducation->MoveWindow(&rc);
	m_spChildrenEducation->ShowWindow(SW_HIDE);
	m_pDlgTab[1] = m_spChildrenEducation.get();

	m_spHouse->Create(IDD_HOUSE, &m_tabCtrl);
	m_spHouse->MoveWindow(&rc);
	m_spHouse->ShowWindow(SW_HIDE);
	m_pDlgTab[2] = m_spHouse.get();

	m_spParents->Create(IDD_PARENTS, &m_tabCtrl);
	m_spParents->MoveWindow(&rc);
	m_spParents->ShowWindow(SW_HIDE);
	m_pDlgTab[3] = m_spParents.get();

	m_spAdultEducation->Create(IDD_ADULT_EDUCATION, &m_tabCtrl);
	m_spAdultEducation->MoveWindow(&rc);
	m_spAdultEducation->ShowWindow(SW_HIDE);
	m_pDlgTab[4] = m_spAdultEducation.get();

	
	m_tipCtrl.Create(this);
	m_tipCtrl.SetMaxTipWidth(300);
	m_tipCtrl.AddTool(GetDlgItem(IDC_STATIC), g_vecTipContent[m_nCurSelTab].c_str());
	m_tipCtrl.Activate(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL COtherItem::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_tipCtrl.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}


void COtherItem::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	m_pDlgTab[m_nCurSelTab]->SetFocus();
	if (m_bChange)
	{
		m_pDlgTab[m_nCurSelTab]->ShowWindow(SW_HIDE);
		m_nCurSelTab = m_tabCtrl.GetCurSel();
		m_pDlgTab[m_nCurSelTab]->ShowWindow(SW_SHOW);
		m_tipCtrl.AddTool(GetDlgItem(IDC_STATIC), g_vecTipContent[m_nCurSelTab].c_str());
	}
	m_tabCtrl.SetCurSel(m_nCurSelTab);
	m_bChange = true;
	*pResult = 0;
}


void COtherItem::OnBnClickedOk()
{
	m_dWXYJCount = m_spInsurance->GetCount();
	m_dOtherCount = m_spChildrenEducation->GetCount();
	m_dOtherCount += m_spHouse->GetCount();
	m_dOtherCount += m_spParents->GetCount();
	m_dOtherCount += m_spAdultEducation->GetCount();

	CDialogEx::OnOK();
}
