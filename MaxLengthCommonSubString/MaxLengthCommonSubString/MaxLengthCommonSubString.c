#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned FindSubString(char *src, char *dec)
{
	if(strlen(src)<strlen(dec))
		return 0;
	else
	{
		unsigned int i, j, k;
		char *tp=(char *)malloc(strlen(dec)+1);
		for(i=0; i<strlen(src)-strlen(dec)+1; i++)
		{	
			k = i;
			// 顺序取出原串中与目标串等长的子串
			for(j=0; j<strlen(dec); j++)
				tp[j] = src[k++];
			tp[j] = '\0';
			k = j = 0; // 清零，并作为比较目标串dec与原串中的子串tp的下标
			while(tp[j++]==dec[k++]); // 比较目标串dec与原串中的子串tp
			if(j>strlen(dec)) // 条件成立，表示匹配成功
			{
				free(tp);
				return i+1;
			}
		}
		free(tp);
		return 0;
	}
}

char *MLCS(char *str1, char *str2)
{
	unsigned int i, j;
	char *tp=(char *)malloc(strlen(str2)+1);
	char *ComStr=(char *)malloc(strlen(str2)+1);
	if(strlen(str1)>strlen(str2))
	{
		for(i=strlen(str2); i>0; i--)
		{
			for(j=0; j<i; j++)
				tp[j] = str2[j];
			tp[j] = '\0';
			if(FindSubString(str1, tp)>0)
			{
				//j = 0;
				//while(ComStr[j]=tp[j++]);
				//return ComStr;
				return tp;
			}
		}
		return NULL;
	}
	else
	{
		for(i=strlen(str1); i>0; i--)
		{
			for(j=0; j<i; j++)
				tp[j] = str1[j];
			tp[j] = '\0';
			if(FindSubString(str2, tp)>0)
			{
				//j = 0;
				//while(ComStr[j]=tp[j++]);
				//return ComStr;
				return tp;
			}
		}
		return NULL;
	}
	free(tp);
	free(ComStr);
}

void main()
{
	char *str1="abcdefg";
	char *str2="abcdgefgcdefg";
	char *str3=(char*)malloc(strlen(str2)+1);
	printf("%u\n", FindSubString(str1, str2));
	str3 = MLCS(str1, str2);
	printf("%s\n", str3);
	free(str3);
}