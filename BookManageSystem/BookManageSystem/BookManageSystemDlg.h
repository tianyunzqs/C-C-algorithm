
// BookManageSystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CBookManageSystemDlg �Ի���
class CBookManageSystemDlg : public CDialogEx
{
// ����
public:
	CBookManageSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BOOKMANAGESYSTEM_DIALOG };

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
	// ��ɫѡ��combox�ؼ��Ĺ�������
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
