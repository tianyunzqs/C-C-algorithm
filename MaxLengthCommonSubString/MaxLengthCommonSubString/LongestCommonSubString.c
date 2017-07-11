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
	// 定义二级指针并申请内存空间，存放dp矩阵
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

	// 获取dp矩阵元素的最大值及其对应的下标
	maxdp=dp[0][0], index=0;
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
		{
			if(dp[i][j]>maxdp)
			{
				maxdp = dp[i][j];  // dp矩阵的最大元素值
				index = i; // 最大元素值所对应的下标
			}
		}
	}
	// 根据dp的含义知，最长公共子串长度为maxdp，也即str1或str2中连续的maxdp个字符
	// 也即str1[index-maxdp ... index]
	ComSubStr = (char *)malloc(sizeof(char)*maxdp+1);
	memset(ComSubStr, 0, (sizeof(char)*maxdp+1)); // 初始化刚申请的内存单元
	for(i=maxdp-1; i>=0; i--)
		ComSubStr[i] = str1[index--];
	printf("the longest common substring is : %s\n", ComSubStr);
}

// 获取dp矩阵
// dp[i][j]表示必须以str1[i]和str2[j]结尾的最长公共子串的长度
// 如果str1[i]==str2[j]，则dp[i][j]=dp[i-1][j-1]+1
// 如果str1[i]!=str2[j]，则dp[i][j]=0
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
	// 定义二级指针并申请内存空间，存放dp矩阵
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

	// 获取dp矩阵元素的最大值及其对应的下标
	maxdp=dp[0][0], index=0;
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
		{
			if(dp[i][j]>maxdp)
			{
				maxdp = dp[i][j];  // dp矩阵的最大元素值
				index = i; // 最大元素值所对应的下标
			}
		}
	}
	// 根据dp的含义知，最长公共子串长度为maxdp，也即str1或str2中连续的maxdp个字符
	// 也即str1[index-maxdp ... index]
	ComSubStr = (char *)malloc(sizeof(char)*maxdp+1);
	memset(ComSubStr, 0, (sizeof(char)*maxdp+1)); // 初始化刚申请的内存单元
	for(i=maxdp-1; i>=0; i--)
		ComSubStr[i] = str1[index--];
	//printf("the longest common substring is : %s\n", ComSubStr);
}

int func1(const char)