
// Login_with_databaseDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <tchar.h>
#include <stdio.h>



// CLogin_with_databaseDlg �Ի���
class CLogin_with_databaseDlg : public CDialogEx
{
// ����
public:
	CLogin_with_databaseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGIN_WITH_DATABASE_DIALOG };

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
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedSignin();
	CEdit m_UserName;
	CEdit m_PassWord;
	CString _UserName;
	CString _PassWord;
};
