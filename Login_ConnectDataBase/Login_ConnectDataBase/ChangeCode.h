#pragma once


// CChangeCode �Ի���

class CChangeCode : public CDialog
{
	DECLARE_DYNAMIC(CChangeCode)

public:
	CChangeCode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeCode();

// �Ի�������
	enum { IDD = IDD_CHANGECODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFinishchange();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
