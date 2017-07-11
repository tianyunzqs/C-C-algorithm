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
	if(num>0)  // 将正数的原码取反加1，"去掉"首1前面的0
	{
		num = num ^ 0xffffffff;  // 取反
		num++;  // 加1
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
	//if(num<0)  // 计算原码中1的个数
	//{
	//	num = num ^ 0x7fffffff;  // 取反
	//	num++;  // 加1
	//}
	while(num)
	{
		num = num & (num-1);
		cnt++;
	}
	return cnt;
}
