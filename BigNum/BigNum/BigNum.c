#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX(a,b) ((a)>(b) ? (a) : (b))
void BigNumPuls(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2);
void BigNumMinus(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2);
void BigNumMinusGreater(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2);
int Compare(char input1[], unsigned int len1, char input2[], unsigned int len2);
void main()
{
	unsigned int i=0;
	//char a[]="9531233424234345234465732341233454567687923456767989042340923846283912";
	char a[]=	 "133424234345234465732341233454567687923456767989042340923846283912";
	char b[]=	 "233424234345234465732341233454567687923456767989042340923846283911";
	//char b[]= "469289421234345232365932341237451267687923456767949042040923340283917";
	//char b[]=				"6631289421234345232365932341237451267687923456767949042";
	//char b[]="3631289421234345232365932341237451267687923456767949042040923340283917";
	unsigned int len_a=strlen(a);
	unsigned int len_b=strlen(b);
	char *c=(char *)malloc(sizeof(char)*(MAX(len_a, len_b)+1));
	memset(c, 0, (MAX(len_a, len_b)+1));
	BigNumMinus(c, a, len_a, b, len_b);
	//BigNumPuls(c, a, len_a, b, len_b);
	printf("%d %d %d\n", strlen(c), sizeof(c), (MAX(len_a, len_b)+1));
	//if(c[0]=='0')
	//	i = 1;
	for(; i<strlen(c); i++)
		printf("%c", c[i]);
	printf("\n");
}

// 比较大数input1和input2绝对值的大小
int Compare(char input1[], unsigned int len1, char input2[], unsigned int len2)
{
	if(len1>len2) // 大数input1的绝对值大于input2的绝对值
		return 1;
	else if(len1<len2) // 大数input1的绝对值小于input2的绝对值
		return 2;
	else
	{
		unsigned int i=0,j=0;
		while(input1[i]==input2[i]) // 寻找第一个不等数字
			i++;
		if(i>=len1)  // 未发现不等数字，则大数input1和input2绝对值相等
			return 3;
		else  // 发现有不等数字
		{
			if(input1[i]>input2[i])  // 比较不等数字的大小
				return 1;
			else
				return 2;
		}
	}
}

// 计算大数input1和大数input2的差，其中大数input1>input2
void BigNumMinusGreater(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2)
{
	int CF=0; // 借位标志位
	unsigned int i,j;
	// 将较大的大数input1赋值给output，初始化output
	for(i=0; i<len1; i++)
		output[i+1] = input1[i];
	output[i+1] = '\0'; // +1是为了保留最高位的符号位，使得output比input多一位
	// 计算input1和input2公共部分
	for(i=0; i<len1&&i<len2; i++)
	{
		int a = input1[len1-i-1]-'0';
		int b = input2[len2-i-1]-'0';
		if(a-b-CF<0)  // 产生借位
		{
			output[len1-i] = (a+10-b-CF)%10 + '0';
			CF = 1;
		}
		else   // 未产生借位
		{
			output[len1-i] = (a-b-CF)%10 + '0';
			CF = 0;
		}
	}
	// 计算多出的部分
	for(j=i; j<len1; j++)
	{
		int a = output[len1-j]-'0';
		if(a-CF<0)   // 产生借位
		{
			output[len1-j] = (a+10-CF)%10 + '0';
			CF = 1;
		}
		else   // 未产生借位
		{
			output[len1-j] = (a-CF)%10 + '0';
			CF = 0;
		}
	}
}

void BigNumMinus(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2)
{
	int CR = Compare(input1, len1, input2, len2);
	switch(CR)
	{
	case 1:  // input1 > input2
		BigNumMinusGreater(output, input1, len1, input2, len2);
		break;
	case 2:  // input1 < input2
		BigNumMinusGreater(output, input2, len2, input1, len1);
		output[0] = '-';
		break;
	case 3:  // input1 = input2 
		output[0] = '0';
		break;
	default : return;
	}
}


void BigNumPuls(char output[], char input1[], unsigned int len1, char input2[], unsigned int len2)
{
	int CF=0;
	unsigned int i,j;
	unsigned int len3=MAX(len1, len2);
	// 将字符长度最大的字符串赋值给output
	if(len1>len2)
	{
		for(i=0; i<len1; i++)
			output[i+1] = input1[i];
	}
	else
	{
		for(i=0; i<len2; i++)
			output[i+1] = input2[i];
	}
	// 计算input1和input2公共部分
	for(i=0; i<len1&&i<len2; i++)
	{
		int a = input1[len1-i-1]-'0';
		int b = input2[len2-i-1]-'0';
		output[len3-i] = (a+b+CF)%10 + '0';
		CF = (a+b+CF)/10;
	}
	// 计算多出的部分
	for(j=i; j<len3; j++)
	{
		int a = output[len3-j]-'0';
		output[len3-j] = (a+CF)%10 + '0';
		CF = (a+CF)/10;
	}
	// 判断最高位是0还是1，取决于次高位是否产生进位
	if(CF==1)
		output[0] = '1';
	else
		output[0] = '0';
}