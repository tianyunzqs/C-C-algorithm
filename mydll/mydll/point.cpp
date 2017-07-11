//文件名：point.cpp，point类的实现

#ifndef DLL_FILE
#define DLL_FILE
#endif

#include "stdafx.h"
#include "point.h"

//类point的缺省构造函数

point::point()
{
	x = 0.0;
	y = 0.0;
}

//类point的构造函数
point::point(float x_coordinate, float y_coordinate)
{
	x = x_coordinate;
	y = y_coordinate;
}
