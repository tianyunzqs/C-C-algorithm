// VideoPlayer.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include "highgui.h"

int main(int argc, char** argv)
{
	cvNamedWindow("��Ƶ���Ŵ���", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture("E:\\CCSԴ�ļ�\\User Guide Video.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if(!frame)
			break;
		cvShowImage("��Ƶ���Ŵ���", frame);
		char c = cvWaitKey(500);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("��Ƶ���Ŵ���");
}

