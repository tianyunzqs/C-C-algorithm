#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))

// ��ȡdp����
// dp[i]��ʾ��arr[i]��β������������г���
int *Getdp(int arr[], int len)
{
	int *dp=(int *)malloc(sizeof(int)*len);
	int i,j;
	for(i=0; i<len; i++)
	{
		dp[i] = 1;
		for(j=0; j<i; j++)
			if(arr[i]>arr[j])
				dp[i] = MAX(dp[i], dp[j]+1); // �ȼ�����max{dp[j]+1}
	}
	return dp;
}

void main()
{
	int arr[]={2,1,5,3,6,4,8,9,7};
	int len=sizeof(arr)/sizeof(arr[0]);
	int *dp, *result;
	int i, maxVal, maxVal2, index=0;
	dp = Getdp(arr, len);
	
	// ��ȡdp��������ֵ��������Ӧ���±�
	maxVal = dp[0];
	for(i=1; i<len; i++)
	{
		if(maxVal<dp[i])
		{
			maxVal = dp[i];
			index = i;
		}
	}
	maxVal2 = maxVal;
	printf("the matrix of dp : ");
	for(i=0; i<len; i++)
		printf("%d ", dp[i]);
	printf("\n");

	// �������������е����һ��Ԫ�ؿ�ʼ��ȡ��
	// ���ԭ�����е�i��Ԫ��С���������еĵ�index��Ԫ�أ�����dp[i]==dp[index]-1
	// ��ôԭ�����е�i��Ԫ�ؾͿ�����Ϊ���������еĵ�index-1��Ԫ��
	result = (int *)malloc(sizeof(int)*maxVal);
	result[--maxVal] = arr[index];
	for(i=index; i>=0; i--)
	{
		if(arr[i]<arr[index] && dp[i]==dp[index]-1)
		{
			result[--maxVal] = arr[i];
			index = i;
		}
	}
	printf("the longest increasing subsqueue of arr is : ");
	for(i=0; i<maxVal2; i++)
		printf("%d ", result[i]);
	printf("\n");
	free(result);
}