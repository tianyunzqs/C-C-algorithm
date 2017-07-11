// YanZhenMaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "YanZhenMa.h"
#include "YanZhenMaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYanZhenMaDlg dialog

CYanZhenMaDlg::CYanZhenMaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYanZhenMaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYanZhenMaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYanZhenMaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYanZhenMaDlg)
	DDX_Control(pDX, IDC_STATIC1, m_bitmap);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CYanZhenMaDlg, CDialog)
	//{{AFX_MSG_MAP(CYanZhenMaDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHENGCHENG, OnShengcheng)
	//}}AFX_MSG_MAP
	ON_STN_CLICKED(IDC_STATIC1, &CYanZhenMaDlg::OnStnClickedStatic1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYanZhenMaDlg message handlers

BOOL CYanZhenMaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYanZhenMaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYanZhenMaDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYanZhenMaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL  myCreateBitmap( HDC hDC,  HBITMAP hbitmap, 					 
					 PBITMAPFILEHEADER &outheadbuf,long *outheadsize,					 
					 PBITMAPINFO &outinfobuf,long *outinfosize,					 
					 LPBYTE &outdatabuf,long *outdatasize)	//生成单色位图					 
{ 	
	BITMAP bmp; 	
	WORD cClrBits; 	
	DWORD my_biClrUsed=0;	
	outinfobuf=NULL;	
	outdatabuf=NULL;	
	outheadbuf=NULL;	
		
	if (!GetObject(hbitmap, sizeof(BITMAP), (LPSTR)&bmp))   
		goto errout; 		
	bmp.bmPlanes=1;
	bmp.bmBitsPixel=1;  //强制赋值转换出来的每像素BIT数
	cClrBits = 1;  //得到每像素多少位		
	*outinfosize= sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * (1<< cClrBits);		
	outinfobuf = (PBITMAPINFO) GlobalAlloc (GPTR,   *outinfosize); 
	outinfobuf->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); //信息头大小（不含调色板）	
	outinfobuf->bmiHeader.biWidth = bmp.bmWidth; 	
	outinfobuf->bmiHeader.biHeight = bmp.bmHeight; 	
	outinfobuf->bmiHeader.biPlanes = bmp.bmPlanes; 	
	outinfobuf->bmiHeader.biBitCount = bmp.bmBitsPixel; 		
	my_biClrUsed=(1<<cClrBits);  
	outinfobuf->bmiHeader.biClrUsed = my_biClrUsed;	
	outinfobuf->bmiHeader.biCompression = BI_RGB; 	
	outinfobuf->bmiHeader.biSizeImage = ((outinfobuf->bmiHeader.biWidth * cClrBits +31) & ~31)\
		
		/8 * outinfobuf->bmiHeader.biHeight;  	
	//图像大小	
	outinfobuf->bmiHeader.biClrImportant = 0; 	
	/////////////////////////////////得到位图数据	
	// GlobalAlloc分配位图数据的内存	
	// GetDIBits 根据hDC 和HBITMAP得到位图数据、调色板数据	
	*outdatasize=outinfobuf->bmiHeader.biSizeImage;	
	outdatabuf = (LPBYTE) GlobalAlloc(GPTR,    *outdatasize);  //根据位图大小分配内存	
	if (!outdatabuf)  
		goto errout; 	
	if (!GetDIBits(//根据DC和BITMAP得到位图数据		
		hDC, 		
		hbitmap, 		
		0, 		
		(WORD) outinfobuf->bmiHeader.biHeight, 		
		outdatabuf,     // outdatabuf中得到位图数据		
		outinfobuf,      		
		DIB_RGB_COLORS) ) 
		
	{  goto errout;  }
	
	/////////////////////////////////得到文件头	
	*outheadsize= sizeof(BITMAPFILEHEADER);	
	outheadbuf = (PBITMAPFILEHEADER) GlobalAlloc(GPTR,  *outheadsize);	
	//根据位图大小分配内存	
	if (!outheadbuf) 
		goto errout;	
	outheadbuf->bfType = 0x4d42;   	
	outheadbuf->bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + 		
		outinfobuf->bmiHeader.biSize +		
		my_biClrUsed * sizeof(RGBQUAD) +		
		outinfobuf->bmiHeader.biSizeImage); 
	outheadbuf->bfReserved1 = 0; 	
	outheadbuf->bfReserved2 = 0; 	
	
	outheadbuf->bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + 		
		outinfobuf->bmiHeader.biSize +		
		my_biClrUsed * sizeof (RGBQUAD); 
	return TRUE;	
	
	//////////////////////错误处理	
errout:	
	if(outinfobuf) GlobalFree(outinfobuf);	
	if(outdatabuf) GlobalFree(outdatabuf);	
	if(outheadbuf) GlobalFree(outheadbuf);	
	outinfobuf=NULL;	
	outdatabuf=NULL;	
	outheadbuf=NULL;	
	*outheadsize=0;	
	*outinfosize=0;	
	*outdatasize=0;	
	return FALSE;	
}

BOOL ShengChengYanZhenMa(CString str,CFile& file)//生成汉字验证码
{
	ASSERT(0 == str.GetLength()%2);
	
	CWnd* pDesk =  CWnd::GetDesktopWindow( );
	CDC* pDC = pDesk->GetDC();
	
	//每个字符的位置随机偏移4
	CRect r(0,0,0,0);
	pDC->DrawText(str,&r,DT_CALCRECT);
	const int w = r.Width()+4;
	const int h = r.Height()+4;  
	const int iCharWidth = w*2/str.GetLength();
	
	//建立内存DC和位图并填充背景
    CBitmap bm;
    bm.CreateCompatibleBitmap(pDC,w,h);
    CDC memdc;
    memdc.CreateCompatibleDC(pDC);	
    CBitmap*pOld=memdc.SelectObject(&bm);
	memdc.FillSolidRect(0,0,w,h,RGB(255,255,255));
	
	::SetGraphicsMode(memdc.m_hDC,GM_ADVANCED);//为字体倾斜作准备
	
	for(int i = 0 ; i < str.GetLength()/2 ; i++)
	{
		//设置字体
		CFont* pFont = memdc.GetCurrentFont();
		LOGFONT logFont;
		pFont->GetLogFont(&logFont);
		logFont.lfOutPrecision = OUT_TT_ONLY_PRECIS;
		logFont.lfOrientation = rand()%90;
		CFont font;
		font.CreateFontIndirect(&logFont);
		memdc.SelectObject(&font);
		
		int x = iCharWidth*i+rand()%5;
		int y = rand()%5;
		memdc.TextOut(x,y,str.Mid(i*2,2));
	}
	
    //将内容存到文件(CFile或CMemFile)
	PBITMAPFILEHEADER outheadbuf;		
	PBITMAPINFO outinfobuf;		
	LPBYTE outdatabuf;		
	long outheadsize,outinfosize,outdatasize;		
	if (!myCreateBitmap( memdc.m_hDC,  bm, 			
		outheadbuf,&outheadsize,			
		outinfobuf,&outinfosize,			
		outdatabuf,&outdatasize) )			
		return FALSE ;
	
	
	file.Write(outheadbuf,outheadsize);		
	file.Write(outinfobuf,outinfosize);		
	file.Write(outdatabuf,outdatasize);		
	
	memdc.SelectObject( pOld );
	bm.DeleteObject( );
	memdc.DeleteDC( );
}

void CYanZhenMaDlg::OnShengcheng() 
{
	srand(GetTickCount());
	
	CString strFileName = "C:\\Users\\Administrator\\Pictures\\background.bmp";
	CFile file;
	file.Open(strFileName,CFile::modeCreate|CFile::modeWrite);
	ShengChengYanZhenMa("中国人民",file);
	file.Close();
	
	HBITMAP bitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),strFileName,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_bitmap.SetBitmap(bitmap);	
}


void CYanZhenMaDlg::OnStnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
	CYanZhenMaDlg::OnShengcheng();
}
