//自动切割一寸照片的程序源码：
// HelloOpenCV.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <ctype.h>
#include <iostream>
using namespace std;
using namespace cv;
static CvMemStorage* storage=0;
static CvHaarClassifierCascade* cascade=0;
void detect_and_draw(IplImage* image,const char* name);
//const char* cascade_name="F:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";
const char* cascade_name="haarcascade_frontalface_alt2.xml";

int main(int argc, char* argv[])
{
	cascade_name="F:\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";
	cascade=(CvHaarClassifierCascade*)cvLoad(cascade_name,0,0,0);
	if(!cascade)
	{
		fprintf(stderr,"ERROR:Could not load classifier cascade\n");
		fprintf(stderr,"Usage:HelloOpenCV [filename]\n");
		return -1;
	}
	storage=cvCreateMemStorage(0);
	// 遍历目录
	WIN32_FIND_DATAA FileData;
	HANDLE hFind;
	hFind=FindFirstFileA((LPCSTR)"*.jpg",&FileData);
	if(hFind==INVALID_HANDLE_VALUE)
	{
		cout<<"Invalid file handle. GetLastError reports %d\n"<<GetLastError()<<endl;
		return 0;
	}
	do
	{
		string name("");
		name.append(FileData.cFileName);
		IplImage* image = cvLoadImage(name.c_str(), 1 );
		if( image )
		{
			detect_and_draw( image,name.c_str() );
			//cvWaitKey(0);
			cvReleaseImage( &image );
		}
	}while(FindNextFileA(hFind,&FileData));
	FindClose(&hFind);
	cvDestroyWindow("result");
	return 0;
}

void detect_and_draw( IplImage* img,const char* name )
{
	// 缩放比例
	double scale = 1.0;
	// 建立一个空的灰度图
	// cvCreateImage Creates an image header and allocates the image data
	IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
	// 缩放
	// cvRound Rounds floating-point number to the nearest integer
	IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
		cvRound (img->height/scale)),
		8, 1 );
	int i;
	// 转换
	// cvVctColor Converts an image from one color space to another.
	cvCvtColor( img, gray, CV_BGR2GRAY );
	// 构建小图
	cvResize( gray, small_img, CV_INTER_LINEAR );
	// 灰度图直方图均衡化
	cvEqualizeHist( small_img, small_img );
	// 建立存储区
	cvClearMemStorage( storage );
	if( cascade )
	{
		double t = (double)cvGetTickCount();
		// 设置最小人脸像素
		CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage,
			1.1, 28, 0,
			cvSize(80, 80),
			cvSize(200,200));
		t = (double)cvGetTickCount() - t;
		//cout<<"检测时间"<<t/((double)cvGetTickFrequency()*1000)<<"ms"<<endl;;
		if(!faces){
			cout<<"哎呀，你整个什么图片来骗老子啊？怎么就没找到人像呢？"<<endl;
		}

		for( i = 0; i < (faces ? faces->total : 0); i++ )
		{
			CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
			// 295*413 头像宽度适应150,顶部预留40像素
			CvPoint pt1,pt2;
			float xradio=float(r->width)/float(145);
			// 面部区域向左扩大75px
			pt1.x = (r->x-xradio*75)*scale;
			// 面部区域向右扩大75px
			pt2.x = (r->x+r->width+xradio*75)*scale;
			// 如果计算出来的宽度值超出图片边界
			if(pt1.x<0){
				pt1.x=0;
			}
			if(pt2.x>img->width){
				pt2.x=img->width;
			}
			// 面部区域向上扩展100px
			pt1.y = (r->y-100*xradio)*scale;
			// 矩形区域的下边缘计算
			pt2.y = (r->y+313*xradio)*scale;

			// 如果计算出来的高度值超出边界
			if(pt2.y>img->height){
				pt1.y=0;
				pt2.y=img->height;
			}
			// 画出寸照边框
			//cvRectangle( img, pt1, pt2, CV_RGB(0,255,0), 2, 8, 0 );  
			if(((pt2.x-pt1.x)>=295*xradio)&&((pt2.y-pt1.y)>=413*xradio)){
				cvSetImageROI(img,cvRect(pt1.x,pt1.y,pt2.x-pt1.x,pt2.y-pt1.y));
			}

			if((pt2.x-pt1.x)<295*xradio){
				float h=float(413*(pt2.x-pt1.x)/295);
				cvSetImageROI(img,cvRect(pt1.x,pt1.y,pt2.x-pt1.x,h));
			}
			if((pt2.y-pt1.y)<413*xradio){
				// 由于高度不够，我们使用整张图片的高度，宽度按高度折合
				float w=float(295*pt2.y/413);
				float tw=float((pt2.x-pt1.x)-w)/2;
				cvSetImageROI(img,cvRect(pt1.x+tw,0,w,pt2.y));
			}
			// 创建一寸照片
			IplImage* one_inch_img=cvCreateImage(cvSize(295,413),img->depth,img->nChannels);
			cvResize( img, one_inch_img,CV_INTER_LINEAR );
			string sname("imgs/");
			sname.append(name);
			cvSaveImage(sname.c_str(),one_inch_img);
		}
		cvReleaseImage( &gray );
		cvReleaseImage( &small_img );

	}
	cout<<endl;
}

