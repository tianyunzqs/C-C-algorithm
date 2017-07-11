#include<stdio.h>

void sort(int input[], int n, int output[])
{
	int temp, i, j;
	for(i=1; i<n; i++)
	{
		temp = input[i];
		for(j=i-1; j>=0&&temp<input[j]; j--)
			input[j+1] = input[j];
		input[j+1] = temp;
	}

	j = n-1;
	output[n/2] = input[j--];
	for(i=1; i<=n/2; i++)
	{
		output[n/2-i] = input[j--];
		output[n/2+i] = input[j--];
	}
}

void main()
{
	int a[]={3, 6, 1, 9, 7, 8};
	int b[6];
	int i;
	sort(a, 6, b);
	for(i=0; i<6; i++)
		printf("%d ", b[i]);
}