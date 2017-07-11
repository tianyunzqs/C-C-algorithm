#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partion(int a[], int low, int high)
{
	int baseV = a[low];
	while(low<high)
	{
		while(low<high && a[high]>=baseV)
			high--;
		swap(&a[low], &a[high]);
		while(low<high && a[low]<=baseV)
			low++;
		swap(&a[low], &a[high]);
	}
	return low;
}


//void QuickSort(int a[], int low, int high)
//{
//	if(low<high)
//	{
//		int t = partion(a, low, high);
//		QuickSort(a, low, t-1);
//		QuickSort(a, t+1, high);
//	}
//}

int QuickSort(int a[], int low, int high, int k)
{	
	//if(low >= high)
 //       return a[low];
 //   else
 //   {
 //       int mid = partion(a,low,high); //»®·Ö×ÓµÝ¹éÊý×é
 //       if(mid > k)
 //           QuickSort(a,low,mid-1,k); //×óµÝ¹é
 //       else if(mid < k)
 //           QuickSort(a,mid+1,high,k); //ÓÒµÝ¹é
 //       else
 //           return a[mid];
 //   }
	if(low >= high)
        return a[low];
    else
	{
		int t = partion(a, low, high);
		if(high-t==k-1)
			return a[t];
		else if(high-t>k-1)			
			QuickSort(a, t+1, high, k-1);
		else
			QuickSort(a, low, t-1, k-t-1);
	}
}


int BuBleSort(int a[], int len, int k)
{
	int i, j, exchange;
	for(i=0; i<k; i++)
	{
		exchange = 0;
		for(j=0; j<len-i-1; j++)
		{			
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				exchange = 1;
			}			
		}
		if(exchange==0)
			break;
	}
	return a[len-k];
}

void main()
{
	int a[]={52,33,52,89,76,12,25,64};
	int i;
	//int b = QuickSort(a, 0, 7, 1);
	int b = BuBleSort(a, 8, 2);
	printf("%d\n", b);
	//QuickSort(a, 0, 7);
	//for(i=0; i<8; i++)
	//	printf("%d ", a[i]);
	//printf("\n");
}