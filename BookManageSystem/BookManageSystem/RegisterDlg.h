#pragma once
#include "afxwin.h"


// CRegisterDlg �Ի���

class CRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDlg)

public:
	CRegisterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegisterDlg();

// �Ի�������
	enum { IDD = IDD_REGISTERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSiginover();
	// ����ע��������֤��
	CString RvcNum;
	// ע�������֤��ͼƬ�����ı���
	CStatic m_RvcPic;
	virtual BOOL OnInitDialog();
	afx_msg void OnStnClickedRvcpic();
	afx_msg void OnBnClickedRtest();
};
