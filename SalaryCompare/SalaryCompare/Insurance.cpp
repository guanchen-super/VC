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
	, m_nChooseGroup(0)
	, m_dCount(0)
	, m_dGJJBase(0)
	, m_dGJJRate(0)
	, m_dSBBase(0)
{

}

CInsurance::~CInsurance()
{
}

void CInsurance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nChooseGroup);
	DDX_Text(pDX, IDC_EDIT1, m_dCount);
	DDX_Text(pDX, IDC_EDIT2, m_dGJJBase);
	DDX_Text(pDX, IDC_EDIT3, m_dGJJRate);
	DDX_Text(pDX, IDC_EDIT4, m_dSBBase);
	DDX_Control(pDX, IDC_COMBO2, m_comboxCity);
}

BOOL CInsurance::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_comboxCity.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
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
		m_comboxCity.EnableWindow(FALSE);
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
		m_comboxCity.EnableWindow(TRUE);
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
		int nIndex = m_comboxCity.GetCurSel();

		// 养老保险
		m_dMoneyCount = m_dSBBase * g_vecAgeInsurance[nIndex];

		// 失业保险
		m_dMoneyCount += m_dSBBase * g_vecLoseJobInsurance[nIndex];

		// 工伤保险
		m_dMoneyCount += m_dSBBase * g_vecInjuryInsurance[nIndex];

		// 生育保险
		m_dMoneyCount += m_dSBBase * g_vecBirthInsurance[nIndex];

		// 医疗保险 + 医疗附加额
		m_dMoneyCount += m_dSBBase * g_vecTreatmentInsurance[nIndex] + g_vecTreatmentInsuranceAdd[nIndex];

		// 公积金
		m_dMoneyCount += m_dGJJBase * m_dGJJRate / 100.0;
	}

	return m_dMoneyCount;
}
