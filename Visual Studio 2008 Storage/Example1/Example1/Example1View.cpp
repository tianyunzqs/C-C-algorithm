// Example1View.cpp : CExample1View 类的实现
//

#include "stdafx.h"
#include "Example1.h"

#include "Example1Doc.h"
#include "Example1View.h"
#include <wingdi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample1View

IMPLEMENT_DYNCREATE(CExample1View, CView)

BEGIN_MESSAGE_MAP(CExample1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExample1View::OnFileOpen)
	ON_COMMAND(IDM_Horrial, &CExample1View::OnHorrial)
END_MESSAGE_MAP()

// CExample1View 构造/析构

CExample1View::CExample1View()

{
	// TODO: 在此处添加构造代码

}

CExample1View::~CExample1View()
{
}

BOOL CExample1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExample1View 绘制

void CExample1View::OnDraw(CDC* pDC)
{
	CExample1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
//	CString str;
//	str = "zqs";
//	CClientDC dc(this);
//	dc.MoveTo(200, 10);
//	dc.LineTo(620, 10);
//	dc.TextOut(10, 10, str);


	if (strFileName != "")
	{		
		
		// Create a bitmap handle using the name of the file
		HBITMAP bmpHandle = (HBITMAP)LoadImage(NULL,   // To load an OEM image, set this parameter to zero
			strFileName,   // 位图名称
			IMAGE_BITMAP,  
			0,
			0,
			LR_LOADFROMFILE);

		CBitmap bmpPicture;
//		CBitmap *bmpFromHandle = bmpPicture.FromHandle(bmpHandle);
		bmpPicture.Attach(bmpHandle);

		// 创建一副位图保存导入位图的属性
		BITMAP bmpProperties;
		bmpPicture.GetBitmap(&bmpProperties);

		// 创建兼容设备
		CDC dcCompatible;
		dcCompatible.CreateCompatibleDC(pDC);

		// 将位图资源选进兼容设备当中
		dcCompatible.SelectObject(bmpPicture);

		CRect rect;
		GetClientRect(&rect);
		// BitBlt函数是1:1的比例进行拷贝
		pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);

	}
}


// CExample1View 打印

BOOL CExample1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExample1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExample1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExample1View 诊断

#ifdef _DEBUG
void CExample1View::AssertValid() const
{
	CView::AssertValid();
}

void CExample1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample1Doc* CExample1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample1Doc)));
	return (CExample1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample1View 消息处理程序

void CExample1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("位图文件(*.BMP)|*.BMP||"));;

	if (IDOK == filedlg.DoModal())
	{

		strFileName = filedlg.GetFileName();
		strPathName = filedlg.GetPathName();
		Invalidate();
	}
}

void CExample1View::OnHorrial()
{
	// 创建一副位图保存导入位图的属性
//	BITMAP bmpProperties2;
	COLORREF clr[bmpProperties.bmWidth][bmpProperties.bmHeight];
//	COLORREF clr[10000][10000];
	for (int i=0; i<bmpProperties.bmWidth; i++)
		for(int j=0; j<bmpProperties.bmWidth; j++)
		{
			clr[i][j] = GetPixel((HDC)bmpHandle, i, j);
		}
//	for (int i=0; i<bmpProperties.bmWidth; i++)
//		for(int j=0; j<bmpProperties.bmWidth; j++)
//		{
//			SetPixel((HDC)bmpHandle, i, j, clr[i][j]);
//		}
}
