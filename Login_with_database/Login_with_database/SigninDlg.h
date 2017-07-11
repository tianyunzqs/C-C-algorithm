#pragma once


// CSigninDlg 对话框

class CSigninDlg : public CDialog
{
	DECLARE_DYNAMIC(CSigninDlg)

public:
	CSigninDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSigninDlg();

// 对话框数据
	enum { IDD = IDD_SIGNIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFinishsigin();
	afx_msg void OnBnClickedCheckusername();
};
