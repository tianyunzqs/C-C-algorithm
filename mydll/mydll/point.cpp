//�ļ�����point.cpp��point���ʵ��

#ifndef DLL_FILE
#define DLL_FILE
#endif

#include "stdafx.h"
#include "point.h"

//��point��ȱʡ���캯��

point::point()
{
	x = 0.0;
	y = 0.0;
}

//��point�Ĺ��캯��
point::point(float x_coordinate, float y_coordinate)
{
	x = x_coordinate;
	y = y_coordinate;
}
