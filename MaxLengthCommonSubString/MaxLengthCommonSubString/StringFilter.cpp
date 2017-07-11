#include <iostream>
#include <string>
using namespace std;
void StringFilter(char output[], char input[]);
void main()
{
	char a[]="ABCD22E";
	char *output = new char[2*strlen(a)+1];
	memset(output, 0, 2*strlen(a)+1);
	StringFilter(output, a);
	cout<<output<<endl;
}

void StringFilter(char output[], char input[])
{
	int i=1, j=0;
	int cnt=1;
	output[0] = input[0];
	while(input[i] != '\0')
	{
		if(input[i]==output[j])  // 对连续相同字符进行计数
			cnt++;
		else
		{
			output[++j] = cnt + '0';  // 将连续相同字符个数写入输出字符串中
			output[++j] = input[i];   // 将下一个连续不同的字符写入输出字符串
			cnt = 1;  // 计数器复位
		}
		i++; // 向前移动一个字符
	}
	output[++j] = cnt + '0';  // 将最后一个字符的个数写入输出字符串
}