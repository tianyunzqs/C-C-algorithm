#include<iostream>
#include<set>
using namespace std;
void main()
{
	set<int> set1;  
	for(int i=5; i>0; i--)
		set1.insert(10*i);  // 默认升序排列，插入后为10--20--30--40--50
	set<int>::iterator it=set1.begin();
	set<int>::iterator it1=it;
	for(; it!=set1.end(); it++)
		cout<<*it<<ends;
	cout<<endl;
	int a[]={10, 11, 12, 13};
	set1.insert(a, a+4);
	cout<<*(--it)<<endl; // 指向50，插入操作不会使得迭代器失效
	set<int>::iterator it2=set1.find(10);
	if(it2!=set1.end())
	{
		cout<<"the elemnt is found"<<endl;
		set1.erase(it2);  // 删除10
//		cout<<*(--it)<<endl;  // 删除元素后，原来指向该元素的迭代器失效
		cout<<*(++it1)<<endl; // it1原来指向元素10，由于10被删除了，所以it1失效，如果删除其他元素，则it1仍有效
	}
	else
		cout<<"the elemnt is not found"<<endl;
	


	int myints[]={5,2,4,2};
	set<int> set2(myints, myints+4);
	set<int> set3(set2);
	set<int> set4(set2.begin(), set2.end());
	cout<<"set1.size() = "<<set1.size()<<endl;
	cout<<"set2.size() = "<<set2.size()<<endl;
	cout<<"set3.size() = "<<set3.size()<<endl;
	cout<<"set4.size() = "<<set4.size()<<endl;
	for(set<int>::iterator it=set2.begin(); it!=set2.end(); it++)
		cout<<*it<<ends;
	cout<<endl;

	cout<<set2.count(2)<<endl; // 只能返回0或1，因为set中每个元素是唯一的，如果出现重复的，只保留一个
}