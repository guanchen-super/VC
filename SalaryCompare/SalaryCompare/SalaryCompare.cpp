
// SalaryCompare.cpp : 定义应用程序的类行为。
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


// CSalaryCompareApp 构造

CSalaryCompareApp::CSalaryCompareApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CSalaryCompareApp 对象

CSalaryCompareApp theApp;

// 北京,...
std::vector<double> g_vecAgeInsurance{ 0.08 };
std::vector<double> g_vecLoseJobInsurance{ 0.002 };
std::vector<double> g_vecInjuryInsurance{ 0 };
std::vector<double> g_vecBirthInsurance{ 0 };
std::vector<double> g_vecTreatmentInsurance{ 0.02 };
std::vector<double> g_vecTreatmentInsuranceAdd{ 3 };

// 政策
std::vector<String> g_vecTipContent
{
	_T("五险一金相关知识网络搜索了解。\n"),
	_T("1.有子女符合以下两个条件之一：\n（1）扣除年度有子女满3岁且处于小学入学前阶段；\n（2）扣除年度有子女正接受全日制学历教育。\n2.同一子女的父亲和母亲扣除比例合计不超过100%。\n"),
	_T("1.租赁\n（1）本人及配偶在主要工作城市无自有住房；\n（2）本人及配偶扣除年度未扣除住房贷款利息支出；\n（3）本人及配偶主要工作城市相同的，该扣除年度配偶未享受过住房租金支出扣除。\n2.房贷\n（1）本人或者配偶购买的中国境内住房；\n（2）属于首套住房贷款（可咨询贷款银行），且扣除年度仍在还贷；\n（3）住房租金支出和住房贷款利息支出未同时扣除；\n"),
	_T("1.扣除年度有一位被赡养人年满60（含）岁\n（被赡养人包括：①父母；②子女均已去世的祖父母或外祖父母）。\n2.纳税人为非独生子女，且属于赡养人约定分摊的或被赡养人指定分摊的，\n需已经签订书面分摊协议。\n"),
	_T("1.学历学位：\n扣除年度内在中国境内接受学历（学位）继续教育。\n2.职业资格：\n扣除年度取得职业资格或者专业技术人员职业资格相关证书。\n")
};

// CSalaryCompareApp 初始化

BOOL CSalaryCompareApp::InitInstance()
{
	CWinApp::InitInstance();


	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CSalaryCompareDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

