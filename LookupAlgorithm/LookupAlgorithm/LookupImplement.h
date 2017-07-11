#include <iostream>
//using namespace std;

template<class T>
void CLookup::fun(T a, T b)
{
	if (a > b)
	{
		std::cout<<"a>b"<<std::endl;
	}
	else
	{
		std::cout<<"a<b"<<std::endl;
	}
}