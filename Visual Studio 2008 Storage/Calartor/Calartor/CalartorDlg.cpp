// CalartorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calartor.h"
#include "CalartorDlg.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCalartorDlg 对话框




CCalartorDlg::CCalartorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalartorDlg::IDD, pParent)
	, ShowString(_T(""))
	, OperatorNumLeft(0)
	, OperatorNumRight(0)
	, Loc(0)
	, SymbolLoc(0)
	, Result(0)
	, EqualNum(0)
	, SymbolFlag(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalartorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_show);
	DDX_Text(pDX, IDC_EDIT1, ShowString);
}

BEGIN_MESSAGE_MAP(CCalartorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_32773, &CCalartorDlg::AthurorInformation)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalartorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalartorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalartorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalartorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalartorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalartorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalartorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalartorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalartorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalartorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_SURE, &CCalartorDlg::OnBnClickedSure)
	ON_BN_CLICKED(IDC_DOT, &CCalartorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PULS, &CCalartorDlg::OnBnClickedPuls)
	ON_BN_CLICKED(IDC_MINUS, &CCalartorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_TIME, &CCalartorDlg::OnBnClickedTime)
	ON_BN_CLICKED(IDC_DIV, &CCalartorDlg::OnBnClickedDiv)
END_MESSAGE_MAP()


// CCalartorDlg 消息处理程序

BOOL CCalartorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	ShowString = _T("");
	Loc = 0;
	SymbolLoc = 0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalartorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalartorDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalartorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalartorDlg::AthurorInformation()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("制作者：朱其斯\n制作时间：2015-2-19"), _T("计算器"));
}

void CCalartorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("1");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("2");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("3");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("4");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("5");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("6");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("7");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("8");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("9");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T("0");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	Loc++;
	ShowString += _T(".");
	GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
}

void CCalartorDlg::OnBnClickedPuls()
{
	// TODO: 在此添加控件通知处理程序代码
	SymbolFlag = 1;  // 加号
	if (EqualNum > 0)
	{
		ShowString = _T("Ans+");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // 符号所在的位置
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // 符号所在的位置
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("+");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedMinus()
{
	// TODO: 在此添加控件通知处理程序代码
	SymbolFlag = 2;   // 减号
	if (EqualNum > 0)
	{
		ShowString = _T("Ans-");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // 符号所在的位置
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // 符号所在的位置
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("-");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedTime()
{
	// TODO: 在此添加控件通知处理程序代码
	SymbolFlag = 3;   // 乘号
	if (EqualNum > 0)
	{
		ShowString = _T("Ans*");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // 符号所在的位置
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // 符号所在的位置
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("*");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}

void CCalartorDlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	SymbolFlag = 4;   // 除号
	if (EqualNum > 0)
	{
		ShowString = _T("Ans/");
		OperatorNumLeft = Result;
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
		SymbolLoc = 4;  // 符号所在的位置
		Loc = 4;
	}
	else
	{
		Loc++;
		SymbolLoc = Loc;  // 符号所在的位置
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		OperatorNumLeft = _wtof(str.GetBuffer());
		ShowString += _T("/");
		GetDlgItem(IDC_EDIT1)->SetWindowText(ShowString);
	}
}


void CCalartorDlg::OnBnClickedSure()
{
	// TODO: 在此添加控件通知处理程序代码
	EqualNum++;
	CString SecNum = _T("");
	for (int i=SymbolLoc; i<Loc; i++)
		SecNum += ShowString[i];
	OperatorNumRight = _wtof(SecNum.GetBuffer());
	switch(SymbolFlag)
	{
	case 1: 
		Result = OperatorNumLeft + OperatorNumRight;
		break;
	case 2:
		Result = OperatorNumLeft - OperatorNumRight;
		break;
	case 3:
		Result = OperatorNumLeft * OperatorNumRight;
		break;
	case 4:
		Result = OperatorNumLeft / OperatorNumRight;
		break;
	default:
		break;
	}
	CString Resultstr;
	Resultstr.Format(_T("%lf"), Result);
	GetDlgItem(IDC_EDIT1)->SetWindowText(Resultstr);
}