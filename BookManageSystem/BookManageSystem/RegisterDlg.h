#pragma once
#include "afxwin.h"


// CRegisterDlg 对话框

class CRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDlg)

public:
	CRegisterDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegisterDlg();

// 对话框数据
	enum { IDD = IDD_REGISTERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSiginover();
	// 保存注册界面的验证码
	CString RvcNum;
	// 注册界面验证码图片关联的变量
	CStatic m_RvcPic;
	virtual BOOL OnInitDialog();
	afx_msg void OnStnClickedRvcpic();
	afx_msg void OnBnClickedRtest();
};
