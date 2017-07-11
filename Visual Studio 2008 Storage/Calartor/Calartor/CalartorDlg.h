// CalartorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCalartorDlg 对话框
class CCalartorDlg : public CDialog
{
// 构造
public:
	CCalartorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALARTOR_DIALOG };

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
	afx_msg void AthurorInformation();
	afx_msg void OnBnClickedButton1();
	CEdit m_show;
	CString ShowString;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedSure();
	// 左操作数
	double OperatorNumLeft;
	// 右操作数
	double OperatorNumRight;
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPuls();
	int Loc;
	int SymbolLoc;
	double Result;
	// 等号键按下次数
	int EqualNum;
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedTime();
	afx_msg void OnBnClickedDiv();
	// 标志四则运算的符号
	int SymbolFlag;
};
