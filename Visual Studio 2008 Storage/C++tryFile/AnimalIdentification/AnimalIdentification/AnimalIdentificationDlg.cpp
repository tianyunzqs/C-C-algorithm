// AnimalIdentificationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AnimalIdentification.h"
#include "AnimalIdentificationDlg.h"

#include "AnimalFeature.h"

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


// CAnimalIdentificationDlg 对话框




CAnimalIdentificationDlg::CAnimalIdentificationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimalIdentificationDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnimalIdentificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
}

BEGIN_MESSAGE_MAP(CAnimalIdentificationDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CAnimalIdentificationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CAnimalIdentificationDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CAnimalIdentificationDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK2, &CAnimalIdentificationDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK4, &CAnimalIdentificationDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CAnimalIdentificationDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CAnimalIdentificationDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CAnimalIdentificationDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CAnimalIdentificationDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CAnimalIdentificationDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CAnimalIdentificationDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CAnimalIdentificationDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CAnimalIdentificationDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CAnimalIdentificationDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CAnimalIdentificationDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CAnimalIdentificationDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &CAnimalIdentificationDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &CAnimalIdentificationDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &CAnimalIdentificationDlg::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK19, &CAnimalIdentificationDlg::OnBnClickedCheck19)
END_MESSAGE_MAP()


// CAnimalIdentificationDlg 消息处理程序

BOOL CAnimalIdentificationDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAnimalIdentificationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnimalIdentificationDlg::OnPaint()
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
HCURSOR CAnimalIdentificationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

AnimalFeature AF;

void CAnimalIdentificationDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AF.IsMammal(AF.UserInputFeature);
	AF.IsBird(AF.UserInputFeature);
	AF.IsCarnivore(AF.UserInputFeature);
	AF.IsUngulate(AF.UserInputFeature, AF.InferenceFeature);

	//AF.IsLeopard(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsTiger(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsGiraffe(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsZebra(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsOstrich(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsPenguin(AF.UserInputFeature, AF.InferenceFeature);
	//AF.IsAlbatross(AF.UserInputFeature, AF.InferenceFeature);
	AF.Identification(AF.UserInputFeature, AF.InferenceFeature);

	CBitmap bitmap;  // CBitmap对象，用于加载位图
	HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄
	switch (AF.IdentificationResult)
	{
	case 1: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("金钱豹"));
			bitmap.LoadBitmap(IDB_LEOPARD);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;
		}
	case 2: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("老虎"));
			bitmap.LoadBitmap(IDB_TIGER);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;
		}	   
	case 3: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("长颈鹿"));
			bitmap.LoadBitmap(IDB_GIRAFFE);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;	
		}
	case 4: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("斑马"));
			bitmap.LoadBitmap(IDB_ZEBRA);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;	
		}	
	case 5: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("鸵鸟"));
			bitmap.LoadBitmap(IDB_OSTRICH);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;
		}		
	case 6: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("企鹅"));
			bitmap.LoadBitmap(IDB_PENGUIN);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;
		}	
	case 7: 
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("信天翁"));
			bitmap.LoadBitmap(IDB_ALBATROSS);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;	
		}
	default:
		{
			GetDlgItem(IDC_SHOW)->SetWindowText(_T("?"));
			bitmap.LoadBitmap(IDB_BITMAP1);  // 将位图IDB_BITMAP1加载到bitmap 
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			m_pic.SetBitmap(hBmp);// 设置图片控件m_Pic的位图为IDB_BITMAP1 
			break;
		}
		
	}
}






void CAnimalIdentificationDlg::OnBnClickedCheck1()
{
	AF.UserInputFeature[0] = !AF.UserInputFeature[0];
}

void CAnimalIdentificationDlg::OnBnClickedCheck2()
{
	AF.UserInputFeature[1] = !AF.UserInputFeature[1];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck3()
{
	AF.UserInputFeature[2] = !AF.UserInputFeature[2];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck4()
{
	AF.UserInputFeature[3] = !AF.UserInputFeature[3];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck5()
{
	AF.UserInputFeature[4] = !AF.UserInputFeature[4];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck6()
{
	AF.UserInputFeature[5] = !AF.UserInputFeature[5];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck7()
{
	AF.UserInputFeature[6] = !AF.UserInputFeature[6];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck8()
{
	AF.UserInputFeature[7] = !AF.UserInputFeature[7];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck9()
{
	AF.UserInputFeature[8] = !AF.UserInputFeature[8];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck10()
{
	AF.UserInputFeature[9] = !AF.UserInputFeature[9];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck11()
{
	AF.UserInputFeature[10] = !AF.UserInputFeature[10];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck12()
{
	AF.UserInputFeature[11] = !AF.UserInputFeature[11];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck13()
{
	AF.UserInputFeature[12] = !AF.UserInputFeature[12];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck14()
{
	AF.UserInputFeature[13] = !AF.UserInputFeature[13];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck15()
{
	AF.UserInputFeature[14] = !AF.UserInputFeature[14];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck16()
{
	AF.UserInputFeature[15] = !AF.UserInputFeature[15];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck17()
{
	AF.UserInputFeature[16] = !AF.UserInputFeature[16];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck18()
{
	AF.UserInputFeature[17] = !AF.UserInputFeature[17];	
}

void CAnimalIdentificationDlg::OnBnClickedCheck19()
{
	AF.UserInputFeature[18] = !AF.UserInputFeature[18];	
}
