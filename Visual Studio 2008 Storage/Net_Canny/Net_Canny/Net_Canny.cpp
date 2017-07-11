// Net_Canny.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "cv.h"  
#include "cxcore.h"  
#include "highgui.h"  
int main( int argc, char** argv )  
{  
	//����IplImageָ��  
	IplImage* img = NULL;  
	IplImage* cannyImg = NULL;  
	char *filename;  
	filename="D:\\�ҵ��ĵ�\\ͼƬ�ղ�\\1.bmp";  
	img=cvLoadImage(filename,1);  
	//����ͼ��ǿ��ת��ΪGray  
	if((img = cvLoadImage(filename, 0)) != 0 )  
	{  
		//Ϊcanny��Եͼ������ռ�  
		cannyImg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);  
		//canny��Ե���  
		cvCanny(img, cannyImg, 50, 150, 3);  
		//��������  
		cvNamedWindow("src", 1);  
		cvNamedWindow("canny",1);  
		//��ʾͼ��  
		cvShowImage( "src", img );  
		cvShowImage( "canny", cannyImg );  
		cvWaitKey(0); //�ȴ�����  
		//���ٴ���  
		cvDestroyWindow( "src" );  
		cvDestroyWindow( "canny" );  
		//�ͷ�ͼ��  
		cvReleaseImage( &img );  
		cvReleaseImage( &cannyImg );  
		return 0;  
	}  
	return -1;  
}

