#include <iostream>
using namespace std;
void main()
{
	cout<<sizeof(char)<<endl;        // 1
	cout<<sizeof(short)<<endl;       // 2
	cout<<sizeof(int)<<endl;         // 4
	cout<<sizeof(long)<<endl;        // 4
	cout<<sizeof(long int)<<endl;    // 4
	cout<<sizeof(float)<<endl;       // 4
	cout<<sizeof(double)<<endl;      // 8
	cout<<sizeof(long double)<<endl; // 8
	cout<<sizeof(long long)<<endl;   // 8
	cout<<sizeof(string)<<endl;      // 32

	int a;
	cout<<sizeof(a)<<endl;    // �Ϸ�    
	cout<<sizeof a<<endl;     // �Ϸ�
	//cout<<sizeof int<<endl; // �Ƿ�

	cout<<"------------------------"<<endl;
	char *b1;
	int *b2;
	double *b3;
	cout<<sizeof(b1)<<endl;  // 4
	cout<<sizeof(b2)<<endl;  // 4 
	cout<<sizeof(b3)<<endl;  // 4


	cout<<"------------------------"<<endl;
	int a[5];
	double *b[5];
	double **c[5];
	int (*e)[5];
	int *(*f)[5];
	cout<<sizeof(a)<<endl;  // 20(4*5��������1)
	cout<<sizeof(b)<<endl;  // 20(4*5��������2)
	cout<<sizeof(c)<<endl;  // 20(4*5��������3)
	cout<<sizeof(e)<<endl;  // 4(������4)
	cout<<sizeof(f)<<endl;  // 4(������5)

	int aa[2][5];
	double *bb[2][5];
	double **cc[2][5];
	int (*ee)[2][5];
	int *(*ff)[2][5];
	cout<<sizeof(aa)<<endl;  // 40(4*2*5��������6)
	cout<<sizeof(bb)<<endl;  // 40(4*2*5��������7)
	cout<<sizeof(cc)<<endl;  // 40(4*2*5��������8)
	cout<<sizeof(ee)<<endl;  // 4(������9)
	cout<<sizeof(ff)<<endl;  // 4(������10)

	cout<<"------------------------"<<endl;
	int i = 3;
	int j;
	j = sizeof(++i + ++i);
	printf("i=%d j=%d\n", i, j);

	cout<<"------------------------"<<endl;
	char m;
	int n;     
	double dn;
	cout<<sizeof (m + n)<<endl;  // 4(������1)
	cout<<sizeof (n + n)<<endl;  // 4(������2)
	cout<<sizeof (m * n)<<endl;  // 4(������3)
	cout<<sizeof (m * m)<<endl;  // 4(������4)
	cout<<sizeof (m + dn)<<endl; // 8(������5)
	cout<<sizeof (m + m)<<endl;  // 4(������6)
	cout<<sizeof (2*m)<<endl;    // 4(������7)

	cout<<"------------------------"<<endl;
	double fun(double a, double b);
	double da,db;
	cout<<sizeof (fun(da,db))<<endl;  // 8 (�ȼ���sizeof(double))
}

double fun(double a, double b)
{
	return a+b;
}