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
		if(input[i]==output[j])  // ��������ͬ�ַ����м���
			cnt++;
		else
		{
			output[++j] = cnt + '0';  // ��������ͬ�ַ�����д������ַ�����
			output[++j] = input[i];   // ����һ��������ͬ���ַ�д������ַ���
			cnt = 1;  // ��������λ
		}
		i++; // ��ǰ�ƶ�һ���ַ�
	}
	output[++j] = cnt + '0';  // �����һ���ַ��ĸ���д������ַ���
}