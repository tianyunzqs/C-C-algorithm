#include <iostream>
using namespace std;
bool FindChar(char* pInputString, char* pChar);
void main()
{
	char* pInputString = "asdfasdff";
	char* pChar = new char[2];
	memset(pChar, 0, sizeof(char)*2);
	if(FindChar(pInputString, pChar))
		cout<<*pChar<<endl;
	else
		cout<<"."<<endl;
}

bool FindChar(char* pInputString, char* pChar)
{
	int hash[256];
	memset(hash, 0, sizeof(hash));
	int i=0;
	char *p = pInputString;
	while(*(p+i) != '\0')
	{
		hash[*(p+i)]++;
		i++;
	}
	i = 0;
	while(*(pInputString+i) != '\0')
	{
		if(hash[*(pInputString+i)] == 1)
		{
			*pChar = *(pInputString+i);
			return true;
		}
		i++;
	}
	return false;
}