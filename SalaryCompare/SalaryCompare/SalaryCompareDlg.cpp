
// SalaryCompareDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "SalaryCompareDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "OtherItem.h"

CSalaryCompareDlg::CSalaryCompareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SALARYCOMPARE_DIALOG, pParent)
	, m_dSalary(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_APP);
}

void CSalaryCompareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listCtrl);
	DDX_Text(pDX, IDC_SALARY, m_dSalary);
	DDV_MinMaxDouble(pDX, m_dSalary, 0, 9999999999);
}

BEGIN_MESSAGE_MAP(CSalaryCompareDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULATE, &CSalaryCompareDlg::OnBnClickedCalculate)
	ON_BN_CLICKED(IDC_OTHER, &CSalaryCompareDlg::OnBnClickedOther)
	ON_EN_CHANGE(IDC_SALARY, &CSalaryCompareDlg::OnEnChangeSalary)
	ON_WM_SIZE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CSalaryCompareDlg ��Ϣ�������

BOOL CSalaryCompareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// ���ñ�ͷ
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listCtrl.InsertColumn(0, _T("�·�"), LVCFMT_LEFT, 50);
	m_listCtrl.InsertColumn(1, _T("��˰��ǰ"), LVCFMT_LEFT);
	m_listCtrl.InsertColumn(2, _T("��˰����"), LVCFMT_LEFT);
	m_listCtrl.InsertColumn(3, _T("���"), LVCFMT_LEFT);

	CHeaderCtrl * pHeader = m_listCtrl.GetHeaderCtrl();
	int nCount = pHeader->GetItemCount();

	RECT rect;
	m_listCtrl.GetWindowRect(&rect);
	for (int i = 1; i != nCount; ++i)
	{
		m_listCtrl.SetColumnWidth(i, (rect.right - rect.left - 50)/3);
	}

	m_listCtrl.InsertItem(0, _T("һ��"));
	m_listCtrl.InsertItem(1, _T("����"));
	m_listCtrl.InsertItem(2, _T("����"));
	m_listCtrl.InsertItem(3, _T("����"));
	m_listCtrl.InsertItem(4, _T("����"));
	m_listCtrl.InsertItem(5, _T("����"));
	m_listCtrl.InsertItem(6, _T("����"));
	m_listCtrl.InsertItem(7, _T("����"));
	m_listCtrl.InsertItem(8, _T("����"));
	m_listCtrl.InsertItem(9, _T("ʮ��"));
	m_listCtrl.InsertItem(10, _T("ʮһ��"));
	m_listCtrl.InsertItem(11, _T("ʮ����"));
	m_listCtrl.InsertItem(12, _T("�ܶ�"));

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_taxRate[0] = 0.03;
	m_taxRate[1] = 0.10;
	m_taxRate[2] = 0.20;
	m_taxRate[3] = 0.25;
	m_taxRate[4] = 0.30;
	m_taxRate[5] = 0.35;
	m_taxRate[6] = 0.45;

	m_oldMinus[0] = 0;
	m_oldMinus[1] = 210;
	m_oldMinus[2] = 1410;
	m_oldMinus[3] = 2660;
	m_oldMinus[4] = 4410;
	m_oldMinus[5] = 7160;
	m_oldMinus[6] = 15160;

	m_newMinus[0] = 0;
	m_newMinus[1] = 2520;
	m_newMinus[2] = 16920;
	m_newMinus[3] = 31920;
	m_newMinus[4] = 52920;
	m_newMinus[5] = 85920;
	m_newMinus[6] = 181920;
	
	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_SALARY));
	if (nullptr != pEdit)
		pEdit->SetLimitText(10);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSalaryCompareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (SC_CLOSE == nID || SC_MOVE == nID || 0xF012 == nID)
		CDialogEx::OnSysCommand(nID, lParam);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSalaryCompareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSalaryCompareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSalaryCompareDlg::OnEnChangeSalary()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	CEdit * pEdit = reinterpret_cast<CEdit*>(GetDlgItem(IDC_SALARY));
	if (nullptr == pEdit)
		return;

	if (0 == pEdit->GetWindowTextLength())
	{
		pEdit->SetWindowText(_T("0"));
		pEdit->SetFocus();
		pEdit->SetSel(0, -1);
	}
}


void CSalaryCompareDlg::OnBnClickedOther()
{
	COtherItem otherItem;
	otherItem.DoModal();

	m_dWXYJMoney = otherItem.GetWXYIItemCount();
	m_dOtherMoney = otherItem.GetOtherItemCount();
}

// ������˰��
void CSalaryCompareDlg::OnBnClickedCalculate()
{
	UpdateData();

	double arrOldSalaryCount[13] = { 0 };
	getForwardSalary(m_dSalary, arrOldSalaryCount);
	double arrNewSalaryCount[13] = { 0 };
	getAfterwardSalary(m_dSalary, m_dWXYJMoney, m_dOtherMoney, arrNewSalaryCount);

	for (int i = 0; i != 13; ++i)
	{
		TCHAR buf[20];
		ZeroMemory(buf, 20);
		swprintf_s(buf, _T("%.2f"), arrOldSalaryCount[i]);
		m_listCtrl.SetItemText(i, 1, buf);

		ZeroMemory(buf, 20);
		swprintf_s(buf, _T("%.2f"), arrNewSalaryCount[i]);
		m_listCtrl.SetItemText(i, 2, buf);

		ZeroMemory(buf, 20);
		swprintf_s(buf, _T("%.2f"), arrNewSalaryCount[i] - arrOldSalaryCount[i]);
		m_listCtrl.SetItemText(i, 3, buf);
	}

	m_dWXYJMoney = 0.0;
	m_dOtherMoney = 0.0;
}

BOOL CSalaryCompareDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// ����������Ϣ֪ͨ�룬ʹ�ý�ֹ�϶�List��ͷ
	NMHEADER* pNMHeader = (NMHEADER*)lParam;
	if (((pNMHeader->hdr.code == HDN_BEGINTRACKW) |
		(pNMHeader->hdr.code == HDN_DIVIDERDBLCLICKW)))
	{
		*pResult = TRUE;
		return TRUE;
	}

	return CDialogEx::OnNotify(wParam, lParam, pResult);
}

void CSalaryCompareDlg::getForwardSalary(const double dSalary, double * salaryCount)
{
	if (dSalary - m_dWXYJMoney <= 5000)
	{
		for (int i = 0; i != 12; ++i)
		{
			salaryCount[i] = dSalary - m_dWXYJMoney;
			salaryCount[12] += salaryCount[i];
		}
	}
	else
	{
		double tempSalary = dSalary - 5000 - m_dWXYJMoney;
		int nLevel = getLevel(tempSalary);
		double nTemp = tempSalary * m_taxRate[nLevel] - m_oldMinus[nLevel];

		for (int i = 0; i != 12; ++i)
		{
			salaryCount[i] = tempSalary - nTemp + 5000;
			salaryCount[12] += salaryCount[i];
		}
	}
}

void CSalaryCompareDlg::getAfterwardSalary(const double dSalary, const double dInsurance, const double dDiscounts, double * salaryCount)
{
	double nTemp0 = 0.0;	// �ۼƽ�˰��
	double nTemp1 = 0.0;	// ���½�˰��
	double nTemp2 = 0.0;	// �ȼ������

	for (int i = 1; i != 13; ++i)
	{
		nTemp2 = dSalary * i - (5000 + dInsurance + dDiscounts) * i;
		if (0 > nTemp2)
			nTemp2 = 0.0;

		int nLevel = getLevel(nTemp2, true);
		nTemp1 = nTemp2 * m_taxRate[nLevel] - m_newMinus[nLevel] - nTemp0;
		salaryCount[i - 1] = dSalary - dInsurance - nTemp1;
		salaryCount[12] += salaryCount[i - 1];
		nTemp0 += nTemp1;
	}
}

int CSalaryCompareDlg::getLevel(const double dSalary, bool bNew /*= false*/)
{
	int nLevel = 0;
	if (bNew)
	{
		if (dSalary <= 36000)
			nLevel = 0;
		else if (dSalary > 36000 && dSalary <= 144000)
			nLevel = 1;
		else if (dSalary > 144000 && dSalary <= 300000)
			nLevel = 2;
		else if (dSalary > 300000 && dSalary <= 420000)
			nLevel = 3;
		else if (dSalary > 420000 && dSalary <= 660000)
			nLevel = 4;
		else if (dSalary > 660000 && dSalary <= 960000)
			nLevel = 5;
		else if (dSalary > 960000)
			nLevel = 6;
	}
	else
	{
		if (dSalary <= 3000)
			nLevel = 0;
		else if (dSalary > 3000 && dSalary <= 12000)
			nLevel = 1;
		else if (dSalary > 12000 && dSalary <= 25000)
			nLevel = 2;
		else if (dSalary > 25000 && dSalary <= 35000)
			nLevel = 3;
		else if (dSalary > 35000 && dSalary <= 55000)
			nLevel = 4;
		else if (dSalary > 55000 && dSalary <= 80000)
			nLevel = 5;
		else if (dSalary > 80000)
			nLevel = 6;
	}
	return nLevel;
}
