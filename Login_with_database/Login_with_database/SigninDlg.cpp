// SigninDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Login_with_database.h"
#include "SigninDlg.h"
#include "afxdialogex.h"
#include "Login_with_databaseDlg.h"

#include <stdio.h>
#include <tchar.h>

//// ʹ��#import�Ѷ�̬���ӿ�msado15.dll����Visual C++Ӧ�ó���
//// �����ɶ���ADO�������C++ͷ�ļ���msado15.tlh��ado15.tli������
//#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")


// CSigninDlg �Ի���

IMPLEMENT_DYNAMIC(CSigninDlg, CDialog)

CSigninDlg::CSigninDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSigninDlg::IDD, pParent)
{

}

CSigninDlg::~CSigninDlg()
{
}

void CSigninDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSigninDlg, CDialog)
	ON_BN_CLICKED(IDC_FINISHSIGIN, &CSigninDlg::OnBnClickedFinishsigin)
	ON_BN_CLICKED(IDC_CHECKUSERNAME, &CSigninDlg::OnBnClickedCheckusername)
END_MESSAGE_MAP()


// CSigninDlg ��Ϣ�������


//void CSigninDlg::OnBnClickedFinishsigin()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CString usrname, password1, password2;
//	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
//	GetDlgItem(IDC_RPASSWORD)->GetWindowText(password1);
//	GetDlgItem(IDC_RPASSWORD2)->GetWindowText(password2);
//	if(strlen(usrname)==0)
//	{
//		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
//		return;
//	}
//	if(strlen(password1)==0)
//	{
//		MessageBox(_T("���벻��Ϊ�գ�"), _T("ע����ʾ"));
//		return;
//	}
//	if(password1 != password2)
//	{
//		MessageBox(_T("������������벻һ�£��������������룡"), _T("ע����ʾ"));
//		GetDlgItem(IDC_RPASSWORD)->SetWindowText("");
//		GetDlgItem(IDC_RPASSWORD2)->SetWindowText("");
//		GetDlgItem(IDC_RPASSWORD)->SetFocus();
//		return;
//	}
//
//	CString sqlCommand0 = "insert into LoginTable values('" + usrname + "', " + "'"+password1+"')";
//	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;
//
//	//����Ĳ���������������ODBC����Դʱ��һЩ����,uid���û�����pwd������
//	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
//	::CoInitialize(NULL);//��ʼ��COM��
//	//���һ��ָ��Connection�����ָ��m_pConnection
//	_ConnectionPtr m_pConnection(__uuidof(Connection));
//
//	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //����Connection����
//		printf("����Connection����ʱ����\n");
//	try
//	{
//		m_pConnection->Open (strConnect,"","", adModeUnknown); //�������ݿ�
//	}
//	catch(_com_error e) 
//	{
//		printf("�������ݿ�ʱ����\n");
//	}
//	m_pConnection->Execute(sqlCommand, NULL, 1);//ִ��SQL���
//	MessageBox(_T("ע��ɹ���"), _T("ע��ɹ�"));
//	this->OnCancel();
//	m_pConnection->Close(); 
//	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ 
//}
//
//
//void CSigninDlg::OnBnClickedCheckusername()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CString usrname, password1, password2;
//	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
//	if(strlen(usrname)==0)
//	{
//		MessageBox(_T("�û�������Ϊ�գ�"), _T("ע����ʾ"));
//		return;
//	}
//	CString sqlCommand0 = "select * from LoginTable where username=";
//	CString sqlCommand1 = sqlCommand0 + "'" + usrname + "'";
//	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;
//
//	//����Ĳ���������������ODBC����Դʱ��һЩ����,uid���û�����pwd������
//	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
//	::CoInitialize(NULL);//��ʼ��COM��
//	//���һ��ָ��Connection�����ָ��m_pConnection
//	_ConnectionPtr m_pConnection(__uuidof(Connection));
//
//	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //����Connection����
//		printf("����Connection����ʱ����\n");
//	try
//	{
//		m_pConnection->Open (strConnect,"","", adModeUnknown); //�������ݿ�
//	}
//	catch(_com_error e) 
//	{
//		printf("�������ݿ�ʱ����\n");
//	}
//	_variant_t t;
//	m_pConnection->Execute(sqlCommand, &t, 1);//ִ��SQL���
//	if(t.iVal == 0)
//		MessageBox(_T("���û�������ע�ᣡ"), _T("ע����ʾ"));
//	else
//		MessageBox(_T("�û�����ע�ᣬ��ѡ�������û�����"), _T("ע����ʾ"));
//	m_pConnection->Close(); 
//	::CoUninitialize(); //�ͷų���ռ�õ�COM ��Դ
//}
