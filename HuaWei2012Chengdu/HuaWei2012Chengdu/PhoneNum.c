#include<stdio.h>
#include<string.h>
int verifyMsisdn(char *inMsisdn)
{
	if(strlen(inMsisdn)!=13)
		return 1;
	else
	{
		while(*inMsisdn)
			if('0'<=*inMsisdn && *inMsisdn<='9')
				inMsisdn++;
			else
				return 2;
		if(*(inMsisdn-13)!='8' && *(inMsisdn-12)!='6')
			return 3;
	}
	return 0;
}

void main()
{
	char *inMsisdn = "8618875208991";
	printf("%d\n", verifyMsisdn(inMsisdn));
}