#include <iostream>
using namespace std;
int sum;
int store[10];
 
//��ӡ����������Ҫ����������ӡ����
//void Output()
//{
//	for(int i = 9; i >= 0; i--)
//		cout << store[i] << " ";
//	cout << endl;
//	++sum; 
//}
 
//�ݹ麯��
void Cumput(int score, int num)
{
	//����Ѿ�����ܻ�������90����ʱscore<0������ʣ�¼�ʹÿ�ζ���10��Ҳ�޷���
	//90�������˳�ѭ��
	if(score<0 || score>(num+1)*10)  //����numΪ0~9
		return ;
 
	//������������Ҵﵽ���һ�Ρ�
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
	cout << "����: " << sum << endl;
	return 0;
}