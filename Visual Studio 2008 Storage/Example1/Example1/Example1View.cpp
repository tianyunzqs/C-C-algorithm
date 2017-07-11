// Example1View.cpp : CExample1View ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExample1View::OnFileOpen)
	ON_COMMAND(IDM_Horrial, &CExample1View::OnHorrial)
END_MESSAGE_MAP()

// CExample1View ����/����

CExample1View::CExample1View()

{
	// TODO: �ڴ˴���ӹ������

}

CExample1View::~CExample1View()
{
}

BOOL CExample1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExample1View ����

void CExample1View::OnDraw(CDC* pDC)
{
	CExample1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
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
			strFileName,   // λͼ����
			IMAGE_BITMAP,  
			0,
			0,
			LR_LOADFROMFILE);

		CBitmap bmpPicture;
//		CBitmap *bmpFromHandle = bmpPicture.FromHandle(bmpHandle);
		bmpPicture.Attach(bmpHandle);

		// ����һ��λͼ���浼��λͼ������
		BITMAP bmpProperties;
		bmpPicture.GetBitmap(&bmpProperties);

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


// CExample1View ��ӡ

BOOL CExample1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExample1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExample1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExample1View ���

#ifdef _DEBUG
void CExample1View::AssertValid() const
{
	CView::AssertValid();
}

void CExample1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExample1Doc* CExample1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExample1Doc)));
	return (CExample1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExample1View ��Ϣ�������

void CExample1View::OnFileOpen()
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

void CExample1View::OnHorrial()
{
	// ����һ��λͼ���浼��λͼ������
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
