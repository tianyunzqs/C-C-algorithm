
// Login_ConnectDataBase.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLogin_ConnectDataBaseApp:
// �йش����ʵ�֣������ Login_ConnectDataBase.cpp
//

class CLogin_ConnectDataBaseApp : public CWinApp
{
public:
	CLogin_ConnectDataBaseApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()


public:
	CString LoginUserNameApp;
	CString LoginPassWordApp;
};