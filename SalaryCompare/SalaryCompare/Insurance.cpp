// Insurance.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "Insurance.h"
#include "afxdialogex.h"


// CInsurance 对话框

IMPLEMENT_DYNAMIC(CInsurance, CDialogEx)

CInsurance::CInsurance(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INSURANCE, pParent)
	, m_strGJJBase(_T(""))
	, m_strGJJRate(_T(""))
	, m_strSBBase(_T(""))
	, m_nChooseGroup(0)
	, m_dCount(0)
{

}

CInsurance::~CInsurance()
{
}

void CInsurance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strGJJBase);
	DDX_Text(pDX, IDC_EDIT3, m_strGJJRate);
	DDX_Text(pDX, IDC_EDIT4, m_strSBBase);
	DDX_Radio(pDX, IDC_RADIO1, m_nChooseGroup);
	DDX_Text(pDX, IDC_EDIT1, m_dCount);
}


BEGIN_MESSAGE_MAP(CInsurance, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CInsurance::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CInsurance::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CInsurance 消息处理程序
void CInsurance::OnBnClickedRadio1()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 0:
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
		break;
	}
}

void CInsurance::OnBnClickedRadio2()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 1:
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
		break;
	}
}

const double CInsurance::GetCount()
{
	UpdateData(TRUE);
	if (0 == m_nChooseGroup)
	{
		m_dMoneyCount = m_dCount;
	}
	else
	{

	}

	return m_dMoneyCount;
}
