// ChangeCode.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_ConnectDataBase.h"
#include "ChangeCode.h"
#include "afxdialogex.h"
#include "Login_ConnectDataBaseDlg.h"
#include "SqlOperation.h"


// CChangeCode 对话框

IMPLEMENT_DYNAMIC(CChangeCode, CDialog)

CChangeCode::CChangeCode(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeCode::IDD, pParent)
{

}

CChangeCode::~CChangeCode()
{
}

void CChangeCode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChangeCode, CDialog)
	ON_BN_CLICKED(IDC_FINISHCHANGE, &CChangeCode::OnBnClickedFinishchange)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CChangeCode 消息处理程序

void CChangeCode::OnBnClickedFinishchange()
{
	// TODO: 在此添加控件通知处理程序代码
	CLogin_ConnectDataBaseApp *p = (CLogin_ConnectDataBaseApp *)AfxGetApp();
	MessageBox(p->LoginUserNameApp + "  " +p->LoginPassWordApp);
	CString OldCode;
	GetDlgItem(IDC_OLDCODE)->GetWindowText(OldCode);
	if(OldCode.Compare(p->LoginPassWordApp))
	{
		MessageBox(_T("原密码输入错误，请重新输入！"));	
		GetDlgItem(IDC_OLDCODE)->SetFocus();
		return;
	}

	CString NewCode1, NewCode2;
	GetDlgItem(IDC_NEWCODE)->GetWindowText(NewCode1);
	GetDlgItem(IDC_NEWCODE2)->GetWindowText(NewCode2);
	if(strlen(NewCode1)==0)
	{
		MessageBox(_T("密码不能为空！"), _T("修改密码提示"));
		return;
	}
	if(NewCode1.Compare(NewCode2))
	{
		MessageBox(_T("两次输入的密码不一致，请重新设置密码！"), _T("修改密码提示"));
		GetDlgItem(IDC_NEWCODE)->SetWindowText("");
		GetDlgItem(IDC_NEWCODE2)->SetWindowText("");
		GetDlgItem(IDC_NEWCODE)->SetFocus();
		return;
	}
	CSqlOperation sql;
	sql.ConnectSql();
	CString sqlCommand0 = "update LoginTable set PassWord=" + \
		NewCode1 + " where UserName= '" + p->LoginUserNameApp +"'";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;
	sql.ExecuteSql(sqlCommand);


	CString sqlCommand1 = "select * from RememberInfoTable where UserName='" + \
		p->LoginUserNameApp  + "' AND PassWord='" + p->LoginPassWordApp + "'";
	char *sqlC1 = (LPSTR)(LPCTSTR)sqlCommand1;
	_variant_t t = sql.ExecuteSql(sqlC1);// 查询，在RememberInfoTable是否存在该用户
	if(t.iVal != 0) // 存在，更新RememberInfoTable中的密码
	{
		CString sqlCommand2 = "update RememberInfoTable set PassWord=" + \
			NewCode1 + " where UserName= '" + p->LoginUserNameApp +"'";
		char *sqlC2 = (LPSTR)(LPCTSTR)sqlCommand2;
		sql.ExecuteSql(sqlC2);
	}
	MessageBox(_T("修改密码成功！"), _T("修改密码提示"));
	sql.CloseSql();
}



HBRUSH CChangeCode::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_STATIC || CTLCOLOR_DLG) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//设置背景透明 
		pDC->SetTextColor(RGB(0,0,0));//设置字体为黄色 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
