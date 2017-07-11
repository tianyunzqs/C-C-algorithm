#include "stdafx.h"
#include "MyFunction.h" 

//取Debug绝对路径方法
CString GetApplicationPath()
{
	CString strRet="";    
	char cExeFileName[10000];
	memset(cExeFileName,0,10000);
	if(::GetModuleFileName(NULL,cExeFileName,9999)==0)//GetModuleFileName方法是获得程序文件所在的绝对路径
													  //返回结果包括路径及 EXE 文件名称
		return strRet;
	///////删除文件名称部份///////
	int len=lstrlen(cExeFileName);   //记录cExeFileName文件大小
	int nLastIndex=-1; //最后一个反斜杠的位置，该位置后即为文件名称
	for(int ls=0;ls<len;ls++)
	{
		if(cExeFileName[ls]=='\\')
		  nLastIndex=ls;
	}
	if(nLastIndex <= 0)
		return strRet;
	cExeFileName[nLastIndex]=0; //截断字符串
	strRet=cExeFileName;
	return strRet;
}
//PictureToCode函数说明:
//通过参数传进来特征码的二进制字符串,把它与图库中的10个记录文件做对比,如果同一位置的值相同,则记录相似度加1.遍历
//10个文件,返回相似度最高的文件相对应的值.codes[]数组中每一个值对应一个文件.
char PictureToCode(const CString &tupianma)
{
			string b=_T(tupianma);//_T的作用是把CString 转换为string , 声明字符串记录图片2进制码
			int MaxC=0; //声明int类型变量,记录最大相似度
			char MaxK;	//字符型变量,记录最大相似度的 文件名
			char codes[] = {'0','1','2','3','4','5','6','7','8','9'};	//声明字符型数组,codes[]数组中每一个值对应一个文件
			for (int k=0;k<sizeof(codes);k++)							//循环10次,sizeof(codes)是返回数组元素个数
			{
				CString strFile;				//声明字符串,用来记录文件名
				strFile.Format("c:\\%c.txt",codes[k]); //返回文件名  Format 是格式字符串方法, 格式成 "codes[k]的值 .txt"的形式


				CString strPath=GetApplicationPath();//取程序输出的绝对路径,例如程序文件在 C:\ 下 , 则 strPath 就是 C:\

				
				ifstream myfile;                      //声明 读文件流
				//myfile.open(strPath + "\\code\\" + strFile,ios::in); //打开文件,文件路径为 strPath + \\code\\ + codes[k].txt .类似 c:\code\1.txt的形式

				myfile.open(strFile,ios::in); //打开文件,文件路径为 strPath + \\code\\ + codes[k].txt .类似 c:\code\1.txt的形式

				if(!myfile)							//没有文件
				{  
					exit(1);                        //退出程序
				} 
				char ch;                            //声明字符,用来读文件
				string tupianma="";					//声明字符串,用来记录文件
				while(myfile.get(ch))				//读文件,把一个字节返回到 ch 变量中
				tupianma+=ch;						//把ch变量累加到tupianma字符串中
				myfile.close();						//关闭文件

				int c=0;//相似点

				//********比较文件,比较相似点********
				for(string::size_type ix=0;ix!=tupianma.size();++ix)  //string::size_type是string中的一个类型,实际就是int型,
				{                                                     //tupianma.size()是tupianma中包含的字符的个数
					if(tupianma[ix]==b[ix])							  //如果相同位置字符相等
					{
						c++;									      //相似点加1
					}
				}
				//********比较文件,比较相似点********

				if(c > MaxC)  //记录相似点最大的文件名, C为本次比较的相似点值, MaxC为历次比较中最大的值
				{
					MaxC=c;            //如果发现更大的相似值 ,则用MaxC记录
					MaxK=codes[k];	   //MaxK记录文件名
				}
			}
			return MaxK;               //返回文件名
}
//Gettezhengma函数说明:
//以先纵后横遍历图象区域,这里是以字节的形式.1个像素是RGB 3个字节.如果RGB3个字节值均大于76
//,则偏向白色,把特征码置1,否则置0.返回特征码
CString Gettezhengma(int left,int right,int height,BYTE *pSrc,int srcStride,int ComputeValue)
{   CString tezhengma; //声明CString类字符串，CString长字节字串,占的内存比 string 要多
    CString temp;
	for(int y=0; y < height; y++ ) 
	{   //遍历图片像素 长
		for(int x=left; x <right;x++) 
		{//遍历图片像素 宽
			int c = ComputeValue;
			int d;
			//******二值化******
			if((pSrc[y*srcStride+(x*3)]<c) & (pSrc[y*srcStride+(x*3)+1]<c) & (pSrc[y*srcStride+(x*3)+2]<c))
			{
				d=0;
			}
			else
			{
				d=1;
			}
			//******二值化******
			temp=tezhengma;                   //临时记录字符串
			tezhengma.Format("%s%d", temp, d);//把临时记录汇总到tezhengma字符串,记录像素值
		}
	}
	return tezhengma;  //返回值
}

int GetComputeValue(int left,int right,int height,BYTE *pSrc,int srcStride)
{  
	//int bytes = (right-left)*height;
	//int *GrayValues = new int[bytes];
	int GrayValues[12000];
	int index=0;

	for(int y=0; y < height; y++ ) 
	{   //遍历图片像素 长
		for(int x=left; x <right;x++) 
		{//遍历图片像素 宽
			GrayValues[index]=*pSrc;
			index++;
			pSrc++;
		}
	}
	int LenGrayValues=0;
	for(int x=0; x <12000;x++) 
		{
			if(GrayValues[x]!=-858993460)
			{
				LenGrayValues++;
			}
		}
	int maxGray = 0;
	int minGray = 255;
	int temp;
    int countPixel[256];
	for(int i=0;i<LenGrayValues;i++)
	{countPixel[i]=0;}
    for (int i = 0; i < 240; i++)
     {
        temp = GrayValues[i];
        countPixel[temp]++;
		if(temp>maxGray)
			{
				maxGray=temp;
			}
		if(temp < minGray)
			{
				minGray=temp;		
			}

	}
	int T,oldT,numerator, denominator;
	double mu1, mu2;
	T = oldT = ( maxGray + minGray ) / 2;
	do
	{
								oldT = T;
                                numerator = denominator = 0;
                                for (int i = minGray; i < T; i++)
                                {
                                    numerator += i * countPixel[i];
                                    denominator += countPixel[i];
                                }
								mu1 = numerator / denominator;
                                numerator = denominator = 0;
                                for (int i = T; i <= maxGray; i++)
                                {
                                    numerator += i * countPixel[i];
                                    denominator += countPixel[i];
                                }
								mu2 = numerator / denominator;
                                T = (int)(mu1 + mu2) / 2;
	}
	while(T != oldT);

	return T;  //返回值
}