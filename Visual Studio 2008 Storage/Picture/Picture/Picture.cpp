// Picture.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/* ͷ�ļ� */

#include <afx.h>

#include <windows.h>

#include <iostream.h>

#include <stdlib.h>

#include <math.h>

#define PI 3.14159265 // ���峣��


// ȫ�ֱ���

int nWidth; //ͼ��Ŀ��

int nHeight; //ͼ��ĸ߶�

int nColorBits; //ÿ��������ռ��λ��

int nColor; //ͼ�����ɫ��

int nLen; //ͼ���ļ��Ĵ�С�����ֽ�����

int nByteWidth; //ͼ��ÿ�е��ֽ���

BYTE *lpBitmap; //ָ��ͼ�����ֽڵ�ָ��

BYTE *lpBits; //ָ��ͼ��ʵ�����ݵ�ָ��

// ��������

BOOL OpenFile(CString FileName);

BOOL SaveFile(CString FileName);

void Smooth3by3();

int GetMidValue(int pixel[],int size);

void DoMedian(int i,int j,int xSize,int ySize,BYTE rgb[]);

void Median(int xSize,int ySize);

void HistogramStat(long bCount[], long gCount[], long rCount[]);

void HistogramEq();

void InvertColor();//��ɫ

void Mirror();//����

void Emerge();//����

void DetectEdge();//��Ե���

void FalseColor();//�ٲ�ɫ

/************************************************************************

* ��������: - OpenFile();

* ����: - CString FileName :ͼ���·�����ļ���

* ����ֵ: - BOOL

* ����: - ��ȡһ��BMPͼ��

************************************************************************/

BOOL OpenFile(CString FileName)
{

	//�����ļ����

	HANDLE hFile = ::CreateFile(FileName,GENERIC_READ,FILE_SHARE_READ,

		NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	if(hFile == 0)

	{

		printf("���ܴ��ļ���������ѡ��!\n");

		return 0;

	}

	//��ȡͼ���ļ�

	DWORD WriteNum;

	BITMAPFILEHEADER BFH; //�ļ�ͷ

	ReadFile(hFile,&BFH,14,&WriteNum,NULL);//��ȡ�ļ�ͷ,��14���ֽ�

	if((BFH.bfType != 'MB')||(WriteNum != sizeof(BITMAPFILEHEADER)))

	{

		printf("����BMPλͼ�ļ�����������!\n");

		return 0;

	}

	nLen = GetFileSize(hFile,NULL)-sizeof(BITMAPFILEHEADER); //��ȡ�ļ��ĳ���

	lpBitmap= new BYTE[nLen];//���ͼ��,����ͼ�����Ϣͷ����ɫ�����������

	ReadFile(hFile,lpBitmap,nLen,&WriteNum,NULL); //��ȡͼ������

	//����ȫ�ֱ�����ֵ

	BITMAPINFOHEADER *BIH = ((BITMAPINFOHEADER *)lpBitmap);

	//ͼ���ļ�����Ϣͷ

	nWidth = BIH->biWidth; //ͼ��Ŀ��

	nHeight = BIH->biHeight; //ͼ��ĸ߶�

	nColorBits = BIH ->biBitCount; //ͼ�����ɫ��

	nByteWidth = (nWidth*nColorBits+31)/32*4; //ͼ���ɨ����

	nColor = (nColorBits>8) ? 0 : (1<<nColorBits); //��ɫ���е���ɫ��

	lpBits = lpBitmap + sizeof(BITMAPINFOHEADER)

		+ sizeof(RGBQUAD)*nColor; //ָ��ͼ�����ݵ�ʵ��λ��

	CloseHandle(hFile); //�ر��ļ����

	return 1;

}

/*************************************************************************

* ��������: - SaveFile();

* ����: - CString FileName - ͼ���·�����ļ���

* ����ֵ: - BOOL

* ����: - ����һ��BMPͼ��

************************************************************************/

BOOL SaveFile(CString FileName)

{

	//����һ���ļ�������ͼ���ļ�

	HANDLE hFile = ::CreateFile(FileName,GENERIC_WRITE,FILE_SHARE_WRITE,

		NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	if(hFile == 0)

	{

		printf("���ܴ����ļ���������ѡ��!\n");

		return 0;

	}

	//����һ���ļ�ͷ,�����浽�������ļ���

	unsigned long WriteNum;

	BITMAPFILEHEADER BFH;

	BFH.bfType = 'MB';

	BFH.bfSize = nLen + sizeof(BITMAPFILEHEADER);

	BFH.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)

		+ nColor * sizeof(RGBQUAD);

	BFH.bfReserved1 = BFH.bfReserved2 = 0;

	WriteFile(hFile,&BFH,sizeof(BITMAPFILEHEADER),&WriteNum,NULL);

	//����ı��λͼ�ļ�����

	WriteFile(hFile,(BITMAPINFOHEADER *)lpBitmap,nLen,&WriteNum,NULL);

	CloseHandle(hFile); //�ر��ļ����

	return 1;

}

/*************************************************************************

* ��������: - HistogramStat();

* ����: - long bCount[];

* - long gCount[];

* - long rCount[];

* ����ֵ: - ��

* ����: - ͳ��ͼ������Ҷȵ����صĸ���,

* ����256ɫͼ��,����ֵ����bCount[]��

* ���ɫͼ����ɫ����ɫ����ɫ�������η�����������������

**************************************************************************/

void HistogramStat(long bCount[], long gCount[], long rCount[])

{

	// ����ֵ

	for (int i = 0; i < 256; i++)

	{

		rCount[i] = 0;

		gCount[i] = 0;

		bCount[i] = 0;

	}

	//ͳ�Ƹ����Ҷȼ����صĸ���

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

* ��������: - HistogramEq();

* ����: - ��

* ����ֵ: - ��

* ����: - ֱ��ͼ����

************************************************************************/

void HistogramEq()

{

	//������ɫ����������ӳ���

	BYTE grayMap[256],rMap[256],gMap[256],bMap[256];

	//������ɫ��������ͳ�Ʊ�

	LONG rCount[256],gCount[256],bCount[256];

	LONG i,j;

	//ֱ��ͼͳ�ƣ�ͳ�Ƹ����Ҷȵ����أ�256ɫͼ��Ľ������bCount��

	HistogramStat(bCount,gCount,rCount);

	//����ÿ���Ҷȼ���Ӧ���µ�����ֵ

	double TotalNum = nWidth * nHeight;

	for (i = 0; i < 256; i++)

	{

		if(nColorBits == 8)

		{

			long grayTemp = 0;

			for (j=0;j<=i;j++) grayTemp += bCount[j];

			grayMap[i] = (BYTE) (grayTemp * 255/TotalNum);//��Ӧ���»Ҷ�ֵ

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

			//�����Ӧ���»Ҷ�ֵ

			rMap[i] = (BYTE) (rTemp * 255/TotalNum);

			gMap[i] = (BYTE) (gTemp * 255/TotalNum);

			bMap[i] = (BYTE) (bTemp * 255/TotalNum);

		}

	}

	//�����صĻҶȸ���ֵ

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

* ��������: - Smooth3by3();

* ����: - ��

* ����ֵ: - �� | 1 1 1 |

* ����: - ��ͼ�����3 x 3ƽ��,ƽ������Ϊ 1/9 | 1 1 1 |

* | 1 1 1 |

**********************************************************************/

void Smooth3by3()

{

	BYTE *lpTemp = new BYTE[nByteWidth*nHeight];

	memcpy(lpTemp,lpBits,nByteWidth*nHeight);

	for(int y = 1; y < nHeight-1; y++) //ͼ�����

	{

		for(int x = 1; x < nWidth-1; x++) //ͼ�����

		{

			//�����y��,��j������ƽ����Ľ��

			int sb = 0, sg = 0, sr = 0;

			for(int y1 = -1; y1 <= 1; y1++)

			{

				for(int x1 = -1; x1 <= 1; x1++)

				{

					if(nColorBits == 24) //���ɫͼ������

					{

						sb+=lpBits[(y+y1)*nByteWidth+(x+x1)*3];

						sg+=lpBits[(y+y1)*nByteWidth+(x+x1)*3+1];

						sr+=lpBits[(y+y1)*nByteWidth+(x+x1)*3+2];

					}

					else if(nColorBits == 8) //8λͼ������

					{

						sb+=lpBits[(y+y1)*nByteWidth+(x+x1)];

					}

				}//end if x1

			}//end if y1

			//ƽ����Ľ��������������lpTemp��

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

	//�޸�ͼ�������,���ͷ���ʱ����

	memcpy(lpBits,lpTemp,nByteWidth*nHeight);

	delete []lpTemp;

}

/*************************************************************************

*

* ����: ������

*

************************************************************************/

void main()

{

	char OpenFileName[100];

	char SaveFileName[100];

	printf("����������ͼ��·��:\n");

	gets(OpenFileName);

	printf("���洦��ͼ������·��:\n");

	gets(SaveFileName);

	//����ͼ��

	if(!OpenFile(OpenFileName))

		exit (1);

	Mirror();

	// InvertColor();

	// DetectEdge();

	// FalseColor();

	// Emerge();

	// Smooth3by3();

	// HistogramEq();//ֱ��ͼ����Ϊ��,���������������ֱ�ӵ���Ӧ��������

	//����ͼ��

	SaveFile(SaveFileName);

	delete []lpBitmap;

}


/**********************************************************************

* ��������: - Mirror();

* ����: - ��

* ����ֵ: - ��

* ����: - ��ͼ��������Ҿ���

**********************************************************************/

void Mirror()

{

	BYTE *lpTemp = new BYTE[nByteWidth*nHeight];

	//memcpy(lpTemp,lpBits,nByteWidth*nHeight);

	for(int y = 0; y < nHeight; y++) //ͼ�����

	{

		for(int x = 0; x < nWidth; x++) //ͼ�����

		{

			int ny = y * nByteWidth;

			if(nColorBits == 24)//���ɫͼ������

			{

				lpTemp[ny +x *3 + 2] = lpBits[ny + (nWidth-1-x) *3 + 2];

				lpTemp[ny +x *3 + 1] = lpBits[ny + (nWidth-1-x) *3 + 1];

				lpTemp[ny +x *3 ] = lpBits[ny + (nWidth-1-x) *3];

			}

			else if(nColorBits == 8)//�Ҷ�ͼ������

			{

				lpTemp[ny + x] = lpBits[ny + nWidth-1-x];

			}

		} // end if for x

	} // end if for y

	//�޸�ͼ�������,���ͷ���ʱ����

	memcpy(lpBits,lpTemp,nByteWidth*nHeight);

	delete []lpTemp;

}