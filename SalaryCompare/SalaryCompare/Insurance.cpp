// Insurance.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "Insurance.h"
#include "afxdialogex.h"


// CInsurance �Ի���

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
				  // �쳣: OCX ����ҳӦ���� FALSE
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


// CInsurance ��Ϣ�������

void CInsurance::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}

void CInsurance::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

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
}

void CInsurance::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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
			MessageBox(_T("������ɴ����ӦΪ5% - 12%"));
			pEdit->SetWindowText(_T("5"));
			pEdit->SetFocus();
			pEdit->SetSel(0, -1);
		}
	}
}

void CInsurance::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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
			MessageBox(_T("������ɴ����ӦΪ5% - 12%"));
			pEdit->SetWindowText(_T("12"));
			pEdit->SetFocus();
			pEdit->SetSel(0, -1);
		}
	}
}

void CInsurance::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

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

		// ���ϱ���
		m_dMoneyCount = m_dSBBase * g_vecAgeInsurance[nIndex];

		// ʧҵ����
		m_dMoneyCount += m_dSBBase * g_vecLoseJobInsurance[nIndex];

		// ���˱���
		m_dMoneyCount += m_dSBBase * g_vecInjuryInsurance[nIndex];

		// ��������
		m_dMoneyCount += m_dSBBase * g_vecBirthInsurance[nIndex];

		// ҽ�Ʊ��� + ҽ�Ƹ��Ӷ�
		m_dMoneyCount += m_dSBBase * g_vecTreatmentInsurance[nIndex] + g_vecTreatmentInsuranceAdd[nIndex];

		// ������
		m_dMoneyCount += m_dGJJBase * m_dGJJRate / 100.0;
	}

	return m_dMoneyCount;
}
