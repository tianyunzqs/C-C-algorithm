// Example2View.cpp : CExample2View 类的实现
//

#include "stdafx.h"
#include "Example2.h"

#include "Example2Doc.h"
#include "Example2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExample2View

IMPLEMENT_DYNCREATE(CExample2View, CView)

BEGIN_MESSAGE_MAP(CExample2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExample2View::OnFileOpen)
	ON_COMMAND(ID_32771, &CExample2View::On32771)
	ON_COMMAND(ID_32773, &CExample2View::OnHorrial)
	ON_COMMAND(ID_FILE_NEW, &CExample2View::OnFileNew)
END_MESSAGE_MAP()

// CExample2View 构造/析构

CExample2View::CExample2View()
: strFileName(_T(""))
, strPathName(_T(""))
{
	// TODO: 在此处添加构造代码

}

CExample2View::~CExample2View()
{
}

BOOL CExample2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExample2View 绘制

void CExample2View::OnDraw(CDC* pDC)
{
	CExample2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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
		CBitmap *bmpFromHandle = bmpPicture.FromHandle(bmpHandle);
		bmpPicture.Attach(bmpHandle);


		// 创建一副位图保存导入位图的属性
		BITMAP bmpProperties;
		bmpPicture.GetBitmap(&bmpProperties);

		//		BYTE *lpBitmap; //指向图像首字节的指针
		//		BITMAPINFOHEADER *BIH = ((BITMAPINFOHEADER *)bmpHandle);
		//		char str[20];
		//		_itoa_s(BIH->biWidth, str, 10);
		//		bmpProperties.bmWidth



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


// CExample2View 打印

BOOL CExample2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExample2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExample2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExample2View 诊断

#ifdef _DEBUG
void CExample2View::AssertValid() const
{
	CView::AssertValid();
}

void CExample2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample2Doc* CExample2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample2Doc)));
	return (CExample2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample2View 消息处理程序

void CExample2View::OnFileOpen()
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

void CExample2View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	HANDLE data1handle;
	LPBITMAPINFOHEADER lpBi;
	CExample2Doc *pDoc=GetDocument();
/*	HDIB hdib;
	unsigned char *hData;
  　unsigned char *data;
    hdib=pDoc->m_hDIB;
  　BeginWaitCursor();
  　lpBi=(LPBITMAPINFOHEADER)GlobalLock((HGLOBAL)hdib);
  　hData= lpbi +* (LPDWORD)lpbi + 256*sizeof(RGBQUAD);
  　//得到指向位图像素值的指针
  　pDoc->SetModifiedFlag(TRUE);//设修改标志为"TRUE"
  　data1handle=GlobalAlloc(GMEM_SHARE,WIDTHBYTES(lpBi->biWidth*8)*lpBi->biHeight);
  　//申请存放处理后的像素值的缓冲区
  　data=(unsigned char*)GlobalLock((HGLOBAL)data1handle);
  　AfxGetApp()->BeginWaitCursor();
  　int i,j,buf,buf1,buf2;
  　for( j=0; jbiHeight; j++)//以下循环求(x,y)位置的灰度值
	　　for( i=0; ibiWidth; i++)
		{ 
		　　　if(((i-1)>=0)&&((i+1)biWidth)&&((j-1)>=0)&&((j+1)biHeight))
		　　　{
				  //对于图像四周边界处的向素点不处理
			　　　buf1=(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				　　　　+2*(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j))
				　　　　+(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				　buf1=buf1-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				　　　　-2*(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j))
				　　　　-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				 //x方向加权微分
				　buf2=(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1))
				　　　　+2*(int)(int)*(hData+(i)*WIDTHBYTES(lpBi->biWidth*8)+(j+1))
				　　　　+(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				　buf2=buf2-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				　　　　-2*(int)(int)*(hData+(i)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				　　　　-(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1));
				  //y方向加权微分
				　buf=abs(buf1)+abs(buf2);//求梯度
				  if(buf>255) buf=255;
				　if(buf<0)
		   　　　 else *(data+i*lpBi->biWidth+j)=(BYTE)0;
			　}
			  for( j=0; jbiHeight; j++)
				　for( i=0; ibiWidth; i++)
				　　*(hData+i*WIDTHBYTES(lpBi->biWidth*8)+j)=*(data+i*WIDTHBYTES(lpBi->biWidth*8)+j); 
				 　 //处理后的数据写回原缓冲区
				  　AfxGetApp()->EndWaitCursor();
				　　GlobalUnlock((HGLOBAL)hdib);
				　　GlobalUnlock(data1handle);
				　　GlobalFree(date1handle);
				　　EndWaitCursor();
				　　Invalidate(TRUE);
	  　}*/
}

void CExample2View::OnHorrial()
{
	// TODO: 在此添加命令处理程序代码
	HANDLE data1handle;
	LPBITMAPINFOHEADER lpBi;
	CExample2Doc *pDoc=GetDocument();
}
