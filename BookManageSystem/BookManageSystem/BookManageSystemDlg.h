
// BookManageSystemDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CBookManageSystemDlg 对话框
class CBookManageSystemDlg : public CDialogEx
{
// 构造
public:
	CBookManageSystemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BOOKMANAGESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 角色选择combox控件的关联变量
	CComboBox m_RoleCon;
	afx_msg void OnBnClickedLogin();
	CStatic m_Bitmap;
	afx_msg void OnStnClickedVerificationcode();

	CString vcNum;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	void ReSize();  
	POINT old; 
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedRegister();
};
