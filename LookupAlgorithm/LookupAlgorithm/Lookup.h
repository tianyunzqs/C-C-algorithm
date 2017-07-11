#pragma once

class CLookup
{
private:
	int Loc;
	

public:
	CLookup(void);
	~CLookup(void);

	int GetLocation();


	bool HashSearch(int Array[], int target, int length);

	template<class T>
	bool IsIncreaseSeq(T Array[], int length)
	{
		for (int i=0,j=1; i<length-1,j<length; ++i,++j)
		{
			if (Array[i] > Array[j])
			{
				return false;
			}
		}
		return true;
	}

	template<class T>
	bool SequentialSearch(T Array[], T target, int length)
	{
		for (int i=0; i<length; ++i)
		{
			if(target == Array[i])
			{
				Loc = i;  // �ҵ��ˣ�����λ��
				return true;
			}
		}
		Loc = -1;  // û�ҵ�
		return false;
	}

	template<class T>
	bool BinarySearch(T Array[], T target, int length)
	{
		int low = 0;
		int high = length-1;
		while(low <= high)
		{		
			int middle = (low+high)/2;
			if (target == Array[middle])
			{
				Loc = middle;
				return true;
			} 
			else if(target < Array[middle])
			{
				high = middle - 1;
			}
			else
			{
				low = middle + 1;
			}
		}
		Loc = -1;
		return false;
	}
};

