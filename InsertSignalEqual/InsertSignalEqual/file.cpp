#include <stdio.h>
#include <iostream>
using namespace std;
void main()
{
	FILE *fp;
	if((fp = fopen("expression.txt", "r+"))==NULL)
		cout<<"can't open the expression.txt file !"<<endl;
	else
		fprintf(fp, "%s\n", "adf");
}