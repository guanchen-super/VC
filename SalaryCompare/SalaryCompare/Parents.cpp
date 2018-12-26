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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

const double CParents::GetCount()
{
	UpdateData(TRUE);
	return m_dMoney;
}


BEGIN_MESSAGE_MAP(CParents, CDialogEx)
END_MESSAGE_MAP()
