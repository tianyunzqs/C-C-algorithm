#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int theendnum = 0;
int sumData = 0;


int calc(char operateChar,int sum,string number){
	if(operateChar=='+'){
		sum+=atoi(number.c_str());
		//number.delete(0, number.length());
	}else if(operateChar=='-'){
		sum-=atoi(number.c_str());
		//number.delete(0, number.length());
	}
	return sum;
}

void showResult(int result[], FILE *fp)
{
	int sum = 0;
	char operateChar = '+';
	string source[] = {"1","2","3","4","5","6","7","8","9"};
	string number,expression;
	number += source[0];
	expression += source[0];

	for (int i=0; i<8; i++)
	{
		if(result[i]==0){//如果为0，表示数字合并
			number += (source[i+1]);
			expression+= (source[i+1]);
		}else if(result[i]==1){
			sum=calc(operateChar,sum,number);
			number.clear();
			operateChar='+';
			number += (source[i+1]);
			
			expression +=  ("+");
			expression +=(source[i+1]);
		}else if(result[i]==2){
			sum=calc(operateChar,sum,number);
			number.clear();
			operateChar='-';
			number += (source[i+1]);
			expression +=  ("-");
			expression +=(source[i+1]);
		}
	
	}
	sum=calc(operateChar,sum,number);
	if(sum==theendnum){
		sumData++;
	}	
	if(fp!=NULL)
		fprintf(fp, "%s\n", expression.c_str());
}

void getResult(int index, int result[], FILE *fp)
{
	if(index==8)
	{
		showResult(result, fp);
		return;
	}
	for(int i=0;i<3;i++)
	{
		result[index]=i;
		getResult(index+1,result, fp);
		result[index]=0; //恢复原来的状态
	}
}
int main()
{
	int result[8] = {0};
	cin>>theendnum;
	FILE *fp;
	if((fp = fopen("expression.txt", "r+"))==NULL)
		cout<<"can't open expression.txt !"<<endl;
	getResult(0, result, fp);
	cout<<sumData<<endl;
	fclose(fp);
	return 0;
}































//#include <iostream>
//#include <string>
//using namespace std;
//
//void getResult(int index,int result[])
//void showResult(int result[]);
//void main()
//{
////	int *result = new int[8];  // new返回的是一个指针
//	int result[8];
//	getResult(0,result);
//}
//
////使用递归求出3^8种情况
//void getResult(int index,int result[]){
//	if(index==8){
//		showResult(result);//根据数组的取值转换成表达式，且求值，这方法有待改进，写的很乱
//		return;
//	}
//	//每个空有三种可能，0,1,2
//	for(int i=0;i<3;i++){
//		result[index]=i;
//		getResult(index+1,result);
//		result[index]=0; //恢复原来的状态
//	}
//}
//void showResult(int result[]){
//		
//	int sum=0;
//	//默认在第一个数字，即1之前是"+"号，方便编程而已
//	char operateChar='+';
//	string source[]={"1","2","3","4","5","6","7","8","9"};
//	//最终的表达式，最好用StringBuilder，在非多线程的情况下，字符串拼接的性能，StringBuilder最好，
//	//当然用StringBuffer或者单纯的String也可以
//	StringBuilder expression=new StringBuilder();
//	//用于记录临时的数字，因为参与运算的数字可能是几位的数字，所以也需要拼接
//	StringBuilder number=new StringBuilder();
//	//先加入第一个字符，即1
//	number.append(source[0]);
//		
//	expression.append(source[0]);
//		
//	for(int i=0;i<result.length;i++){
//		if(result[i]==0){//如果为0，表示数字合并
//			number.append(source[i+1]);
//			expression.append(source[i+1]);
//		}else if(result[i]==1){
//			sum=calc(operateChar,sum,number);
//			operateChar='+';
//			number.append(source[i+1]);
//			expression.append("+").append(source[i+1]);
//		}else if(result[i]==2){
//			sum=calc(operateChar,sum,number);
//			operateChar='-';
//			number.append(source[i+1]);
//			expression.append("-").append(source[i+1]);
//		}
//	}
//	sum=calc(operateChar,sum,number);
//	if(sum==110){
//		System.out.print(expression.toString()+"=110");
//		System.out.println();
//	}
//}
//public static int calc(char operateChar,int sum,StringBuilder number){
//	if(operateChar=='+'){
//		sum+=Integer.parseInt(number.toString());
//		number.delete(0, number.length());
//	}else if(operateChar=='-'){
//		sum-=Integer.parseInt(number.toString());
//		number.delete(0, number.length());
//	}
//	return sum;
//} 
