#ifndef _BIT_OPERATION_H
#define _BIT_OPERATION_H

class CBitOperation {
public:
	bool Is2pow(int num);
	bool Is2pow_1(int num);
	bool Is2pow_2(int num);

	int NumberofOne(int num);
	int NumberofZero(int num);

	int LostNumber1(int num[], int len);
	int LostNumber2(int num[], int len);
};

#endif