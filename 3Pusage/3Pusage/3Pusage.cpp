#include <iostream>
using namespace std;

/**************** private ****************/
// 1-1.�ܱ������еĺ�������
// 1-2.�ܱ�����Ԫ�������ʡ�
// 1-3.���ܱ��κ��������ʣ�����Ķ���Ҳ���ܷ��ʡ�
/**************** protected ****************/
// 2-1.�ܱ������еĺ�������
// 2-2.�ܱ�����ĺ�������
// 2-3.�ܱ�����Ԫ�������ʡ� 
// 2-4.���ܱ�����Ķ�����ʡ�
/**************** public ****************/
// 3-1.�ܱ������еĺ�������
// 3-2.�ܱ�����ĺ�������
// 3-3.�ܱ�����Ԫ��������
// 3-4.�ܱ�����Ķ�����ʡ�
/****************  Ĭ��Ȩ�ޣ�default�� ****************/
// �࣬���ݳ�Ա�����췽����������Ա�����ܹ�ʹ��Ĭ��Ȩ�ޣ�����д�κιؼ��֡�
// Ĭ��Ȩ�޼�ͬ��Ȩ�ޣ�ͬ��Ȩ�޵�Ԫ��ֻ���ڶ������ǵ����У��Լ�ͬ�������б����á�

// ע����Ԫ��������3�֣���Ϊ��Ԫ����ͨ�ķǳ�Ա��������Ϊ��Ԫ��������ĳ�Ա��������Ϊ��Ԫ���е����г�Ա������

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
	PrivateData = a+b;   // 1-1.��Ա�������Է���private����
	cout<<"1-1.��Ա�������Է���private����PrivateData="<<PrivateData<<endl;
	ProtectedData = a-b; // 2-1.��Ա�������Է���private����
	cout<<"2-1.��Ա�������Է���protected����ProtectedData="<<ProtectedData<<endl;
	PublicData = a*b; // 3-1.��Ա�������Է���public����
	cout<<"3-1.��Ա�������Է���public����PublicData="<<PublicData<<endl;
}

void SonExpClass::Sonfun(int a, int b)
{
	ProtectedData = 10;
	PublicData = 10;
	int temp1 = ProtectedData+a+b; // 2-2.����ĺ������Է���protected����
	cout<<"2-2.����ĺ������Է���protected����ProtectedData+"<<a<<"+"<<b<<"="<<temp1<<endl;
	int temp2 = PublicData+a*b; // 3-2.����ĺ����������Է���public����
	cout<<"3-2.����ĺ������Է���public����PublicData+"<<a<<"*"<<b<<"="<<temp2<<endl;
}


void fun1(ExpClass f, int a)
{
	int temp1 = a+f.PrivateData;   // 1-2.��Ԫ�������Է���private����
	cout<<"1-2.��Ԫ�������Է���private����"<<a<<"+PrivateData"<<"="<<temp1<<endl;
	// cout<<a+PrivateData<<endl;// ������������
	int temp2 = a-f.ProtectedData;    // 2-3.��Ԫ�������Է���protected����
	cout<<"2-3.��Ԫ�������Է���protected����"<<a<<"-ProtectedData"<<"="<<temp2<<endl;
	int temp3 = a*f.PublicData;    // 3-3.��Ԫ�������Է���public����
	cout<<"3-3.��Ԫ�������Է���public����"<<a<<"*PublicData"<<"="<<temp3<<endl;
}

void main()
{
	cout<<"************************����A1************************"<<endl;
	ExpClass A1(0);
	A1.fun(5, 3);
	fun1(A1, 10);
	// cout<<A1.PrivateData<<endl; // 1-3.����private���ͱ������ܱ���Ķ���������
	// cout<<A1.ProtectedData<<endl; // 2-4.����protected���ͱ������ܱ���Ķ���������
	cout<<"3-4.��Ķ���ɷ���public����A1.PublicData="<<A1.PublicData<<endl;


	cout<<endl;
	cout<<"************************����B1************************"<<endl;
	SonExpClass B1(0, 0, 0);
	B1.Sonfun(20, 30);
	// cout<<B1.PublicData<<endl;  // ����Ķ����ܷ��ʸ����public���ͱ���
	// B1.fun(1, 2);  // ����Ķ����ܷ��ʸ����public���ͺ���
}