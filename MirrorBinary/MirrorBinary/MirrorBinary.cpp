#include<iostream>
#include<string>
#include<math.h>
using namespace std;
void Dec2Bin(char output[], int num);
void Bin2Hex(char output[], char input[]);
char Data2HexCharateric(size_t data);

void main()
{
	char bin[33];
	char hex[8];
	int num;
start:	printf("Input data : ");
	scanf("%d", &num);
	Dec2Bin(bin, num);
	for(int i=strlen(bin)-1; i>=0; i--)
	{
		printf("%c", bin[i]);
		if(i%4==0)
			printf(" ");
	}
	printf("\n");

	size_t len=strlen(bin);
	for(size_t i=0; i<len/2; i++)
	{
		char c;
		c = bin[i];
		bin[i] = bin[len-1-i];
		bin[len-1-i] = c;
	}

	Bin2Hex(hex, bin);
	for(int i=strlen(hex)-1; i>=0; i--)
		printf("%c", hex[i]);
	printf("\n");
	goto start;
}


// 十进制数到二进制的转换（正负都可以）
void Dec2Bin(char output[], int num)
{
	size_t index=0;
	if(num>=0)
		for(size_t i=0; i<32; i++)
			output[i] = '0';
	else
		for(size_t i=0; i<32; i++)
			output[i] = '1';
	output[32] = '\0';
	size_t tmp = abs(num);
	while(tmp>0)
	{
		output[index++] = tmp%2 + '0';
		tmp = tmp/2;		
	}
	if(num<0)
	{
		// 取反
		for(size_t i=0; i<index; i++)
			output[i] = !(output[i]-'0') + '0';
		// 加1
		// 由于正数二进制的最高位始终为1，所以取反后，进行加1操作的时候
		// 不用考虑最高位产生进位的问题，不会产生进位
		size_t CF=1;
		for(int i=index-1; i>=0; i--)
		{
			size_t a=output[index-i-1]-'0';
			output[index-i-1] = (a+CF)%2 + '0';
			CF = (a+CF)/2;
		}
	}
}

void Bin2Hex(char output[], char input[])
{
	size_t k=0;
	size_t len=strlen(input);
	size_t a;
	for(int i=len/4; i>0; i--)
	{
		size_t index = len-1-(len/4-i)*4;
		a = (input[index]-'0')+2*(input[index-1]-'0')+4*(input[index-2]-'0')+8*(input[index-3]-'0');
		output[k++] = Data2HexCharateric(a);
	}
	output[k] = '\0';
	switch(strlen(input)%4)
	{
	case 1:
		a = input[0]-'0';
		break;
	case 2:
		a = 2*(input[0]-'0')+(input[1]-'0');
		break;
	case 3:
		a = 4*(input[0]-'0')+2*(input[1]-'0')+(input[2]-'0');
		break;
	default :
		return;
	}
	output[k++] = Data2HexCharateric(a);
	output[k] = '\0';
}

char Data2HexCharateric(size_t data)
{
	if(data<10)
		return data + '0';
	else
		switch(data)
		{
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		}
}