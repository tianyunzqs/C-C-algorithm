//#include<stdio.h>  
//#include<string.h>  
//void main()  
//{  
//    char name[26][128];
//    int b[26]={0};  
//    int N;  
//    int i, j;  
//    scanf("%d", &N);  
//    for(i=0; i<N; i++)  
//        scanf("%s", name[i]);  
//    for(i=0; i<N; i++)  
//    {  
//		j=0;
//        while(name[i][j]!='\0')  
//        {  
//            if('a'<=name[i][j] &&name[i][j]<='z')  
//                b[i] += name[i][j]-96;  
//            if('A'<=name[i][j] &&name[i][j]<='Z')  
//                b[i] += name[i][j]-64;
//			j++;
//        }  
//    }  
//    for(i=0; i<N; i++)  
//        printf("%d ", b[i]);  
//}  

#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;
int Beauty(char a[])  //计算一个字符串的最大漂亮度
{
	int b[26]={0};  //存储每个字符的个数
	int sum=0;
	for(int i=0; a[i]!='\0'; i++)
		a[i]=tolower(a[i]);  //全部先转换成小写
	for(int i=0; a[i]!='\0'; i++)
		b[a[i]-97]++;
	sort(b,b+26);
	for(int i=25; i>=0; i--)
		sum+=(i+1)*b[i];
	return sum;
}

int main()
{   
	int M;
	char array[100][100];
	cin>>M;
	getchar(); //清除回车
	for(int i=0;i<M;i++)
		gets(array[i]);
	for(int i=0;i<M;i++)
		cout<<Beauty(array[i])<<endl; 
	return 0;
}