#include<iostream>
#include<set>
using namespace std;
void main()
{
	set<int> set1;  
	for(int i=5; i>0; i--)
		set1.insert(10*i);  // Ĭ���������У������Ϊ10--20--30--40--50
	set<int>::iterator it=set1.begin();
	set<int>::iterator it1=it;
	for(; it!=set1.end(); it++)
		cout<<*it<<ends;
	cout<<endl;
	int a[]={10, 11, 12, 13};
	set1.insert(a, a+4);
	cout<<*(--it)<<endl; // ָ��50�������������ʹ�õ�����ʧЧ
	set<int>::iterator it2=set1.find(10);
	if(it2!=set1.end())
	{
		cout<<"the elemnt is found"<<endl;
		set1.erase(it2);  // ɾ��10
//		cout<<*(--it)<<endl;  // ɾ��Ԫ�غ�ԭ��ָ���Ԫ�صĵ�����ʧЧ
		cout<<*(++it1)<<endl; // it1ԭ��ָ��Ԫ��10������10��ɾ���ˣ�����it1ʧЧ�����ɾ������Ԫ�أ���it1����Ч
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

	cout<<set2.count(2)<<endl; // ֻ�ܷ���0��1����Ϊset��ÿ��Ԫ����Ψһ�ģ���������ظ��ģ�ֻ����һ��
}