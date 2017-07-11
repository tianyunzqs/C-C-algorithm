#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define ic 5  // 插入代价(insert cost)
#define dc 3  // 删除代价(delete cost)
#define rc 2  // 替换代价(replace cost)
void Getdp(int **dp, char str1[], int len1, char str2[], int len2);
void main()
{
	int i, j;
	char str1[]="";
	char str2[]="";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	// 为dp矩阵申请内存空间
	int **dp = (int **)malloc(sizeof(int)*len1); 
	for(i=0; i<len1; i++)
		dp[i] = (int *)malloc(sizeof(int)*len2);
	Getdp(dp, str1, len1, str2, len2);
	printf("the matrix of dp is as follow : \n");
	for(i=0; i<len1; i++)
	{
		for(j=0; j<len2; j++)
			printf("%4d", dp[i][j]);
		printf("\n");
	}
	// dp矩阵的右下角元素即为最终的最小编辑代价
	printf("the minimum edit cost is : %d\n", dp[len1-1][len2-1]);
}

// 获取最小编辑代价
// dp[i][j]的含义是str1[0..i]到str2[0..j]的最小编辑代价
// 当str1[i]==str2[j]时，dp[i][j]=dp[i-1][j-1]
// 当str1[i]!=str2[j]时，str1[0..i]到str2[0..j]的最小编辑代价等于
// 1、从str1[0..i-1]到str2[0..j-1]的最小编辑代价加上str1[i]到str2[j]的最小编辑代价（min{rc, dc+ic}）
// 2、从str1[0..i-1]到str2[0..j]的最小编辑代价加上一个插入代价
// 3、从str1[0..i]到str2[0..j-1]的最小编辑代价加上一个删除代价
void Getdp(int **dp, char str1[], int len1, char str2[], int len2)
{
	int i, j;
	dp[0][0] = str1[0]==str2[0] ? 0 : (MIN(rc, dc+ic));
	for(i=1; i<len1; i++)
		dp[i][0] = dp[i-1][0] + dc;
	for(j=1; j<len2; j++)
		dp[0][j] = dp[0][j-1] + ic;
	for(i=1; i<len1; i++)
	{
		for(j=1; j<len2; j++)
		{
			int b , c, d;
			if(str1[i]==str2[j])
				dp[i][j] = dp[i-1][j-1];
			else
			{
				b = dp[i][j-1] + ic;
				c = dp[i-1][j] + dc;
				d = dp[i-1][j-1] + MIN(rc, dc+ic);
				dp[i][j] = MIN(b, MIN(c, d));
			}			
		}
	}
}