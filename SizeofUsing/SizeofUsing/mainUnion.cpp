#include <iostream>
using namespace std;

union A
{
	char a;
	short b;
};
void main()
{
	cout<<sizeof(A)<<endl;  // 2

}