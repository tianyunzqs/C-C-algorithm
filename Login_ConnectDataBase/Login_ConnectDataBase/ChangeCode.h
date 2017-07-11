#pragma once


// CChangeCode 对话框

class CChangeCode : public CDialog
{
	DECLARE_DYNAMIC(CChangeCode)

public:
	CChangeCode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeCode();

// 对话框数据
	enum { IDD = IDD_CHANGECODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFinishchange();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
