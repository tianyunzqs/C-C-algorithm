// VideoPlayer.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "highgui.h"

int main(int argc, char** argv)
{
	cvNamedWindow("视频播放窗口", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("E:\\CCS源文件\\User Guide Video.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if(!frame)
			break;
		cvShowImage("视频播放窗口", frame);
		char c = cvWaitKey(500);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("视频播放窗口");
}

