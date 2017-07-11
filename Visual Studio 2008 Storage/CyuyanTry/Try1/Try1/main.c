#include <stdio.h>

//struct sss
//{
//	int x;
//	char y[5];
//};
//
//union aaa
//{
//	int x;
//	char y;
//};

void main()
{
////	printf("hello world!\n");
//	char a[5] = "sdfa";
//	char *t;
//	int i;
//	t = a;
//	for(i=0; i<4; i++)
//	{
//		if(*(t+i)=='d')
//			printf("hello world!\n");
//	}

	//unsigned int t[100][65];
	////t = 10000;

	//printf("%d\n", &t[0][0]);
	//printf("%d\n", &t[56][22]);

//	struct sss s;
//union aaa a;
//
//	printf("%d\n", sizeof(s));
//
//	printf("%d\n", sizeof(a));
	
	float num;
	double x;
	scanf("%f", &x);
	printf("x：%f", x);



start:	printf("请输入学生成绩(0~100)：");
	scanf("%f", &num); // 允许输入小数如：85.5
	if(num<0 || num>100)
	{
		printf("成绩输入错误，请重新输入\n");
		goto start;
	}
	switch((int)num/10)
	{
	case 10 :
	case 9:
			{printf("A\n"); break;}
	case 8:
			{printf("B\n"); break;}
	case 7:
			{printf("C\n"); break;}
	case 6:
			{printf("D\n"); break;}
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
			{printf("E\n"); break;}
	default:
			printf("error\n");
	}

}