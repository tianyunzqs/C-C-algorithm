#include <iostream>
using namespace std;
class Base 
{
public:
	int a;
    virtual void f() { cout << "Base::f" << endl; }
    //virtual void g() { cout << "Base::g" << endl; }
    //virtual void h() { cout << "Base::h" << endl; }
};
class Derive : virtual public Base
{
public:
	int b;
    virtual void f1() { cout << "Derive::f1" << endl; }
    //virtual void g1() { cout << "Derive::g1" << endl; }
    //virtual void h1() { cout << "Derive::h1" << endl; }
};
class Derive2 : virtual public Derive
{
public:
	int b2;
    virtual void f2() { cout << "Derive2::f2" << endl; }
    //virtual void g1() { cout << "Derive::g1" << endl; }
    //virtual void h1() { cout << "Derive::h1" << endl; }
};



class MyClass
{
    int var;
public:
    virtual void fun(){cout<<"MyClass::fun()"<<endl;}
};
class MyClassA : virtual public MyClass
{
    int varA;
public:
    virtual void fun(){cout<<"MyClassA::fun()"<<endl;}
    virtual void funA(){cout<<"MyClassA::funA()"<<endl;}
};
class MyClassB : virtual public MyClass
{
    int varB;
public:
    //virtual void fun(){cout<<"MyClassB::fun()"<<endl;}
    virtual void funB(){cout<<"MyClassB::funB()"<<endl;}
};
class MyClassC : public MyClassA, public MyClassB
{
    int varC;
public:
    virtual void funB(){cout<<"MyClassC::funB()"<<endl;}
	virtual void funC(){cout<<"MyClassC::funC()"<<endl;}
};
void main()
{
	typedef void(*Fun)(void);
    Base b;
    Fun pFun = NULL;
 
    //cout << "虚函数表地址：" << (int*)(&b) << endl;
    //cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
 
    // Invoke the first virtual function 
    //pFun = (Fun)*((int*)*(int*)(&b));
    //pFun();
	cout<<"sizeof(b) = "<<sizeof(b)<<endl;

	Derive d;
	cout<<"sizeof(d) = "<<sizeof(d)<<endl;
	Derive2 d2;
	cout<<"sizeof(d2) = "<<sizeof(d2)<<endl;


	MyClass myclassobj;
	MyClassA myclassobjA;
	MyClassB myclassobjB;
	MyClassC myclassobjC;

	cout<<"sizeof(myclassobj)  = "<<sizeof(myclassobj)<<endl;
	cout<<"sizeof(myclassobjA) = "<<sizeof(myclassobjA)<<endl;
	cout<<"sizeof(myclassobjB) = "<<sizeof(myclassobjB)<<endl;
	cout<<"sizeof(myclassobjC) = "<<sizeof(myclassobjC)<<endl;
	for(int i=0; i<5; ++i)
	{
		pFun = (Fun)*((int*)*(int*)(&myclassobjA)+i);
		pFun();
	}
}