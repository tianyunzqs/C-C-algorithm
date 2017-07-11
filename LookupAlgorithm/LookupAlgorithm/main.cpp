#include <iostream>
#include "Lookup.h"
#include <string>
using namespace std;

void main()
{
	//string a[] = { "s2", "s3"};
	//string s = "s2";
	CLookup instance;
	//if(instance.SequentialSearch(a, s, 2))
	//	cout << instance.GetLocation()<< endl;

	int b[] = { 3, 7, 24, 10, 11, 24, 45, 66, 77 };
	int c = 24;
	//cout << instance.IsIncreaseSeq(b, 9)<< endl;
	//if(instance.BinarySearch(b, c, 9))
	//	cout << instance.GetLocation()<< endl;
	if(instance.HashSearch(b, c, 9))
		cout << instance.GetLocation()<< endl;
}

