#pragma once
#include "afxcmn.h"
#include "ChangeCode.h"


// CSystemViewDlg �Ի���

class CSystemViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSystemViewDlg)

public:
	CSystemViewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSystemViewDlg();

// �Ի�������
	enum { IDD = IDD_SYSTEMVIEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_MyTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnIdcancel();
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
