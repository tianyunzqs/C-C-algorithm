#pragma once


// CSigInDlg �Ի���

class CSigInDlg : public CDialog
{
	DECLARE_DYNAMIC(CSigInDlg)

public:
	CSigInDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSigInDlg();

// �Ի�������
	enum { IDD = IDD_SIGNIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTestusername();
	afx_msg void OnBnClickedFinishsignin();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
