#include <iostream>
using namespace std;
int Pick7(int num);
void main()
{
	int num = 20;
	cout<<Pick7(num)<<endl;
}

int Pick7(int num)
{
	int cnt=0;
	for(int i=1; i<=num; ++i)
	{
		if(i%7==0)
		{
			cout<<i<<" ";
			cnt++;
		}
		else
		{
			int tmp = i;
			while(tmp)
			{
				if(tmp%10==7)
				{
					cout<<i<<" ";
					cnt++;
					break;
				}
				tmp = tmp / 10;
			}
		}
	}
	return cnt;
}