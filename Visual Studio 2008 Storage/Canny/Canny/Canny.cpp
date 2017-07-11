// Canny.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <highgui.h>  
#include <cv.h>  
#include <cxcore.h>  //人脸识别的一个库文件  

//Canny:Implements Canny algorithm for edge detection.  
int main( int argc, char** argv )  
{  
	IplImage* src = NULL;  
	IplImage* dst = NULL;  

	//载入图像，转换为灰度图  
	src = cvLoadImage( "d:\\我的文档\\图片收藏\\1.bmp", 0 );    
	//为canny边缘图像申请空间，1表示单通道灰度图  
	dst = cvCreateImage( cvGetSize( src ), IPL_DEPTH_8U, 1 );   
	cvCanny( src, dst, 50, 150, 3 );//边缘检测  
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

