#include <iostream>
using namespace std;

/**************** private ****************/
// 1-1.能被该类中的函数访问
// 1-2.能被其友元函数访问。
// 1-3.不能被任何其他访问，该类的对象也不能访问。
/**************** protected ****************/
// 2-1.能被该类中的函数访问
// 2-2.能被子类的函数访问
// 2-3.能被其友元函数访问。 
// 2-4.不能被该类的对象访问。
/**************** public ****************/
// 3-1.能被该类中的函数访问
// 3-2.能被子类的函数访问
// 3-3.能被其友元函数访问
// 3-4.能被该类的对象访问。
/****************  默认权限（default） ****************/
// 类，数据成员，构造方法，方法成员，都能够使用默认权限，即不写任何关键字。
// 默认权限即同包权限，同包权限的元素只能在定义它们的类中，以及同包的类中被调用。

// 注：友元函数包括3种：设为友元的普通的非成员函数；设为友元的其他类的成员函数；设为友元类中的所有成员函数。

class ExpClass
{
public:
	ExpClass(){};
	ExpClass(int a):PrivateData(a){}
	ExpClass(int a, int b):PrivateData(a),PublicData(b){}
	void fun(int a, int b);
	friend void fun1(ExpClass f, int a);
private:
	int PrivateData;
protected:
	int ProtectedData;
public:
	int PublicData;
};

class SonExpClass : ExpClass
{
public:
	SonExpClass(){};
	SonExpClass(int a):SonPrivateData(a){}
	SonExpClass(int a, int b, int c):SonPrivateData(a),SonProtectedData(b),SonPublicData(c){}
	void Sonfun(int a, int b);
//	friend void Sonfun1(ExpClass f, int a);
private:
	int SonPrivateData;
protected:
	int SonProtectedData;
public:
	int SonPublicData;
};

void ExpClass::fun(int a, int b)
{
	PrivateData = a+b;   // 1-1.成员函数可以访问private类型
	cout<<"1-1.成员函数可以访问private类型PrivateData="<<PrivateData<<endl;
	ProtectedData = a-b; // 2-1.成员函数可以访问private类型
	cout<<"2-1.成员函数可以访问protected类型ProtectedData="<<ProtectedData<<endl;
	PublicData = a*b; // 3-1.成员函数可以访问public类型
	cout<<"3-1.成员函数可以访问public类型PublicData="<<PublicData<<endl;
}

void SonExpClass::Sonfun(int a, int b)
{
	ProtectedData = 10;
	PublicData = 10;
	int temp1 = ProtectedData+a+b; // 2-2.子类的函数可以访问protected类型
	cout<<"2-2.子类的函数可以访问protected类型ProtectedData+"<<a<<"+"<<b<<"="<<temp1<<endl;
	int temp2 = PublicData+a*b; // 3-2.子类的函数函数可以访问public类型
	cout<<"3-2.子类的函数可以访问public类型PublicData+"<<a<<"*"<<b<<"="<<temp2<<endl;
}


void fun1(ExpClass f, int a)
{
	int temp1 = a+f.PrivateData;   // 1-2.友元函数可以访问private类型
	cout<<"1-2.友元函数可以访问private类型"<<a<<"+PrivateData"<<"="<<temp1<<endl;
	// cout<<a+PrivateData<<endl;// 不能这样访问
	int temp2 = a-f.ProtectedData;    // 2-3.友元函数可以访问protected类型
	cout<<"2-3.友元函数可以访问protected类型"<<a<<"-ProtectedData"<<"="<<temp2<<endl;
	int temp3 = a*f.PublicData;    // 3-3.友元函数可以访问public类型
	cout<<"3-3.友元函数可以访问public类型"<<a<<"*PublicData"<<"="<<temp3<<endl;
}

void main()
{
	cout<<"************************基类A1************************"<<endl;
	ExpClass A1(0);
	A1.fun(5, 3);
	fun1(A1, 10);
	// cout<<A1.PrivateData<<endl; // 1-3.错误，private类型变量不能被类的对象所访问
	// cout<<A1.ProtectedData<<endl; // 2-4.错误，protected类型变量不能被类的对象所访问
	cout<<"3-4.类的对象可访问public类型A1.PublicData="<<A1.PublicData<<endl;


	cout<<endl;
	cout<<"************************子类B1************************"<<endl;
	SonExpClass B1(0, 0, 0);
	B1.Sonfun(20, 30);
	// cout<<B1.PublicData<<endl;  // 子类的对象不能访问父类的public类型变量
	// B1.fun(1, 2);  // 子类的对象不能访问父类的public类型函数
}