
// SalaryCompare.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "SalaryCompare.h"
#include "SalaryCompareDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalaryCompareApp

BEGIN_MESSAGE_MAP(CSalaryCompareApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CSalaryCompareApp ����

CSalaryCompareApp::CSalaryCompareApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CSalaryCompareApp ����

CSalaryCompareApp theApp;

// ����,...
std::vector<double> g_vecAgeInsurance{ 0.08 };
std::vector<double> g_vecLoseJobInsurance{ 0.002 };
std::vector<double> g_vecInjuryInsurance{ 0 };
std::vector<double> g_vecBirthInsurance{ 0 };
std::vector<double> g_vecTreatmentInsurance{ 0.02 };
std::vector<double> g_vecTreatmentInsuranceAdd{ 3 };

// ����
std::vector<String> g_vecTipContent
{
	_T("����һ�����֪ʶ���������˽⡣\n"),
	_T("1.����Ů����������������֮һ��\n��1���۳��������Ů��3���Ҵ���Сѧ��ѧǰ�׶Σ�\n��2���۳��������Ů������ȫ����ѧ��������\n2.ͬһ��Ů�ĸ��׺�ĸ�׿۳������ϼƲ�����100%��\n"),
	_T("1.����\n��1�����˼���ż����Ҫ��������������ס����\n��2�����˼���ż�۳����δ�۳�ס��������Ϣ֧����\n��3�����˼���ż��Ҫ����������ͬ�ģ��ÿ۳������żδ���ܹ�ס�����֧���۳���\n2.����\n��1�����˻�����ż������й�����ס����\n��2����������ס���������ѯ�������У����ҿ۳�������ڻ�����\n��3��ס�����֧����ס��������Ϣ֧��δͬʱ�۳���\n"),
	_T("1.�۳������һλ������������60��������\n���������˰������ٸ�ĸ������Ů����ȥ�����游ĸ�����游ĸ����\n2.��˰��Ϊ�Ƕ�����Ů��������������Լ����̯�Ļ�������ָ����̯�ģ�\n���Ѿ�ǩ�������̯Э�顣\n"),
	_T("1.ѧ��ѧλ��\n�۳���������й����ڽ���ѧ����ѧλ������������\n2.ְҵ�ʸ�\n�۳����ȡ��ְҵ�ʸ����רҵ������Աְҵ�ʸ����֤�顣\n")
};

// CSalaryCompareApp ��ʼ��

BOOL CSalaryCompareApp::InitInstance()
{
	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CSalaryCompareDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

