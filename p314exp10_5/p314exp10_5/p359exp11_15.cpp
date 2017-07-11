#include<iostream>
using namespace std;
struct A
{
	void f(){cout<<"f function of A is called !\n";}
};
struct B
{
	void f(){cout<<"f function of B is called !\n";}
};
struct C : public B, public A
{
	//void f(){cout<<"f function of C is called !\n";}
};
void main()
{
	C objc;
	objc.f();
}