#include <iostream>
using namespace std;
int sum;
int store[10];
 
//打印函数，符合要求的则把它打印出来
//void Output()
//{
//	for(int i = 9; i >= 0; i--)
//		cout << store[i] << " ";
//	cout << endl;
//	++sum; 
//}
 
//递归函数
void Cumput(int score, int num)
{
	//如果已经打的总环数超过90，此时score<0，或者剩下即使每次都打10环也无法打到
	//90环，则退出循环
	if(score<0 || score>(num+1)*10)  //次数num为0~9
		return ;
 
	//如果满足条件且达到最后一次。
	if(num == 0)
	{++sum;
		//store[num] = score;
		//Output();
		//return ;
	}
 
	for(int i=0; i<=10; ++i)
	{
		//store[num] = i;
		Cumput(score-i, num-1);
	}
}
 
int main()
{
	Cumput(90, 10);
	cout << "总数: " << sum << endl;
	return 0;
}