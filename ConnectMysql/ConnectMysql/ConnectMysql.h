
// ConnectMysql.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CConnectMysqlApp:
// �йش����ʵ�֣������ ConnectMysql.cpp
//

class CConnectMysqlApp : public CWinApp
{
public:
	CConnectMysqlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CConnectMysqlApp theApp;