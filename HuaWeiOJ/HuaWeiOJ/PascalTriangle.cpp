#include <iostream>
using namespace std;
int CalVaule(int row, int index);
void main()
{
	int row;
	cin>>row;
	int i;
	for(i=1; i<=2*row-1; ++i)
	{
		if(CalVaule(row, i)%2==0)
		{
			cout<<i<<endl;
			break;
		}
	}
	if(i>2*row-1)
		cout<<-1<<endl;
}

int CalVaule(int row, int index)
{
	if(index<1 || index>2*row-1)
		return 0;
	else if(index==1 || index==2*row-1)
		return 1;
	else 
		return CalVaule(row-1, index-2) + CalVaule(row-1, index-1) + CalVaule(row-1, index);
}