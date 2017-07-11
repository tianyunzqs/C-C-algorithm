#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int NumBinary0(int num);
int NumBinary1(int num);

void main()
{
	int a = 2;
	printf("%d\n", NumBinary1(a));
	printf("%d\n", NumBinary1(-1));
	//printf("%d\n", NumBinary0(a));
	//printf("%d\n", NumBinary0(-1));

}

int NumBinary0(int num)
{
	int cnt = 0;
	if(num>0)  // ��������ԭ��ȡ����1��"ȥ��"��1ǰ���0
	{
		num = num ^ 0xffffffff;  // ȡ��
		num++;  // ��1
	}
	for(int i=0; i<32; ++i)
	{
		if((num & 0x80000000) == 0)
			cnt++;
		num = num << 1;
	}
	return cnt;
}

int NumBinary1(int num)
{
	int cnt = 0;
	//if(num<0)  // ����ԭ����1�ĸ���
	//{
	//	num = num ^ 0x7fffffff;  // ȡ��
	//	num++;  // ��1
	//}
	while(num)
	{
		num = num & (num-1);
		cnt++;
	}
	return cnt;
}
