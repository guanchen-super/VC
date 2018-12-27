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
	, m_dGJJRate(12)
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

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	if (nullptr != pEdit)
		pEdit->SetLimitText(10);

	pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	if (nullptr != pEdit)
		pEdit->SetLimitText(10);

	pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	if (nullptr != pEdit)
		pEdit->SetLimitText(2);

	pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	if (nullptr != pEdit)
		pEdit->SetLimitText(10);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

BEGIN_MESSAGE_MAP(CInsurance, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &CInsurance::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CInsurance::OnBnClickedRadio2)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CInsurance::OnEnKillfocusEdit3)
	ON_EN_CHANGE(IDC_EDIT3, &CInsurance::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CInsurance::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CInsurance::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CInsurance::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CInsurance 消息处理程序

void CInsurance::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CInsurance::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}

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

void CInsurance::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	if (nullptr == pEdit)
		return;

	if (0 == pEdit->GetWindowTextLength())
	{
		pEdit->SetWindowText(_T("0"));
		pEdit->SetFocus();
		pEdit->SetSel(0, -1);
	}
}

void CInsurance::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	if (nullptr == pEdit)
		return;

	if (0 == pEdit->GetWindowTextLength())
	{
		pEdit->SetWindowText(_T("0"));
		pEdit->SetFocus();
		pEdit->SetSel(0, -1);
	}
}

void CInsurance::OnEnKillfocusEdit3()
{
	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	if (nullptr == pEdit)
		return;

	if (1 == pEdit->GetWindowTextLength())
	{
		UpdateData(TRUE);
		if (m_dGJJRate < 5)
		{
			MessageBox(_T("公积金缴存比例应为5% - 12%"));
			pEdit->SetWindowText(_T("5"));
			pEdit->SetFocus();
			pEdit->SetSel(0, -1);
		}
	}
}

void CInsurance::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	if (nullptr == pEdit)
		return;

	if (0 == pEdit->GetWindowTextLength())
	{
		pEdit->SetWindowText(_T("12"));
		pEdit->SetFocus();
		pEdit->SetSel(0, -1);
	}

	if (2 == pEdit->GetWindowTextLength())
	{
		UpdateData(TRUE);
		if (m_dGJJRate > 12)
		{
			MessageBox(_T("公积金缴存比例应为5% - 12%"));
			pEdit->SetWindowText(_T("12"));
			pEdit->SetFocus();
			pEdit->SetSel(0, -1);
		}
	}
}

void CInsurance::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	if (nullptr == pEdit)
		return;

	if (0 == pEdit->GetWindowTextLength())
	{
		pEdit->SetWindowText(_T("0"));
		pEdit->SetFocus();
		pEdit->SetSel(0, -1);
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
