#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void DivideString(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int cnt;
	while(*pInputStr)
	{
		if(*pInputStr!=' ')
		{	cnt = 0;
			*pOutputStr++ = *pInputStr++;
		}
		else
		{	cnt++;
			pInputStr++;
			if(cnt==1)	
				*pOutputStr++ = ',';
		}		
	}
	*pOutputStr++ = ',';
	*pOutputStr = '\0';
}

void main()
{
	char *str = "abc def  gh i    d";
	int len = strlen(str);
	char *outstr = (char*)malloc(sizeof(str));
	//char outstr[100];
	DivideString(str,len,outstr);
	printf("%s\n",outstr);
}