#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Student
{
public:
	//Student(){}
	Student(int x):int_x(x){cout<<"Student constructor!"<<endl;}
	Student(int x, int y):int_x(x),int_y(y){}
	Student(const Student& Stu){cout<<"Student copy_constructor!"<<endl;}
	~Student(){static int i=0; i++; cout<<"Student destrcuctor! "<<i<<endl;}
	void output(){cout<<"Student类的int_x = "<<int_x<<endl;}	
private:
	int int_x;
	int int_y;
};

void main()
{
	//list<Student> list4;
	//if(list4.empty())
	//	cout<<"list4 is empty!"<<endl;
	//list4.front().output();
	cout<<"开始调用构造函数？"<<endl;
	Student s1(1), s2(2);
	cout<<"cccccccccc"<<endl;
	list<Student> list5(12,23);	
	cout<<"eeeeeeeeee"<<endl;
	list5.push_back(s1);
	cout<<"dddddddddd"<<endl;
	list5.push_back(s2);
	cout<<"aaaaaaaaaa"<<endl;
	//list5.front().output();
	//list<Student> list6(12,23,34); // 错误，没有匹配的构造函数
	cout<<"bbbbbbbbbb"<<endl;

	list<int> list1; // 利用默认构造函数创建一个空列表
	list<int> list2(5, 10); // 创建一个含5个元素10的列表
	list<int> list3(list2); // 创建一个与list2一样的列表
	list3.pop_back();  // 从尾部删除list3中的一个元素
	list3.pop_front(); // 从头部删除list3中的一个元素
	// list<int>::iterator itor=list3.begin();
	// cout<<*(itor+2)<<ends; // 对于双向链表不能这样操作，只能++或--
	for(list<int>::iterator itor=list3.begin(); itor!=list3.end(); itor++)
	{
		cout<<*itor<<ends;
	}
	cout<<endl;
	// 插入后变为：3--2--1--4--5
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.insert(list1.begin(), 2, 100); // 在list1开始位置插入2个100
	list1.insert(list1.end(), list2.begin(), list2.end()); // 在list1的尾部插入list2的所以元素
	for(list<int>::iterator itor=list1.begin(); itor!=list1.end(); itor++)
	{
		//itor = list1.erase(list1.begin());
		cout<<*itor<<ends;
	}
	cout<<endl;
	list1.reverse(); // 完成list1的逆置
	for(list<int>::iterator itor=list1.begin(); itor!=list1.end(); itor++)
	{
		cout<<*itor<<ends;
	}
	cout<<endl;


	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	//vector<int>::iterator Vecit;
	list<int> list8(vec.begin(), vec.end()); // 利用vector的迭代器进行创建list
	for(list<int>::iterator itor=list8.begin(); itor!=list8.end(); itor++)
	{
		cout<<*itor<<ends;
	}
	cout<<endl;
}