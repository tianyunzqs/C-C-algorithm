// �˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š�
// �����С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������
// 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
// ���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
// ��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

// ��������
//��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣�
//     ��������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
//��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ
//    ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
//��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��
//     ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
//��4������������Ʋ��������ȵ������

// ����ʾ��
// ��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
// ��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
// ��3�������˳���Ѿ�������С����������˲�����������.

#include <iostream>
#include <string.h>
using namespace std;
void CardCompare(char output[], char input[], int len);
int main()
{
    char input[] = "joker JOKER-K K K K";
    int len = strlen(input);
    char *output = new char[len];
    memset(output, 0, len);
    CardCompare(output, input, len);
    cout<<output<<endl;
    return 0;
}

// �����Ŀ�ʼ��С�ķ������αȽ�
void OneNumberCompare(char output[], char *str1, char *str2)
{
	if((str1=="JOKER") || (str2=="JOKER"))  // ��������к��д��������������
	{
		strcpy(output, "JOKER");
		return;
	}
	else if((str1=="joker") || (str2=="joker"))  // ��������к���С���������С��
	{
		strcpy(output, "joker");
		return;
	}
	else if((str1[0]=='2') || (str2[0]=='2'))  // ������ӡ����ӡ�������ը���к���2�����������2��������
	{
		strcpy(output, str1[0]=='2' ? str1 : str2);
		return;
	}
	else if(str1[0]=='1' && str1[1]=='0') // �����һ����Ϊ10����Ƚϵ�һ���ƵĴ�С
	{
		strcpy(output, str2[0]>10+'0' ? str2 : str1); 
		return;
	}
	else if(str2[0]=='1' && str2[1]=='0')  // �����һ����Ϊ10����Ƚϵ�һ���ƵĴ�С
	{
		strcpy(output, str1[0]>10+'0' ? str1 : str2);
		return;
	}
	else if(str1[0]>str2[0])  // ���Ǵ�С����2��10���������͵ıȽ�
	{
		strcpy(output, str1);
		return;
	}
	else
	{
		strcpy(output, str2);
		return;
	}
}

void CardCompare(char output[], char input[], int len)
{
	// ����������д��ڶ��������������
    if(strstr(input, "joker JOKER")!=NULL)
    {
        strcpy(output, "joker JOKER");
        return;
    }
    char *str1 = new char[len];  // ��ŵ�һ����
    char *str2 = new char[len];  // ��ŵڶ�����
    memset(str1, 0, len);
    memset(str2, 0, len);
    for(int i=0; i<len; ++i)
    {
        if(input[i]=='-')  // ��һ���ƺ͵ڶ�������'-'����
        {
            strncpy(str1, input, i);
            strncpy(str2, input+i+1, len-i-1);
			break;
        }
    }
	int cnt1=0, cnt2=0; // ������־�����Ƶ�����
	for(int i=0,j=0; i<strlen(str1)||j<strlen(str2); ++i,++j)
	{
		if(str1[i]==' ')
			cnt1++;
		if(str2[j]==' ')
			cnt2++;
	}
	if(cnt1==cnt2) // ���������������ͬ����˵����ͬ���͵��ƱȽϴ�С��ֻ��Ƚϵ�һ���ƾ���
	{
		OneNumberCompare(output, str1, str2);
	}
	else if(strlen(str1)==7 || strlen(str2)==7)  // �����������ֻ��һ���ƴ���ը������ֱ�������ը��
    {
        strcpy(output, strlen(str1)==7 ? str1 : str2);
        return;
    }
	else  // ���������������ͬ���Ҳ���ը������ô�޷��Ƚϴ�С�����"ERROR"
	{
		strcpy(output, "ERROR");
        return;
	}
}    