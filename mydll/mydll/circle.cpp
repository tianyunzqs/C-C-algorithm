#ifndef DLL_FILE
#define DLL_FILE
#endif

#include "stdafx.h"
#include "circle.h"
#define PI 3.1415926

//circle类的构造函数
circle::circle()
{
	centre = point(0, 0);
	radius = 0;
}

//得到圆的面积
float circle::GetArea()
{
	return PI *radius * radius;
}

//得到圆的周长
float circle::GetGirth()
{
	return 2 *PI * radius;
}

//设置圆心坐标
void circle::SetCentre(const point centrePoint)
{
	centre = centrePoint;
}

//设置圆的半径
void circle::SetRadius(float r)
{
	radius = r;
}