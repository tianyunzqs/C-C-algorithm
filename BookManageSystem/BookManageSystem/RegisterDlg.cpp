// RegisterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"
#include "VerificationCode.h"
#include "MysqlOperation.h"

// CRegisterDlg 对话框

IMPLEMENT_DYNAMIC(CRegisterDlg, CDialogEx)

CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegisterDlg::IDD, pParent)
	, RvcNum(_T(""))
{

}

CRegisterDlg::~CRegisterDlg()
{
}

void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RVCPIC, m_RvcPic);
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SIGINOVER, &CRegisterDlg::OnBnClickedSiginover)
	ON_STN_CLICKED(IDC_RVCPIC, &CRegisterDlg::OnStnClickedRvcpic)
	ON_BN_CLICKED(IDC_RTEST, &CRegisterDlg::OnBnClickedRtest)
END_MESSAGE_MAP()


// CRegisterDlg 消息处理程序


void CRegisterDlg::OnBnClickedSiginover()
{
	// TODO: 在此添加控件通知处理程序代码
	CString usrname, password1, password2, vcnum;
	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
	GetDlgItem(IDC_RPASSWORD)->GetWindowText(password1);
	GetDlgItem(IDC_RPASSWORD2)->GetWindowText(password2);
	GetDlgItem(IDC_RVC)->GetWindowText(vcnum);
	if(usrname.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
		GetDlgItem(IDC_RUSERNAME)->SetFocus();
		return;
	}
	if(password1.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"), _T("注册提示"));
		GetDlgItem(IDC_RPASSWORD)->SetFocus();
		return;
	}
	if(password1 != password2)
	{
		MessageBox(_T("两次输入的密码不一致，请重新设置密码！"), _T("注册提示"));
		GetDlgItem(IDC_RPASSWORD2)->SetFocus();
		return;
	}
	if (vcnum != RvcNum)
	{
		MessageBox(_T("验证码输入错误！"), _T("注册提示"));
		GetDlgItem(IDC_RVC)->SetFocus();
		return;
	}

	CString sqlCommand0 = "insert into logininfo values('" 
		+ usrname + "', " + "'"+password1 + "', 0, now(), 0);";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;

	CMysqlOperation *sql = new CMysqlOperation();
	sql->CMysqlConnect();
	sql->UpdateDatabase(sqlCommand);
	MessageBox(_T("注册成功！"), _T("注册成功"));
	sql->CMysqlClose();
	delete sql;
}


BOOL CRegisterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 生成并显示初始验证码
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	RvcNum = VC->Generate4RandNum();
	VC->ShengChengYanZhenMa(RvcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_RvcPic.SetBitmap(bitmap);	


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CRegisterDlg::OnStnClickedRvcpic()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	RvcNum = VC->Generate4RandNum(); // vcNum是成员变量
	VC->ShengChengYanZhenMa(RvcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_RvcPic.SetBitmap(bitmap);	
}


void CRegisterDlg::OnBnClickedRtest()
{
	// TODO: 在此添加控件通知处理程序代码
	CString usrname, password1, password2;
	GetDlgItem(IDC_RUSERNAME)->GetWindowText(usrname);
	if(usrname.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"), _T("注册提示"));
		return;
	}
	CString sqlCommand0 = "select * from logininfo where username=";
	CString sqlCommand1 = sqlCommand0 + "'" + usrname + "'";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;

	CMysqlOperation *mysql = new CMysqlOperation();
	mysql->CMysqlConnect();
	MYSQL_RES *res = mysql->QueryDatabase(sqlCommand);
	if (0 == mysql_num_rows(res))
	{
		MessageBox(_T("该用户名可以注册！"), _T("注册提示"));
	} else 
	{
		MessageBox(_T("用户名已注册，请选择其他用户名！"), _T("注册提示"));
	}
	mysql->CMysqlClose();
	delete mysql;
}
