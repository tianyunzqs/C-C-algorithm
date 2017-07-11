#include<iostream>
#include<string>
using namespace std;

template <class T>
bool IsHuiWen(T a[], size_t len)
{
	size_t i=0;
	while(i<len/2)  // 只需循环比较len/2次
	{
		if(a[i]!=a[len-i-1])  // 如果对称位置元素不等，则跳出
			break;
		i++;  // 如果对称位置元素相等，则继续比较下一对称位置
	}
	if(i==len/2) // 如果是回文数组(即对称位置元素全部相等)，那么经过while循环后，i肯定为len/2
		return 1;
	else
		return 0;
}

void main()
{
	//int a[]={1,2,3,3,2,1};
	char *a="abcdefedcba";
	cout<<IsHuiWen(a, 11)<<endl;
}