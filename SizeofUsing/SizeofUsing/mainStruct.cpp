#include <iostream>
using namespace std;

struct A
{
	char a;
	char c;
	short b;
};
struct B
{
	char a;	
	short b;
	char c;
};
struct C
{
	char a;
	int b;
	double c;
};
struct D
{
	char a : 5;
	char b : 2;
	short c : 1;
};
struct E
{
	char a : 5;
	short c : 1;
	char b : 2;
};
struct F
{
	char a : 5;
	int c : 1;
	char b : 2;
};
void main()
{
	cout<<sizeof(A)<<endl;  // 4 (见解释1)
	cout<<sizeof(B)<<endl;  // 6 (见解释2)
	cout<<sizeof(C)<<endl;  // 16 (见解释3)
	cout<<sizeof(D)<<endl;  // 4 (见解释4)
	cout<<sizeof(E)<<endl;  // 6 (见解释5)
	cout<<sizeof(F)<<endl;  // 12 (见解释6)
}