#include <iostream>
using namespace std;

class MyClass
{
    int var;
public:
    virtual void fun(){cout<<"MyClass::fun()"<<endl;}
};
class MyClassA : public MyClass
{
    int varA;
public:
    virtual void fun(){cout<<"MyClassA::fun()"<<endl;}
    virtual void funA(){cout<<"MyClassA::funA()"<<endl;}
};

//class MyClassA2 : public MyClass
//{
//    int varA2;
//public:
//    virtual void fun(){cout<<"MyClassA2::fun()"<<endl;}
//    virtual void funA(){cout<<"MyClassA2::funA()"<<endl;}
//
//};
class MyClassB : public MyClass
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


 class   base   
  {   
  public:   
  virtual   void   f()   const   {};   
  };   
    
  class   d1   :   virtual   public   base   
  {};   
    
  class   d2   :   virtual   public   base     
  {};   
    
  class   derived   :   public   d1,   public   d2   
  {};   
  
void main()
{
	MyClass myclassobj;
	MyClassA myclassobjA;
	//MyClassA2 myclassobjA2;
	MyClassB myclassobjB;
	MyClassC myclassobjC;
	//cout<<&myclassobj<<endl;
	//void (MyClassA2::*pfun)();
	//pfun = &MyClassA2::funA;		varB	-858993460	int

	//cout<<pfun<<endl;
	//cout<<myclassobjA2::funA<<endl;
	cout<<"sizeof(myclassobj)  = "<<sizeof(myclassobj)<<endl;
	cout<<"sizeof(myclassobjA) = "<<sizeof(myclassobjA)<<endl;
	//cout<<"sizeof(myclassobjA2) = "<<sizeof(myclassobjA2)<<endl;
	cout<<"sizeof(myclassobjB) = "<<sizeof(myclassobjB)<<endl;
	cout<<"sizeof(myclassobjC) = "<<sizeof(myclassobjC)<<endl;

	cout<<"sizeof(MyClass)  = "<<sizeof(MyClass)<<endl;
	cout<<"sizeof(MyClassA) = "<<sizeof(MyClassA)<<endl;
	cout<<"sizeof(MyClassB) = "<<sizeof(MyClassB)<<endl;
	cout<<"sizeof(MyClassC) = "<<sizeof(MyClassC)<<endl;


	cout<<"==========="<<endl;
	  d1   b;   
  d2   c;   
  derived   d;   
  cout<<sizeof(b)<<endl;   
  cout<<sizeof(c)<<endl;   
  cout<<sizeof(d)<<endl;   
}