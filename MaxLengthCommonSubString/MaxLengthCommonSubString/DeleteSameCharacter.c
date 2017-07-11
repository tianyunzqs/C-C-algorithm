#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))
void DeleteSameCharacter(const char* pInputStr , int lInputLen , char* pOutputStr);
void main()
{
	char str[]="abba23c!@@#";
	int len = strlen(str);
	char *pOutputStr = (char *)malloc(sizeof(char)*(len+1));
	memset(pOutputStr, 0, sizeof(char)*(len+1));
	DeleteSameCharacter(str , len , pOutputStr);
	printf("the string after deleting the same characters is : %s\n", pOutputStr);
}

void DeleteSameCharacter(const char* pInputStr , int lInputLen , char* pOutputStr)
{  
	int hash[256] = {0};    //统计字符是否出现  
    int i , j;  
    for(i = 0 , j = 0 ; i < lInputLen; ++i)  
    {  
        if(0 == hash[pInputStr[i]])     //该字符还木有出现过  
        {  
            hash[pInputStr[i]] = 1;  
            pOutputStr[j++] = pInputStr[i];  
        }  
    }  
    pOutputStr[j] = '\0';  
}