
// Login_with_database.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLogin_with_databaseApp:
// �йش����ʵ�֣������ Login_with_database.cpp
//

class CLogin_with_databaseApp : public CWinApp
{
public:
	CLogin_with_databaseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLogin_with_databaseApp theApp;