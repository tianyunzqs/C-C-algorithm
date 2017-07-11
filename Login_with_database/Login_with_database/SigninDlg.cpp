// SigninDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_with_database.h"
#include "SigninDlg.h"
#include "afxdialogex.h"
#include "Login_with_databaseDlg.h"

#include <stdio.h>
#include <tchar.h>

//// 使用#import把动态连接库msado15.dll导入Visual C++应用程序，
//// 并生成定义ADO库的两个C++头文件：msado15.tlh和ado15.tli。即：
//#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")


// CSigninDlg 对话框

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


// CSigninDlg 消息处理程序


//void CSigninDlg::OnBnClickedFinishsigin()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CString usrname, password1, password2;
//	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
//	GetDlgItem(IDC_RPASSWORD)->GetWindowText(password1);
//	GetDlgItem(IDC_RPASSWORD2)->GetWindowText(password2);
//	if(strlen(usrname)==0)
//	{
//		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
//		return;
//	}
//	if(strlen(password1)==0)
//	{
//		MessageBox(_T("密码不能为空！"), _T("注册提示"));
//		return;
//	}
//	if(password1 != password2)
//	{
//		MessageBox(_T("两次输入的密码不一致，请重新设置密码！"), _T("注册提示"));
//		GetDlgItem(IDC_RPASSWORD)->SetWindowText("");
//		GetDlgItem(IDC_RPASSWORD2)->SetWindowText("");
//		GetDlgItem(IDC_RPASSWORD)->SetFocus();
//		return;
//	}
//
//	CString sqlCommand0 = "insert into LoginTable values('" + usrname + "', " + "'"+password1+"')";
//	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;
//
//	//这里的参数就是上面配置ODBC数据源时的一些配置,uid是用户名，pwd是密码
//	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
//	::CoInitialize(NULL);//初始化COM库
//	//添加一个指向Connection对象的指针m_pConnection
//	_ConnectionPtr m_pConnection(__uuidof(Connection));
//
//	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //创键Connection对象
//		printf("创键Connection对象时出错\n");
//	try
//	{
//		m_pConnection->Open (strConnect,"","", adModeUnknown); //连接数据库
//	}
//	catch(_com_error e) 
//	{
//		printf("连接数据库时出错\n");
//	}
//	m_pConnection->Execute(sqlCommand, NULL, 1);//执行SQL语句
//	MessageBox(_T("注册成功！"), _T("注册成功"));
//	this->OnCancel();
//	m_pConnection->Close(); 
//	::CoUninitialize(); //释放程序占用的COM 资源 
//}
//
//
//void CSigninDlg::OnBnClickedCheckusername()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CString usrname, password1, password2;
//	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
//	if(strlen(usrname)==0)
//	{
//		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
//		return;
//	}
//	CString sqlCommand0 = "select * from LoginTable where username=";
//	CString sqlCommand1 = sqlCommand0 + "'" + usrname + "'";
//	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;
//
//	//这里的参数就是上面配置ODBC数据源时的一些配置,uid是用户名，pwd是密码
//	_bstr_t strConnect="DSN=csql;Database=S-C;uid=sa;pwd=2502;";
//	::CoInitialize(NULL);//初始化COM库
//	//添加一个指向Connection对象的指针m_pConnection
//	_ConnectionPtr m_pConnection(__uuidof(Connection));
//
//	if( FAILED( m_pConnection.CreateInstance(__uuidof(Connection)) ) ) //创键Connection对象
//		printf("创键Connection对象时出错\n");
//	try
//	{
//		m_pConnection->Open (strConnect,"","", adModeUnknown); //连接数据库
//	}
//	catch(_com_error e) 
//	{
//		printf("连接数据库时出错\n");
//	}
//	_variant_t t;
//	m_pConnection->Execute(sqlCommand, &t, 1);//执行SQL语句
//	if(t.iVal == 0)
//		MessageBox(_T("该用户名可以注册！"), _T("注册提示"));
//	else
//		MessageBox(_T("用户名已注册，请选择其他用户名！"), _T("注册提示"));
//	m_pConnection->Close(); 
//	::CoUninitialize(); //释放程序占用的COM 资源
//}
