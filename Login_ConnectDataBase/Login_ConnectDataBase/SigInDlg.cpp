// SigInDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_ConnectDataBase.h"
#include "SigInDlg.h"
#include "afxdialogex.h"
#include "SqlOperation.h"


// CSigInDlg 对话框

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


// CSigInDlg 消息处理程序


void CSigInDlg::OnBnClickedTestusername()
{
	// TODO: 在此添加控件通知处理程序代码
	CString usrname, password1, password2;
	GetDlgItem(IDC_SIGINUSERNAME)->GetWindowText(usrname);
	if(strlen(usrname)==0)
	{
		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
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
		MessageBox(_T("该用户名可以注册！"), _T("注册提示"));
	else
		MessageBox(_T("用户名已注册，请选择其他用户名！"), _T("注册提示"));
	
	sql.CloseSql();
}


void CSigInDlg::OnBnClickedFinishsignin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString usrname, password1, password2;
	GetDlgItem(IDC_SIGINUSERNAME)->GetWindowText(usrname);
	GetDlgItem(IDC_SIGINCODE)->GetWindowText(password1);
	GetDlgItem(IDC_SIGINCODE2)->GetWindowText(password2);
	if(strlen(usrname)==0)
	{
		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
		return;
	}
	if(strlen(password1)==0)
	{
		MessageBox(_T("密码不能为空！"), _T("注册提示"));
		return;
	}
	if(password1 != password2)
	{
		MessageBox(_T("两次输入的密码不一致，请重新设置密码！"), _T("注册提示"));
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
	MessageBox(_T("注册成功！"), _T("注册成功"));
	sql.CloseSql();
}


void CSigInDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

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

//WM_CTLCOLOR消息的响应函数.此函数的原型:
//  afx_msg HBRUSH OnCtlColor(CDC *pDC,CWnd *pWnd,UINT nCtlColor);
//           参数nCtlColor用于指定控件的类型,可以是:
//           .CTLCOLOR_BTN                按钮控件
//           .CTLCOLOR_DLG                对话框
//           .CTLCOLOR_EDIT               编辑框
//           .CTLCOLOR_LISTBOX            列表控件
//           .CTLCOLOR_MSGBOX             消息控件
//           .CTLCOLOR_SCROLLBAR          滚动条控件
//           .CTLCOLOR_STATIC             静态控件

HBRUSH CSigInDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_STATIC || CTLCOLOR_BTN) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//设置背景透明 
		pDC->SetTextColor(RGB(0,0,0));//设置字体为黄色 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
