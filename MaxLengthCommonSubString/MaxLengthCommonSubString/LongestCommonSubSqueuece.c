#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))
void Getdp(int **dp, char str1[], int len1, char str2[], int len2);
void GetCommomSubSqueuece(char ComStr[], int **dp, char str1[], int len1, int len2);
void main()
{
	int i,j;
	char str1[]="AB34C";
	char str2[]="2AB1CD";
	char *ComStr;
	int len1=strlen(str1);
	int len2=strlen(str2);
	// 定义二级指针并申请内存空间，存放dp矩阵
	int **dp=(int **)malloc(sizeof(int)*len1);
	memset(dp, 0, (sizeof(int)*len1));
	for(i=0; i<len1; i++)
		dp[i] = (int *)malloc(sizeof(int)*len2);
	Getdp(dp, str1, len1, str2, len2);

	ComStr = (char *)malloc(sizeof(char)*(dp[len1-1][len2-1]+1));
	memset(ComStr, 0, (sizeof(char)*(dp[len1-1][len2-1]+1)));
	GetCommomSubSqueuece(ComStr, dp, str1, len1, len2);

	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}

	printf("the longest common string is : %s\n", ComStr);

	for(i=0; i<len1; i++)
		free(dp[i]);
	free(dp);
	free(ComStr);
}

// 获取dp矩阵
// dp[i][j]表示以str1[i]和str2[j]结尾的最长公共子序列（不要求连续）的长度
// dp[i][j]=max{dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1}
void Getdp(int **dp, char str1[], int len1, char str2[], int len2)
{
	int i, j;
	dp[0][0] = str1[0]==str2[0] ? 1 : 0;
	for(i=1; i<len1; i++)
		dp[i][0] = MAX(dp[i-1][0], str1[i]==str2[0] ? 1 : 0);
	for(j=0; j<len2; j++)
		dp[0][j] = MAX(dp[0][j-1], str1[0]==str2[j] ? 1 : 0);
	for(i=1; i<len1; i++)
	{
		for(j=1; j<len2; j++)
		{
			dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
			if(str1[i]==str2[j])
				dp[i][j] = MAX(dp[i][j], dp[i-1][j-1]+1);
		}
	}
}

// 获取最长公共子序列
// 根据dp矩阵的含义知，dp[i][j]是dp矩阵中最大的元素。
// 寻找最长公共子序列的过程如下：
// 从最大元素开始，沿着str1[i]==str2[j]，也即dp[i][j]=dp[i-1][j-1]+1，
// 直到i或j小于0
void GetCommomSubSqueuece(char ComStr[], int **dp, char str1[], int len1, int len2)
{
	int row = len1-1;
	int col = len2-1;
	int index=dp[row][col]-1; // dp[row][col]即最长公共子序列的长度
	while(index>=0)
	{
		if(row>0 && dp[row][col]==dp[row-1][col]) // 如果上下两个dp值相等，跳到上一行
			row--;
		else if(col>0 && dp[row][col]==dp[row][col-1]) // 如果左右两个dp值相等，跳到前一列
			col--;
		else
		{
			ComStr[index--] = str1[row];  // 找到公共子序列中的一个字符
			// 行列数各减1，跳到左上角继续寻找
			row--;
			col--;
		}
	}
}