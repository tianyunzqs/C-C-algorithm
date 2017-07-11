// Picture.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/* 头文件 */

#include <afx.h>

#include <windows.h>

#include <iostream.h>

#include <stdlib.h>

#include <math.h>

#define PI 3.14159265 // 定义常量


// 全局变量

int nWidth; //图像的宽度

int nHeight; //图像的高度

int nColorBits; //每个像素所占的位数

int nColor; //图像的颜色数

int nLen; //图像文件的大小，以字节数计

int nByteWidth; //图像每行的字节数

BYTE *lpBitmap; //指向图像首字节的指针

BYTE *lpBits; //指向图像实际数据的指针

// 函数声明

BOOL OpenFile(CString FileName);

BOOL SaveFile(CString FileName);

void Smooth3by3();

int GetMidValue(int pixel[],int size);

void DoMedian(int i,int j,int xSize,int ySize,BYTE rgb[]);

void Median(int xSize,int ySize);

void HistogramStat(long bCount[], long gCount[], long rCount[]);

void HistogramEq();

void InvertColor();//反色

void Mirror();//镜像

void Emerge();//浮雕

void DetectEdge();//边缘检测

void FalseColor();//假彩色

/************************************************************************

* 函数名称: - OpenFile();

* 参数: - CString FileName :图像的路径和文件名

* 返回值: - BOOL

* 功能: - 读取一幅BMP图像

************************************************************************/

BOOL OpenFile(CString FileName)
{

	//创建文件句柄

	HANDLE hFile = ::CreateFile(FileName,GENERIC_READ,FILE_SHARE_READ,

		NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	if(hFile == 0)

	{

		printf("不能打开文件，请重新选择!\n");

		return 0;

	}

	//读取图像文件

	DWORD WriteNum;

	BITMAPFILEHEADER BFH; //文件头

	ReadFile(hFile,&BFH,14,&WriteNum,NULL);//读取文件头,共14个字节

	if((BFH.bfType != 'MB')||(WriteNum != sizeof(BITMAPFILEHEADER)))

	{

		printf("不是BMP位图文件或数据有误!\n");

		return 0;

	}

	nLen = GetFileSize(hFile,NULL)-sizeof(BITMAPFILEHEADER); //获取文件的长度

	lpBitmap= new BYTE[nLen];//存放图像,包括图像的信息头、调色板和像素数据

	ReadFile(hFile,lpBitmap,nLen,&WriteNum,NULL); //读取图像数据

	//设置全局变量的值

	BITMAPINFOHEADER *BIH = ((BITMAPINFOHEADER *)lpBitmap);

	//图像文件的信息头

	nWidth = BIH->biWidth; //图像的宽度

	nHeight = BIH->biHeight; //图像的高度

	nColorBits = BIH ->biBitCount; //图像的颜色数

	nByteWidth = (nWidth*nColorBits+31)/32*4; //图像的扫描宽度

	nColor = (nColorBits>8) ? 0 : (1<<nColorBits); //调色板中的颜色数

	lpBits = lpBitmap + sizeof(BITMAPINFOHEADER)

		+ sizeof(RGBQUAD)*nColor; //指向图像数据的实际位置

	CloseHandle(hFile); //关闭文件句柄

	return 1;

}

/*************************************************************************

* 函数名称: - SaveFile();

* 参数: - CString FileName - 图像的路径和文件名

* 返回值: - BOOL

* 功能: - 保存一幅BMP图像

************************************************************************/

BOOL SaveFile(CString FileName)

{

	//创建一个文件来保存图像文件

	HANDLE hFile = ::CreateFile(FileName,GENERIC_WRITE,FILE_SHARE_WRITE,

		NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	if(hFile == 0)

	{

		printf("不能创建文件，请重新选择!\n");

		return 0;

	}

	//创建一个文件头,并保存到创建的文件中

	unsigned long WriteNum;

	BITMAPFILEHEADER BFH;

	BFH.bfType = 'MB';

	BFH.bfSize = nLen + sizeof(BITMAPFILEHEADER);

	BFH.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)

		+ nColor * sizeof(RGBQUAD);

	BFH.bfReserved1 = BFH.bfReserved2 = 0;

	WriteFile(hFile,&BFH,sizeof(BITMAPFILEHEADER),&WriteNum,NULL);

	//保存改变的位图文件数据

	WriteFile(hFile,(BITMAPINFOHEADER *)lpBitmap,nLen,&WriteNum,NULL);

	CloseHandle(hFile); //关闭文件句柄

	return 1;

}

/*************************************************************************

* 函数名称: - HistogramStat();

* 参数: - long bCount[];

* - long gCount[];

* - long rCount[];

* 返回值: - 无

* 功能: - 统计图像各级灰度的像素的个数,

* 当是256色图像,返回值放在bCount[]中

* 真彩色图像蓝色、绿色、红色分量依次放在三个参数变量中

**************************************************************************/

void HistogramStat(long bCount[], long gCount[], long rCount[])

{

	// 赋初值

	for (int i = 0; i < 256; i++)

	{

		rCount[i] = 0;

		gCount[i] = 0;

		bCount[i] = 0;

	}

	//统计各个灰度级像素的个数

	for (i=0;i<nHeight;i++)

	{

		for (int j=0;j<nWidth;j++)

		{

			if(nColorBits == 8)

			{

				unsigned char *pData = lpBits + i * nByteWidth + j;

				bCount[*pData]++;

			}

			else if(nColorBits == 24)

			{

				unsigned char *pData = lpBits + i * nByteWidth + j*3;

				bCount[*pData]++;

				gCount[*(pData+1)]++;

				rCount[*(pData+2)]++;

			}

		}

	}

}

/*************************************************************************

* 函数名称: - HistogramEq();

* 参数: - 无

* 返回值: - 无

* 功能: - 直方图均衡

************************************************************************/

void HistogramEq()

{

	//各个颜色分量的亮度映射表

	BYTE grayMap[256],rMap[256],gMap[256],bMap[256];

	//各个颜色分量亮度统计表

	LONG rCount[256],gCount[256],bCount[256];

	LONG i,j;

	//直方图统计，统计各个灰度的像素，256色图像的结果放在bCount中

	HistogramStat(bCount,gCount,rCount);

	//计算每个灰度级对应的新的像素值

	double TotalNum = nWidth * nHeight;

	for (i = 0; i < 256; i++)

	{

		if(nColorBits == 8)

		{

			long grayTemp = 0;

			for (j=0;j<=i;j++) grayTemp += bCount[j];

			grayMap[i] = (BYTE) (grayTemp * 255/TotalNum);//对应的新灰度值

		}

		else if(nColorBits == 24)

		{

			long rTemp = 0, gTemp = 0, bTemp = 0;

			for (j = 0; j <= i ; j++)

			{

				rTemp += rCount[j];

				gTemp += gCount[j];

				bTemp += bCount[j];

			}

			//计算对应的新灰度值

			rMap[i] = (BYTE) (rTemp * 255/TotalNum);

			gMap[i] = (BYTE) (gTemp * 255/TotalNum);

			bMap[i] = (BYTE) (bTemp * 255/TotalNum);

		}

	}

	//对像素的灰度赋新值

	for (i = 0; i < nHeight; i++)

	{

		for(j = 0; j < nWidth; j++)

		{

			if(nColorBits == 8)

			{

				unsigned char *pData = lpBits + i*nByteWidth+j;

				*pData = grayMap[*pData];

			}

			else if(nColorBits == 24)

			{

				unsigned char *pData = lpBits + i*nByteWidth + j*3;

				*pData = bMap[*pData];

				*(pData+1) = gMap[*(pData+1)];

				*(pData+2) = rMap[*(pData+2)];

			}

		}

	}

}

/**********************************************************************

* 函数名称: - Smooth3by3();

* 参数: - 无

* 返回值: - 无 | 1 1 1 |

* 功能: - 对图像进行3 x 3平滑,平滑算子为 1/9 | 1 1 1 |

* | 1 1 1 |

**********************************************************************/

void Smooth3by3()

{

	BYTE *lpTemp = new BYTE[nByteWidth*nHeight];

	memcpy(lpTemp,lpBits,nByteWidth*nHeight);

	for(int y = 1; y < nHeight-1; y++) //图像的行

	{

		for(int x = 1; x < nWidth-1; x++) //图像的列

		{

			//计算第y行,第j列像素平滑后的结果

			int sb = 0, sg = 0, sr = 0;

			for(int y1 = -1; y1 <= 1; y1++)

			{

				for(int x1 = -1; x1 <= 1; x1++)

				{

					if(nColorBits == 24) //真彩色图像的情况

					{

						sb+=lpBits[(y+y1)*nByteWidth+(x+x1)*3];

						sg+=lpBits[(y+y1)*nByteWidth+(x+x1)*3+1];

						sr+=lpBits[(y+y1)*nByteWidth+(x+x1)*3+2];

					}

					else if(nColorBits == 8) //8位图像的情况

					{

						sb+=lpBits[(y+y1)*nByteWidth+(x+x1)];

					}

				}//end if x1

			}//end if y1

			//平滑后的结果保存在数据在lpTemp中

			if(nColorBits == 24)

			{

				lpTemp[y * nByteWidth +x *3 + 2] = sr/9;

				lpTemp[y * nByteWidth +x *3 + 1] = sg/9;

				lpTemp[y * nByteWidth +x *3 ] = sb/9;

			}

			else if(nColorBits == 8)

			{

				lpTemp[y * nByteWidth + x] = sb/9;

			}

		} // end if for x

	} // end if for y

	//修改图像的数据,并释放临时变量

	memcpy(lpBits,lpTemp,nByteWidth*nHeight);

	delete []lpTemp;

}

/*************************************************************************

*

* 功能: 主程序

*

************************************************************************/

void main()

{

	char OpenFileName[100];

	char SaveFileName[100];

	printf("输入待处理的图像路径:\n");

	gets(OpenFileName);

	printf("保存处理图像结果的路径:\n");

	gets(SaveFileName);

	//输入图像

	if(!OpenFile(OpenFileName))

		exit (1);

	Mirror();

	// InvertColor();

	// DetectEdge();

	// FalseColor();

	// Emerge();

	// Smooth3by3();

	// HistogramEq();//直方图均衡为例,如果想做其它处理，直接调相应函数即可

	//保存图像

	SaveFile(SaveFileName);

	delete []lpBitmap;

}


/**********************************************************************

* 函数名称: - Mirror();

* 参数: - 无

* 返回值: - 无

* 功能: - 对图像进行左右镜像

**********************************************************************/

void Mirror()

{

	BYTE *lpTemp = new BYTE[nByteWidth*nHeight];

	//memcpy(lpTemp,lpBits,nByteWidth*nHeight);

	for(int y = 0; y < nHeight; y++) //图像的行

	{

		for(int x = 0; x < nWidth; x++) //图像的列

		{

			int ny = y * nByteWidth;

			if(nColorBits == 24)//真彩色图像的情况

			{

				lpTemp[ny +x *3 + 2] = lpBits[ny + (nWidth-1-x) *3 + 2];

				lpTemp[ny +x *3 + 1] = lpBits[ny + (nWidth-1-x) *3 + 1];

				lpTemp[ny +x *3 ] = lpBits[ny + (nWidth-1-x) *3];

			}

			else if(nColorBits == 8)//灰度图像的情况

			{

				lpTemp[ny + x] = lpBits[ny + nWidth-1-x];

			}

		} // end if for x

	} // end if for y

	//修改图像的数据,并释放临时变量

	memcpy(lpBits,lpTemp,nByteWidth*nHeight);

	delete []lpTemp;

}