#include "stdafx.h"
#include "MyFunction.h" 

//ȡDebug����·������
CString GetApplicationPath()
{
	CString strRet="";    
	char cExeFileName[10000];
	memset(cExeFileName,0,10000);
	if(::GetModuleFileName(NULL,cExeFileName,9999)==0)//GetModuleFileName�����ǻ�ó����ļ����ڵľ���·��
													  //���ؽ������·���� EXE �ļ�����
		return strRet;
	///////ɾ���ļ����Ʋ���///////
	int len=lstrlen(cExeFileName);   //��¼cExeFileName�ļ���С
	int nLastIndex=-1; //���һ����б�ܵ�λ�ã���λ�ú�Ϊ�ļ�����
	for(int ls=0;ls<len;ls++)
	{
		if(cExeFileName[ls]=='\\')
		  nLastIndex=ls;
	}
	if(nLastIndex <= 0)
		return strRet;
	cExeFileName[nLastIndex]=0; //�ض��ַ���
	strRet=cExeFileName;
	return strRet;
}
//PictureToCode����˵��:
//ͨ������������������Ķ������ַ���,������ͼ���е�10����¼�ļ����Ա�,���ͬһλ�õ�ֵ��ͬ,���¼���ƶȼ�1.����
//10���ļ�,�������ƶ���ߵ��ļ����Ӧ��ֵ.codes[]������ÿһ��ֵ��Ӧһ���ļ�.
char PictureToCode(const CString &tupianma)
{
			string b=_T(tupianma);//_T�������ǰ�CString ת��Ϊstring , �����ַ�����¼ͼƬ2������
			int MaxC=0; //����int���ͱ���,��¼������ƶ�
			char MaxK;	//�ַ��ͱ���,��¼������ƶȵ� �ļ���
			char codes[] = {'0','1','2','3','4','5','6','7','8','9'};	//�����ַ�������,codes[]������ÿһ��ֵ��Ӧһ���ļ�
			for (int k=0;k<sizeof(codes);k++)							//ѭ��10��,sizeof(codes)�Ƿ�������Ԫ�ظ���
			{
				CString strFile;				//�����ַ���,������¼�ļ���
				strFile.Format("c:\\%c.txt",codes[k]); //�����ļ���  Format �Ǹ�ʽ�ַ�������, ��ʽ�� "codes[k]��ֵ .txt"����ʽ


				CString strPath=GetApplicationPath();//ȡ��������ľ���·��,��������ļ��� C:\ �� , �� strPath ���� C:\

				
				ifstream myfile;                      //���� ���ļ���
				//myfile.open(strPath + "\\code\\" + strFile,ios::in); //���ļ�,�ļ�·��Ϊ strPath + \\code\\ + codes[k].txt .���� c:\code\1.txt����ʽ

				myfile.open(strFile,ios::in); //���ļ�,�ļ�·��Ϊ strPath + \\code\\ + codes[k].txt .���� c:\code\1.txt����ʽ

				if(!myfile)							//û���ļ�
				{  
					exit(1);                        //�˳�����
				} 
				char ch;                            //�����ַ�,�������ļ�
				string tupianma="";					//�����ַ���,������¼�ļ�
				while(myfile.get(ch))				//���ļ�,��һ���ֽڷ��ص� ch ������
				tupianma+=ch;						//��ch�����ۼӵ�tupianma�ַ�����
				myfile.close();						//�ر��ļ�

				int c=0;//���Ƶ�

				//********�Ƚ��ļ�,�Ƚ����Ƶ�********
				for(string::size_type ix=0;ix!=tupianma.size();++ix)  //string::size_type��string�е�һ������,ʵ�ʾ���int��,
				{                                                     //tupianma.size()��tupianma�а������ַ��ĸ���
					if(tupianma[ix]==b[ix])							  //�����ͬλ���ַ����
					{
						c++;									      //���Ƶ��1
					}
				}
				//********�Ƚ��ļ�,�Ƚ����Ƶ�********

				if(c > MaxC)  //��¼���Ƶ������ļ���, CΪ���αȽϵ����Ƶ�ֵ, MaxCΪ���αȽ�������ֵ
				{
					MaxC=c;            //������ָ��������ֵ ,����MaxC��¼
					MaxK=codes[k];	   //MaxK��¼�ļ���
				}
			}
			return MaxK;               //�����ļ���
}
//Gettezhengma����˵��:
//�����ݺ�����ͼ������,���������ֽڵ���ʽ.1��������RGB 3���ֽ�.���RGB3���ֽ�ֵ������76
//,��ƫ���ɫ,����������1,������0.����������
CString Gettezhengma(int left,int right,int height,BYTE *pSrc,int srcStride,int ComputeValue)
{   CString tezhengma; //����CString���ַ�����CString���ֽ��ִ�,ռ���ڴ�� string Ҫ��
    CString temp;
	for(int y=0; y < height; y++ ) 
	{   //����ͼƬ���� ��
		for(int x=left; x <right;x++) 
		{//����ͼƬ���� ��
			int c = ComputeValue;
			int d;
			//******��ֵ��******
			if((pSrc[y*srcStride+(x*3)]<c) & (pSrc[y*srcStride+(x*3)+1]<c) & (pSrc[y*srcStride+(x*3)+2]<c))
			{
				d=0;
			}
			else
			{
				d=1;
			}
			//******��ֵ��******
			temp=tezhengma;                   //��ʱ��¼�ַ���
			tezhengma.Format("%s%d", temp, d);//����ʱ��¼���ܵ�tezhengma�ַ���,��¼����ֵ
		}
	}
	return tezhengma;  //����ֵ
}

int GetComputeValue(int left,int right,int height,BYTE *pSrc,int srcStride)
{  
	//int bytes = (right-left)*height;
	//int *GrayValues = new int[bytes];
	int GrayValues[12000];
	int index=0;

	for(int y=0; y < height; y++ ) 
	{   //����ͼƬ���� ��
		for(int x=left; x <right;x++) 
		{//����ͼƬ���� ��
			GrayValues[index]=*pSrc;
			index++;
			pSrc++;
		}
	}
	int LenGrayValues=0;
	for(int x=0; x <12000;x++) 
		{
			if(GrayValues[x]!=-858993460)
			{
				LenGrayValues++;
			}
		}
	int maxGray = 0;
	int minGray = 255;
	int temp;
    int countPixel[256];
	for(int i=0;i<LenGrayValues;i++)
	{countPixel[i]=0;}
    for (int i = 0; i < 240; i++)
     {
        temp = GrayValues[i];
        countPixel[temp]++;
		if(temp>maxGray)
			{
				maxGray=temp;
			}
		if(temp < minGray)
			{
				minGray=temp;		
			}

	}
	int T,oldT,numerator, denominator;
	double mu1, mu2;
	T = oldT = ( maxGray + minGray ) / 2;
	do
	{
								oldT = T;
                                numerator = denominator = 0;
                                for (int i = minGray; i < T; i++)
                                {
                                    numerator += i * countPixel[i];
                                    denominator += countPixel[i];
                                }
								mu1 = numerator / denominator;
                                numerator = denominator = 0;
                                for (int i = T; i <= maxGray; i++)
                                {
                                    numerator += i * countPixel[i];
                                    denominator += countPixel[i];
                                }
								mu2 = numerator / denominator;
                                T = (int)(mu1 + mu2) / 2;
	}
	while(T != oldT);

	return T;  //����ֵ
}