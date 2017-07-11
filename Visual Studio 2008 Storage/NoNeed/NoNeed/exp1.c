#include<stdio.h>

//int i;
//
//fun(int a, int *b)
//{
//	static int m=2;
//	i += m+a;
//	m = ++(*b);
//	printf("%d, %d\n", i, m);
//	return (m);
//}


//void fun(int c, int d, int *PPC, int *PLC, int *PPH, int *PLH)
//{
//	*PPC = c*c - d*d;
//	*PLC = c*c*c - d*d*d;
//	*PPH = c*c + d*d;
//	*PLH = c*c*c + d*d*d;
//	return;
//}

//double fun1(int x)
//{
//	double sum=0;
//	if (!x)
//		sum = 0;
//	else
//		sum = x + fun1(x-1);
//	return sum;
//}
//
//double fun2(int y)
//{
//	double sum=1;
//	if (y==1)
//		sum = 1;
//	else
//		sum = y * fun2(y-1);
//	return sum;
//}


void main()
//int main(int argc, const char *argv[])
{
	//int i, j;
	//double sum=0;
	//printf("%f\n", fun2(5));  // 阶乘
	//printf("%f\n", fun1(5));  // 加
	//for (i=1;i<=6;i++)
	//	for(j=1;j<=i;j++)
	//		sum = sum + fun2(j);
	//printf("%f\n", sum);
	//int i, j=0, k, n;
	//printf("请输入整数n = ");
	//scanf("%d", &n);
	//for(i=1; i<=n; i++)
	//{
	//	j++;
	//	for(k=i; k>0; k--)
	//		printf("%d", j);
	//	printf("\n");
	//}



	//int a[]={1,2,3,4,5,6,7,8,9,0},*p; 
	//p=a;
	//printf("%d",*p+9);



	//int a, b, m=5, y=2;
	//y+=y-=m*=y;
	//printf("%d\n", y);
	//b = (a=4*5,a*2), a+6;
	//printf("%d,%d\n", a, b);

	int i;
	//printf("%d, %d\n", i, (i=3,i++,++i,i+5));
	printf("%d, %d\n", i,(i=3,++i,++i,i+5));
	


	//int j=0, k, n, x;
	//printf("请输入整数n = ");
	//scanf("%d", &n);
	//
	//for(j=1; j<=2*n-1; j+=2)
	//{
	//	for(k=n-(j+1)/2; k>0; k--)
	//	printf(" ");
	//	for(x=j; x>0; x--)
	//		printf("*");
	//	printf("\n");
	//}

	//int a[10] = {6,7,2,9,5,10,4,3,8,1};
	//int *p=a, i;
	//for(i=0;i<10;i++,p++)
	//	if(*a < *p)
	//		*a = *p;
	//printf("%d", *a);
	/*int a, x=1, y=0;
	a = x-->y+x ? 5 : 25>y++ ? '1' : '2';
	printf("%c\n", a);*/

	//float x=2, y;
	//y = x++*x++;
	//printf("x = %f\ty = %f", x, y);


	/*int x, y;
	while(scanf("%d%d",&x,&y)==2)
		printf("x = %d\ty = %d", x, y);
	printf("OVER");*/


//	int arr[] = {6, 7, 8, 9, 10};
//	int *ptr = arr;
//	*(ptr++) += 123;
//	printf("%d\n", *ptr);
////	printf("%d, %d\n", *ptr, *(++ptr)); // C语言中printf计算参数时是从右到进行计算的

	//int a;
	//a = 7 + 4.3;
	//printf("a = %d\n", a);

	//char a[] = "aaaaaaa";
	//char *b  = "aaaaaaa";
	//printf("%d，%d\n", sizeof(a), sizeof(b));

	//printf("sizeof(long long) = %d\n", sizeof(long long));
	//long long a[] = { 0, 0, 0 };
	//long long *b = 0;
	//long long *c = a;


	//int i=1, j=2;
	//fun(fun(i, &j), &j);


	//char s[2][5] = {"8345", "3967"}, *p[2];
	//int i, j, t=0;
	//for(i=0; i<2; i++)
	//	p[i] = s[i];

	//for(i=0; i<2; i++)
	//	printf("%s\t", p[i]);

	//for(i=0; i<2; i++)
	//	for(j=0; p[i][j]!='\0'; j+=2)
	//		t = t*10 + p[i][j] - '0';
	//printf("%d\n", t);


	//int i;
	//for(i=0; ; i++)
	//{
	//	printf("dsfa");
	//	break;
	//}


	//int k=3, s[2];
	//s[0]=k; 
	//k=s[1]*10;
	//printf("%d\n", s[1]);
	//printf("%d\n", k);


	//char str[] = "123456789", *p=str;
	//int index=0;
	//while (*p++ != '\0')
	//	index++;
	//printf("%d\n",index);
	//printf("%c\n", *(str2+3));



	
	//int i=8; 
	//printf("%d\n%d\n%d\n%d\n%d\n",--i,i++,i--,-i++,-i--); 


	//int *p = 8;
	//printf("%d\n", *p);
	//printf("%d\n", p);
	//printf("%d\n", &p);

	//for (i=index-1; i>=0; i--)
	//{
	//	if (str[i] != '*')
	//	{
	//		printf("1");
	//		//Loc = i-1;
	//		//break;
	//	}
	//	else
	//		printf("0");
	//}
	//printf("%d, %d\n", index, Loc);



	
	//char a = 8451;
	//printf("%c\n", a);
	//printf("%d\n", 8451%256);


	//printf("sizeof(int) = %d\n", sizeof(int));
	//printf("sizeof(char) = %d\n", sizeof(char));
	//printf("sizeof(float) = %d\n", sizeof(float));
	//printf("sizeof(double) = %d\n", sizeof(double));
	//printf("sizeof(short) = %d\n", sizeof(short));
	//printf("sizeof(long) = %d\n", sizeof(long));

	////char b[][] = {'SEG0','SEG2','SEG33','SEG35','SEG37','SEG11','SEG16'}; //第一个寄存器
	////char *b[][7] = {{"SEG0"},{"SEG2"},{"SEG33"},{"SEG35"},{"SEG37"},{"SEG11"},{"SEG16"}}; //第一个寄存器
	//char b[][5] = {{'S','E','G','0'},{'S','E','G','2','4'}}; //第一个寄存器
	//int i;
	//for(i=0; i<5; i++)
	//	printf("%c", b[0][i]);
	//printf("\n");


	//int *PC = 0, *LC=0, *PH=0, *LH=0;
	//fun(5,4,PC,LC,PH,LH);
	//printf("%d,%d,%d,%d", *PC, *LC, *PH, *LH);
	
}	