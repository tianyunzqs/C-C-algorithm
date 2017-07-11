// LoadImage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "highgui.h"
#include "cv.h"
using namespace cv;

int main()
{
	Mat image = imread("E:\\Visual Studio 2008 Storage\\Image Storage\\WALL.BMP");
	cvNamedWindow("MyPicture");
	imshow("MyPicture",image);
	waitKey(0);
	return 0;
}
/*
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <stdio.h> 
using namespace std;
using namespace cv;
int main()
{
	const char* imagename = "1.bmp";
	Mat img = imread(imagename);
	if(img.empty())
	{
		fprintf(stderr, "Can not load image %s\n", imagename);
		return -1;
	}
	imshow("image", img);
	waitKey();
}*/