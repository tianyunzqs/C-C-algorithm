//#include <iostream.h>

// VC6.0是在C标准出来前发布的，所以它可以使用#include<iostream.h>这形式，
// 而VS2008采用标准C格式
#include<iostream>
#include<windows.h>
#include <conio.h>
#include<cstdlib> 
using namespace std;

union data1
{
	float f_data;
	int i_data;
	double d_data;
};

struct data2
{
	float f_data;
	int i_data;
	double d_data;
};

void UnionAndStruct()
{
	union data1 t1;
	struct data2 t2;
	cout<<sizeof(t1)<<ends<<sizeof(t2)<<endl;  // ends输出空格
}

void Expression1()
{
	int x = 2, y = 3, f = 5.5;
	float f1 = 5.5;
	int nResult;
	float fResult;
	cout<<x<<ends<<y<<ends<<f<<endl; // 输出f=5
	nResult = x*y/f+x*y-f;
	fResult = x*y/f1+x*y-f1;
	cout<<"x*y/f+x*y-f = "<<x*y/f+x*y-f<<endl;
	cout<<"double(x*y/f+x*y-f) = "<<double(x*y/f+x*y-f)<<endl;
	cout<<"nResult = "<<nResult<<endl;
	cout<<"fResult = "<<fResult<<endl;
}

void Expression2()
{
	int a1 = 5, a2 = 5, a3 = 5;
	
	cout<<"(a1--)+(a1++)+(a1++)+(++a1)+(++a1) = "<<(a1--)+(a1++)+(a1++)+(++a1)+(++a1)<<endl;
	cout<<"a1 = "<<a1<<endl;
	cout<<"a2--+(a2++)+(++a2) = "<<a2--+(a2++)+(++a2)<<endl;
	cout<<"a2 = "<<a2<<endl;
	cout<<"a3-- = "<<a3--<<endl;
	cout<<"a3 = "<<a3<<endl;
}

void Expression3()
{
	int a = 5, b = 5;
	
	cout<<"(a--)+(b++)+(a++)+(++a)+(++a) = "<<(a--)+(b++)+(a++)+(++a)+(++a)<<endl;
	cout<<"a = "<<a<<endl;
	cout<<"b = "<<b<<endl;
}

void Expression4()
{
	int x = 5, y = 3, z;
	float f = 3.1;
	z = x||(x-y)&&f&&!(f||x);
	cout<<"x||(x-y)&&f&&!(f||x) = "<<z<<endl;
	z = (x-y)&&f&&!(f||x)&&x;
	cout<<"(x-y)&&f&&!(f||x)&&x = "<<z<<endl;
}

void Expression5()
{
	long x = 55, y = 1, z = 48;
	long Result1, Result2;
	Result1 = (x<<y)&z|~(z>>y|x);
	Result2 = ~(z>>y|x);
	cout<<"(x<<y)&z|~(z>>y|x) = "<<Result1<<endl;
	cout<<"~(z>>y|x) = "<<Result2<<endl;
}

void Expression6()
{
	int s = 8, t =4;
	int Result;
	//Result = !s&&++t;
	//cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;
	/*Result = t||s-4&&s/t;
	cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;*/
	//Result = s=2,t=3,s>t?s++:t--;     // Result = (s=2,t=3,s>t?s++:t--);输出Result=3，s=2，t=2
	//cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;
	//Result = ++s,t=10,t+3;    // Result = (++s,t=10,t+3);输出Result=13，s=9，t=10
	//cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;
	//Result = s+=t%=s+t;
	//cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;
	Result = s!=t>2<=s+1;
	cout<<"Result, s, t: "<<Result<<ends<<s<<ends<<t<<endl;
}

void Expression7()
{
	int x = 999;  
	//int countx = 0;  
	//while(x)
	//{  
		//countx++;  
		x=x&(x-1);  
		x=x&(x-1);
		x=x&(x-1);
		x=x&(x-1);
		x=x&(x-1);
		x=x&(x-1);
		x=x&(x-1);
		x=x&(x-1);
	//}  
	//return countx;
	cout<<"x: "<<x<<endl;
}
// 在32位机器上，下列代码中sizeof(a)的值是（）20、21、22、24、全不是
class A  
{  
	int i;  
	union U  
	{  
	  char buff[13];  
	  int i;  
	}u;  
	void foo() {    }  
	typedef char* (*f)(void*);  
	enum{red, green, blue} color;  
}a;  

void main()
{
	system("color A4");
    cout<<"change!"<<endl;

	//HANDLE Screen = GetStdHandle(STD_OUTPUT_HANDLE); 
	//SetConsoleTextAttribute(Screen,FOREGROUND_RED);//这个表示红色文本，绿色为FOREGROUND_GREEN蓝色就是blue了 

	cout<<"******* Result of UnionAndStruct *******"<<endl;
	UnionAndStruct();
	cout<<endl<<"******* Result of Expression1 *******"<<endl;
	Expression1();
	cout<<endl<<"******* Result of Expression2 *******"<<endl;
	Expression2();
	cout<<endl<<"******* Result of Expression3 *******"<<endl;
	Expression3();
	cout<<endl<<"******* Result of Expression4 *******"<<endl;
	Expression4();
	cout<<endl<<"******* Result of Expression5 *******"<<endl;
	Expression5();
	cout<<endl<<"******* Result of Expression6 *******"<<endl;
	Expression6();
	cout<<endl<<"******* Result of Expression7 *******"<<endl;
	Expression7();
	cout<<endl<<"******* Result of Expression8 *******"<<endl;
	cout<<sizeof(a)<<endl;


	int i, n = 0;
	double x = 1, y1 = 2.1/1.9, y2 = 1.9/2.1;
	for( i = 1; i<22; i++) x = x*y1; 
	while( x!=1.0) { x =x*y2; n++; } printf("%d\n", n);
}