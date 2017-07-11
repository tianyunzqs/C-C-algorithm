
// Login_ConnectDataBaseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Login_ConnectDataBase.h"
#include "Login_ConnectDataBaseDlg.h"
#include "afxdialogex.h"
#include "SqlOperation.h"
#include "SigInDlg.h"
#include "MainView.h"
#include "ChangeCode.h"

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


// CLogin_ConnectDataBaseDlg 对话框




CLogin_ConnectDataBaseDlg::CLogin_ConnectDataBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin_ConnectDataBaseDlg::IDD, pParent)
	, Login_UserName(_T(""))
	, Login_PassWord(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogin_ConnectDataBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LOGINUSERNAME, Login_UserName);
	DDX_Text(pDX, IDC_LOGINCODE, Login_PassWord);
}

BEGIN_MESSAGE_MAP(CLogin_ConnectDataBaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CLogin_ConnectDataBaseDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_SIGNIN, &CLogin_ConnectDataBaseDlg::OnBnClickedSignin)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLogin_ConnectDataBaseDlg 消息处理程序

BOOL CLogin_ConnectDataBaseDlg::OnInitDialog()
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
	_variant_t vsUserName,vsPassWord,vsUNorPW; //对应库中的
	CSqlOperation myInitSql;
	myInitSql.ConnectSql();
	CString sqlCommand = "select * from RememberInfoTable \
		where LoginDate = (select max(LoginDate) from RememberInfoTable)";
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
	vsUserName = myInitSql.GetSqlData(sqlC, "UserName");
	vsPassWord = myInitSql.GetSqlData(sqlC, "PassWord");
	vsUNorPW = myInitSql.GetSqlData(sqlC, "UNorPW");
	CString UserName = (char*)(_bstr_t)vsUserName;
	CString PassWord = (char*)(_bstr_t)vsPassWord;
	int UNorPW = vsUNorPW.lVal;
	if(UNorPW==1) // 记住用户名
		GetDlgItem(IDC_LOGINUSERNAME)->SetWindowText(UserName);
	else if(UNorPW==2) // 记住用户名和密码
	{
		GetDlgItem(IDC_LOGINUSERNAME)->SetWindowText(UserName);
		GetDlgItem(IDC_LOGINCODE)->SetWindowText(PassWord);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLogin_ConnectDataBaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLogin_ConnectDataBaseDlg::OnPaint()
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
		//CDialogEx::OnPaint();

		CPaintDC dc(this);
        CRect rc;
        GetClientRect(&rc);
        CDC dcMem;
        dcMem.CreateCompatibleDC(&dc);
        CBitmap bmpBackground;
        bmpBackground.LoadBitmap(IDB_BITMAP1);

        BITMAP bitmap;
        bmpBackground.GetBitmap(&bitmap);
        CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
        dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLogin_ConnectDataBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLogin_ConnectDataBaseDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_LOGINUSERNAME)->GetWindowText(Login_UserName);
	GetDlgItem(IDC_LOGINCODE)->GetWindowText(Login_PassWord);
	// 赋值给全局变量
	CLogin_ConnectDataBaseApp *p = (CLogin_ConnectDataBaseApp *)AfxGetApp();
	p->LoginUserNameApp = Login_UserName;
	p->LoginPassWordApp = Login_PassWord;

	if(strlen(Login_UserName)==0)
	{
		MessageBox(_T("用户名不能为空！"), _T("登录错误"));
		return;
	}
	if(strlen(Login_PassWord)==0)
	{
		MessageBox(_T("密码不能为空！"), _T("登录错误"));
		return;
	}
	CString sqlCommand0 = "select * from LoginTable where username='" \
		+ Login_UserName  + "' AND password='" + Login_PassWord + "'";
	char *sqlCommand = (LPSTR)(LPCTSTR)sqlCommand0;

	CSqlOperation mysql;
	mysql.ConnectSql();

	_variant_t t;
	t = mysql.ExecuteSql(sqlCommand);//执行SQL语句
	if(t.iVal == 0)
		MessageBox(_T("用户名或密码错误！"), _T("登录错误"));
	else
	{
		//MessageBox(_T("登录成功！"), _T("登录成功"));
		
		CButton* pBtn1 = (CButton*)GetDlgItem(IDC_REMEMBERUSERNAME);
		CButton* pBtn2 = (CButton*)GetDlgItem(IDC_REMEMBERBOTH);
		if(pBtn1->GetCheck()==0 && pBtn2->GetCheck()==0) // 都没选，更新空用户名时间
		{
			CString sqlCommand = "DECLARE @f varchar(50) \
					select @f=CONVERT(varchar(50),GETDATE(),25) \
					update RememberInfoTable set LoginDate=@f where \
					UserName= '' AND PassWord=''";
			char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
			mysql.ExecuteSql(sqlC);	
		}
		else if(pBtn1->GetCheck()==1 && pBtn2->GetCheck()==0) // 记住用户名
		{
			CString sqlCommand1 = "select * from RememberInfoTable where UserName='" + \
				Login_UserName  + "' AND PassWord='" + Login_PassWord + "'";
			char *sqlC1 = (LPSTR)(LPCTSTR)sqlCommand1;
			t = mysql.ExecuteSql(sqlC1);// 查询，在RememberInfoTable是否存在该用户
			if(t.iVal == 0) // 不存在，写入RememberInfoTable
			{
				CString sqlCommand2 = "DECLARE @f varchar(50) \
					select @f=CONVERT(varchar(50),GETDATE(),25) \
					insert into RememberInfoTable values \
					('" + Login_UserName + "'," + "'"+Login_PassWord+"'"+",@f,1)";
				char *sqlC2 = (LPSTR)(LPCTSTR)sqlCommand2;
				mysql.ExecuteSql(sqlC2);
			}
			else   // 存在，更新
			{
				CString sqlCommand3 = "DECLARE @f varchar(50) \
					select @f=CONVERT(varchar(50),GETDATE(),25) \
					update RememberInfoTable set LoginDate=@f, UNorPW=1 where UserName= \
					'" + Login_UserName + "'";
				char *sqlC3 = (LPSTR)(LPCTSTR)sqlCommand3;
				mysql.ExecuteSql(sqlC3);
			}
		}
		else if(pBtn2->GetCheck()==1) // 记住用户名和密码
		{
			CString sqlCommand1 = "select * from RememberInfoTable where UserName='" + \
				Login_UserName  + "' AND PassWord='" + Login_PassWord + "'";
			char *sqlC1 = (LPSTR)(LPCTSTR)sqlCommand1;
			t = mysql.ExecuteSql(sqlC1);// 查询，在RememberInfoTable是否存在该用户
			if(t.iVal == 0) // 不存在，写入RememberInfoTable
			{
				CString sqlCommand2 = "DECLARE @f varchar(50) \
					select @f=CONVERT(varchar(50),GETDATE(),25) \
					insert into RememberInfoTable values \
					('" + Login_UserName + "'," + "'"+Login_PassWord+"'"+",@f,2)";
				char *sqlC2 = (LPSTR)(LPCTSTR)sqlCommand2;
				mysql.ExecuteSql(sqlC2);
			}
			else   // 存在，更新
			{
				CString sqlCommand3 = "DECLARE @f varchar(50) \
					select @f=CONVERT(varchar(50),GETDATE(),25) \
					update RememberInfoTable set LoginDate=@f, UNorPW=2 where UserName= \
					'" + Login_UserName + "'";
				char *sqlC3 = (LPSTR)(LPCTSTR)sqlCommand3;
				mysql.ExecuteSql(sqlC3);
			}
		}
		// 登录成功后
		this->ShowWindow(SW_HIDE);
		CMainView *pTD = new CMainView();
		pTD->Create(IDD_MAINVIEW, GetDesktopWindow()); //创建一个非模态对话框
		pTD->ShowWindow(SW_SHOW); //显示非模态对话框

		HTREEITEM hItem, hSubItem;
		hItem = pTD->m_MyTree.InsertItem(_T("个人基本信息"),TVI_ROOT); //在根结点上添加Parent1
		hSubItem = pTD->m_MyTree.InsertItem(_T("基本信息查询"),hItem); //在Parent1上添加一个子结点
		hSubItem = pTD->m_MyTree.InsertItem(_T("修改个人信息"),hItem,hSubItem); //在Parent1上添加一个子结点，排在Child1_1后面
		hSubItem = pTD->m_MyTree.InsertItem(_T("修改密码"),hItem,hSubItem);
		hItem = pTD->m_MyTree.InsertItem(_T("图书信息"),TVI_ROOT,hItem);
		hSubItem = pTD->m_MyTree.InsertItem(_T("图书查询"),hItem);
		hSubItem = pTD->m_MyTree.InsertItem(_T("添加图书"),hItem, hSubItem);
		hItem = pTD->m_MyTree.InsertItem(_T("活动"),TVI_ROOT,hItem);
	}
	mysql.CloseSql();
}



void CLogin_ConnectDataBaseDlg::OnBnClickedSignin()
{
	// TODO: 在此添加控件通知处理程序代码
	CSigInDlg dlg;
	if(dlg.DoModal() == IDOK)
		dlg.ShowWindow(SW_SHOW); 
}

HBRUSH CLogin_ConnectDataBaseDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_STATIC ) 
	{ 
		pDC->SetBkMode(TRANSPARENT);//设置背景透明 
		pDC->SetTextColor(RGB(0,0,0));//设置字体为黄色 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
