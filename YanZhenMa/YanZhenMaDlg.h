// YanZhenMaDlg.h : header file
//

#if !defined(AFX_YANZHENMADLG_H__53C79349_1E9B_4272_A4FC_9CD6C203EDA3__INCLUDED_)
#define AFX_YANZHENMADLG_H__53C79349_1E9B_4272_A4FC_9CD6C203EDA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CYanZhenMaDlg dialog

class CYanZhenMaDlg : public CDialog
{
// Construction
public:
	CYanZhenMaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CYanZhenMaDlg)
	enum { IDD = IDD_YANZHENMA_DIALOG };
	CStatic	m_bitmap;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYanZhenMaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CYanZhenMaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShengcheng();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStatic1();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YANZHENMADLG_H__53C79349_1E9B_4272_A4FC_9CD6C203EDA3__INCLUDED_)
