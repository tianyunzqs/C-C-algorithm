#pragma once
class CVerificationCode
{
public:
	CVerificationCode(void);
	~CVerificationCode(void);

	BOOL  myCreateBitmap( 
		HDC hDC,  
		HBITMAP hbitmap, 					 
		PBITMAPFILEHEADER &outheadbuf,
		long *outheadsize,					 
		PBITMAPINFO &outinfobuf,
		long *outinfosize,					 
		LPBYTE &outdatabuf,
		long *outdatasize);	//���ɵ�ɫλͼ

	BOOL ShengChengYanZhenMa(CString str,CFile& file);  // ���ɺ�����֤��

	CString Generate4RandNum();  // �������4λ����֤��
};

