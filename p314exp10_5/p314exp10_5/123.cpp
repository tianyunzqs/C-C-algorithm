#include<iostream>
using namespace std;

class A1;  // �����࣬����ΪA1
class A2;  // �����࣬����ΪA2

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
		return q->funA(4); // �˴������ǷǷ��ģ���Ϊ�ڵ���A1���funA����֮ǰ��
						   // û�ж���ú��������Իᱨ��
	}
	void funAA();	
	A1 *p;
//	A1 aa;  // ֻ����ָ��������͵�ָ�������
			// �˴�����һ��A1���aa�����ʱ�򣬾���Ҫ���ù��캯����
			// ����ʱ��A1�໹��һ�����������ࣨû�й��캯���������Իᱨ��
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
	cout<<p->funA(4)<<endl;  // ��Ϊǰ�涨������A1�����Ҷ�����funA������
							 // ���Դ˴�p->funA()�ǺϷ���
}

void main()
{
	A obja;
	obja.funAA();
//	cout<<"sizeof(A2) is "<<sizeof(A2)<<endl;  // ���벻��ͨ����������ʾ��ʹ����δ�������͡�A2��
}