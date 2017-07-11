#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;

//void ChangeVaule(int a, int b)
//{
//	a = a^b;
//	b = a^b;
//	a = a^b;
//}


//struct
//{
//	short a1;
//	short a2;
//	short a3;
//}A;
//
//struct 
//{
//	long a1;
//	short a2;
//}B;
//
//
//class E
//{
//private:
//	bool m_bTemp;
//	int m_nTemp;
//	bool m_bTemp2;
//};
//
//class F
//{
//private:
//	int m_nTemp;
//	bool m_bTemp;
//	bool m_bTemp2;
//};


class tt{

	char *stu;

public:
	tt(){}
	tt(char *t)
	{
		stu=t;

	}
	void prin()
	{
		cout<<stu;
	}
};


void main()
{
	//float a = 0.0f;
	//cout << (int)a <<endl;
	//cout << &a <<endl;
	//cout << (int&)a <<endl; // (int&)a 相当于将该浮点数地址开始的sizeof(int)个字节当成int型的数据输出
	//cout << boolalpha << ((int)a == (int&)a) <<endl;
	//cout << sizeof(int) <<endl;
	//cout << sizeof(float) <<endl;

	//float b = 0.0f;
	//cout << (int)b <<endl;
	//cout << &b <<endl;
	//cout << (int&)b <<endl;
	//cout << boolalpha << ((int)b == (int&)b) <<endl;


	//unsigned int a = 0xFFFFFFF7;
	//unsigned char i = (unsigned char)a;
	//char *b = (char *)&a;
	//printf("%08x, %08x\n", i, *b);

	
	//int *a=5, *b=4;
	//ChangeValue(*a, *b);
	//printf("%d, %d\n", *a, *b);

	//int a=5, b=4;
	//a = a^b;
	//b = a^b;
	//a = a^b;
	//printf("%d, %d\n", a, b);


	//char* ss1 = "0123456789";
	//char ss2[] = "0123456789";
	//char ss3[100] = "0123456789";
	//int ss4[100];
	//char q1[] = "abc";
	//char q2[] = "a\n";
	//char* q3 = "a\n";
	//char *str1 = (char *)malloc(100);
	//void *str2 = (void *)malloc(100);

	//cout<<sizeof(ss1)<<ends; // 4 字节，指针为固定大小4字节
	//cout<<sizeof(ss2)<<ends; // 11 字节，末尾补充字符'\0'
	//cout<<sizeof(ss3)<<ends; // 100 字节，预分配100字节
	//cout<<sizeof(ss4)<<ends; // 400 字节，预分配4*100字节
	//cout<<sizeof(q1)<<ends;  // 4 字节，与ss2类似，末尾补充字符'\0'
	//cout<<sizeof(q2)<<ends;  // 3 字节，字符'\n'算一个字符，末尾补充字符'\0'
	//cout<<sizeof(q3)<<ends;  // 4 字节，指针为固定大小4字节
	//cout<<sizeof(A)<<ends;   // 6 字节，short占2字节，3*2
	//cout<<sizeof(B)<<ends;   // 8 字节，内存对齐，long占4字节
	//cout<<sizeof(str1)<<ends; // 4 字节，指针为固定大小4字节
	//cout<<sizeof(str2)<<ends; // 4 字节，指针为固定大小4字节

	//cout<<endl;
	//cout<<sizeof(E)<<ends;
	//cout<<sizeof(F)<<ends;


	
	tt n("ffff");
	n.prin();
	
}