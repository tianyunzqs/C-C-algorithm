// AnimalIdentification2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAnimalIdentification2App:
// �йش����ʵ�֣������ AnimalIdentification2.cpp
//

class CAnimalIdentification2App : public CWinApp
{
public:
	CAnimalIdentification2App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAnimalIdentification2App theApp;