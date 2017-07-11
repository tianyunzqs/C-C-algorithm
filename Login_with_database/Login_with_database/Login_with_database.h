
// Login_with_database.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CLogin_with_databaseApp:
// 有关此类的实现，请参阅 Login_with_database.cpp
//

class CLogin_with_databaseApp : public CWinApp
{
public:
	CLogin_with_databaseApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CLogin_with_databaseApp theApp;