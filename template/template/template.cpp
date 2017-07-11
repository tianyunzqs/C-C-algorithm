#include<iostream>
//#include "test.h"
#include<stack>
#include<vector>
using namespace std;

//template <class T>
//T min1(T a, T b)
//{
//	return a<b ? a : b;
//}



//template <class T>
//class Person
//{
//private:
//	T heigh;
//	T weight;
//public:
//	Person(T h, T w);
//	Person(){}
//	bool health();
//	void show();
//};
//
//template <class T>
//Person <T>::Person(T h, T w)
//{
//	heigh = h;
//	weight = w;
//}
//
//template <class T>
//bool Person <T>::health()
//{
//	if(heigh+weight > 200)
//		return true;
//	else
//		return false;
//}
//
//template <class T>
//void Person <T>::show()
//{
//	cout<<"height="<<heigh<<ends<<"weight="<<weight<<endl;
//}



//class Person
//{
//private:
//	int heigh;
//	int weight;
//public:
//	Person(int h, int w);
//	Person(){}
//	bool health();
//	void show();
//};
//
//Person::Person(int h, int w)
//{
//	heigh = h;
//	weight = w;
//}
//
//bool Person::health()
//{
//	if(heigh+weight > 200)
//		return true;
//	else
//		return false;
//}
//
//void Person::show()
//{
//	cout<<"height="<<heigh<<ends<<"weight="<<weight<<endl;
//}

//class Solution
//{
//public:
//	void push(int node) {
//		while(!stack2.empty())
//        {
//            int a = stack2.top();
//            stack2.pop();
//            stack1.push(a);
//        }
//        stack1.push(node);
//	}
//
//	int pop() {        
//		while(!stack1.empty())
//        {
//            int a = stack1.top();
//            stack1.pop();
//            stack2.push(a);
//        }
//        int result = stack2.top();
//        stack2.pop();
//        return result;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};



class Solution2 {
public:
	void push(int value) {
        st.push(value);
	}
	void pop() {
		st.pop();
	}
	int top() {
		return st.top();
	}
	int size(){
		return st.size();
	}
	int min() {
		vector<int> vec;
        int minV=st.top();
		unsigned int Ssize=st.size();
        for(unsigned int i=0; i<Ssize; i++)
        {
            vec.push_back(st.top());
            st.pop();
			if(!st.empty() && minV > st.top())
                minV = st.top();
        }
		for(int j=vec.size()-1; j>=0; j--)
        {
            st.push(vec[j]);
        }
        return minV;
	}
private:
    stack<int> st;
};


void main()
{
	Solution2 S;
	//stack<int> st;
	S.push(5);
	S.push(3);
	S.push(25);
	S.push(0);
	S.push(12);
	cout<<S.min()<<endl;
	S.pop();
	S.pop();


	cout<<S.min()<<endl;
	int Ssize=S.size();
	for(int i=0; i<Ssize; i++)
	{
		cout<<S.top()<<endl;
		S.pop();
	}

	//Solution S;
	//for(int i=0; i<4; i++)
	//	S.push(i);
	//cout<<S.pop()<<endl;
	//stack<int> st;
	//cout<<st.empty()<<endl;
	//for(int i=0; i<4; i++)
	//	st.push(i);
	//int a = st.top();
	//st.pop();
	//cout<<a<<endl;
	//cout<<st.top()<<endl;




	//int int1, int2;
	//cin>>int1>>int2;
	//cout<<min1(int1, int2)<<endl;
	//float f1, f2;
	//cin>>f1>>f2;
	//cout<<min1(f1, f2)<<endl;


	//int h=170, w=50;
	//person <int>intperson(h,w);
	////intperson.heigh = h;
	////intperson.weight = w;
	//bool a = intperson.health();
	//if(a)
	//	cout<<"½¡¿µ"<<endl;
	//else
	//	cout<<"²»½¡¿µ"<<endl;


	//int h=170, w=50;
	//float hf=165.8, wf=34.4;
	//bool a;
	//Person <float>intperson(hf,wf);
	//intperson.show();
	//a = intperson.health();
	//intperson.show();
	//if(a)
	//	cout<<"½¡¿µ"<<endl;
	//else
	//	cout<<"²»½¡¿µ"<<endl;
}