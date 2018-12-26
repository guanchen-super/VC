// House.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "House.h"
#include "afxdialogex.h"


// CHouse 对话框

IMPLEMENT_DYNAMIC(CHouse, CDialogEx)

CHouse::CHouse(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HOUSE, pParent)
	, m_nChooseGroup(0)
{

}

CHouse::~CHouse()
{
}

void CHouse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nChooseGroup);
	DDV_MinMaxInt(pDX, m_nChooseGroup, 0, 1);
	DDX_Control(pDX, IDC_COMBO1, m_comboxRent);
	DDX_Control(pDX, IDC_COMBO2, m_comboxDeal);
}

BOOL CHouse::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_comboxRent.SetCurSel(0);
	m_comboxDeal.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CHouse::OnBnClickedRadio1()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 0:
		m_comboxRent.EnableWindow(TRUE);
		m_comboxDeal.EnableWindow(FALSE);
		break;
	}
}

void CHouse::OnBnClickedRadio3()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 1:
		m_comboxRent.EnableWindow(FALSE);
		m_comboxDeal.EnableWindow(TRUE);
		break;
	}
}

const int CHouse::GetCount()
{
	UpdateData(TRUE);
	
	if (0 == m_nChooseGroup)
	{
		if (0 == m_comboxRent.GetCurSel())
			m_nMoneyCount = 0;
		else if (1 == m_comboxRent.GetCurSel())
			m_nMoneyCount = 800;
		else if (2 == m_comboxRent.GetCurSel())
			m_nMoneyCount = 1100;
		else if (3 == m_comboxRent.GetCurSel())
			m_nMoneyCount = 1500;
	}
	else
	{
		if (0 == m_comboxDeal.GetCurSel())
			m_nMoneyCount = 0;
		else if (1 == m_comboxDeal.GetCurSel())
			m_nMoneyCount = 1000;
	}

	return m_nMoneyCount;
}

BEGIN_MESSAGE_MAP(CHouse, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CHouse::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CHouse::OnBnClickedRadio3)
END_MESSAGE_MAP()