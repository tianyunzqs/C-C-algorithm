#pragma once


// CSigninDlg �Ի���

class CSigninDlg : public CDialog
{
	DECLARE_DYNAMIC(CSigninDlg)

public:
	CSigninDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSigninDlg();

// �Ի�������
	enum { IDD = IDD_SIGNIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFinishsigin();
	afx_msg void OnBnClickedCheckusername();
};
