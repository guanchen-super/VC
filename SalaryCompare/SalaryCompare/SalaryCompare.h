
// SalaryCompare.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSalaryCompareApp: 
// �йش����ʵ�֣������ SalaryCompare.cpp
//

class CSalaryCompareApp : public CWinApp
{
public:
	CSalaryCompareApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSalaryCompareApp theApp;