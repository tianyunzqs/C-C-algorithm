#include<stdio.h>
#include<string.h>
void main()
{
	char str[20];
	int len, i, j, val=0, cnt=0;
	gets(str);
	//scanf("%s", str);
	len = strlen(str);
	for(i=0; i<len-1; i++)
	{
		if(str[i]=='.')
		{
			cnt++;
			continue;
		}
		else if(str[i]<'0' || str[i]>'9' || str[0]=='.')
		{
			puts("NO");
			//goto s;
			return;
		}
	}
	if(cnt!=3)
	{
		puts("NO");
		//goto s;
		return;
	}
	for(i=len-1; i>=0; i--)
	{
		val = -1;
		j=1;
		while(str[i]!='.' && i>=0)
		{
			val += (str[i] - '0')*j;
			i--;
			j *= 10;
		}
		if(val+1>255)
		{
			puts("NO");
			//goto s;
			return;
		}
	}
	puts("YES");
	//goto s;
}