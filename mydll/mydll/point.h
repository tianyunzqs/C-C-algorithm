#ifndef POINT_H
#define POINT_H

#ifdef DLL_FILE
class _declspec(dllexport) point //导出类point
#else
class _declspec(dllimport) point //导入类point
#endif
{
public:
	float y;
	float x;
	point();
	point(float x_coordinate, float y_coordinate);
};
#endif