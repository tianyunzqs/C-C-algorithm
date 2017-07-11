#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int fun(char *res, char* str, int n);
#define MAX(x,y) ((x)>(y) ? (x) : (y))
void main()
{
    char *s = "2b3adb4db";
    int n =strlen(s);
    int outsum;
	char *res = new char[n/2+1];//(char *)malloc(sizeof(char)*(n/2+1))
	memset(res, 0, n/2+1);
    outsum = fun(res, s, n);
    cout << outsum << endl;
	cout<<res<<endl;
}
int fun(char *res, char* str, int n)
{
    char *temp = new char[n/2+1];
    char *str2 = str;
    int cnt=0, maxcnt=0;
    char* t;
    for(int i=0; i<=n/2; i++)
    {
        for(int j=2; j<=n-i; j++)
        {
            cnt = 0;
            str2 = str;
            memset(temp,0,(n/2+1)*sizeof(char));
            strncpy(temp, str+i, j);
            while((t = strstr(str2,temp)) != NULL)
            {
                cnt++;
                str2 = t+j;
				if(cnt>1 && strlen(temp)>strlen(res))
					strcpy(res, temp);
				maxcnt = MAX(cnt, maxcnt);
            }
        }       
    }
    if(maxcnt == 1)
		return 0;
    return maxcnt;
}