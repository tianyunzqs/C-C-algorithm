#pragma once
#include "afxcmn.h"
#include "ChangeCode.h"


// CSystemViewDlg 对话框

class CSystemViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemViewDlg)

public:
	CSystemViewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSystemViewDlg();

// 对话框数据
	enum { IDD = IDD_SYSTEMVIEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_MyTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnIdcancel();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
