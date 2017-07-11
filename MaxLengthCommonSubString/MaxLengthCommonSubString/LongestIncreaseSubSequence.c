#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y) ? (x) : (y))

// 获取dp数组
// dp[i]表示以arr[i]结尾的最长递增子序列长度
int *Getdp(int arr[], int len)
{
	int *dp=(int *)malloc(sizeof(int)*len);
	int i,j;
	for(i=0; i<len; i++)
	{
		dp[i] = 1;
		for(j=0; j<i; j++)
			if(arr[i]>arr[j])
				dp[i] = MAX(dp[i], dp[j]+1); // 等价于求max{dp[j]+1}
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
	
	// 获取dp数组的最大值及其所对应的下标
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

	// 从最大递增子序列的最后一个元素开始获取，
	// 如果原序列中第i个元素小于子序列中的第index个元素，而且dp[i]==dp[index]-1
	// 那么原序列中第i个元素就可以作为递增子序列的第index-1个元素
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