#include<iostream>
using namespace std;

class A1;
class A2;

class A
{
public:
	virtual double funA(double x)
	{
		cout<<"funA of class A called."<<endl;
		return x*x;
	}
	void funAA();	
	double funB(double x)
	{return funA(x);}
//	A1 *p;
};

class A1
{
public:
	int funA(int x)
	{
		cout<<"funA1 of class A called."<<endl;
		return 4*x*x;
	}
};
//
//void A::funAA()
//{
//	cout<<p->funA(4)<<endl;
//}

class B : public A
{
public:
	double funA(double x)
	{
		cout<<"funA of class B called."<<endl;
		return 2*x*x;
	}
};

class C : public B
{
public:
	double funA(double x)
	{
		cout<<"funA of class C called."<<endl;
		return 3*x*x;
	}
};

class K
{};

void main()
{
	C objc;
	cout<<objc.funB(3)<<endl;
	//objc.funAA();
	
	B objb;
	cout<<objb.funB(3)<<endl;

	cout<<"sizeof(A) is "<<sizeof(A)<<endl;
	cout<<"sizeof(B) is "<<sizeof(B)<<endl;
	cout<<"sizeof(C) is "<<sizeof(C)<<endl;
	cout<<"sizeof(K) is "<<sizeof(K)<<endl;
//	cout<<"sizeof(A2) is "<<sizeof(A2)<<endl;
}