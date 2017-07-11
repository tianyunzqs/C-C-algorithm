#include <iostream>
#include <stdlib.h>
using namespace std;
bool characterlegal(char *outStr, char str[]);
bool BracketsMatch(char str[]);
void main()
{
	//char *str="(1,(2,3),(4,(5,6),7))";
	char *str;
	gets(str);
	int len = strlen(str);
	char *outStr = new char[len+1];
	memset(outStr, 0, sizeof(char)*(len+1));
	if(BracketsMatch(str) && characterlegal(outStr, str))
	{
		int i;
		cout<<"(";
		for(i=0; i<strlen(outStr)-1; ++i)
			cout<<outStr[i]<<",";	
		cout<<outStr[i]<<")"<<endl;
	}
	else
		cout<<"error"<<endl;
	delete outStr;
}

bool characterlegal(char *outStr, char str[])
{
	size_t i=0, j=0;
	while(str[i]!='\0')
	{
		if(str[i]=='(' || str[i]==')' || str[i]==',' || (str[i]>='0' && str[i]<='9'))
		{
			if(str[i]>='0' && str[i]<='9')
			{
				outStr[j++] = str[i];
			}
			i++;
		}			
		else
			return false;
	}
	return true;
}

bool BracketsMatch(char str[])
{
	size_t i=0;
	int cnt=0;
	while(str[i]!='\0')
	{
		if(str[i]=='(')
			cnt++;
		if(str[i]==')')
		{
			cnt--;
			if(cnt<0)
				return false;
		}
		i++;
	}
	if(cnt==0)
		return true;
	else
		return false;
}