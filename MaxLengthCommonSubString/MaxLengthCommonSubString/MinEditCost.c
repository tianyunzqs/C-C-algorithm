#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(x,y) ((x)<(y) ? (x) : (y))
#define ic 5  // �������(insert cost)
#define dc 3  // ɾ������(delete cost)
#define rc 2  // �滻����(replace cost)
void Getdp(int **dp, char str1[], int len1, char str2[], int len2);
void main()
{
	int i, j;
	char str1[]="";
	char str2[]="";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	// Ϊdp���������ڴ�ռ�
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
	// dp��������½�Ԫ�ؼ�Ϊ���յ���С�༭����
	printf("the minimum edit cost is : %d\n", dp[len1-1][len2-1]);
}

// ��ȡ��С�༭����
// dp[i][j]�ĺ�����str1[0..i]��str2[0..j]����С�༭����
// ��str1[i]==str2[j]ʱ��dp[i][j]=dp[i-1][j-1]
// ��str1[i]!=str2[j]ʱ��str1[0..i]��str2[0..j]����С�༭���۵���
// 1����str1[0..i-1]��str2[0..j-1]����С�༭���ۼ���str1[i]��str2[j]����С�༭���ۣ�min{rc, dc+ic}��
// 2����str1[0..i-1]��str2[0..j]����С�༭���ۼ���һ���������
// 3����str1[0..i]��str2[0..j-1]����С�༭���ۼ���һ��ɾ������
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