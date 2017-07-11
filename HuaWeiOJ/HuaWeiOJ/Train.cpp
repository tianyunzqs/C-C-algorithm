//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//void main()
//{
//	int a[]={1, 2, 3};
//	sort(a, a+3);
//	for(int i=0; i<3; ++i)
//		cout << a[i] << ends;
//	cout<<endl;
//	while(next_permutation(a, a+3))
//	{
//		for(int i=0; i<3; ++i)
//			cout << a[i] << ends;
//		cout<<endl;
//	}
//}










//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//// ��Ҫ���ֵ��������������õݹ鲻����������ʷ���
//// left��ʾʣ��û��ջ�����ָ�����vt������ս��,A��ʾ�û����������
//void Train(int left,int right,vector<int> &vt,int count,int A[])
//{
//	if(left<0 || right<left)//ʣ��û��ջ����С��0���߽�ջ����С�ڳ�ջ����
//		return ;
//	if(left>0)
//	{
//		vt[count]=1;
//		Train(left-1,right,vt,count+1,A);
//	}
//	if(right>left)
//	{
//		vt[count]=0;
//		Train(left,right-1,vt,count+1,A);
//	}
//	if(left==0 && right==0)
//	{
//		stack<int> stk;
//		int j=0;
//		for(int i=0;i<count;i++)
//			if(vt[i]==1)
//			{
//				stk.push(A[j]);
//				j++;
//			}
//			else
//			{
//				cout<<stk.top()<<" ";
//				stk.pop();
//			}
//			cout<<endl;
//	}
//}
//
//int main()
//{
//
//	int n=5;
//	vector<int> vt(2*n);
//	int A[]={1,2,3,4,5};
//	Train(5,5,vt,0,A);
//
//}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int num;
//	string str="ABCDEFGHIJ",a;
//	vector<string> tmp;
//	cin>>num; 
//	getchar();
//	getline(cin,a);
//	str=str.substr(0,num);
//	tmp.push_back(str);
//	while (next_permutation(str.begin(),str.end())) 
//		tmp.push_back(str);//�õ���ȫ����
//	for (int i=0;i<tmp.size();i++)
//	{
//		string s=tmp[i];
//		int len=s.size();
//		for (int j=0;j<len;j++)
//		{
//			if (s[j]>s[0])
//			{
//				s.erase(j);
//				len--;
//			}
//		}
//		string q=s;
//		sort(s.rbegin(),s.rend());
//		if(q!=s)
//			tmp.erase(i+tmp.begin()); 
//	}
//
//	for(int j=0;j<tmp.size();j++)
//		for (int i=0;i<num;i++)
//			replace(tmp[j].begin(),tmp[j].end(),str[i],a[i*2]);
//	sort(tmp.begin(),tmp.end());
//
//	for (int i=0;i<tmp.size();i++)
//	{
//		string m;
//		m=tmp[i];
//		for (int k=0;k<m.size();k++)
//		{
//			cout<<m[k];
//			if(k==m.size()-1)
//				cout<<endl;
//			else
//				cout<<" ";
//		}
//	}
//
//}



 

//[��Ϊ������ϰ��]13.�𳵽�վ
//��Ŀ
//����:     
//����һ��������N�����������0<N<10���������������վ�����У�һ��N���𳵣�ÿ����������1-9��š�Ҫ�����ֵ�����������𳵳�վ�����кš�
//
//��Ŀ���:    ջ 
//�Ѷ�:  �߼� 
//����ʱ������: 10Sec
//�ڴ�����:   128MByte
//�׶�:  ��ְǰ��ϰ 
//����:  
//�ж������������ÿһ���һ������һ��������N��0<N<10�����ڶ��а���N������������ΧΪ1��9��
//
//���:  
//������ֵ�������Ļ𳵳�վ���кţ�ÿ������Կո������ÿ��������л��У������sample��
//
//��������:   
//3
//1 2 3
//
//�������:   
//1 2 3
//1 3 2
//2 1 3
//2 3 1
//3 2 1
//˼·
//1����n=1��ô��һ�����з�ʽ��
//2��n>1ʱ�����n-1�ĳ�ջ˳���ٷֿ���n����n-1֮ǰ��n-1֮���ÿһ��n-1֮���ÿһ������
//����
///*---------------------------------------
//*   ���ڣ�2015-06-30
//*   ���ߣ�SJF0115
//*   ��Ŀ���𳵽�վ
//*   ��Դ����Ϊ�ϻ�
//-----------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void helper(string &inTrain,vector<string> &outTrain,int index)
{
    if(index == inTrain.size())
	{
        return;
    }//if
    if(index == 0)
	{
        string outNum("");
        outNum += inTrain[index];
        outTrain.push_back(outNum);
    }//if
    else
	{
        vector<string> newOutTrain;
        // ��ջ����
        int size = outTrain.size();
        // ��index���𳵽�ջ
        for(int i = 0;i < size;++i)
		{
            // ��i����ջ����
            int count = outTrain[i].size();
            // Ѱ��ǰһ����ջ�Ļ��±�
            int targetIndex;
            for(int j = 0;j < count;++j)
			{
                if(inTrain[index-1] == outTrain[i][j])
				{
                    targetIndex = j;
                    break;
                }//if
            }//for
            string tmp(outTrain[i]);
            for(int j = targetIndex;j <= count;++j)
			{
                tmp.insert(tmp.begin()+j,inTrain[index]);
                newOutTrain.push_back(tmp);
                tmp.erase(tmp.begin()+j);
            }//for
        }//for
        swap(outTrain,newOutTrain);
    }//else
    helper(inTrain,outTrain,index+1);
}

vector<string> TrainLeft(string inTrain){
    vector<string> result;
    int size = inTrain.size();
    if(size <= 0)
        return result;
    helper(inTrain,result,0);
    sort(result.begin(),result.end());
    return result;
}

int main()
{
    int n;
    while(cin>>n)
	{
        string train("");
        int num;
        for(int i = 1;i <= n;++i)
		{
            cin>>num;
            train += num + '0';
        }//for
        vector<string> trainNum = TrainLeft(train);
        // ���
        int size = trainNum.size();
        for(int i = 0;i < size;++i)
		{
            int count = trainNum[i].size();
            for(int j = 0;j < count;++j)
			{
                if(j == 0)
                    cout<<trainNum[i][j];
                else
                    cout<<" "<<trainNum[i][j];
            }//for
            cout<<"   "<<size<<endl;
        }//for
    }//while
    return 0;
}