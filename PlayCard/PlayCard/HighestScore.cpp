// ��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ�
// ��Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�. 
// ��������:
// �����������������ݡ�
// ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
// ѧ��ID��Ŵ�1�ൽN��
// �ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
// ��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,
// ��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У��ɼ���ߵ��Ƕ���
// ��CΪ'U'��ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��
//
//
// �������:
// ����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.
//
// ��������:
// 5 7
// 1 2 3 4 5
// Q 1 5
// U 3 6
// Q 3 4
// Q 4 5
// U 4 5
// U 2 9
// Q 1 5
//
// �������:
// 5
// 6
// 5
// 9


#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void Updata(int a[], int ID, int score);
int GetHighestScore(int a[], int low, int high);
int main()
{
	int N, M;
	while(cin>>N>>M)  // �����������������������ݣ�������Ҫѭ�����룬���ǻ������ѭ��
	{
		int *a = new int[N];
		for(int i=0; i<N; ++i)
			cin>>a[i];
		int *res = new int[M];
		int k=0;
		for(int i=0; i<M; ++i)
		{
			char ch;
			int LowNum, HighNum;
			cin>>ch>>LowNum>>HighNum; 
			if(ch == 'Q')
			{
				// ���в�ѯ��ʱ�����ǰһ�������ں�һ��������ô��������λ��
				if(LowNum>HighNum)
					res[k++] = GetHighestScore(a, HighNum, LowNum);
				else
					res[k++] = GetHighestScore(a, LowNum, HighNum);
			}
			if(ch == 'U')
				Updata(a, LowNum, HighNum);
		}
		for(int i=0; i<k; ++i)
			cout<<res[i]<<endl;
	}
}

// ��������a
void Updata(int a[], int ID, int score)
{
	a[ID-1] = score;
}
//��ȡ����a�д�lowID��highID֮�����߷�����������
int GetHighestScore(int a[], int lowID, int highID)
{
	int max = a[lowID-1];
	for(int i=lowID; i<highID; ++i)
	{
		if(max<a[i])
			max = a[i];
	}
	return max;
}