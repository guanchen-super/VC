#pragma once


// CParents �Ի���

class CParents : public CDialogEx
{
	DECLARE_DYNAMIC(CParents)

public:
	CParents(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CParents();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARENTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	const double GetCount();

private:	
	double m_dMoney;
};
