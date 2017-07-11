// MyCodeDlg.cpp : ʵ���ļ�
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

// CMyCodeDlg �Ի���
CString strFilePath;   //�ļ��� 



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


// CMyCodeDlg ��Ϣ�������

BOOL CMyCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyCodeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		CDialog::UpdateWindow(); //����windows���ڣ�������ⲽ���ã�ͼƬ��ʾ�����������
		//Show_picture();     //�ػ�ͼƬ����
		if(strFilePath!="")
		{
			CRect rect;
			mPicture.GetClientRect(&rect);     //m_pictureΪPicture Control�ؼ���������ÿؼ����������
			CImage image1;       //ʹ��ͼƬ��
			image1.Load(strFilePath);   //װ��·����ͼƬ��Ϣ��ͼƬ��
			CDC* pDC = mPicture.GetWindowDC();    //�����ʾ�ؼ���DC
			image1.Draw( pDC -> m_hDC,rect);      //ͼƬ���ͼƬ����Draw����
			ReleaseDC(pDC);


	        CRect rect2;
			mPicture2.GetClientRect(&rect2);     //m_pictureΪPicture Control�ؼ���������ÿؼ����������
			CImage image2;       //ʹ��ͼƬ��
			image2.Load(strFilePath);   //װ��·����ͼƬ��Ϣ��ͼƬ��
			
			 if(!image1.IsIndexed())
	 {
	 // ֱ���޸�������ɫ 
	 COLORREF pixel;
	 int maxY = image1.GetHeight(), maxX = image1.GetWidth(); 
	 //byte r,avg,Gmax,Gmin,ThreHold;
	 byte r,avg,Gmax,Gmin;
	  pixel=image1.GetPixel(0,0);
	 Gmax=Gmin=GetRValue(pixel); 
//Ѱ�һҶ����ֵ����Сֵ
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
			
			CDC* pDC2 = mPicture2.GetWindowDC();    //�����ʾ�ؼ���DC
			image2.Draw( pDC2 -> m_hDC,rect2);      //ͼƬ���ͼƬ����Draw����
			ReleaseDC(pDC2);
		}   //�ļ��� 
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyCodeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyCodeDlg::OnBnClickedOk()
{

	//�Ի����� �ı�����ļ�,  _T("*.bmp")�� �򿪵ĶԻ����е�Ĭ��ֵ
	CFileDialog dlg(TRUE, NULL, _T("*.bmp"), OFN_FILEMUSTEXIST|OFN_HIDEREADONLY, _T("image files (*.bmp) |*.bmp |"), this);  
 
	if(dlg.DoModal() == IDOK)  //����û����ȷ�� DoModal�����ǻ�ȡ�û�ѡ����
		{  
				strFilePath=dlg.GetPathName();  //ȡ��ѡ����ļ��� , GetPathName��������û�ѡ����ļ���
		}
	else
		{
				return;							//����û�ѡ�� "ȡ��" ,�򷵻�
		}		

	CRect rect,rect2;                        //��������������
	mPicture.GetClientRect(&rect);     //mPictureΪPicture Control�ؼ���������ÿؼ����������
	mPicture2.GetClientRect(&rect2);     //mPictureΪPicture Control�ؼ���������ÿؼ����������
	CImage image1,image2;					   //ʹ��ͼƬ��
	image1.Load(strFilePath);           //װ��·����ͼƬ��Ϣ��ͼƬ��
	image2.Load(strFilePath);
	 if(!image1.IsIndexed())
	 {
	 // ֱ���޸�������ɫ 
	 COLORREF pixel;
	 int maxY = image1.GetHeight(), maxX = image1.GetWidth(); 
	 //byte r,avg,Gmax,Gmin,ThreHold;
	 byte r,avg,Gmax,Gmin;
	  pixel=image1.GetPixel(0,0);
	 Gmax=Gmin=GetRValue(pixel); 
//Ѱ�һҶ����ֵ����Сֵ
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
	
	CDC* pDC = mPicture.GetWindowDC(); //�����ʾ�ؼ��ľ��
	CDC* pDC2 = mPicture2.GetWindowDC(); //�����ʾ�ؼ��ľ��
	image1.Draw( pDC -> m_hDC,rect);    //ͼƬ���ͼƬ���ƺ���
	image2.Draw( pDC2 -> m_hDC,rect);    //ͼƬ���ͼƬ���ƺ���
	ReleaseDC(pDC);					   //�ͷž���ڴ�
	ReleaseDC(pDC2);	
	
	CString tezhengma1="";			   //��֤�������ַ���1 CString���ֽ��ִ�,ռ���ڴ�� string Ҫ��
	CString tezhengma2="";			   //��֤�������ַ���2
	CString tezhengma3="";			   //��֤�������ַ���3
	CString tezhengma4="";			   //��֤�������ַ���4
	CString tezhengma5="";			   //��֤�������ַ���5



	GDI_Plus_Controler.Initialize();   //GDIͼ���豸�ӿڿ�������ʼ��
	using namespace Gdiplus;		   //����Gdiplus�����ռ�
	Bitmap bmpSrc(strFilePath.AllocSysString(),FALSE);  //BMPͼƬ��,����λͼ����


	int widthSrc = bmpSrc.GetWidth();			//��ȡ��  GetWidth����
	int heightSrc = bmpSrc.GetHeight();         //��ȡ��  GetHeight����
	
	Rect rectSrc(0, 0, widthSrc, heightSrc);    //���������� ,����Ϊͼ�����Ͻ�����,ͼ���,ͼ���
	BitmapData bmDataSrc;                       //����λͼ������
	ZeroMemory(&bmDataSrc, sizeof(bmDataSrc));  //ʹbmDataSrcָ����������

	bmpSrc.LockBits(&rectSrc,
		ImageLockModeRead,
		PixelFormat24bppRGB,
		&bmDataSrc
		);                                       //��������Ϣ�洢�� ָ����ָ��Ļ�����
	int srcStride = bmDataSrc.Stride;            //��ȿ�� ÿ����3�ֽ�,3*width = Stride ,��Stride �����������4��������
	BYTE *pSrc = (BYTE *)((void *)bmDataSrc.Scan0); //ָ��ָ�� λͼ�ĵ�0�����ص�ַ
	

	    int ComputeValue1=GetComputeValue(0,10,heightSrc,pSrc,srcStride);
		int ComputeValue2=GetComputeValue(10,20,heightSrc,pSrc,srcStride);
		int ComputeValue3=GetComputeValue(20,30,heightSrc,pSrc,srcStride);
		int ComputeValue4=GetComputeValue(30,40,heightSrc,pSrc,srcStride);
		int ComputeValue5=GetComputeValue(40,50,heightSrc,pSrc,srcStride);

        //*****�ָ�ͼƬ******
		tezhengma1=Gettezhengma(0,10,heightSrc,pSrc,srcStride,ComputeValue1);    //��ȡ�����뺯�� ����1:ͼ��X�� �� ����2:ͼ��X�� ��  
		tezhengma2=Gettezhengma(10,20,heightSrc,pSrc,srcStride,ComputeValue2);   //               ����3:ͼ���     ����4:ͼ��ָ��
		tezhengma3=Gettezhengma(20,30,heightSrc,pSrc,srcStride,ComputeValue3);   //               ����5:��ȿ��
		tezhengma4=Gettezhengma(30,40,heightSrc,pSrc,srcStride,ComputeValue4);
		tezhengma5=Gettezhengma(40,50,heightSrc,pSrc,srcStride,ComputeValue5);
		//*****�ָ�ͼƬ******
		
		char code1,code2,code3,code4,code5;                         //�����ַ�����,����������֤��ֵ,����͵��ı���ؼ���ʾ
		code1=PictureToCode(_T(tezhengma1));                        //����������ͼ�����Ա�,�������ƶ���ߵ� 
		code2=PictureToCode(_T(tezhengma2));						//_T�������ǰ�CStringתΪstring 
		code3=PictureToCode(_T(tezhengma3));
		code4=PictureToCode(_T(tezhengma4));
		code5=PictureToCode(_T(tezhengma5));

		CString StaticText;										      //������֤���ַ���
		StaticText.Format("%c%c%c%c%c",code1,code2,code3,code4,code5);//��5λ��֤���ַ�������һ��,Format�����������ǰ��ַ���ʽ����ָ����ʽ .code1��code2��code3��code4��code5�ĸ�ʽ.
		GetDlgItem(IDC_STATIC_1)->SetWindowText(_T(StaticText));      //���ı��ؼ���� GetDlgItem������ͨ���ؼ�ID��ÿؼ����
																	  //,SetWindowText���������ÿؼ�ֵ,_T�����ǰѳ��ַ���תΪstring��׼�ַ�������
}
