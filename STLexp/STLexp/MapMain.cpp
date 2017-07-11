#include<iostream>
#include<map>
#include<string>
using namespace std;
void main()
{
	map<int, string> stu;
	stu.insert(pair<int, string>(1,"student1"));  // �����¼��ʽ1
	stu.insert(map<int, string>::value_type(2,"student2")); // �����¼��ʽ2
	stu[3] = "student3"; // �����¼��ʽ3
	stu[2] = "student?"; // ���ֲ��뷽��Ϊ���ǲ���
	pair<map<int, string>::iterator, bool> Insert_Pair; 
	Insert_Pair = stu.insert(map<int, string>::value_type(3, "student1")); // ����key���ж��Ƿ����
	cout<<"insert success ? "<<Insert_Pair.second<<endl;

	for(map<int,string>::iterator it=stu.begin(); it!=stu.end(); it++)
		cout<<it->first<<ends<<it->second<<endl;

	// cout<<stu.at(0)<<endl;  // at�����е�ֵ��map�е�firstֵ����ʱ������������Ϊû����0��Ӧ��key
	cout<<"stu.at(3) = "<<stu.at(3)<<endl; // ���student1
	cout<<"stu.count(4) = "<<stu.count(4)<<endl; // ����key=4�ļ�¼�������ڣ�����1�����򷵻�0

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