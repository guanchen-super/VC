// Parents.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "Parents.h"
#include "afxdialogex.h"


// CParents �Ի���

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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	if (nullptr != pEdit)
		pEdit->SetLimitText(4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CParents::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

void CParents::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}

void CParents::OnEnKillfocusEdit1()
{
	/*UpdateData(TRUE);
	if (m_dMoney < 0 || m_dMoney > 2000)
	{
		MessageBox(_T("����������߽��Ϊ2000Ԫ/�£�"));
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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
			MessageBox(_T("����������߽��Ϊ2000Ԫ/�£�"));
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
