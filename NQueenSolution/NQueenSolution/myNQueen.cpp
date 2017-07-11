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
				// �����if���У���֪��ԭ��
				// if(j==col || abs(row-col)==abs(i-j) || row+col==i+j)
				// �������ͬһб���ϣ���б��Ϊ+-1
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
			chessboard[row][j] = 1; // ���ûʺ�
			if(IsLegeal(chessboard, row, j))
				func(row+1);
			// ���ǰ�εĻʺ���õ��º���ķ���������ζ���������Ҫ��
			// ����ݣ�����
			chessboard[row][j] = 0;
		}
	}
}

void main()
{
	func(0);
}