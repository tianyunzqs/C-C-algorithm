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
		long *outdatasize);	//生成单色位图

	BOOL ShengChengYanZhenMa(CString str,CFile& file);  // 生成汉字验证码

	CString Generate4RandNum();  // 随机生成4位数验证码
};

