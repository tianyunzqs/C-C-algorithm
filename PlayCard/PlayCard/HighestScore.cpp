// 老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。
// 当然，老师有时候需要更新某位同学的成绩. 
// 输入描述:
// 输入包括多组测试数据。
// 每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
// 学生ID编号从1编到N。
// 第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
// 接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,
// 当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
// 当C为'U'的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
//
//
// 输出描述:
// 对于每一次询问操作，在一行里面输出最高成绩.
//
// 输入例子:
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
// 输出例子:
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
	while(cin>>N>>M)  // 由于是输入包括多组测试数据，所以需要循环输入，但是会造成死循环
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
				// 进行查询的时候，如果前一个数大于后一个数，那么交换两数位置
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

// 更新数组a
void Updata(int a[], int ID, int score)
{
	a[ID-1] = score;
}
//获取数组a中从lowID到highID之间的最高分数，并返回
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