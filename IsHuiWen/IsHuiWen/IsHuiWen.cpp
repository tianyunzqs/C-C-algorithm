#include<iostream>
#include<string>
using namespace std;

template <class T>
bool IsHuiWen(T a[], size_t len)
{
	size_t i=0;
	while(i<len/2)  // ֻ��ѭ���Ƚ�len/2��
	{
		if(a[i]!=a[len-i-1])  // ����Գ�λ��Ԫ�ز��ȣ�������
			break;
		i++;  // ����Գ�λ��Ԫ����ȣ�������Ƚ���һ�Գ�λ��
	}
	if(i==len/2) // ����ǻ�������(���Գ�λ��Ԫ��ȫ�����)����ô����whileѭ����i�϶�Ϊlen/2
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