#pragma once
#include "afxwin.h"


// CChildrenEducation �Ի���

class CChildrenEducation : public CDialogEx
{
	DECLARE_DYNAMIC(CChildrenEducation)

public:
	CChildrenEducation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChildrenEducation();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHILDREN_EDUCATION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	const int GetCount();

private:
	CComboBox m_comboxChildren;
	CComboBox m_comboxMoney;
};
