#include<iostream>
using namespace std;

class A1;  // 声明类，类名为A1
class A2;  // 声明类，类名为A2

class A
{
public:
	double funA(double x)
	{
		cout<<"funA of class A called."<<endl;
		return x*x;
	}
	double funB(double x)
	{
		A1 *q;
		return q->funA(4); // 此处引用是非法的，因为在调用A1类的funA函数之前，
						   // 没有定义该函数，所以会报错
	}
	void funAA();	
	A1 *p;
//	A1 aa;  // 只能是指向这个类型的指针或引用
			// 此处定义一个A1类的aa对象的时候，就需要调用构造函数，
			// 而此时，A1类还是一个不完整的类（没有构造函数），所以会报错
};

class A1
{
public:
	double funA(double x)
	{
		cout<<"funA1 of class A called."<<endl;
		return 4*x*x;
	}	
};

void A::funAA()
{
	cout<<p->funA(4)<<endl;  // 因为前面定义了类A1，而且定义了funA函数，
							 // 所以此处p->funA()是合法的
}

void main()
{
	A obja;
	obja.funAA();
//	cout<<"sizeof(A2) is "<<sizeof(A2)<<endl;  // 编译不能通过，错误提示：使用了未定义类型“A2”
}