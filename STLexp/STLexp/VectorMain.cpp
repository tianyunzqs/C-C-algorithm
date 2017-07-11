#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student
{
public:
	//Student(){}
	Student(int x):int_x(x){}
	Student(int x, int y):int_x(x),int_y(y){}
	void output(){cout<<int_x<<endl;}
private:
	int int_x;
	int int_y;
};

void main()
{
	Student s1(1),s2(2);
	vector<Student> S3; // ��ȷ������һ������������������ΪStudent��
	// vector<Student> S2(2); // ����û�ж���Ĭ�Ϲ��캯��
	// vector<Student> S1(2,10,20); // ����û�ж�Ӧ�Ĺ��캯��
	vector<Student> S(2,10);  // ��ȷ������һ����2�������vector��������ʼ��Ϊ10
	S.push_back(s1);
	S.push_back(s2);
	cout<<S.empty()<<endl;  // ���vector����S�Ƿ�Ϊ��
	vector<Student>::iterator itorS=S.begin(); // �����������ʱ����Ҫ���г�ʼ��
	itorS->output();  // �ȼ���S.at(0).output();��S[0].output();
	S.at(1).output();

	// ���涼�����20�ֽ�
	cout<<"sizeof(vector<bool>)  ="<<sizeof(vector<bool>)<<endl;
	cout<<"sizeof(vector<char>)  ="<<sizeof(vector<char>)<<endl;
	cout<<"sizeof(vector<int>)   ="<<sizeof(vector<int>)<<endl;
	cout<<"sizeof(vector<float>) ="<<sizeof(vector<float>)<<endl;
	cout<<"sizeof(vector<double>)="<<sizeof(vector<double>)<<endl;
	cout<<"sizeof(vector<string>)="<<sizeof(vector<string>)<<endl;

	string sa[6]={"adfd", "bad", "dfew", "qwe", "oiew", "tyu"};
	string str="sdfadfdffffffffffffffffffffffffffffffffdddddddddddddddddddddd";
	cout<<"sizeof(string) = "<<sizeof(string)<<endl;
	cout<<sizeof(sa)<<endl;
	cout<<sizeof(str)<<endl; // ʼ�����32
	cout<<str<<endl;




	// ���캯��1,2,3,���ƹ��캯��4(Ԫ������Ҫһ��), 
	// ��3�з������ڲ�ͬ���������临�� ������������֮��,�������㷨��ճ����
/* 1 */    vector<int> A;  // ����һ���յĵ�����

/* 2 */    vector<int> B(10,100); // ����һ��10��Ԫ��,ÿ��Ԫ��ֵΪ100�������ָ����ֵ��Ĭ��Ϊ0
	cout<<B[4]<<endl;
	for (int i = 0; i < 10; i++)  // ���Ѵ��ڵ�10��Ԫ�ص�β�����0,1,2,3...
        B.push_back(i); 
	cout<<"B.size() = "<<B.size()<<endl;  // һ��20��Ԫ��
	cout<<*B.begin()-54<<endl; // B.begin()���ص���B�ĵ�һ��Ԫ�صĵ�������*B.begin()��ʾȡ��һ��Ԫ��
	cout<<B.front()<<endl; // B.front()���ص�һ��Ԫ��(�ȼ���*B.begin())��ע����B��begin()������
	vector<int>::iterator itor=B.begin();
	itor = B.erase(itor);  // ɾ��������itorָ���Ԫ��
	for(int i=0; i<B.size(); i++)
		cout<<*(itor+i)<<ends;
	cout<<endl;

/* 3 */    vector<int> C(B.begin(),B.end()); //ʹ�õ�����,����ȡ����Ԫ�ش���һ���µ�����
	cout<<"C.size() = "<<C.size()<<endl;

/* 4 */	vector<int> D(C); // ���ƹ��캯��,����һ����ȫһ��������  
	cout<<D.at(5)<<endl;  // �ȼ���D[5]

	cout<<"capacity(A) = "<<A.capacity()<<endl; // capacity(A) = 0
	cout<<"capacity(B) = "<<B.capacity()<<endl; // capacity(B) = 22
	cout<<"capacity(C) = "<<C.capacity()<<endl; // capacity(C) = 20
	cout<<"capacity(D) = "<<D.capacity()<<endl; // capacity(D) = 20

}