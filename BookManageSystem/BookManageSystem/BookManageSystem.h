
// BookManageSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBookManageSystemApp:
// �йش����ʵ�֣������ BookManageSystem.cpp
//

class CBookManageSystemApp : public CWinApp
{
public:
	CBookManageSystemApp();

// ��д
public:
	virtual BOOL InitInstance();

public:
	CString LoginUserNameApp;
	CString LoginPassWordApp;
	int NextTypeApp;

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBookManageSystemApp theApp;