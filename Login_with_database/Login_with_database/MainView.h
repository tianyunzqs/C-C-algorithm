#pragma once
#include "afxcmn.h"


// MainView �Ի���

class MainView : public CDialog
{
	DECLARE_DYNAMIC(MainView)

public:
	MainView(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MainView();

// �Ի�������
	enum { IDD = IDD_MAINVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_ctrlTree;
};
