#include<Windows.h>  
#include<iostream>
#include "E:\\VS2010Storage\\CreateDLL\\CreateDLL\\CreateDLL.h"
#pragma comment(lib, "CreateDLL.lib")
using namespace std;
typedef void(*FUNA)(int&,int&);  
typedef void(*FUNB)(int&,int&,int&);


//TestClass类为DLL导出的类  
class MY : public TestClass  
{  
public:  
    virtual void VirtualFunction()  
    {  
        cout<< "my VirtualFunction()" <<endl;  
        return;  
    }  
    void NormalFunction()  
    {  
        cout<< "my NormalFunction()" <<endl;  
        return;  
    }  
};  

int main()  
{  
	MY my;  
    TestClass *tc = &my;  
  
    tc->NormalFunction();  
    tc->VirtualFunction();  
    //调用导出的函数  
    func();  
  
    cout<<"liu zhiliang"<<endl;  
    system("PAUSE");  



    const char* dllName = "CreateDLL.dll";  
/*	const char* funName1 = "?printMax@@YAXAAH0@Z";  
	const char* funName2 = "?printMax@@YAXAAH00@Z";*/  
	const char* funName1 = "printMax2";  
	const char* funName2 = "printMax3";
    int x(100), y(100), z(100);  
    HMODULE hDLL = LoadLibrary(dllName);  
    if(hDLL != NULL)  
    {  
        FUNA fp1 = FUNA(GetProcAddress(hDLL,funName1));  
        if(fp1 != NULL)  
        {  
            std::cout<<"Input 2 Numbers:";  
            std::cin>>x>>y;  
            fp1(x,y);  
        }  
        else  
        {  
            std::cout<<"Cannot Find Function "<<funName1<<std::endl;  
        }  
        FUNB fp2 = FUNB(GetProcAddress(hDLL,funName2));  
        if(fp2 != NULL)  
        {  
            std::cout<<"Input 3 Numbers:";  
            std::cin>>x>>y>>z;  
            fp2(x,y,z);  
        }  
        else  
        {  
            std::cout<<"Cannot Find Function "<<funName2<<std::endl;  
        }  
        FreeLibrary(hDLL);  
    }  
    else  
    {  
        std::cout<<"Cannot Find "<<dllName<<std::endl;  
    }  

	//typedef CCreateDLL* (*PFNCreateA1)(void); 
	//PFNCreateA1 pfnCreateA1 = (PFNCreateA1)GetProcAddress(hDLL, "CreateObjectofA"); 
	////PFNCreateA1 pfnCreateA1 =  PFNCreateA1(GetProcAddress(hDLL, "CreateObjectofA"));
	//CCreateDLL *a = (pfnCreateA1)();
	//a->SetNum(1);
	//printf("Value of m_nNum in a is %d\n", a->GetNum());
	//delete a;


    return 1;  
}  