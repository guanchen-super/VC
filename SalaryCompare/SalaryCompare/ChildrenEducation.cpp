// ChildrenEducation.cpp : 实现文件
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "ChildrenEducation.h"
#include "afxdialogex.h"


// CChildrenEducation 对话框

IMPLEMENT_DYNAMIC(CChildrenEducation, CDialogEx)

CChildrenEducation::CChildrenEducation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHILDREN_EDUCATION, pParent)
{

}

CChildrenEducation::~CChildrenEducation()
{
}

void CChildrenEducation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboxChildren);
	DDX_Control(pDX, IDC_COMBO2, m_comboxMoney);
}

BOOL CChildrenEducation::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_comboxChildren.SetCurSel(0);
	m_comboxMoney.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

const int CChildrenEducation::GetCount()
{
	UpdateData(TRUE);

	int nMoney = 0;
	int nPerson = m_comboxChildren.GetCurSel();
	if (0 != nPerson)
	{
		if (0 == m_comboxMoney.GetCurSel())
			nMoney = 0;
		else if (1 == m_comboxMoney.GetCurSel())
			nMoney = 500;
		else if (2 == m_comboxMoney.GetCurSel())
			nMoney = 1000;
	}
	return nPerson * nMoney;
}


BEGIN_MESSAGE_MAP(CChildrenEducation, CDialogEx)
END_MESSAGE_MAP()


// CChildrenEducation 消息处理程序
