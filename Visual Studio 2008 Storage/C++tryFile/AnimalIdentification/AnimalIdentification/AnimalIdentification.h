// AnimalIdentification.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAnimalIdentificationApp:
// �йش����ʵ�֣������ AnimalIdentification.cpp
//

class CAnimalIdentificationApp : public CWinApp
{
public:
	CAnimalIdentificationApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAnimalIdentificationApp theApp;