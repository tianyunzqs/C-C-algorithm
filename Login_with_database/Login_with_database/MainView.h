#pragma once
#include "afxcmn.h"


// MainView 对话框

class MainView : public CDialog
{
	DECLARE_DYNAMIC(MainView)

public:
	MainView(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainView();

// 对话框数据
	enum { IDD = IDD_MAINVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_ctrlTree;
};
