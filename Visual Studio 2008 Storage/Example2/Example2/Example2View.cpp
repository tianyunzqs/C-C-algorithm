// Example2View.cpp : CExample2View ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExample2View::OnFileOpen)
	ON_COMMAND(ID_32771, &CExample2View::On32771)
	ON_COMMAND(ID_32773, &CExample2View::OnHorrial)
	ON_COMMAND(ID_FILE_NEW, &CExample2View::OnFileNew)
END_MESSAGE_MAP()

// CExample2View ����/����

CExample2View::CExample2View()
: strFileName(_T(""))
, strPathName(_T(""))
{
	// TODO: �ڴ˴���ӹ������

}

CExample2View::~CExample2View()
{
}

BOOL CExample2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExample2View ����

void CExample2View::OnDraw(CDC* pDC)
{
	CExample2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (strFileName != "")
	{		
		// Create a bitmap handle using the name of the file
		HBITMAP bmpHandle = (HBITMAP)LoadImage(NULL,   // To load an OEM image, set this parameter to zero
			strFileName,   // λͼ����
			IMAGE_BITMAP,  
			0,
			0,
			LR_LOADFROMFILE);


		CBitmap bmpPicture;
		CBitmap *bmpFromHandle = bmpPicture.FromHandle(bmpHandle);
		bmpPicture.Attach(bmpHandle);


		// ����һ��λͼ���浼��λͼ������
		BITMAP bmpProperties;
		bmpPicture.GetBitmap(&bmpProperties);

		//		BYTE *lpBitmap; //ָ��ͼ�����ֽڵ�ָ��
		//		BITMAPINFOHEADER *BIH = ((BITMAPINFOHEADER *)bmpHandle);
		//		char str[20];
		//		_itoa_s(BIH->biWidth, str, 10);
		//		bmpProperties.bmWidth



		// ���������豸
		CDC dcCompatible;
		dcCompatible.CreateCompatibleDC(pDC);

		// ��λͼ��Դѡ�������豸����
		dcCompatible.SelectObject(bmpPicture);



		CRect rect;
		GetClientRect(&rect);
		// BitBlt������1:1�ı������п���
		pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);

	}
}


// CExample2View ��ӡ

BOOL CExample2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExample2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExample2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExample2View ���

#ifdef _DEBUG
void CExample2View::AssertValid() const
{
	CView::AssertValid();
}

void CExample2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample2Doc* CExample2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample2Doc)));
	return (CExample2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample2View ��Ϣ�������

void CExample2View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog filedlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("λͼ�ļ�(*.BMP)|*.BMP||"));;

	if (IDOK == filedlg.DoModal())
	{

		strFileName = filedlg.GetFileName();
		strPathName = filedlg.GetPathName();
		Invalidate();
	}
}

void CExample2View::On32771()
{
	// TODO: �ڴ���������������
	HANDLE data1handle;
	LPBITMAPINFOHEADER lpBi;
	CExample2Doc *pDoc=GetDocument();
/*	HDIB hdib;
	unsigned char *hData;
  ��unsigned char *data;
    hdib=pDoc->m_hDIB;
  ��BeginWaitCursor();
  ��lpBi=(LPBITMAPINFOHEADER)GlobalLock((HGLOBAL)hdib);
  ��hData= lpbi +* (LPDWORD)lpbi + 256*sizeof(RGBQUAD);
  ��//�õ�ָ��λͼ����ֵ��ָ��
  ��pDoc->SetModifiedFlag(TRUE);//���޸ı�־Ϊ"TRUE"
  ��data1handle=GlobalAlloc(GMEM_SHARE,WIDTHBYTES(lpBi->biWidth*8)*lpBi->biHeight);
  ��//�����Ŵ���������ֵ�Ļ�����
  ��data=(unsigned char*)GlobalLock((HGLOBAL)data1handle);
  ��AfxGetApp()->BeginWaitCursor();
  ��int i,j,buf,buf1,buf2;
  ��for( j=0; jbiHeight; j++)//����ѭ����(x,y)λ�õĻҶ�ֵ
	����for( i=0; ibiWidth; i++)
		{ 
		������if(((i-1)>=0)&&((i+1)biWidth)&&((j-1)>=0)&&((j+1)biHeight))
		������{
				  //����ͼ�����ܱ߽紦�����ص㲻����
			������buf1=(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				��������+2*(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j))
				��������+(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				��buf1=buf1-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				��������-2*(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j))
				��������-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				 //x�����Ȩ΢��
				��buf2=(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1))
				��������+2*(int)(int)*(hData+(i)*WIDTHBYTES(lpBi->biWidth*8)+(j+1))
				��������+(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j+1));
				��buf2=buf2-(int)(int)*(hData+(i-1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				��������-2*(int)(int)*(hData+(i)*WIDTHBYTES(lpBi->biWidth*8)+(j-1))
				��������-(int)(int)*(hData+(i+1)*WIDTHBYTES(lpBi->biWidth*8)+(j-1));
				  //y�����Ȩ΢��
				��buf=abs(buf1)+abs(buf2);//���ݶ�
				  if(buf>255) buf=255;
				��if(buf<0)
		   ������ else *(data+i*lpBi->biWidth+j)=(BYTE)0;
			��}
			  for( j=0; jbiHeight; j++)
				��for( i=0; ibiWidth; i++)
				����*(hData+i*WIDTHBYTES(lpBi->biWidth*8)+j)=*(data+i*WIDTHBYTES(lpBi->biWidth*8)+j); 
				 �� //����������д��ԭ������
				  ��AfxGetApp()->EndWaitCursor();
				����GlobalUnlock((HGLOBAL)hdib);
				����GlobalUnlock(data1handle);
				����GlobalFree(date1handle);
				����EndWaitCursor();
				����Invalidate(TRUE);
	  ��}*/
}

void CExample2View::OnHorrial()
{
	// TODO: �ڴ���������������
	HANDLE data1handle;
	LPBITMAPINFOHEADER lpBi;
	CExample2Doc *pDoc=GetDocument();
}
