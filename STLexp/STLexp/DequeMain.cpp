#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void main()
{
	deque<int> deq1;
	deq1.push_back(1);
	deq1.push_back(2);
	deq1.push_back(3);
	deq1.push_back(4);
	for(deque<int>::iterator itor=deq1.begin(); itor!=deq1.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl<<"size of deq1 is "<<deq1.size()<<endl;

	deque<int> deq2(2);
	for(deque<int>::iterator itor=deq2.begin(); itor!=deq2.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl<<"size of deq2 is "<<deq2.size()<<endl;

	deque<int> deq3(3,10); // 3个元素
	deque<int> deq4(deq2); // 2个元素
	cout<<endl<<"size of deq4 is "<<deq4.size()<<endl;
	deq4.assign(deq3.begin(), deq3.end()); // deq4的size扩大一个
	cout<<endl<<"size of deq4 is "<<deq4.size()<<endl;
	for(deque<int>::iterator itor=deq4.begin(); itor!=deq4.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl;
	cout<<endl<<"size of deq2 is "<<deq2.size()<<endl;
	cout<<endl<<"size of deq3 is "<<deq3.size()<<endl;
	cout<<endl<<"size of deq4 is "<<deq4.size()<<endl;




	vector<char> vec;
	vec.push_back('a');
	vec.push_back('b');
	vec.push_back('c');
	deque<char> deq5(vec.begin(), vec.end());
	for(deque<char>::iterator itor=deq5.begin(); itor!=deq5.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl;
	cout<<deq5.at(2)<<endl;  // 等价于deq5[2]能够进行随机访问，deq数据结构为双向队列
	cout<<deq5.front()<<endl; // 等价于deq5[0]
	cout<<deq5.back()<<endl;
	deq5.push_front('z'); // 从头部插入
	deq5.push_front('q');
	deq5.push_front('s');
	deque<char>::iterator itor=deq5.begin();
	cout<<*(itor+2)<<endl; // 对于双向队列deque可以这样操作
	for(deque<char>::iterator itor=deq5.begin(); itor!=deq5.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl;
	deq5.erase(itor+2);
	for(deque<char>::iterator itor=deq5.begin(); itor!=deq5.end(); itor++)
		cout<<*itor<<ends;
	cout<<endl;
}
