#include <iostream>
#include <algorithm>
using namespace std;
void main()
{
	int hash[256];
	memset(hash, 0, sizeof(hash));
	char *pInputString="Ihave1nose2hands10fingers";
	cout<<pInputString<<endl;
	int i=0;
	char *p = pInputString;
	while(*(p+i)!='\0')
	{
		hash[*(p+i)]++;
		i++;
	}
	char *pOutputString = new char[strlen(pInputString)+1];
	memset(pOutputString, 0, sizeof(char)*(strlen(pInputString)+1));
	int k=0;
	for(int i=0; i<256; ++i)
	{
		for(int j=0; j<hash[i]; ++j)
		{
			*(pOutputString+k) = i;  // ASCIIÂë¶ÔÓ¦µÄ×Ö·û
			k++;
		}
	}
	cout<<pOutputString<<endl;
}