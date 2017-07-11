// SigInDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Login_ConnectDataBase.h"
#include "SigInDlg.h"
#include "afxdialogex.h"
#include "SqlOperation.h"


// CSigInDlg �Ի���

IMPLEMENT_DYNAMIC(CSigInDlg, CDialog)

CSigInDlg::CSigInDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSigInDlg::IDD, pParent)
{

}

CSigInDlg::~CSigInDlg()
{
}

void CSigInDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSigInDlg, CDialog)
	ON_BN_CLICKED(IDC_TESTUSERNAME, &CSigInDlg::OnBnClickedTestusername)
	ON_BN_CLICKED(IDC_FINISHSIGNIN, &CSigInDlg::OnBnClickedFinishsignin)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSigInDlg ��Ϣ�������


void CSigInDlg::OnBnClickedTestusername()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString usrname, password1, password2;
	GetDlgItem(IDC_SIGINUSERNAME)->GetWindowText(usrname);
	if(strlen(usrname)==0)
	{
		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
		return;
	}
	CString sqlCommand0 = "select * from LoginTable where username=";
	CString sqlCommand1 = sqlCommand0 + "'" + usrname + "'";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;

	CSqlOperation sql;
	sql.ConnectSql();
	_variant_t t;
	t = sql.ExecuteSql(sqlCommand);
	if(t.iVal == 0)
		MessageBox(_T("���û�������ע�ᣡ"), _T("ע����ʾ"));
	else
		MessageBox(_T("�û�����ע�ᣬ��ѡ�������û�����"), _T("ע����ʾ"));
	
	sql.CloseSql();
}


void CSigInDlg::OnBnClickedFinishsignin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString usrname, password1, password2;
	GetDlgItem(IDC_SIGINUSERNAME)->GetWindowText(usrname);
	GetDlgItem(IDC_SIGINCODE)->GetWindowText(password1);
	GetDlgItem(IDC_SIGINCODE2)->GetWindowText(password2);
	if(strlen(usrname)==0)
	{
		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
		return;
	}
	if(strlen(password1)==0)
	{
		MessageBox(_T("���벻��Ϊ�գ�"), _T("ע����ʾ"));
		return;
	}
	if(password1 != password2)
	{
		MessageBox(_T("������������벻һ�£��������������룡"), _T("ע����ʾ"));
		GetDlgItem(IDC_SIGINCODE)->SetWindowText("");
		GetDlgItem(IDC_SIGINCODE2)->SetWindowText("");
		GetDlgItem(IDC_SIGINCODE)->SetFocus();
		return;
	}

	CString sqlCommand0 = "DECLARE @f varchar(50) \
						  select @f=CONVERT(varchar(50),GETDATE(),25) \
						  insert into LoginTable values('" + usrname + "', " + "'"+password1+"'"+
						  ",@f)";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;

	CSqlOperation sql;
	sql.ConnectSql();
	sql.ExecuteSql(sqlCommand);
	MessageBox(_T("ע��ɹ���"), _T("ע��ɹ�"));
	sql.CloseSql();
}


void CSigInDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()

    CRect rc;
    GetClientRect(&rc);
    CDC dcMem;
    dcMem.CreateCompatibleDC(&dc);
    CBitmap bmpBackground;
    bmpBackground.LoadBitmap(IDB_BITMAP2);

    BITMAP bitmap;
    bmpBackground.GetBitmap(&bitmap);
    CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
    dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}

//WM_CTLCOLOR��Ϣ����Ӧ����.�˺�����ԭ��:
//  afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);
//           ����nCtlColor����ָ���ؼ�������,������:
//           .CTLCOLOR_BTN                ��ť�ؼ�
//           .CTLCOLOR_DLG                �Ի���
//           .CTLCOLOR_EDIT               �༭��
//           .CTLCOLOR_LISTBOX            �б�ؼ�
//           .CTLCOLOR_MSGBOX             ��Ϣ�ؼ�
//           .CTLCOLOR_SCROLLBAR          �������ؼ�
//           .CTLCOLOR_STATIC             ��̬�ؼ�

HBRUSH CSigInDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if(nCtlColor == CTLCOLOR_STATIC || CTLCOLOR_BTN) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//���ñ���͸�� 
		pDC->SetTextColor(RGB(0,0,0));//��������Ϊ��ɫ 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
