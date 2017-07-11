#include<iostream>
#include<string>
using namespace std;
bool BracketsMatch(char str[]);
void main()
{
	char a[]="a)((df(sdf)df(df))";
	cout<<BracketsMatch(a)<<endl;
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