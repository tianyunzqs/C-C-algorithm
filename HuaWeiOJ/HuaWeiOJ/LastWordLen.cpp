#include<stdio.h>
#include<string.h>
int LastWordLen(char *str)
{
	int len=strlen(str);
	int cnt=0;
	int a=0;
	char *p=str+len-1;
	while(*(p--)==' ')
	{
		a++;
		if(a>=len)
			return cnt;
	}
	while(*(p+1)!=' ')
	{
		cnt++;
		a++;
		if(a>=len)
			return cnt;
		else
			p--;
	}
	return cnt;
}
void main()
{
	char str[128];
	int cnt;
	gets(str);
	cnt = LastWordLen(str);
	printf("%d\n", cnt);
}