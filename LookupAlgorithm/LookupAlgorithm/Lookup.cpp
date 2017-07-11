#include "Lookup.h"
#include <iostream>
using namespace std;
//#include <stdlib.h>
CLookup::CLookup(void){}

CLookup::~CLookup(void){}

int CLookup::GetLocation()
{
	return Loc;
}

static struct HashIndex
{
	int data;   // ������������
	int index;  // ���������±�
};

static void CreatHashTable(HashIndex *HashTable, int Array[], int length)
{
	for (int i=0; i<length; ++i)
	{
		int index = Array[i] % length;
		while(HashTable[index].data != 0)
		{
			index = (++index) % length;
		}
		HashTable[index].data = Array[i];
		HashTable[index].index = i;
	}
}

bool CLookup::HashSearch(int Array[], int target, int length)
{
	HashIndex *HashTable = new HashIndex[(sizeof(int)*length)*2];
	for (int i=0; i<length; ++i)
	{
		HashTable[i].data = 0;
		HashTable[i].index = 0;
	}
	//int *HashTable = (int *)malloc(sizeof(int)*length);
	CreatHashTable(HashTable, Array, length);
	int index = target % length;
	int startLoc = index; // ��ʼѰ�ҵ�λ��
	while(HashTable[index].data != target)
	{		
		index = (++index) % length;
		if (index == startLoc)  // �������һ�飬δ�ҵ�
		{
			Loc = -1;
			return false;
		}
	}
	Loc = HashTable[index].index;
	return true;
}