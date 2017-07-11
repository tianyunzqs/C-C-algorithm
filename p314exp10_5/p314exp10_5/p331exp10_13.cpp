#include <iostream>
using namespace std;
struct A
{
	A(int a){cout<<a<<" class A\t";}
};
struct B : virtual public A
{
	B(int a, int b):A(a)
	{cout<<b<<" class B\t";}
};
struct C : virtual public A
{
	C(int a, int c):A(a)
	{cout<<c<<" class C\t";}
};
struct D : virtual public B, virtual public C
{
	D(int a, int b, int c, int d):A(b), B(a,b), C(a,c)
	{cout<<d<<" class D\t";}
};
struct E : public D
{
	E(int a, int b, int c, int d, int e):A(b), B(a,a), C(a,a),D(a,b,c,d)
	{cout<<e<<" class E\t";}
};
void main()
{
	D objd(1,2,3,4);
	cout<<endl;
	E obje(1,2,3,4,5);
	cout<<endl;
}