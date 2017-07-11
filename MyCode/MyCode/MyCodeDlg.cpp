// MyCodeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFunction.h"
#include "MyCode.h"
#include "MyCodeDlg.h"
#include "initgdiplus.h"
#include <atlimage.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
static InitGDIPlus GDI_Plus_Controler;

// CMyCodeDlg 对话框
CString strFilePath;   //文件名 



CMyCodeDlg::CMyCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyCodeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_2, mPicture);
	DDX_Control(pDX, IDC_STATIC_3, mPicture2);
}

BEGIN_MESSAGE_MAP(CMyCodeDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMyCodeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyCodeDlg 消息处理程序

BOOL CMyCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyCodeDlg::OnPaint()
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
		CDialog::UpdateWindow(); //更新windows窗口，如果无这步调用，图片显示还会出现问题
		//Show_picture();     //重绘图片函数
		if(strFilePath!="")
		{
			CRect rect;
			mPicture.GetClientRect(&rect);     //m_picture为Picture Control控件变量，获得控件的区域对象
			CImage image1;       //使用图片类
			image1.Load(strFilePath);   //装载路径下图片信息到图片类
			CDC* pDC = mPicture.GetWindowDC();    //获得显示控件的DC
			image1.Draw( pDC -> m_hDC,rect);      //图片类的图片绘制Draw函数
			ReleaseDC(pDC);


	        CRect rect2;
			mPicture2.GetClientRect(&rect2);     //m_picture为Picture Control控件变量，获得控件的区域对象
			CImage image2;       //使用图片类
			image2.Load(strFilePath);   //装载路径下图片信息到图片类
			
			 if(!image1.IsIndexed())
	 {
	 // 直接修改像素颜色 
	 COLORREF pixel;
	 int maxY = image1.GetHeight(), maxX = image1.GetWidth(); 
	 //byte r,avg,Gmax,Gmin,ThreHold;
	 byte r,avg,Gmax,Gmin;
	  pixel=image1.GetPixel(0,0);
	 Gmax=Gmin=GetRValue(pixel); 
//寻找灰度最大值和最小值
	 for (int x=0; x<maxX; x++)
	 { 
		 for(int y=0; y<maxY; y++)
		 { 
			 pixel =image1.GetPixel(x,y);
			 r = GetRValue(pixel);
			 Gmax=Gmax>r?Gmax:r ;
			 Gmin=Gmin<r?Gmin:r ;
			
		 }
	 }
	 for (int x=0; x<maxX; x++) 
	 { 
		 for(int y=0; y<maxY; y++) 
		 { 
			  //ThreHold =(byte)((2*Gmax+Gmin)/3);
			   pixel =image1.GetPixel(x,y);
			  r = GetRValue(pixel);
			  //avg=r>ThreHold?255:0;
			 avg=r>76?255:0;	
			 image2.SetPixelRGB(x,y,avg,avg,avg);

		 }
	 }
	 }
			
			CDC* pDC2 = mPicture2.GetWindowDC();    //获得显示控件的DC
			image2.Draw( pDC2 -> m_hDC,rect2);      //图片类的图片绘制Draw函数
			ReleaseDC(pDC2);
		}   //文件名 
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyCodeDlg::OnBnClickedOk()
{

	//对话框类 文本框打开文件,  _T("*.bmp")是 打开的对话框中的默认值
	CFileDialog dlg(TRUE, NULL, _T("*.bmp"), OFN_FILEMUSTEXIST|OFN_HIDEREADONLY, _T("image files (*.bmp) |*.bmp |"), this);  
 
	if(dlg.DoModal() == IDOK)  //如果用户点击确定 DoModal方法是获取用户选择项
		{  
				strFilePath=dlg.GetPathName();  //取得选择的文件名 , GetPathName方法获得用户选择的文件名
		}
	else
		{
				return;							//如果用户选择 "取消" ,则返回
		}		

	CRect rect,rect2;                        //声明窗口区域类
	mPicture.GetClientRect(&rect);     //mPicture为Picture Control控件变量，获得控件的区域对象
	mPicture2.GetClientRect(&rect2);     //mPicture为Picture Control控件变量，获得控件的区域对象
	CImage image1,image2;					   //使用图片类
	image1.Load(strFilePath);           //装载路径下图片信息到图片类
	image2.Load(strFilePath);
	 if(!image1.IsIndexed())
	 {
	 // 直接修改像素颜色 
	 COLORREF pixel;
	 int maxY = image1.GetHeight(), maxX = image1.GetWidth(); 
	 //byte r,avg,Gmax,Gmin,ThreHold;
	 byte r,avg,Gmax,Gmin;
	  pixel=image1.GetPixel(0,0);
	 Gmax=Gmin=GetRValue(pixel); 
//寻找灰度最大值和最小值
	 for (int x=0; x<maxX; x++)
	 { 
		 for(int y=0; y<maxY; y++)
		 { 
			 pixel =image1.GetPixel(x,y);
			 r = GetRValue(pixel);
			 Gmax=Gmax>r?Gmax:r ;
			 Gmin=Gmin<r?Gmin:r ;
			
		 }
	 }
	 for (int x=0; x<maxX; x++) 
	 { 
		 for(int y=0; y<maxY; y++) 
		 { 
			  //ThreHold =(byte)((2*Gmax+Gmin)/3);
			   pixel =image1.GetPixel(x,y);
			  r = GetRValue(pixel);
			  //avg=r>ThreHold?255:0;
			  avg=r>76?255:0;
			 image2.SetPixelRGB(x,y,avg,avg,avg);

		 }
	 }
	 }
	
	CDC* pDC = mPicture.GetWindowDC(); //获得显示控件的句柄
	CDC* pDC2 = mPicture2.GetWindowDC(); //获得显示控件的句柄
	image1.Draw( pDC -> m_hDC,rect);    //图片类的图片绘制函数
	image2.Draw( pDC2 -> m_hDC,rect);    //图片类的图片绘制函数
	ReleaseDC(pDC);					   //释放句柄内存
	ReleaseDC(pDC2);	
	
	CString tezhengma1="";			   //验证码特征字符串1 CString长字节字串,占的内存比 string 要多
	CString tezhengma2="";			   //验证码特征字符串2
	CString tezhengma3="";			   //验证码特征字符串3
	CString tezhengma4="";			   //验证码特征字符串4
	CString tezhengma5="";			   //验证码特征字符串5



	GDI_Plus_Controler.Initialize();   //GDI图形设备接口控制器初始化
	using namespace Gdiplus;		   //引用Gdiplus命名空间
	Bitmap bmpSrc(strFilePath.AllocSysString(),FALSE);  //BMP图片类,建立位图对象


	int widthSrc = bmpSrc.GetWidth();			//获取长  GetWidth方法
	int heightSrc = bmpSrc.GetHeight();         //获取宽  GetHeight方法
	
	Rect rectSrc(0, 0, widthSrc, heightSrc);    //声明矩形类 ,参数为图象左上角坐标,图象宽,图象高
	BitmapData bmDataSrc;                       //声明位图数据类
	ZeroMemory(&bmDataSrc, sizeof(bmDataSrc));  //使bmDataSrc指针内容清零

	bmpSrc.LockBits(&rectSrc,
		ImageLockModeRead,
		PixelFormat24bppRGB,
		&bmDataSrc
		);                                       //将像素信息存储到 指针所指向的缓冲区
	int srcStride = bmDataSrc.Stride;            //跨度宽度 每像素3字节,3*width = Stride ,但Stride 是里它最近的4的整数倍
	BYTE *pSrc = (BYTE *)((void *)bmDataSrc.Scan0); //指针指向 位图的第0个像素地址
	

	    int ComputeValue1=GetComputeValue(0,10,heightSrc,pSrc,srcStride);
		int ComputeValue2=GetComputeValue(10,20,heightSrc,pSrc,srcStride);
		int ComputeValue3=GetComputeValue(20,30,heightSrc,pSrc,srcStride);
		int ComputeValue4=GetComputeValue(30,40,heightSrc,pSrc,srcStride);
		int ComputeValue5=GetComputeValue(40,50,heightSrc,pSrc,srcStride);

        //*****分割图片******
		tezhengma1=Gettezhengma(0,10,heightSrc,pSrc,srcStride,ComputeValue1);    //获取特征码函数 参数1:图象X轴 左 参数2:图象X轴 右  
		tezhengma2=Gettezhengma(10,20,heightSrc,pSrc,srcStride,ComputeValue2);   //               参数3:图象高     参数4:图象指针
		tezhengma3=Gettezhengma(20,30,heightSrc,pSrc,srcStride,ComputeValue3);   //               参数5:跨度宽度
		tezhengma4=Gettezhengma(30,40,heightSrc,pSrc,srcStride,ComputeValue4);
		tezhengma5=Gettezhengma(40,50,heightSrc,pSrc,srcStride,ComputeValue5);
		//*****分割图片******
		
		char code1,code2,code3,code4,code5;                         //声明字符变量,用来保存验证码值,最后送到文本框控件显示
		code1=PictureToCode(_T(tezhengma1));                        //将特征码与图库做对比,返回相似度最高的 
		code2=PictureToCode(_T(tezhengma2));						//_T的作用是把CString转为string 
		code3=PictureToCode(_T(tezhengma3));
		code4=PictureToCode(_T(tezhengma4));
		code5=PictureToCode(_T(tezhengma5));

		CString StaticText;										      //声明验证码字符串
		StaticText.Format("%c%c%c%c%c",code1,code2,code3,code4,code5);//将5位验证码字符整合在一起,Format方法的作用是把字符格式化成指定格式 .code1并code2并code3并code4并code5的格式.
		GetDlgItem(IDC_STATIC_1)->SetWindowText(_T(StaticText));      //在文本控件输出 GetDlgItem方法是通过控件ID获得控件句柄
																	  //,SetWindowText方法是设置控件值,_T作用是把长字符串转为string标准字符串类型
}
