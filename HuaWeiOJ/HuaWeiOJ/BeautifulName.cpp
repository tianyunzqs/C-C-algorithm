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
int Beauty(char a[])  //����һ���ַ��������Ư����
{
	int b[26]={0};  //�洢ÿ���ַ��ĸ���
	int sum=0;
	for(int i=0; a[i]!='\0'; i++)
		a[i]=tolower(a[i]);  //ȫ����ת����Сд
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
	getchar(); //����س�
	for(int i=0;i<M;i++)
		gets(array[i]);
	for(int i=0;i<M;i++)
		cout<<Beauty(array[i])<<endl; 
	return 0;
}