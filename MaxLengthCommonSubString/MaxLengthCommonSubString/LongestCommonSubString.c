#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Getdp(int **dp, char str1[], int len1, char str2[], int len2);
void main()
{
	int i,j;
	char str1[] = "abcdefg";
	char str2[] = "abcdgefgcdefg";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char *ComSubStr;
	int maxdp, index;
	// �������ָ�벢�����ڴ�ռ䣬���dp����
	int **dp = (int **)malloc(sizeof(int)*len1);
	for(j=0; j<len2; j++)
		dp[j] = (int *)malloc(sizeof(int)*len2);
	Getdp(dp, str1, len1, str2, len2);
	printf("the matrix of dp is as follow : \n");
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}

	// ��ȡdp����Ԫ�ص����ֵ�����Ӧ���±�
	maxdp=dp[0][0], index=0;
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
		{
			if(dp[i][j]>maxdp)
			{
				maxdp = dp[i][j];  // dp��������Ԫ��ֵ
				index = i; // ���Ԫ��ֵ����Ӧ���±�
			}
		}
	}
	// ����dp�ĺ���֪��������Ӵ�����Ϊmaxdp��Ҳ��str1��str2��������maxdp���ַ�
	// Ҳ��str1[index-maxdp ... index]
	ComSubStr = (char *)malloc(sizeof(char)*maxdp+1);
	memset(ComSubStr, 0, (sizeof(char)*maxdp+1)); // ��ʼ����������ڴ浥Ԫ
	for(i=maxdp-1; i>=0; i--)
		ComSubStr[i] = str1[index--];
	printf("the longest common substring is : %s\n", ComSubStr);
}

// ��ȡdp����
// dp[i][j]��ʾ������str1[i]��str2[j]��β��������Ӵ��ĳ���
// ���str1[i]==str2[j]����dp[i][j]=dp[i-1][j-1]+1
// ���str1[i]!=str2[j]����dp[i][j]=0
void Getdp(int **dp, char str1[], int len1, char str2[], int len2)
{
	int i, j;
	for(i=0; i<len1; i++)
		dp[i][0] = str1[i]==str2[0] ? 1 : 0;
	for(j=0; j<len2; j++)
		dp[0][j] = str2[j]==str1[0] ? 1 : 0;
	for(i=1; i<len1; i++)
		for(j=1; j<len2; j++)
			dp[i][j] = str1[i]==str2[j] ? dp[i-1][j-1]+1 : 0;
}


void GetComStr(char *ComSubStr, char str1[], int len1, char str2[], int len2)
{
	int i,j;
	int maxdp, index;
	// �������ָ�벢�����ڴ�ռ䣬���dp����
	int **dp = (int **)malloc(sizeof(int)*len1);
	for(j=0; j<len2; j++)
		dp[j] = (int *)malloc(sizeof(int)*len2);
	Getdp(dp, str1, len1, str2, len2);
	//printf("the matrix of dp is as follow : \n");
	//for(i=0; i<len1; i++)
	//{
	//	for(j=0; j<len2; j++)
	//		printf("%d ", dp[i][j]);
	//	printf("\n");
	//}

	// ��ȡdp����Ԫ�ص����ֵ�����Ӧ���±�
	maxdp=dp[0][0], index=0;
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
		{
			if(dp[i][j]>maxdp)
			{
				maxdp = dp[i][j];  // dp��������Ԫ��ֵ
				index = i; // ���Ԫ��ֵ����Ӧ���±�
			}
		}
	}
	// ����dp�ĺ���֪��������Ӵ�����Ϊmaxdp��Ҳ��str1��str2��������maxdp���ַ�
	// Ҳ��str1[index-maxdp ... index]
	ComSubStr = (char *)malloc(sizeof(char)*maxdp+1);
	memset(ComSubStr, 0, (sizeof(char)*maxdp+1)); // ��ʼ����������ڴ浥Ԫ
	for(i=maxdp-1; i>=0; i--)
		ComSubStr[i] = str1[index--];
	//printf("the longest common substring is : %s\n", ComSubStr);
}

int func1(const char)