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
		lastloc = loc;  // 记录最后一个分号的位置
		temp = str.substr(loc+1, temp.length()-loc-1); // 取出分号后面的字符串
		str = str.substr(0, loc-1);		 // 取出分号前的字符串
		if(LegalCheck(dir, val, str))
		{
			cout<<dir<<ends<<val<<endl;
			CoordinateMove(output, dir, val);
		}
		str = temp;  // 分号前的一个字符串处理完毕后，将分号后的字符串当做新的字符串进行处理
		loc = str.find_first_of(';'); // 检测第一个分号出现的位置
	}
	if(loc == -1)
	{
		temp = temp.substr(0, lastloc-1);  // 将最后一个分号后面的字符串取出，作为最后一个串
		if(LegalCheck(dir, val, temp))
		{
			cout<<dir<<ends<<val<<endl;
			CoordinateMove(output, dir, val);
		}
	}
	cout<<output[0]<<","<<output[1]<<endl;
}

// 一次操作合法性检查，如果合法，则返回true和方向和数字；
// 如果不合法，则返回false
bool LegalCheck(char &dir, int &val, string str)
{
	if(str=="")
		return false;
	int i=0, j=0;
	int len = str.length();
	// 去掉操作前面的空格
	while(*(str.c_str()+i)==' ')
		i++;
	str = str.substr(i, len-i);
	len = str.length();
	// 去掉操作后面的空格
	while(*(str.c_str()+len-1-j)==' ')
		j++;
	str = str.substr(0, len-j);
	if(str=="")
		return false;

	const char *s = str.c_str();

	i = 0;
	// 如果操作首字母为下列字母之一
	if(*(s+i)=='A' || *(s+i)=='a' || *(s+i)=='D' || *(s+i)=='d' ||\
		*(s+i)=='W' || *(s+i)=='w' || *(s+i)=='S' || *(s+i)=='s')
	{
		dir = *(s+i);  // 取出操作的方向
		if(*(s+i+1) == '\0')  // 如果本次操作只含一个操作的方向
			return false;
		else // 如果操作方向的后面还有字符
		{
			i++;	// 跳到操作方向的下一个字符
			// 操作方向后面如果只有一个数字
			if(*(s+i)>='0' && *(s+i)<='9' && *(s+i+1) == '\0')
			{
				val = *(s+i) - '0';
				return true;
			}
			// 操作方向后面如果只有二个数字
			else if(*(s+i)>='0' && *(s+i)<='9' && *(s+i+1)>='0' && *(s+i+1)<='9' && *(s+i+2) == '\0')
			{
				val = *(s+i) - '0';
				val *= 10;
				val += *(s+i+1) - '0';
				return true;
			}
			// 操作方向后面如果只有二个数字和'+','-'
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
	else // 如果操作首字母不为上面所列字母之一
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