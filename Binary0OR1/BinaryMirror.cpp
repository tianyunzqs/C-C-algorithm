#include <iostream>
#include <float.h>
using namespace std;
int cpu_bits(void *dummy1, void *dummy2);
unsigned int BinaryMirror(int b[], int data);
void main()
{
	int *b=new int[32];
	int data=-23;
	unsigned int res=BinaryMirror(b, data);
	for(int i=0; i<32; ++i)
	{
		if(i>0 && i%4==0)
			cout<<ends;
		cout<<b[i];
	}
	cout<<endl;
	cout<<res<<endl;
	delete[] b;
	printf("%d\n", cpu_bits(NULL, NULL));
	unsigned int u = 4294967295;
    float f = u;
	printf("%f\n", f);
	printf("the min of int = %d\n", INT_MIN);
	printf("the max of int = %d\n", INT_MAX);
	printf("the min of float = %f\n", FLT_MIN);
	printf("the max of float = %f\n", FLT_MAX);
	printf("the min of double = %lf\n", DBL_MIN);
	printf("the max of double = %lf\n", DBL_MAX);
}

int cpu_bits(void *dummy1, void *dummy2) 
{ 
     long offset1 = (long)&dummy1;
	 long offset2 = (long)&dummy2; 
	 long offset = offset2 - offset1;
     int ret = 0; 
     if (8 == offset) 
         ret = 64; 
     else if (4 == offset) 
         ret = 32; 
     else if (2 == offset) 
         ret = 16; 
     else if (1 == offset) 
         ret = 8; 
     else 
         ret = -1; 
     return ret;  
} 

unsigned int BinaryMirror(int b[], int data)
{
	//int i=0;
	//while(data!=0)
	//{
	//	b[i++] = data % 2;
	//	data = data / 2;
	//	cout<<b[i-1];
	//} 
	// 对于有符号数，若原符号位为0，则右移后最高位补0
	// 对于有符号数，若原符号位为1，则右移后最高位补1
	// 也即，右移后保存这个数的符号不变
	for(int i=0; i<32; ++i)
	{
		b[i] = data & 1;
		data = data >> 1;
	}
	int res=0;
	for(int j=0; j<32; ++j)
		res = res*2 + b[j];
	return res;
}