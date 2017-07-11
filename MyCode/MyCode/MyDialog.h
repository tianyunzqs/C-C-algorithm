#pragma once


// MyDialog 对话框

class MyDialog : public CDialog
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialog();

// 对话框数据
	enum { IDD = IDD_MYCODE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
