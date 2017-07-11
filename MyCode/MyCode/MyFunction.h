#include<fstream>
using namespace std;

//取Debug绝对路径方法
CString GetApplicationPath();
//PictureToCode函数说明:
//通过参数传进来特征码的二进制字符串,把它与图库中的10个记录文件做对比,如果同一位置的值相同,则记录相似度加1.遍历
//10个文件,返回相似度最高的文件相对应的值.codes[]数组中每一个值对应一个文件.
char PictureToCode(const CString &tupianma);
//Gettezhengma函数说明:
//以先纵后横遍历图象区域,这里是以字节的形式.1个像素是RGB 3个字节.如果RGB3个字节值均大于76
//,则偏向白色,把特征码置1,否则置0.返回特征码
CString Gettezhengma(int left,int right,int height,BYTE *pSrc,int srcStride,int ComputeValue);
int GetComputeValue(int left,int right,int height,BYTE *pSrc,int srcStride);