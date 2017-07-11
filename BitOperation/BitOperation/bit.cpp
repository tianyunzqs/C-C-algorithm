#include <iostream>
#include "CBitOperation.h"
using namespace std;

void main() {
	CBitOperation *cb = new CBitOperation();
	cout << cb->Is2pow(0) << endl;
	cout << cb->NumberofOne(15) << endl;
	cout << cb->NumberofZero(14) << endl;
	int a[] = {1,1,2,2,3,3,4,5,5,4,4};
	cout << cb->LostNumber1(a, sizeof(a)/sizeof(a[0])) << endl;
}

