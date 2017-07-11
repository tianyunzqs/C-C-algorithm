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
	vector<Student> S3; // 正确，定义一个空容器，容器类型为Student类
	// vector<Student> S2(2); // 错误，没有定义默认构造函数
	// vector<Student> S1(2,10,20); // 错误，没有对应的构造函数
	vector<Student> S(2,10);  // 正确，定义一个含2个对象的vector容器，初始化为10
	S.push_back(s1);
	S.push_back(s2);
	cout<<S.empty()<<endl;  // 检测vector容器S是否为空
	vector<Student>::iterator itorS=S.begin(); // 定义迭代器的时候需要进行初始化
	itorS->output();  // 等价于S.at(0).output();或S[0].output();
	S.at(1).output();

	// 下面都是输出20字节
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
	cout<<sizeof(str)<<endl; // 始终输出32
	cout<<str<<endl;




	// 构造函数1,2,3,复制构造函数4(元素类型要一致), 
	// 第3中方法可在不同类型容器间复制 迭代器是容器之间,容器与算法的粘贴剂
/* 1 */    vector<int> A;  // 创建一个空的的容器

/* 2 */    vector<int> B(10,100); // 创建一个10个元素,每个元素值为100，如果不指定初值，默认为0
	cout<<B[4]<<endl;
	for (int i = 0; i < 10; i++)  // 在已存在的10个元素的尾部添加0,1,2,3...
        B.push_back(i); 
	cout<<"B.size() = "<<B.size()<<endl;  // 一个20个元素
	cout<<*B.begin()-54<<endl; // B.begin()返回的是B的第一个元素的迭代器，*B.begin()表示取第一个元素
	cout<<B.front()<<endl; // B.front()返回第一个元素(等价于*B.begin())，注意与B。begin()的区别
	vector<int>::iterator itor=B.begin();
	itor = B.erase(itor);  // 删除迭代器itor指向的元素
	for(int i=0; i<B.size(); i++)
		cout<<*(itor+i)<<ends;
	cout<<endl;

/* 3 */    vector<int> C(B.begin(),B.end()); //使用迭代器,可以取部分元素创建一个新的容器
	cout<<"C.size() = "<<C.size()<<endl;

/* 4 */	vector<int> D(C); // 复制构造函数,创建一个完全一样的容器  
	cout<<D.at(5)<<endl;  // 等价于D[5]

	cout<<"capacity(A) = "<<A.capacity()<<endl; // capacity(A) = 0
	cout<<"capacity(B) = "<<B.capacity()<<endl; // capacity(B) = 22
	cout<<"capacity(C) = "<<C.capacity()<<endl; // capacity(C) = 20
	cout<<"capacity(D) = "<<D.capacity()<<endl; // capacity(D) = 20

}