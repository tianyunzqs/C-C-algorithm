#include "E:\VS2010Storage\mydll\mydll\circle.h" //包含类声明头文件
#include <stdio.h>
#pragma comment(lib,"mydll.lib")
int main(int argc, char *argv[])
{
	circle c;
	point p(2.0, 2.0);
	c.SetCentre(p);
	c.SetRadius(1.0);
	printf("area:%f\ngirth:%f\n", c.GetArea(), c.GetGirth());
	return 0;
}