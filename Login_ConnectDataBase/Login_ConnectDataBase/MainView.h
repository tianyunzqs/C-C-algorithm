#pragma once
#include "afxcmn.h"


// CMainView 对话框

class CMainView : public CDialog
{
	DECLARE_DYNAMIC(CMainView)

public:
	CMainView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainView();

// 对话框数据
	enum { IDD = IDD_MAINVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_MyTree;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

public:
	void ReSize();
	POINT old;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
//extern CMainView theApp;