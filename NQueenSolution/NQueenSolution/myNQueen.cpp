#include <iostream>
#include <math.h>
using namespace std;
#define N 8
bool chessboard[N][N] = {0};
bool IsLegeal(bool chessboard[N][N], int row, int col)
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<N; ++j)	
		{
			if(chessboard[i][j])
			{
				// 下面的if不行，不知道原因
				// if(j==col || abs(row-col)==abs(i-j) || row+col==i+j)
				// 如果处于同一斜线上，则斜率为+-1
				if(j==col || abs(row-i)==abs(col-j))
					return false;
			}
		}
	}
	return true;
}

void Print(bool matrix[N][N])
{
	static int count = 1;
	printf("Case %d:\n", count++);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] == 1 ? printf("%c ", 2) : printf(". ");
		}
		cout << endl;
	}
	cout << endl;
}

void func(int row)
{
	if(row==N)
		Print(chessboard);
	else
	{
		for(int j=0; j<N; ++j)
		{
			chessboard[row][j] = 1; // 放置皇后
			if(IsLegeal(chessboard, row, j))
				func(row+1);
			// 如果前次的皇后放置导致后面的放置无论如何都不能满足要求
			// 则回溯，重置
			chessboard[row][j] = 0;
		}
	}
}

void main()
{
	func(0);
}