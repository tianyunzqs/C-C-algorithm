#include <iostream>
#include <vector>
using namespace std;
#define MAX(x,y) ((x)>(y) ? (x) : (y))
void Chorus(int arr[], int len);
int Getdpmax(int arr[], int Tloc, int len);
void main()
{
	int arr[]={186, 186, 150, 200, 160, 130, 197, 200};
	//int arr[]={1, 5, 3, 4, 160, 130, 197, 200};
	int len=8;
	//Chorus(arr, len);
	for(int i=0; i<len; ++i)
		cout<<Getdpmax(arr, i, len)<<endl;
}

int Getdpmax(int arr[], int Tloc, int len)
{
	int *dp1 = new int[len];	
	for(int i=0; i<=Tloc; ++i)
	{
		dp1[i] = 1;
		for(int j=0; j<i; ++j)
		{
			if(arr[i]>arr[j])
				dp1[i] = MAX(dp1[i], dp1[j]+1);
		}
	}
	int max1 = dp1[0];
	for(int i=1; i<=Tloc; ++i)
		max1 = MAX(max1, dp1[i]);

	for(int i=Tloc; i<len; ++i)
	{
		dp1[i] = 1;
		for(int j=Tloc; j<i; ++j)
		{
			if(arr[i]<arr[j])
				dp1[i] = MAX(dp1[i], dp1[j]+1);
		}
	}
	int max2 = dp1[Tloc];
	for(int i=Tloc+1; i<len; ++i)
		max2 = MAX(max2, dp1[i]);
	delete[] dp1;
	return len - max1 - max2 + 1;
}

//void Chorus(int arr[], int len)
//{
//	int *dpUp = new int[len];
//	int *dpDown = new int[len];
//	for(int i=0; i<len; ++i)
//	{
//		dpUp[i] = 1;
//		for(int j=0; j<i; ++j)
//		{
//			if(arr[i]>arr[j] && dpUp[j]>dpUp[i])
//				dpUp[i] = dpUp[j] + 1;
//		}
//
//		dpDown[i] = 1;
//		for(int k=i+1; k<len; ++k)
//		{
//			if(arr[i]>arr[k] && dpDown[k]>dpDown[i])
//				dpDown[i] = dpDown[k] + 1;
//		}
//	}
//}