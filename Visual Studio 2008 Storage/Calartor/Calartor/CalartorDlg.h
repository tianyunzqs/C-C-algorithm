// CalartorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCalartorDlg �Ի���
class CCalartorDlg : public CDialog
{
// ����
public:
	CCalartorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALARTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	// �������
	double OperatorNumLeft;
	// �Ҳ�����
	double OperatorNumRight;
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPuls();
	int Loc;
	int SymbolLoc;
	double Result;
	// �Ⱥż����´���
	int EqualNum;
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedTime();
	afx_msg void OnBnClickedDiv();
	// ��־��������ķ���
	int SymbolFlag;
};
