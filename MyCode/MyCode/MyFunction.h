#include<fstream>
using namespace std;

//ȡDebug����·������
CString GetApplicationPath();
//PictureToCode����˵��:
//ͨ������������������Ķ������ַ���,������ͼ���е�10����¼�ļ����Ա�,���ͬһλ�õ�ֵ��ͬ,���¼���ƶȼ�1.����
//10���ļ�,�������ƶ���ߵ��ļ����Ӧ��ֵ.codes[]������ÿһ��ֵ��Ӧһ���ļ�.
char PictureToCode(const CString &tupianma);
//Gettezhengma����˵��:
//�����ݺ�����ͼ������,���������ֽڵ���ʽ.1��������RGB 3���ֽ�.���RGB3���ֽ�ֵ������76
//,��ƫ���ɫ,����������1,������0.����������
CString Gettezhengma(int left,int right,int height,BYTE *pSrc,int srcStride,int ComputeValue);
int GetComputeValue(int left,int right,int height,BYTE *pSrc,int srcStride);