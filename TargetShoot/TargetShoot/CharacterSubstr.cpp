#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void DoCombine(char in[], char out[], int len, int rec, int start)
{
	for(int i=start; i<len; ++i)
	{
		out[rec] = in[i];
		out[rec+1] = 0;
		cout<<out<<ends;
		if(i<len)
			DoCombine(in, out, len, rec+1, i+1);
	}
	cout<<endl;
}

void main()
{
	char str[] = "hart";
	int len = strlen(str);
	char* out = (char*)malloc(sizeof(char)*(len+1));
	DoCombine(str, out, len, 0, 0);
}