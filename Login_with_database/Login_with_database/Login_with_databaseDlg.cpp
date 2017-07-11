
// Login_with_databaseDlg.cpp : 实现文件
//
#define WIN32_LEAN_AND_MEAN  // Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include "Login_with_database.h"
#include "Login_with_databaseDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "SigninDlg.h"
#include "MainView.h"
#include "SqlOperation.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLogin_with_databaseDlg 对话框




CLogin_with_databaseDlg::CLogin_with_databaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin_with_databaseDlg::IDD, pParent)
	, _UserName(_T(""))
	, _PassWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogin_with_databaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USERNAME, m_UserName);
	DDX_Control(pDX, IDC_PASSWORD, m_PassWord);
}

BEGIN_MESSAGE_MAP(CLogin_with_databaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CLogin_with_databaseDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_SIGNIN, &CLogin_with_databaseDlg::OnBnClickedSignin)
END_MESSAGE_MAP()


// CLogin_with_databaseDlg 消息处理程序

BOOL CLogin_with_databaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_UserName.SetWindowText(_UserName);
	m_PassWord.SetWindowText(_PassWord);

	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLogin_with_databaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLogin_with_databaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLogin_with_databaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLogin_with_databaseDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_USERNAME)->GetWindowText(_UserName);
	GetDlgItem(IDC_PASSWORD)->GetWindowText(_PassWord);

	CString sqlCommand0 = "select * from LoginTable where username=";
	CString sqlCommand1 = sqlCommand0 + "'" + _UserName + "'" + " AND password=" + "'" + _PassWord + "'";

	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand1;
	_variant_t t;
	CSqlOperation mysql;
	mysql.ConnectSql();
	t = mysql.ExecuteSql(sqlCommand);//执行SQL语句
	if(t.iVal == 0)
		MessageBox(_T("用户名或密码错误！"), _T("登录错误"));
	else
	{
		MessageBox(_T("登录成功"), _T("登录错误"));
		//MainView dlg;
		//if(dlg.DoModal() == IDOK)
		//	dlg.ShowWindow(SW_SHOW);
		//HTREEITEM hRoot = dlg.m_ctrlTree.InsertItem(_T("Root"));//插入树根
	}
	mysql.CloseSql();
}


void CLogin_with_databaseDlg::OnBnClickedSignin()
{
	// TODO: 在此添加控件通知处理程序代码
	CSigninDlg dlg;
	if(dlg.DoModal() == IDOK)
		dlg.ShowWindow(SW_SHOW); 
}
