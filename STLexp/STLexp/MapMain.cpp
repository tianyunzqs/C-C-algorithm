#include<iostream>
#include<map>
#include<string>
using namespace std;
void main()
{
	map<int, string> stu;
	stu.insert(pair<int, string>(1,"student1"));  // 插入记录方式1
	stu.insert(map<int, string>::value_type(2,"student2")); // 插入记录方式2
	stu[3] = "student3"; // 插入记录方式3
	stu[2] = "student?"; // 此种插入方法为覆盖插入
	pair<map<int, string>::iterator, bool> Insert_Pair; 
	Insert_Pair = stu.insert(map<int, string>::value_type(3, "student1")); // 根据key来判断是否插入
	cout<<"insert success ? "<<Insert_Pair.second<<endl;

	for(map<int,string>::iterator it=stu.begin(); it!=stu.end(); it++)
		cout<<it->first<<ends<<it->second<<endl;

	// cout<<stu.at(0)<<endl;  // at括号中的值是map中的first值，此时，该语句错误，因为没有与0对应的key
	cout<<"stu.at(3) = "<<stu.at(3)<<endl; // 输出student1
	cout<<"stu.count(4) = "<<stu.count(4)<<endl; // 查找key=4的记录，若存在，返回1，否则返回0

	int n=stu.erase(3);
	if(n==1)
		cout<<"erase is successful"<<endl;
	else
		cout<<"erase is fail"<<endl;

	map<int,string>::iterator mapItor;
	mapItor = stu.find(3);
	if(mapItor!=stu.end())
	{		
		cout<<"find is successful "<<mapItor->second<<endl;
		stu.erase(mapItor);
	}
	else
		cout<<"find is fail "<<endl;
}