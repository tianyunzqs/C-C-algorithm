#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h" 

#ifdef DLL_FILE
class _declspec(dllexport)circle //导出类circle
#else
class _declspec(dllimport)circle //导入类circle
#endif
{
public:
	void SetCentre(const point centrePoint);
	void SetRadius(float r);
	float GetGirth();
	float GetArea();
	circle();
private:
	float radius;
	point centre;
};

#endif