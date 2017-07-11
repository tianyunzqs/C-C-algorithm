//// CreateDLL.cpp : 定义 DLL 应用程序的导出函数。
////
//
#include "stdafx.h"
#include <iostream>
#include "CreateDLL.h"
using namespace std;
//
//
//// 这是导出变量的一个示例
//CREATEDLL_API int nCreateDLL=0;
//
//// 这是导出函数的一个示例。
//CREATEDLL_API int fnCreateDLL(void)
//{
//	return 42;
//}
//
//// 这是已导出类的构造函数。
//// 有关类定义的信息，请参阅 CreateDLL.h
//CCreateDLL::CCreateDLL()
//{
//	return;
//}


extern "C" CREATEDLL_API void printMax2(int& a,int& b)  
{  
	//printf("Among (%d, %d), the Max Number is ", a>b?a:b);
    std::cout<<"Among ("<<a<<","<<b<<"), the Max Number is "<<(a>b?a:b)<<"\n";  
}  
extern "C" CREATEDLL_API void printMax3(int& a,int& b,int& c)  
{  
    std::cout<<"Among ("<<a<<","<<b<<","<<c<<"), the Max Number is "<<(((a>b?a:b)>c)?(a>b?a:b):c)<<"\n";  
}  

//extern "C" CREATEDLL_API CCreateDLL* CreateObjectofA(void)
//{
//	return new CCreateDLL();
//}

//extern "C" CREATEDLL_API CCreateDLL* CreateObjectofA1(int n)
//{
//	return new CCreateDLL(n);
//}


void TestClass::VirtualFunction(void)  
    {  
        cout<< "this is VirtualFunction()!" <<endl;  
        return;  
    }  
void TestClass::NormalFunction(void)  
    {  
        cout<< "this is NormalFunction()!" <<endl;  
        return;  
    }  
void func(void)  
{  
    cout << "xixi haha" <<endl;  
    return;  
}  
