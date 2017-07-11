#include<iostream>
#include<stack>
#include<string>
using namespace std;

template <class T>
class Myqueue
{
public:
	Myqueue(){}
	Myqueue(const size_t n, const T val);
	Myqueue(Myqueue& que);
	~Myqueue(){}
	void push(const T x);
	void pop();
	T top();
	size_t empty();
	size_t size();
private:
	stack<T> stack_push;
	stack<T> stack_pop;
};

template <class T>
Myqueue<T>::Myqueue(const size_t n, const T val)
{
	for(size_t i=n; i>0; i--)
		push(val);
}

template <class T>
Myqueue<T>::Myqueue(Myqueue& que)
{
	if(que.empty())
		this->Myqueue::Myqueue();  // 有参构造函数调用默认构造函数（构造函数调用构造函数的方法）
	else
	{
		Myqueue temp=this->Myqueue::Myqueue(); // 调用默认构造函数创建一个临时对象
		temp = que;  // 将引用que赋值给临时对象temp
		size_t temp_size = temp.size();
		for(size_t i=temp_size; i>0; i--)
		{
			push(temp.top());
			temp.pop();
		}
	}
}

template <class T>
void Myqueue <T>::push(const T x)
{
	if(stack_pop.empty())
	{
		stack_push.push(x);
		cout<<"push queue: "<<x<<endl;
	}
	else
	{
		size_t stack_pop_size = stack_pop.size();
		for(size_t i=0; i<stack_pop_size; i++)
		{
			stack_push.push(stack_pop.top());
			stack_pop.pop();
		}
		stack_push.push(x);
		cout<<"push queue: "<<x<<endl;
	}
}

template <class T>
void Myqueue <T>::pop()
{
	if(empty())
	{
		cout<<"the queue is empty, and the operation is failed!"<<endl;
		return;
	}
	else if(stack_push.empty())
	{
		cout<<"pop  queue: "<<top()<<endl;
		stack_pop.pop();
	}
	else
	{
		size_t stack_push_size = stack_push.size();
		for(size_t i=0; i<stack_push_size; i++)
		{
			stack_pop.push(stack_push.top());
			stack_push.pop();
		}
		cout<<"pop  queue: "<<top()<<endl;
		stack_pop.pop();
	}
}

template <class T>
T Myqueue <T>::top()
{
	if(stack_push.empty())
		return stack_pop.top();
	else
	{
		size_t stack_push_size = stack_push.size();
		for(size_t i=0; i<stack_push_size; i++)
		{
			stack_pop.push(stack_push.top());
			stack_push.pop();
		}
		return stack_pop.top();
	}
}

template <class T>
size_t Myqueue<T>::empty()
{
	if(stack_push.empty() && stack_pop.empty())
		return 1;
	else
		return 0;
}

template <class T>
size_t Myqueue<T>::size()
{
	return stack_push.size() + stack_pop.size();
}

void main()
{
	//stack<int> stack1;
	//for(int i=5; i>0; i--)
	//	stack1.push(i);
	//size_t stack1_size = stack1.size();
	//for(size_t i=0; i<stack1_size; i++)
	//{
	//	cout<<stack1.top()<<ends;
	//	stack1.pop();
	//}
	//cout<<endl;

	Myqueue<int> myque;
	myque.push(1);
	myque.push(2);
	cout<<myque.top()<<endl;	
	myque.pop();
	myque.push(3);
	cout<<myque.top()<<endl;
	myque.pop();
	cout<<myque.top()<<endl;
	myque.pop();
	myque.pop();
	string str = myque.empty() ? "the queue is empty" : "the queue isn't empty";
	cout<<str<<endl;

	cout<<"*********myque2***********"<<endl;
	Myqueue<string> myque2;
	myque2.push("朱");
	myque2.push("其");
	cout<<"the size of myque2 is "<<myque2.size()<<endl;
	myque2.push("斯");
	myque2.pop();
	myque2.pop();
	myque2.pop();
	cout<<"the size of myque2 is "<<myque2.size()<<endl;

	cout<<"*********myque3***********"<<endl;
	Myqueue<float> myque3(3, 4.5);
	cout<<"the size of myque3 is "<<myque3.size()<<endl;

	cout<<"*********myque4***********"<<endl;
	Myqueue<char> que;
	Myqueue<char> myque4_1(que);
	Myqueue<float> myque4_2(myque3);
	cout<<"the size of myque4_1 is "<<myque4_1.size()<<endl;
	cout<<"the size of myque4_2 is "<<myque4_2.size()<<endl;
	cout<<"the size of myque3 is "<<myque3.size()<<endl;
	cout<<myque3.top()<<endl;
}