// Canny.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <highgui.h>  
#include <cv.h>  
#include <cxcore.h>  //����ʶ���һ�����ļ�  

//Canny:Implements Canny algorithm for edge detection.  
int main( int argc, char** argv )  
{  
	IplImage* src = NULL;  
	IplImage* dst = NULL;  

	//����ͼ��ת��Ϊ�Ҷ�ͼ  
	src = cvLoadImage( "d:\\�ҵ��ĵ�\\ͼƬ�ղ�\\1.bmp", 0 );    
	//Ϊcanny��Եͼ������ռ䣬1��ʾ��ͨ���Ҷ�ͼ  
	dst = cvCreateImage( cvGetSize( src ), IPL_DEPTH_8U, 1 );   
	cvCanny( src, dst, 50, 150, 3 );//��Ե���  
	cvNamedWindow( "src", 1 );  
	cvNamedWindow( "canny", 1 );  
	cvShowImage( "src", src );  
	cvShowImage( "canny", dst );  
	cvWaitKey(0);  

	cvReleaseImage( &src );  
	cvReleaseImage( &dst );  
	cvDestroyAllWindows();  
	return 0;  

}

