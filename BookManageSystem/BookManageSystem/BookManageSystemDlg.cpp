
// BookManageSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BookManageSystem.h"
#include "BookManageSystemDlg.h"
#include "afxdialogex.h"
#include "VerificationCode.h"
#include "MysqlOperation.h"
#include "RegisterDlg.h"
#include "SystemViewDlg.h"

#include <io.h>  
#include <fcntl.h>   


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


// CBookManageSystemDlg 对话框




CBookManageSystemDlg::CBookManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBookManageSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ROLE, m_RoleCon);
	DDX_Control(pDX, IDC_VERIFICATIONCODE, m_Bitmap);
}

BEGIN_MESSAGE_MAP(CBookManageSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CBookManageSystemDlg::OnBnClickedLogin)
	ON_STN_CLICKED(IDC_VERIFICATIONCODE, &CBookManageSystemDlg::OnStnClickedVerificationcode)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_REGISTER, &CBookManageSystemDlg::OnBnClickedRegister)
END_MESSAGE_MAP()


void OpenConsole()  
{  
	AllocConsole();  
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	int hCrt = _open_osfhandle((long)handle,_O_TEXT);  
	FILE * hf = _fdopen( hCrt, "w" );  
	*stdout = *hf;  
} 


// CBookManageSystemDlg 消息处理程序

BOOL CBookManageSystemDlg::OnInitDialog()
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
	Sleep(10);
	this->CenterWindow(GetDesktopWindow()); // 居中显示
	ShowWindow(SW_SHOW);

	m_RoleCon.AddString(_T("学生"));
	m_RoleCon.AddString(_T("老师"));
	m_RoleCon.AddString(_T("管理员"));
	m_RoleCon.SetCurSel(0);


	// 生成并显示初始验证码
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	vcNum = VC->Generate4RandNum();
	VC->ShengChengYanZhenMa(vcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_Bitmap.SetBitmap(bitmap);	

	//OpenConsole();  


	CRect rect;      
	GetClientRect(&rect);     //取客户区大小    
	old.x = rect.right - rect.left;  
	old.y = rect.bottom - rect.top; 


	// 控件字体
	CFont * m_pFont;
	m_pFont = new CFont;
	m_pFont->CreateFont(32,            // nHeight
		0,           // nWidth
		0,           // nEscapement
		0,           // nOrientation
		FW_BOLD,     // nWeight
		FALSE,        // bItalic
		FALSE,       // bUnderline
		0,           // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("楷体"));              // lpszFac
	GetDlgItem(IDC_TITLE)->SetFont(m_pFont,false);

	// 记住用户名与密码功能
	CMysqlOperation *myInitSql = new CMysqlOperation();
	myInitSql->CMysqlConnect();
	CString sqlCommand = "select * from \
						 (select * from logininfo order by logintime desc) NOname limit 1";
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
	MYSQL_RES *res = myInitSql->QueryDatabase(sqlC);
	MYSQL_ROW col = mysql_fetch_row(res);
	CString UserName = col[0];
	CString PassWord = col[1];
	int NextTpye = atoi(col[2]);
	if(NextTpye==1) // 记住用户名
		GetDlgItem(IDC_USERNAME)->SetWindowText(UserName);
	else // 记住用户名和密码，或者都没选
	{
		GetDlgItem(IDC_USERNAME)->SetWindowText(UserName);
		GetDlgItem(IDC_PASSWORD)->SetWindowText(PassWord);
	}
	delete myInitSql;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBookManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBookManageSystemDlg::OnPaint()
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
		// CDialogEx::OnPaint();
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
HCURSOR CBookManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBookManageSystemDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString UserNameInput, PassWordInput, UserInputVcNum;
	GetDlgItem(IDC_USERNAME)->GetWindowText(UserNameInput);
	GetDlgItem(IDC_PASSWORD)->GetWindowText(PassWordInput);
	GetDlgItem(IDC_VC)->GetWindowText(UserInputVcNum);

	if (UserNameInput.IsEmpty())
	{
		MessageBox(_T("用户名不能为空！"), _T("登录提示"));
		return;
	}
	if(PassWordInput.IsEmpty())
	{
		MessageBox(_T("密码不能为空！"), _T("登录提示"));
		return;
	}

	int nIndex = m_RoleCon.GetCurSel();
	char LoginRole[2];
	itoa(nIndex, LoginRole, 10);

	CString sqlCommand = "select * from logininfo where username='" \
		+ UserNameInput  + "' AND password='" + PassWordInput + "' AND loginrole=" \
		+ LoginRole;
	char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;

	CMysqlOperation *mysql = new CMysqlOperation();
	mysql->CMysqlConnect();
	MYSQL_RES *res = mysql->QueryDatabase(sqlC);
	if (0 == mysql_num_rows(res))
	{
		MessageBox(_T("用户名或密码错误！"), _T("登录提示"));
	} else
	{
		if (UserInputVcNum != vcNum)
		{
			MessageBox(_T("验证码输入错误！"), _T("登录提示"));
		} else
		{   // 登陆成功
			// 赋值给全局变量
			CBookManageSystemApp *p = (CBookManageSystemApp *)AfxGetApp();
			p->LoginUserNameApp = UserNameInput;
			p->LoginPassWordApp = PassWordInput;

			CButton* pRemName = (CButton*)GetDlgItem(IDC_REMNAME);
			CButton* pRemBoth = (CButton*)GetDlgItem(IDC_REMBOTH);
			if(pRemName->GetCheck()==0 && pRemBoth->GetCheck()==0) 
			{	// 都没选，更新空用户名时间，设置时间比登陆时间滞后1s
				CString sqlCommand1 = "update logininfo set logintime= \
									 (select date_add(now(), interval 1 second)) where \
									 username= '' AND password=''";
				CString sqlCommand2 = "update logininfo set logintime=now(), nexttype=0 \
									 where UserName='" + UserNameInput + "'";
				char *sqlC1 = (LPSTR)(LPCTSTR)sqlCommand1;
				char *sqlC2 = (LPSTR)(LPCTSTR)sqlCommand2;
				mysql->UpdateDatabase(sqlC1);
				mysql->UpdateDatabase(sqlC2);
				p->NextTypeApp = 0;
			}
			else if(pRemName->GetCheck()==1 && pRemBoth->GetCheck()==0)
			{	// 记住用户名，更新该用户名的时间和下次登陆类型
				CString sqlCommand = "update logininfo set logintime=now(), nexttype=1 \
									  where UserName='" + UserNameInput + "'";
				char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
				mysql->UpdateDatabase(sqlC);
				p->NextTypeApp = 1;
			}
			else if(pRemBoth->GetCheck()==1) 
			{	// 记住用户名和密码，更新该用户名的时间和下次登陆类型
				CString sqlCommand = "update logininfo set logintime=now(), nexttype=2 \
									 where UserName='" + UserNameInput + "'";
				char *sqlC = (LPSTR)(LPCTSTR)sqlCommand;
				mysql->UpdateDatabase(sqlC);
				p->NextTypeApp = 2;
			}

			this->ShowWindow(SW_HIDE);
			CSystemViewDlg *pTD = new CSystemViewDlg();
			pTD->Create(IDD_SYSTEMVIEWDLG, GetDesktopWindow()); //创建一个非模态对话框
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
	}
	mysql->CMysqlClose();
	delete mysql;
}


void CBookManageSystemDlg::OnStnClickedVerificationcode()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFileName = _T(".\\background1.bmp");
	CFile file;
	file.Open(strFileName, CFile::modeCreate|CFile::modeWrite);

	CVerificationCode *VC = new CVerificationCode();
	vcNum = VC->Generate4RandNum(); // vcNum是成员变量
	VC->ShengChengYanZhenMa(vcNum, file);
	file.Close();
	delete VC;

	HBITMAP bitmap=(HBITMAP)LoadImage(
		AfxGetInstanceHandle(),
		strFileName,
		IMAGE_BITMAP,
		0,
		0,
		LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_Bitmap.SetBitmap(bitmap);	
}


// 通过类向导添加消息WM_CTLCOLOR即可
HBRUSH CBookManageSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CBookManageSystemDlg::ReSize()
{  
	float fsp[2];  
	POINT Newp; //获取现在对话框的大小  
	CRect recta;      
	GetClientRect(&recta);     //取客户区大小    
	Newp.x=recta.right-recta.left;  
	Newp.y=recta.bottom-recta.top;  
	fsp[0]=(float)Newp.x/old.x;  
	fsp[1]=(float)Newp.y/old.y;  
	CRect Rect;  
	int woc;  
	CPoint OldTLPoint,TLPoint; //左上角  
	CPoint OldBRPoint,BRPoint; //右下角  
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //列出所有控件    
	while(hwndChild)      
	{      
		woc=::GetDlgCtrlID(hwndChild);//取得ID  
		GetDlgItem(woc)->GetWindowRect(Rect);    
		ScreenToClient(Rect);    
		OldTLPoint = Rect.TopLeft();    
		TLPoint.x = long(OldTLPoint.x*fsp[0]);    
		TLPoint.y = long(OldTLPoint.y*fsp[1]);    
		OldBRPoint = Rect.BottomRight();    
		BRPoint.x = long(OldBRPoint.x *fsp[0]);    
		BRPoint.y = long(OldBRPoint.y *fsp[1]);    
		Rect.SetRect(TLPoint,BRPoint);    
		GetDlgItem(woc)->MoveWindow(Rect,TRUE);  
		hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);      
	}  
	old=Newp;  
}

void CBookManageSystemDlg::OnSize(UINT nType, int cx, int cy)
{
	//CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (nType==SIZE_RESTORED||nType==SIZE_MAXIMIZED)  
	{  
		ReSize();  
	}
}


void CBookManageSystemDlg::OnBnClickedRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegisterDlg dlg;
	if(dlg.DoModal() == IDOK)
		dlg.ShowWindow(SW_SHOW); 
}
