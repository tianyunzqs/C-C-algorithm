#include <iostream>
using namespace std;

class A
{
private:
	int Aa;
	static int Ab;
};

class B : virtual public A
{
private:
	int Ba;
	static int Bb;
};

class C : virtual public A
{
private:
	int Ca;
	static int Cb;
};

class D : virtual public B, virtual public C
{
private:
	int Da;
	static int Db;
};

class E
{
public:
	virtual void fun(){cout<<"E::fun()"<<endl;}
private:
	int Ea;
};

class F : virtual public E
{
public:
	virtual void fun1(){cout<<"F::fun1()"<<endl;}
private:
	int Fa;
};

class G
{};
class H : public G
{};
void main()
{
	cout<<sizeof(A)<<endl;  // 4
	cout<<sizeof(B)<<endl;  // 12
	cout<<sizeof(C)<<endl;  // 12
	cout<<sizeof(D)<<endl;  // 28

	cout<<"-------------"<<endl;
	cout<<sizeof(E)<<endl;  // 8
	cout<<sizeof(F)<<endl;  // 20
	F f;
	f.fun();
	//f.fun2();
	E e;
	e.fun();



	cout<<"-------------"<<endl;
	cout<<sizeof(G)<<endl;  // 1
	cout<<sizeof(H)<<endl;  // 1
}