// Parents.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "Parents.h"
#include "afxdialogex.h"


// CParents 对话框

IMPLEMENT_DYNAMIC(CParents, CDialogEx)

CParents::CParents(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PARENTS, pParent)
	, m_dMoney(0)
{

}

CParents::~CParents()
{
}

void CParents::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dMoney);
}

BOOL CParents::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	if (nullptr != pEdit)
		pEdit->SetLimitText(4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CParents::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CParents::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}

void CParents::OnEnKillfocusEdit1()
{
	/*UpdateData(TRUE);
	if (m_dMoney < 0 || m_dMoney > 2000)
	{
		MessageBox(_T("赡养老人最高金额为2000元/月！"));
		CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
		if (nullptr != pEdit)
		{
			pEdit->SetFocus();
			pEdit->SetWindowText(_T("2000"));
			pEdit->SetSel(0, -1);
		}
	}*/
}

void CParents::OnEnChangeEdit1()
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

	if (4 == pEdit->GetWindowTextLength())
	{
		UpdateData(TRUE);
		if (m_dMoney > 2000)
		{
			MessageBox(_T("赡养老人最高金额为2000元/月！"));
			pEdit->SetFocus();
			pEdit->SetWindowText(_T("2000"));
			pEdit->SetSel(0, -1);
		}
	}
}

const double CParents::GetCount()
{
	UpdateData(TRUE);
	return m_dMoney;
}


BEGIN_MESSAGE_MAP(CParents, CDialogEx)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CParents::OnEnKillfocusEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &CParents::OnEnChangeEdit1)
END_MESSAGE_MAP()
