// YanZhenMa.h : main header file for the YANZHENMA application
//

#if !defined(AFX_YANZHENMA_H__0BEA2D7D_59E8_4283_BE85_2CAB9073ED93__INCLUDED_)
#define AFX_YANZHENMA_H__0BEA2D7D_59E8_4283_BE85_2CAB9073ED93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CYanZhenMaApp:
// See YanZhenMa.cpp for the implementation of this class
//

class CYanZhenMaApp : public CWinApp
{
public:
	CYanZhenMaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYanZhenMaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CYanZhenMaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YANZHENMA_H__0BEA2D7D_59E8_4283_BE85_2CAB9073ED93__INCLUDED_)
