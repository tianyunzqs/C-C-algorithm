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
//// 主要是字典排序输出结果，用递归不好排序输出故放弃
//// left表示剩余没进栈的数字个数，vt存放最终结果,A表示用户输入的数字
//void Train(int left,int right,vector<int> &vt,int count,int A[])
//{
//	if(left<0 || right<left)//剩余没进栈个数小于0或者进栈个数小于出栈个数
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
//		tmp.push_back(str);//得到了全排列
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



 

//[华为机试练习题]13.火车进站
//题目
//描述:     
//给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号。要求以字典序排序输出火车出站的序列号。
//
//题目类别:    栈 
//难度:  高级 
//运行时间限制: 10Sec
//内存限制:   128MByte
//阶段:  入职前练习 
//输入:  
//有多组测试用例，每一组第一行输入一个正整数N（0<N<10），第二行包括N个正整数，范围为1到9。
//
//输出:  
//输出以字典序排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。
//
//样例输入:   
//3
//1 2 3
//
//样例输出:   
//1 2 3
//1 3 2
//2 1 3
//2 3 1
//3 2 1
//思路
//1、若n=1那么就一种排列方式。
//2、n>1时先求出n-1的出栈顺序，再分开将n插入n-1之前，n-1之后和每一个n-1之后的每一个数！
//代码
///*---------------------------------------
//*   日期：2015-06-30
//*   作者：SJF0115
//*   题目：火车进站
//*   来源：华为上机
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
        // 出栈序列
        int size = outTrain.size();
        // 第index辆火车进栈
        for(int i = 0;i < size;++i)
		{
            // 第i个出栈序列
            int count = outTrain[i].size();
            // 寻找前一个进栈的火车下标
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
        // 输出
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