//	N皇后问题

#include <iostream>
using namespace std;

#define N 8

bool matrix[N + 1][N + 1] = {0};

bool IsLegal(bool matrix[N + 1][N + 1], const int &i, const int &j)
{
	//	判断前面的i-1个棋子与matrix[i][j]是否冲突，i为1时合法

	for (int m = 1; m <= i - 1; ++m) {
		for (int n = 1; n <= N; ++n) {	//	实际每一行只有一个棋子
			if (matrix[m][n] == 1) {
				if ( n == j || abs(i - m) == abs(j - n) )	//	key, not bad
					return false;
			}
		}
	}
	return true;
}

void Print(bool matrix[N + 1][N + 1])
{
	static int count = 1;
	printf("Case %d:\n", count++);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			matrix[i][j] == 1 ? printf("%c ", 2) : printf(". ");
		}
		cout << endl;
	}
	cout << endl;
}

void Trial(const int i)
{
	//	进入本函数时，在N*N的棋盘前i-1行已放置了互不攻击的i-1个棋子
	//	现从第i行起继续为后续棋子选择合适位置

	if (i > N)	//	输出当前的合法布局
		Print(matrix);
	else
		for (int j = 1; j <= N; ++j) {
			matrix[i][j] = 1;
			if ( IsLegal(matrix, i, j) )
				Trial(i + 1);
			matrix[i][j] = 0;
		}
}

int main(void)
{
	Trial(1);

	return 0;
}