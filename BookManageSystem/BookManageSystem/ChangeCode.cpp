// ChangeCode.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "ChangeCode.h"
#include "afxdialogex.h"
#include "MysqlOperation.h"

// CChangeCode 对话框

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


// CChangeCode 消息处理程序


void CChangeCode::OnBnClickedChangeover()
{
	// TODO: 在此添加控件通知处理程序代码
	CString OldCode;
	GetDlgItem(IDC_OLDCODE)->GetWindowText(OldCode);
	CBookManageSystemApp *p = (CBookManageSystemApp *)AfxGetApp();
	if(OldCode.Compare(p->LoginPassWordApp))
	{
		MessageBox(_T("原密码输入错误，请重新输入！"));	
		GetDlgItem(IDC_OLDCODE)->SetFocus();
		return;
	}

	CString NewCode1, NewCode2;
	GetDlgItem(IDC_NEWCODE)->GetWindowText(NewCode1);
	GetDlgItem(IDC_NEWCODE2)->GetWindowText(NewCode2);
	if(NewCode1.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"), _T("修改密码提示"));
		GetDlgItem(IDC_NEWCODE)->SetFocus();
		return;
	}
	if(NewCode1.Compare(NewCode2))
	{
		MessageBox(_T("两次输入的密码不一致，请重新设置密码！"), _T("修改密码提示"));
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
	MessageBox(_T("修改密码成功！"), _T("修改密码提示"));
	sql->CMysqlClose();
	delete sql;

	// 修改密码后，重启该应用程序
	char buf[256];
	::GetModuleFileName(NULL,buf,sizeof(buf));
	CString strPath = buf;
	AfxGetMainWnd()->PostMessage(WM_CLOSE, 0, 0);
	PostQuitMessage(0);
	WinExec(strPath, SW_SHOW);// 启动strPath路径下的执行文件
}
