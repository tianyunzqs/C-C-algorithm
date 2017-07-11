#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
bool LegalCheck(char &dir, int &val, string str);
void CoordinateMove(int output[], char dir, int val);
void main()
{
	char dir;
	int val;
	int output[2];
	memset(output, 0, sizeof(output));
	string str = "  A%A-78  ;D+34  ;;;";
	string temp = str;
	int loc = str.find_first_of(';');
	int lastloc = str.length();
	while(loc>0)
	{
		lastloc = loc;  // ��¼���һ���ֺŵ�λ��
		temp = str.substr(loc+1, temp.length()-loc-1); // ȡ���ֺź�����ַ���
		str = str.substr(0, loc-1);		 // ȡ���ֺ�ǰ���ַ���
		if(LegalCheck(dir, val, str))
		{
			cout<<dir<<ends<<val<<endl;
			CoordinateMove(output, dir, val);
		}
		str = temp;  // �ֺ�ǰ��һ���ַ���������Ϻ󣬽��ֺź���ַ��������µ��ַ������д���
		loc = str.find_first_of(';'); // ����һ���ֺų��ֵ�λ��
	}
	if(loc == -1)
	{
		temp = temp.substr(0, lastloc-1);  // �����һ���ֺź�����ַ���ȡ������Ϊ���һ����
		if(LegalCheck(dir, val, temp))
		{
			cout<<dir<<ends<<val<<endl;
			CoordinateMove(output, dir, val);
		}
	}
	cout<<output[0]<<","<<output[1]<<endl;
}

// һ�β����Ϸ��Լ�飬����Ϸ����򷵻�true�ͷ�������֣�
// ������Ϸ����򷵻�false
bool LegalCheck(char &dir, int &val, string str)
{
	if(str=="")
		return false;
	int i=0, j=0;
	int len = str.length();
	// ȥ������ǰ��Ŀո�
	while(*(str.c_str()+i)==' ')
		i++;
	str = str.substr(i, len-i);
	len = str.length();
	// ȥ����������Ŀո�
	while(*(str.c_str()+len-1-j)==' ')
		j++;
	str = str.substr(0, len-j);
	if(str=="")
		return false;

	const char *s = str.c_str();

	i = 0;
	// �����������ĸΪ������ĸ֮һ
	if(*(s+i)=='A' || *(s+i)=='a' || *(s+i)=='D' || *(s+i)=='d' ||\
		*(s+i)=='W' || *(s+i)=='w' || *(s+i)=='S' || *(s+i)=='s')
	{
		dir = *(s+i);  // ȡ�������ķ���
		if(*(s+i+1) == '\0')  // ������β���ֻ��һ�������ķ���
			return false;
		else // �����������ĺ��滹���ַ�
		{
			i++;	// ���������������һ���ַ�
			// ��������������ֻ��һ������
			if(*(s+i)>='0' && *(s+i)<='9' && *(s+i+1) == '\0')
			{
				val = *(s+i) - '0';
				return true;
			}
			// ��������������ֻ�ж�������
			else if(*(s+i)>='0' && *(s+i)<='9' && *(s+i+1)>='0' && *(s+i+1)<='9' && *(s+i+2) == '\0')
			{
				val = *(s+i) - '0';
				val *= 10;
				val += *(s+i+1) - '0';
				return true;
			}
			// ��������������ֻ�ж������ֺ�'+','-'
			else if((*(s+i)=='+' || *(s+i)=='-') && *(s+i+1)>='0' && *(s+i+1)<='9' && *(s+i+2)>='0' && *(s+i+2)<='9' && *(s+i+3) == '\0')
			{
				val = *(s+i+1) - '0';
				val *= 10;
				val += *(s+i+2) - '0';
				if(*(s+i)=='-')
					val = -val;
				return true;
			}
			else
				return false;
		}
	}
	else // �����������ĸ��Ϊ����������ĸ֮һ
		return false;
}

void CoordinateMove(int output[], char dir, int val)
{
	switch(dir)
	{
	case 'A' :
	case 'a' :
		output[0] -= val;
		break;
	case 'D' :
	case 'd' :
		output[0] += val;
		break;
	case 'W' :
	case 'w' :
		output[1] += val;
		break;
	case 'S' :
	case 's' :
		output[1] -= val;
		break;
	default:
		return;
	}
}