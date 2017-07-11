#pragma once


// CSigInDlg 对话框

class CSigInDlg : public CDialog
{
	DECLARE_DYNAMIC(CSigInDlg)

public:
	CSigInDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSigInDlg();

// 对话框数据
	enum { IDD = IDD_SIGNIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTestusername();
	afx_msg void OnBnClickedFinishsignin();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
