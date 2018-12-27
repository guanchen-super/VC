// AdultEducation.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "AdultEducation.h"
#include "afxdialogex.h"


// CAdultEducation 对话框

IMPLEMENT_DYNAMIC(CAdultEducation, CDialogEx)

CAdultEducation::CAdultEducation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADULT_EDUCATION, pParent)
	, m_nChooseGroup(0)
{

}

CAdultEducation::~CAdultEducation()
{
}

void CAdultEducation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_comboxXL);
	DDX_Control(pDX, IDC_COMBO3, m_comboxZY);
	DDX_Radio(pDX, IDC_RADIO1, m_nChooseGroup);
}

BOOL CAdultEducation::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_comboxXL.SetCurSel(0);
	m_comboxZY.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CAdultEducation::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CAdultEducation::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}

void CAdultEducation::OnBnClickedRadio1()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 0:
		m_comboxXL.EnableWindow(TRUE);
		m_comboxZY.EnableWindow(FALSE);
		break;
	}
}


void CAdultEducation::OnBnClickedRadio3()
{
	UpdateData(TRUE);
	switch (m_nChooseGroup)
	{
	case 1:
		m_comboxXL.EnableWindow(FALSE);
		m_comboxZY.EnableWindow(TRUE);
		break;
	}
}

const double CAdultEducation::GetCount()
{
	UpdateData(TRUE);

	int nMoney = 0;
	if (0 == m_nChooseGroup)
	{
		nMoney = 0 == m_comboxXL.GetCurSel() ? 0 : 400;
	}
	else
	{
		nMoney = 0 == m_comboxZY.GetCurSel() ? 0 : 3600;
		nMoney /= 12;
	}

	return nMoney;
}

BEGIN_MESSAGE_MAP(CAdultEducation, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CAdultEducation::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CAdultEducation::OnBnClickedRadio3)
END_MESSAGE_MAP()
