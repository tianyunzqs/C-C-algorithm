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
		if(result[i]==0){//���Ϊ0����ʾ���ֺϲ�
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
		result[index]=0; //�ָ�ԭ����״̬
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
////	int *result = new int[8];  // new���ص���һ��ָ��
//	int result[8];
//	getResult(0,result);
//}
//
////ʹ�õݹ����3^8�����
//void getResult(int index,int result[]){
//	if(index==8){
//		showResult(result);//���������ȡֵת���ɱ��ʽ������ֵ���ⷽ���д��Ľ���д�ĺ���
//		return;
//	}
//	//ÿ���������ֿ��ܣ�0,1,2
//	for(int i=0;i<3;i++){
//		result[index]=i;
//		getResult(index+1,result);
//		result[index]=0; //�ָ�ԭ����״̬
//	}
//}
//void showResult(int result[]){
//		
//	int sum=0;
//	//Ĭ���ڵ�һ�����֣���1֮ǰ��"+"�ţ������̶���
//	char operateChar='+';
//	string source[]={"1","2","3","4","5","6","7","8","9"};
//	//���յı��ʽ�������StringBuilder���ڷǶ��̵߳�����£��ַ���ƴ�ӵ����ܣ�StringBuilder��ã�
//	//��Ȼ��StringBuffer���ߵ�����StringҲ����
//	StringBuilder expression=new StringBuilder();
//	//���ڼ�¼��ʱ�����֣���Ϊ������������ֿ����Ǽ�λ�����֣�����Ҳ��Ҫƴ��
//	StringBuilder number=new StringBuilder();
//	//�ȼ����һ���ַ�����1
//	number.append(source[0]);
//		
//	expression.append(source[0]);
//		
//	for(int i=0;i<result.length;i++){
//		if(result[i]==0){//���Ϊ0����ʾ���ֺϲ�
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
