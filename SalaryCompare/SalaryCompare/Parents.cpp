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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

const double CParents::GetCount()
{
	UpdateData(TRUE);
	return m_dMoney;
}


BEGIN_MESSAGE_MAP(CParents, CDialogEx)
END_MESSAGE_MAP()
