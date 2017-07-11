#include <iostream>  
using namespace std;  
  
class A  
{  
public:  
    A(){}  
    A(int a):m_a(a){}  
    virtual void print()  
    {  
        cout<<"A::"<<m_a<<endl;  
    }  
private:  
    int m_a;  
};  
  
class B:public A  
{  
public:  
    B(){}  
    B(int a, int b):A(a),m_b(b){}  
    virtual void print()  
    {  
        A::print();  
        printf("B::%d/n", m_b);  
    }  
private:  
    int m_b;  
};  
  
void main()
{  
    cout<<sizeof(A)<<endl;  
    cout<<sizeof(B)<<endl;//sizeof(B)=sizeof(A)+sizeof(m_b)+sizeof(指向B中虚函数print的指针)+sizeof(指向父类A的指针(虚继承))  
}  