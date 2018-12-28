
// SalaryCompareDlg.cpp : 实现文件
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


// CSalaryCompareDlg 消息处理程序

BOOL CSalaryCompareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// 设置表头
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listCtrl.InsertColumn(0, _T("月份"), LVCFMT_LEFT, 50);
	m_listCtrl.InsertColumn(1, _T("新税法前"), LVCFMT_LEFT);
	m_listCtrl.InsertColumn(2, _T("新税法后"), LVCFMT_LEFT);
	m_listCtrl.InsertColumn(3, _T("差额"), LVCFMT_LEFT);

	CHeaderCtrl * pHeader = m_listCtrl.GetHeaderCtrl();
	int nCount = pHeader->GetItemCount();

	RECT rect;
	m_listCtrl.GetWindowRect(&rect);
	for (int i = 1; i != nCount; ++i)
	{
		m_listCtrl.SetColumnWidth(i, (rect.right - rect.left - 50)/3);
	}

	m_listCtrl.InsertItem(0, _T("一月"));
	m_listCtrl.InsertItem(1, _T("二月"));
	m_listCtrl.InsertItem(2, _T("三月"));
	m_listCtrl.InsertItem(3, _T("四月"));
	m_listCtrl.InsertItem(4, _T("五月"));
	m_listCtrl.InsertItem(5, _T("六月"));
	m_listCtrl.InsertItem(6, _T("七月"));
	m_listCtrl.InsertItem(7, _T("八月"));
	m_listCtrl.InsertItem(8, _T("九月"));
	m_listCtrl.InsertItem(9, _T("十月"));
	m_listCtrl.InsertItem(10, _T("十一月"));
	m_listCtrl.InsertItem(11, _T("十二月"));
	m_listCtrl.InsertItem(12, _T("总额"));

	// TODO: 在此添加额外的初始化代码
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
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSalaryCompareDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (SC_CLOSE == nID || SC_MOVE == nID || 0xF012 == nID)
		CDialogEx::OnSysCommand(nID, lParam);
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSalaryCompareDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSalaryCompareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSalaryCompareDlg::OnEnChangeSalary()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

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

// 计算新税法
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
	// 屏蔽两个消息通知码，使得禁止拖动List表头
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
	double nTemp0 = 0.0;	// 累计缴税额
	double nTemp1 = 0.0;	// 当月缴税额
	double nTemp2 = 0.0;	// 等级计算额

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
