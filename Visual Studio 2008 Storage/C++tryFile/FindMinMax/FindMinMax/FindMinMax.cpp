#include<iostream>
using namespace std;

//int sum(int a, int b)
//{
//	return(a+b);
//}
//
//int sum(int *a, int *b)
//{
//	*a = *a + 1;
//	return(*a+*b);
//}
//
//void main()
//{
//	int c, d;
//	int x = 3, y = 5;
//	c = sum(x,y);    // �������ݷ�ʽΪ��ֵ����
//	cout<<"x = "<<x<<"\ty = "<<y<<"\tx+y = "<<c<<endl;
//	d = sum(&x, &y); // �������ݷ�ʽΪ����ַ����
//	cout<<"x = "<<x<<"\ty = "<<y<<"\tx+y = "<<d<<endl;
//
//	cout<<"x = "<<x<<"\ty = "<<y<<"\tx+y = "<<sum(x,y)<<endl;
//}


void FindMinMax(int a[], int len, int *min, int *max)
{
	*min = *max = a[0];
	for(int i=1; i<len; i++)
	{
		if(a[i]>*max) 
			*max = a[i];
		if(a[i]<*min) 
			*min = a[i];
	}
}

void FindMinMaxNum(int a[], int len, int min, int max, int *MinNum, int *MaxNum)
{
	*MinNum = *MaxNum = 0;
	for(int j=0; j<len; j++)
	{
		if(a[j]==min) 
			(*MinNum)++;
		if(a[j]==max) 
			(*MaxNum)++;
	}
}

//int* FindMinMaxNum(int a[], int len, int min, int max)
//{
//	int MN[2] = {0, 0};
//	int *M = MN;
//	//M = MN;
//	for(int i=0; i<len; i++)
//	{
//		if(a[i]==max) 
//			MN[0]++;
//		if(a[i]==min) 
//			MN[1]++;
//	}
//	return(M);
//}

void change(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	//int a[6] = {12, 12, 1, 1, 2, 1};
	//int x, y;
	//int MinN, MaxN;

	//FindMinMax(a,6,&x,&y);
	//cout<<x<<ends<<y<<endl;
	//FindMinMaxNum(a,6,x,y,&MinN,&MaxN);
	//cout<<MinN<<ends<<MaxN<<endl;
	//int *M;
	//M = FindMinMaxNum(a,6,x,y);
	//cout<<M[0]<<ends<<M[1]<<endl;



	///////////////////////////////////
	/*int m, n, **a;
	cout<<"����������������";
	cin>>m;
	cout<<"����������������";
	cin>>n;
	cout<<m<<ends<<n<<endl;
	
	cout<<"������ľ����СΪ"<<m<<"*"<<n<<"������������Ԫ��(��������)��";
	for(int i=0; i<m*n; i++)*/
	

	int a[3][3];
	cout<<"����������Ԫ��(��������)��";
	for(int j=0; j<3; j++)
		for(int i=0; i<3; i++)
			cin>>a[i][j];

	cout<<"�������������:"<<endl;
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
			cout<<a[i][j]<<ends;
		cout<<endl;
	}

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(i<j)
				change(&a[i][j], &a[j][i]);
	cout<<"ת�ú�ľ�������:"<<endl;
	for(int j=0; j<3; j++)
	{
		for(int i=0; i<3; i++)
			cout<<a[i][j]<<ends;
		cout<<endl;
	}
}