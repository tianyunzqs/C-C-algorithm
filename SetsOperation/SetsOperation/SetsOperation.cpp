#include<iostream>
#include<string>
using namespace std;

// 交集
template<class T>
void SetsAnd(T output[], T input1[], size_t len1, T input2[], size_t len2)
{
	size_t len3=0;
	for(size_t i=0; i<len1; i++)
		for(size_t j=0; j<len2; j++)
			if(input1[i]==input2[j])
				output[len3++] = input1[i];
}

// 并集
template<class T>
void SetsOr(T output[], T input1[], size_t len1, T input2[], size_t len2)
{
	size_t len3=len1;
	size_t i,j;
	for(i=0; i<len1; i++)
		output[i] = input1[i];
	for(j=0; j<len2; j++)
	{	
		for(i=0; i<len1; i++)
			if(input2[j]==input1[i])
				break;
		if(i>=len1)
			output[len3++] = input2[j];
	}
}

// 差集
template<class T>
void SetsMinus(T output[], T input1[], size_t len1, T input2[], size_t len2)
{
	size_t len3=0;
	size_t i,j;
	for(i=0; i<len1; i++)
	{	
		for(j=0; j<len2; j++)
			if(input1[i]==input2[j])
				break;
		if(j>=len1)
			output[len3++] = input1[i];
	}
}


void main()
{
	int a[]={1,2,3,4};
	int b[]={2,4,0,5};
	int c1[4];
	int c2[8];
	int c3[4];
	SetsAnd(c1, a, 4, b, 4);
	for(size_t i=0; i<4; i++)
		cout<<c1[i]<<ends;
	cout<<endl;
	SetsOr(c2, a, 4, b, 4);
	for(size_t i=0; i<8; i++)
		cout<<c2[i]<<ends;
	cout<<endl;
	SetsMinus(c3, a, 4, b, 4);
	for(size_t i=0; i<4; i++)
		cout<<c3[i]<<ends;
	cout<<endl;

}