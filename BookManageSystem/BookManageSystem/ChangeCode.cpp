// ChangeCode.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "ChangeCode.h"
#include "afxdialogex.h"
#include "MysqlOperation.h"

// CChangeCode �Ի���

IMPLEMENT_DYNAMIC(CChangeCode, CDialogEx)

CChangeCode::CChangeCode(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeCode::IDD, pParent)
{

}

CChangeCode::~CChangeCode()
{
}

void CChangeCode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChangeCode, CDialogEx)
	ON_BN_CLICKED(IDC_CHANGEOVER, &CChangeCode::OnBnClickedChangeover)
END_MESSAGE_MAP()


// CChangeCode ��Ϣ�������


void CChangeCode::OnBnClickedChangeover()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString OldCode;
	GetDlgItem(IDC_OLDCODE)->GetWindowText(OldCode);
	CBookManageSystemApp *p = (CBookManageSystemApp *)AfxGetApp();
	if(OldCode.Compare(p->LoginPassWordApp))
	{
		MessageBox(_T("ԭ��������������������룡"));	
		GetDlgItem(IDC_OLDCODE)->SetFocus();
		return;
	}

	CString NewCode1, NewCode2;
	GetDlgItem(IDC_NEWCODE)->GetWindowText(NewCode1);
	GetDlgItem(IDC_NEWCODE2)->GetWindowText(NewCode2);
	if(NewCode1.IsEmpty())
	{
		MessageBox(_T("���벻��Ϊ�գ�"), _T("�޸�������ʾ"));
		GetDlgItem(IDC_NEWCODE)->SetFocus();
		return;
	}
	if(NewCode1.Compare(NewCode2))
	{
		MessageBox(_T("������������벻һ�£��������������룡"), _T("�޸�������ʾ"));
		GetDlgItem(IDC_NEWCODE2)->SetFocus();
		return;
	}
	CMysqlOperation *sql = new CMysqlOperation();
	sql->CMysqlConnect();
	CString sqlCommand;
	if (p->NextTypeApp == 2)
	{
		sqlCommand = "update logininfo set password=" + \
			NewCode1 + ", nexttype=1 where username= '" + p->LoginUserNameApp +"'";
	}
	else
	{
		sqlCommand = "update logininfo set password=" + \
			NewCode1 + "where username= '" + p->LoginUserNameApp +"'";
	}
	
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
	sql->UpdateDatabase(sqlC);
	MessageBox(_T("�޸�����ɹ���"), _T("�޸�������ʾ"));
	sql->CMysqlClose();
	delete sql;

	// �޸������������Ӧ�ó���
	char buf[256];
	::GetModuleFileName(NULL,buf,sizeof(buf));
	CString strPath = buf;
	AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0);
	PostQuitMessage(0);
	WinExec(strPath, SW_SHOW);// ����strPath·���µ�ִ���ļ�
}
