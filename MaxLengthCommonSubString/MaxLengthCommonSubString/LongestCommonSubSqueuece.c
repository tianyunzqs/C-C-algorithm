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
	// �������ָ�벢�����ڴ�ռ䣬���dp����
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

// ��ȡdp����
// dp[i][j]��ʾ��str1[i]��str2[j]��β������������У���Ҫ���������ĳ���
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

// ��ȡ�����������
// ����dp����ĺ���֪��dp[i][j]��dp����������Ԫ�ء�
// Ѱ������������еĹ������£�
// �����Ԫ�ؿ�ʼ������str1[i]==str2[j]��Ҳ��dp[i][j]=dp[i-1][j-1]+1��
// ֱ��i��jС��0
void GetCommomSubSqueuece(char ComStr[], int **dp, char str1[], int len1, int len2)
{
	int row = len1-1;
	int col = len2-1;
	int index=dp[row][col]-1; // dp[row][col]������������еĳ���
	while(index>=0)
	{
		if(row>0 && dp[row][col]==dp[row-1][col]) // �����������dpֵ��ȣ�������һ��
			row--;
		else if(col>0 && dp[row][col]==dp[row][col-1]) // �����������dpֵ��ȣ�����ǰһ��
			col--;
		else
		{
			ComStr[index--] = str1[row];  // �ҵ������������е�һ���ַ�
			// ����������1���������ϽǼ���Ѱ��
			row--;
			col--;
		}
	}
}