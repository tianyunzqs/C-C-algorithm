#include "StdAfx.h"
#include "VerificationCode.h"
#include <time.h>
#include <stdlib.h>

CVerificationCode::CVerificationCode(void)
{
}


CVerificationCode::~CVerificationCode(void)
{
}


BOOL  CVerificationCode::myCreateBitmap( HDC hDC,  HBITMAP hbitmap, 					 
	PBITMAPFILEHEADER &outheadbuf,long *outheadsize,					 
	PBITMAPINFO &outinfobuf,long *outinfosize,					 
	LPBYTE &outdatabuf,long *outdatasize)	//���ɵ�ɫλͼ					 
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
	bmp.bmBitsPixel=1;  //ǿ�Ƹ�ֵת��������ÿ����BIT��
	cClrBits = 1;  //�õ�ÿ���ض���λ		
	*outinfosize= sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * (1<< cClrBits);		
	outinfobuf = (PBITMAPINFO) GlobalAlloc (GPTR,   *outinfosize); 
	outinfobuf->bmiHeader.biSize = sizeof(BITMAPINFOHEADER); //��Ϣͷ��С��������ɫ�壩	
	outinfobuf->bmiHeader.biWidth = bmp.bmWidth; 	
	outinfobuf->bmiHeader.biHeight = bmp.bmHeight; 	
	outinfobuf->bmiHeader.biPlanes = bmp.bmPlanes; 	
	outinfobuf->bmiHeader.biBitCount = bmp.bmBitsPixel; 		
	my_biClrUsed=(1<<cClrBits);  
	outinfobuf->bmiHeader.biClrUsed = my_biClrUsed;	
	outinfobuf->bmiHeader.biCompression = BI_RGB; 	
	outinfobuf->bmiHeader.biSizeImage = ((outinfobuf->bmiHeader.biWidth * cClrBits +31) & ~31)\

		/8 * outinfobuf->bmiHeader.biHeight;  	
	//ͼ���С	
	outinfobuf->bmiHeader.biClrImportant = 0; 	
	/////////////////////////////////�õ�λͼ����	
	// GlobalAlloc����λͼ���ݵ��ڴ�	
	// GetDIBits ����hDC ��HBITMAP�õ�λͼ���ݡ���ɫ������	
	*outdatasize=outinfobuf->bmiHeader.biSizeImage;	
	outdatabuf = (LPBYTE) GlobalAlloc(GPTR,    *outdatasize);  //����λͼ��С�����ڴ�	
	if (!outdatabuf)  
		goto errout; 	
	if (!GetDIBits(//����DC��BITMAP�õ�λͼ����		
		hDC, 		
		hbitmap, 		
		0, 		
		(WORD) outinfobuf->bmiHeader.biHeight, 		
		outdatabuf,     // outdatabuf�еõ�λͼ����		
		outinfobuf,      		
		DIB_RGB_COLORS) ) 

	{  goto errout;  }

	/////////////////////////////////�õ��ļ�ͷ	
	*outheadsize= sizeof(BITMAPFILEHEADER);	
	outheadbuf = (PBITMAPFILEHEADER) GlobalAlloc(GPTR,  *outheadsize);	
	//����λͼ��С�����ڴ�	
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

	//////////////////////������	
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


BOOL CVerificationCode::ShengChengYanZhenMa(CString str,CFile& file)//���ɺ�����֤��
{
	ASSERT(0 == str.GetLength()%2);

	CWnd* pDesk =  CWnd::GetDesktopWindow( );
	CDC* pDC = pDesk->GetDC();

	//ÿ���ַ���λ�����ƫ��4
	CRect r(0,0,0,0);
	pDC->DrawText(str,&r,DT_CALCRECT);
	const int w = r.Width()+4;
	const int h = r.Height()+4;  
	const int iCharWidth = w*2/str.GetLength();

	//�����ڴ�DC��λͼ����䱳��
	CBitmap bm;
	bm.CreateCompatibleBitmap(pDC,w,h);
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);	
	CBitmap*pOld=memdc.SelectObject(&bm);
	memdc.FillSolidRect(0,0,w+10,h+10,RGB(255,255,255));

	::SetGraphicsMode(memdc.m_hDC,GM_ADVANCED);//Ϊ������б��׼��

	for(int i = 0 ; i < str.GetLength()/2 ; i++)
	{
		//��������
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

	//�����ݴ浽�ļ�(CFile��CMemFile)
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

CString CVerificationCode::Generate4RandNum()
{
	CString res;
	srand(time(NULL));   // ��Ҫͷ�ļ� time.h,stdlib.h  
	for (int i=0; i<4; ++i)
	{
		CString aa;
		aa.Format(_T("%d"), rand() % 10); // ����0��9 ֮��������
		res += aa;
	}
	return res;	
}
