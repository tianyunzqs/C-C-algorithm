//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//#include<windows.h>
//#include <setjmp.h>
//#include <time.h>
//// ���Լ������
//int GreatestCommonDivisor(int m, int n)
//{
//	int temp;
//	if(m<n)
//	{
//		m = m^n;
//		n = n^m;
//		m = m^n;
//	}
//	temp = m % n;
//	while(temp)
//	{
//		m = n;
//		n = temp;
//		temp = m % n;
//	}
//	return n;
//}
//
//// ��С��Լ������
//int LeastCommonMultiple(int m, int n)
//{
//	return m*n/GreatestCommonDivisor(m,n);
//}

//char* delet(char str[],int n)
//{
//	char *p=str;
//	int i, j=0;
//	for(i=0; i<n; i++)
//		if(str[i] != '*')
//		{
//			*(p+j) = str[i];
//			j++;
//		}
//	*(p+j) = '\0';
//	return p;
//}

//void reverse(char *s, int len) 
//{ 
//	char ch; 
//	if (len>1) 
//	{ 
//		ch = *s; 
//		*s = *(s+len-1); 
//		*(s+len-1) = ch; 
//		reverse(s+1, len-2); 
//	} 
//}

//void str_copy(char *str1, char *str2)
//{
//    while(*str1++ = *str2++);
//}

//void (*p[2])(int*, int);


//void e(int n)
//{
//	if (n > 0)
//	{
//		e(-n);
//		printf("%d ", n);
//		e(-n);
//	}
//}


//int ripple(int n, ...)
//{
//	int i, j, k;
//	va_list p;
//	k = 0;
//	j = 1;
//	va_start(p, n);
//	for (; j < n; ++j)
//	{
//		i = va_arg(p, int);
//		printf("%d\n", i);
//		for (; i; i &= i - 1)
//		++k;
//	}
//	return k;
//}


//void fun(int *ptr1, int *ptr2)
//{
//	//int *tmp = ptr2;
//	*ptr1 *= 10;
//	*ptr2 *= 10;
//	ptr2 = ptr1;
//	//*ptr1 = tmp;
//}

//void get_str(char** p)
//{
//    *p = (char*)malloc(sizeof("abcd"));
//    printf("%d\n", sizeof("abcd"));
//    strcpy(*p, "abcd");
//    return;
//}

//// λ��
//typedef struct
//{
//	char a:5;
//	char b:2;
//	int c:1;
//}demo;

//void GetMemory(char **p, int num){
//*p = (char *)malloc(num);
//}
//char *GetMemory(void){
//char *p = (char *)malloc(100);;
//return p;
//}
//int inc(int a)
//{
//return(++a);
//}

//#define swap(x, y)\
//x = x + y;\
//y = x - y;\
//x = x - y;
//
// #define SQUARE(a) ((a)*(a))
//typedef struct  AA
//{
//        int b1:5;
//        int b2:2;
//}AA;

//void g(int**p)
//{
//(**p)++;
//(*p)++;// ��Ч
//}
//
// �ַ����������
//void fun(char *a)
//{
//	if(*a=='\0')
//		return;
//	else
//	{
//		fun(a+1);
//		printf("%c", *a);
//	}
//}

//int disp(char *str)
//{
//	while( *str)
//	putchar(*str++);
//	putchar('#');
//	return *str;  // '\0'ת��Ϊint��������0
//}
//#define a "��"
//void main()
//{
//	char b[101];
//	int num=5;
//	pid_t pid;
//	time_t t, t2;
//	t = time(&t);
//	printf("xxx,�㰮��ô?\n");
//	printf("����һСʱʱ��,������ѡ��.\n");
//	printf("������3600��ʱ��");
//	//system("shutdown -s -t 3600");
//	while (1)
//	{
//		int i;
//		t2 = time(&t2);
//		for(i=18; i>0; --i)
//			printf("\b");
//		printf("������%d��ʱ��", 3600 - (t2 - t));
//		//while(num--)
//		//{
//			scanf("%s", b);
//			if (!strcmp(a, b))
//			{
//				//system("shutdown -a");
//				printf("лл,��Ҳ����!");
//				exit(0);
//			}
//			system("cls");
//			printf("�����һ����ĵ�\n");
//		//}
//	}



//char ch = 255; // ����unsigned charҲһ��
//printf("%d , %d , %d\n" , ch , ch + 1 , ch + 2);

//int x=3, y;
//y=++x+x+++x++;
//printf("%d %d\n", x, y);

// C�����е�const������ʱconst������ʱֻ�Ƕ��壬�����вŻ��ʼ����
// C������const�����������ڳ�Ϊ���鳤�ȵ���Ϊ����ʱ�����������ԭ����ڴˡ�
// C����const����������ʱ�ı����ǿ����ٴζ����ı���ֵ�ġ�
//
// C++�У�const�����Ǳ���ʱ�ĳ�����������#define����ĳ���һ��ʹ�á�
// ��C++��const������ֵ�ڱ���ʱ���Ѿ�ȷ���ˣ�ֱ�Ӷ�cosnt����������ֵ���滻��
// ��˵�const������ֵ�ı�ʱ��const�ı���ֵ�ǲ���õ����µġ�
//const int i = 0; 
//int *j = (int *) &i; 
//*j = 1; 
//printf("%d,%d", i, *j);


	//printf("%d\n",disp("C##123"));


	//int a[]={10,6,9,5,2,8,4,7,1,3};
	//int i,temp;
	//for(i=0; i<10; i++)
	//{
	//	if(a[i]!=i+1)
	//	{
	//		temp = a[a[i]-1];
	//		a[a[i]-1] = a[i];
	//		a[i] = temp;
	//		i--;
	//	}
	//}
	//for(i=0; i<10; i++)
	//	printf("%d ", a[i]);
	//printf("\n");
	//char *a="1234567890";
	//fun(a);


	//AA aa;
 //       char cc[100];
 //        strcpy(cc,"0123456789abcdefghijklmnopqrstuvwxyz");
 //      memcpy(&aa,cc,sizeof(AA));
 //       printf("%x\n",aa.b1);
 //       printf("%d\n",aa.b2);
	//	printf("%x\n", -1);

	//	struct BBB
 //{
 //long num;
 //char *name;
 //short int data;
 //char ha;
 //short ba[5];
 //}*p;
 //p=(struct BBB*)0x1000000;
 //printf("%x\n", p);
 //printf("%x\n", p+0x200);
 //printf("%x\n", (unsigned long)p+0x200);
 //printf("%x\n", (unsigned long*)p+0x200);
 

//int line[10],i;
//int *p=line; //p�ǵ�ַ�ĵ�ַ
//for (i=0;i<10;i++)
//{
//	*p=i;
//	g(&p);// �����Ӧ��ֵ��1
//}
//for(i=0;i<10;i++)
//	printf("%d\n",line[i]);
//	int (*p)(int)=&inc;
//int temp =p(10);
//printf("%d\n",temp);

	//unsigned char *p1;
 //   unsigned long *p2;
 //   p1=(unsigned char *)0x801000;
 //   p2=(unsigned long *)0x810000;
	//printf("%x\n", p1+5);
	//printf("%x\n", p2+5);

	// int a=5;
 //   int b;
 //   b=SQUARE(a++);
	//printf("%d,%d\n",a,b);
	//swap(a,b);
	//printf("%d,%d\n",a,b);


	//int a[5]={1,2,3,4,5};
 //  int *ptr=(int *)(&a);
 //  printf("%d\n", a);
 //  printf("%d\n",ptr+1);
 //  printf("%d\n",&a[4]);
 //  printf("%d,%d",*(a+1),*(ptr+1));


	//short A = 10;
	//printf("~A = %d\n", ~A);
//	char aa[10];
//printf("%d",strlen(aa)); // ֵ��ȷ��


//	char *str = NULL;
//GetMemory(&str, 100);
//strcpy(str, "hello");
//printf(str);

//char *str = NULL;
//str = GetMemory();
//strcpy(str, "hello");
//printf("%s\n", str);

//char *str = (char *) malloc(100);
//strcpy(str, "hello");
//free(str);
//if(str != NULL){
//strcpy(str, "world");
//printf(str);
//}


	//int arr[5] = {1,4,3,5,2};
	//int i, k;
	//for(i = 0; i < 5; i++)
	//	printf("%d ", arr[i]);
	//printf("\n");
	//memset(arr,1,sizeof(int));// ע�� ����������ĳ���ͬ
	//for(k=0; k < 5; k++)
	//	printf("%d ", arr[k]);
	//printf("\n");

/*	char *p1="name"; 
	char *p2,*p3;
	p2=(char*)malloc(20);
	p3=p2;
	memset (p2, 'a', 20);
	printf("%s\n",p2);
	while(*p2++ = *p1++); 
	printf("%s\n",p3);*/ 


	//demo aa;
	//aa.a = 10;
	//aa.b = 1;

	//printf("%d,%d\n", aa.a, aa.b);
	//char* p = NULL;
 //   get_str(&p);
 //   printf("p=%p\n", p);
 //   puts(p);
	//int i=0, j=20, *p1=&i, *p2=&j;
	//printf("p1 = %d\np2 = %d\n", p1, p2);
	//fun(p1, p2);
	//printf("p1 = %d\np2 = %d\n", p1, p2);
	//printf("i=%d, j=%d\n", i, j);



	//extern void sub();
	//int x=10;
	//add();
	//sub();
	//printf("%d, %d\n", x, y);

	//printf("\n%dn", ripple(3, 5, 7));

//	char p;
//char buf[10] = {1, 2, 3, 4, 5, 6, 9, 8};
//p=5[buf +1];
//printf("%dn", p);


	//	int a = 3;
	//e(a);
	//putchar('n');

	//	int a = 3;
	//int b = 5;
	//p[0] = f1;
	//p[1] = f1;
	//p[0](&a, b);
	//printf("%d %d ", a, b);
	//p[1](&a, b);
	//printf("%d %dn", a, b);

	//jmp_buf env;
	//int i;
	//i = setjmp(env);
	//printf("i = %d\n", i);
	//if (i != 0) exit(0);
	//longjmp(env, 0);
	//printf("Does this line get printed?\n");


//	struct node
//{
//    char a;     
//    int b;     
//    int c;
//};
//struct node s = { 3, 5, 6 };
//struct node *pt = &s;
//printf("%dn", *(int*)pt);


	//int i = 3;   
	//double m=4.23;
	//char n = 2;
	//short k = 3;
	//int j1 = sizeof(++i + ++i);
	//int j2 = sizeof(++i + ++m);
	//int j3 = sizeof(++m + ++m);
	//int j4 = sizeof(++i + ++n);

	//printf("i=%d j1=%d\n", i, j1);
	//printf("m=%lf j3=%d\n", m, j3);
	//printf("n=%d j4=%d\n", n, j4);


	//int num1=1,num2=2;
	//int *p1 = &num1;
	//int *p2 = &num2;
	//printf("%x %x\n", p1, p2);
	//printf("%d %d\n", *p1, *p2);
	//fun(p1, p2);
	//printf("%x %x\n", p1, p2);
	//printf("%d %d\n", *p1, *p2);



	//char a,b,c;
	//scanf("%c%*c%c", &a, &b);
	//printf("%c\n", a);
	//printf("%c\n", b);
	//printf("%c\n", c);

	//char s1[] = "abcd";
 //   char s2[5];
 //   str_copy(s2, s1);
 //   printf("%s", s2);



	//char *s="abcde";
	//reverse(s, 5);
	//puts(s);

	
	//int a = printf("%d\n", 123);
	//printf("%d\n", a);


	//int a[3], *p=a;
	//printf("%x\n", &a[2]);
	//printf("%x\n", p);
	//printf("%x\n", &a[2]-&a[1]); // ����Ԫ��֮��ľ���
	//printf("%x\n", (char*)&a[2]-(char*)&a[1]);// ����Ԫ�������ڴ�֮��ľ���

	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(float));
	//printf("%d\n", sizeof(double));
	//printf("%d\n", sizeof(long));
	//printf("%d\n", sizeof(unsigned long));


	//double a[2][2]={{1,2},{3,4}};
	//double *b[2];
	//b[0]=a[0];
	//b[1]=a[1];

	

	/*int i, x, n, data[16], index=0;
	scanf("%d%d", &x, &n);
	for(i=0; i<16; i++)
		data[i] = 0;
	printf("%d��Ӧ��%d����Ϊ��", x, n);
	while(x>0)
	{
		data[index] = x%n;
		x = x/n;
		index++;
	}
	for(i=index-1; i>=0; i--)
		printf("%d", data[i]);
	printf("\n");*/



	//int *a, *b, *c;
	//a=b=c=(int *)malloc(sizeof(int));
	//*a=1;
	//*b=2;
	//*c=3;
	////a=b;
	//printf("%d, %d, %d\n", *a, *b, *c);


	//char a[12], b[]="tianjin";
	////a=b;
	//printf("%s\n", a);


	//int a = 015;
	//printf("���Լ��Ϊ��%d\n", GreatestCommonDivisor(24, 32));
	//printf("��С������Ϊ��%d\n", a);
	//printf("%d\n", a);
	//int max(int,int);
	//
	//int a=67, b=98;
	//int (*p)(int,int);
	//p=max;
	////printf("%d\n", p(a,b));
	//printf("%d\n", (*p)(a,b));
	//return 0;


	//unsigned int A=50, B=55, C;
	//printf("%u\n", C=A-B);


	//char string[20], *s;
	//int n;
	//gets(string);
	//n=strlen(string);
	//s = delet(string,n);
	//puts(s);


	//unsigned int mask=2;
	//unsigned char timer=0;
	//printf("%d\n",timer);
	//mask|=(unsigned int)(1<<timer); 
	//printf("%d\n",1<<timer);


	//unsigned short int a=65535;
	//short int b=1;
	//printf("a=%hd,%ho,%hx,%hu\n", a,a,a,a);
	//printf("b=%hd,%ho,%hx,%hu\n", b,b,b,b);



	//int a;
	//scanf("%2d", &a);
	//printf("%d\n", a);
	//int b=1234;
	//printf("%%d@%d\n", b);


	//printf("AB\bCDEF\rAGH\123");
	//printf("\n%d\n", sizeof("AB\bCDE\rAGH\123"));
	//printf("\n%d\n", sizeof("AB"));


	//char c='sda';
	//printf("c=%d\n",c);


	//int day=3, inputday=12;
	//int outputday;
	//outputday = (day+inputday+(int)(abs(inputday)/7+1)*7)%7;
	//printf("����%d\n", outputday);


	//int c[4]={1,2,3,4};
	//int (*a)[4]; // ����ָ��
	//a = &c;  // ָ��һά�����ָ��
	//printf("%d\n", (*a)[2]);


	//char *p="test7";
	//char *q="test7";
	//char a[]="test7";
	//printf("%x, %x, %x\n", p, q, a);
	////p[0]='1';  // ���������޸��ַ�����ֵ
	//printf("%s\n", p);
	//a[0]='1';
	//printf("%s\n", a);



	//1.scanf()�����з���ֵ��Ϊint�͡� 
	//2.scanf()�������ص�ֵΪ����ȷ��ָ����ʽ��������ĸ�����Ҳ������ȷ���յ�ֵ�ı��������� 
	//scanf("%d%d", &a, &b);
	//���a��b�����ɹ����룬��ôscanf�ķ���ֵ����2
	//���ֻ��a���ɹ����룬����ֵΪ1
	//���a��b��δ���ɹ����룬����ֵΪ0
	//����������������end of file������ֵΪEOF��
	//int n, e;
	//int a = scanf("%d%d", &n, &e);
	//printf("%d,    %d   %d\n", a, n, e);


	//int a = 132;
	//float x=103.47;
	//char ch = 'k';
	//printf("%d\12", ch);
	//ch = a;
	//printf("%d, %c\n", ch, ch);
	//ch = x;
	//printf("%d, %c\xa", ch, ch);
//}

//#include <stdio.h>
//int main()
//{
//int i = 0;
//printf("%d %d\n", ++i, ++i);
//printf("%d", i);
//return 0;
//}


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int a=1,i=1,c;
//	double sum=0,b,d=1,e;
//	do
//	{
//		sum = sum + d/a;
//		c = (int)pow(-1,i);
//		e = (a+1)*c;
//		a++;
//		b = fabs(d/e);
//		i++;
//	}while(b>0.0001);
//	printf("%lf\n", sum);
//	return 0;
//}


//#include<stdio.h>
//#include<string.h>
//void main()
//{
//	char a[]="abc";
//	char b[]={'a', 'b', 'b'};
//	printf("%d\n", strlen(a));
//	printf("%d\n", strlen(b));
//}

//void print2num(int m, int n)
//{
//	int i,j;
//	for(i=0; i<n; ++i)
//	{
//		for(j=0; j<n && i!=j; ++j)
//		{
//			if(i+j == m)
//				printf("%d + %d = m", i, j);
//		}
//	}
//}



//#include<stdio.h>
//double power(double m,int n);
//int main(void)
//{
//	double x,y;
//	int p;
//	while(scanf("%f%d",&x,&p)==2)
//	{
//		y=power(x,p);
//		printf("%.3g %d %.5g\n",x,p,y);
//	}
// return 0;
//}
//double power(double m,int n)
//{
//	int i;
//	double pow=1;
//	for(i=1;i<=n;i++)
//		pow*=m;
//return pow;
//}


//#include <stdio.h>
//#include <string.h>
//void main()
//{
//	char a[10]="98765", *p=a, *q, t;
//	q = a + strlen(a) - 1;
//	while(p<q)
//	{
//		t = *p++, *p=*q--, *q=t;
//		printf("t=%c, *p=%c, *q=%c\n", t, *p, *q);
//		puts(a);
//		printf("\n");
//	}
//	puts(a);
//}


//#include <stdio.h>
//void main()
//{
//	enum en {en1=3, en2=1, en3}; // en1=3, en2=1, en3=2
//	char *a[] = {"A", "B", "C", "D"};
//	printf("%s %s %s\n", a[en1], a[en2], a[en3]); // DBC
//}


//#include <stdio.h>
//void fun(char *p)
//{
//	int i, j;
//	for(i=j=0; *(p+i)!='\0'; i++)
//		if(*(p+i) >= 'j')
//		{
//			*(p+j) = *(p+i);
//			j++;
//		}
//	*(p+j) = '\0';
//}
//void main()
//{
//	char ch[] = "dgfhjgyuhgf";
//	fun(ch);
//	puts(ch);
//}


//#include <stdio.h>
//#include <math.h>
//
//void main()
//{
//	int a=1, b=4, c=2;
//	float x=5.5, y=9.0, z;
//	z = (a+b)/c + sqrt((double)y)*1.2/c + x;	
//}


//#include <stdio.h>
//#include <math.h>
//
//int fun(int num)
//{
//	int x;
//	if (num == 1)
//	{
//		x = 10;
//	} 
//	else
//	{
//		x = fun(num-1) + 2;
//	}
//	return x;
//}
//void main()
//{
//	printf("%d\n", fun(10));
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void fun(char a[])
//{
//	int i, j, k=0;
//	
//	char *tmp = (char *)malloc(strlen(a)+1);
//	printf("%d\n", strlen(a));
//	for (i=0; a[i]=='*'; i++)
//	{
//		tmp[k++] = '*';
//	}
//	for (j=0; a[i+j]!='\0'; j++)
//	{
//		if (a[i+j]!='*')
//		{
//			tmp[k++] = a[i+j];
//		}
//	}
//	tmp[k] = '\0';
//	//strcpy(a, tmp);
//	puts(tmp);
//	for (j=0; j<=k; j++)
//	{
//		char b = tmp[j];
//		a[j] = b;
//	}
//}
//
//void fun2(char *a)
//{
//	char *p = a;
//	int i,j,n;
//	for(i=0;p[i]=='*';++i)
//	{
//		a[i]='*';
//	}
//	n = i;  //n��ʾǰ��*�Ž�����λ�ã�Ҳ��ʵ����Ч��ĸ��ʼ��λ��
//	for(j=0;p[i+j] != '\0';j++)
//	{
//		if (p[i+j]!='*') 
//		{
//			a[n++]=p[i+j]; //�ö�����n�±�������޸�����a��������p�ı�����Ӱ��
//		}
//	}
//	a[n]='\0';  //������a�Ľ���λ��д��\0�ַ�����
//}
//
//void main()
//{
//	// ��ʱ�ַ�������ڳ�������ͨ��ָ��ֻ���Է����ַ����������������Ըı�����
//	// ���ڱ���ʱ��ȷ���ˣ���ΪΪ��������
//	//char *t = "****A*BC*DEF*G****"; 
//
//	// ��ʱ�ַ��������ջ������ͨ��ָ��ȥ���ʺ��޸��������ݡ�
//	// ������ʱȷ��
//	char s[20] = "****A*BC*DEF*G****";  
//	//gets(s);
//	fun2(s);
//	//t[0] = 'P';  // ����ͨ��ָ��ֻ���Է����ַ����������������Ըı�����
//	puts(s);
//	//puts(t);
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void main()
//{
//	int i;
//	for (i=0; i<3; ++i)
//	{
//		static int a = 1;  // ��̬����ֻ��ʼ��һ��
//		int b = 1;  // ÿ�ζ��ḳֵΪ1
//		printf("a=%d, b=%d\n", ++a, ++b);  // �����a��ֵΪ2,3,4������bÿ�ζ�Ϊ2
//	}
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void main()
//{
//	int *ptr;
//	int buf[2][2] = {{12}, {14, 16}};
//	ptr = buf[0];
//	printf("%d\n", *(ptr+2));
//}


//#include <stdio.h>
//void  fun( char *a )
//{
//	int w=0,m=0,n=0,k,i,j,d;
//	for(k=0; a[k]!='\0'; k++)
//		m++;//�ַ�����
//	for(i=0; a[i]=='*';i++)
//		n++;//ǰ���ǺŸ���
//	for(j=n;j<m;j++)
//		a[w++]=a[j];
//	for(d=m;d<m+n;d++)
//		a[w++]='*';
//	a[w]='\0';
//}
//void main()
//{
//	char str[50] = "*******A*BC*DEF*G****";
//	fun(str);
//	printf("%s\n", str);
//}


//#include <stdio.h>
//void main()
//{
//	int a = -1;
//	printf("%d\n", a%65535);
//}


#include<stdio.h>
int main()
{
	int i,f,a,b,c,d,e;
	char text[3][80];
	i=a=b=c=d=e=f=0;
	for(i=1;i<=3;i++)
	{
		printf("�������%d��:\n",i);
		gets(text[i]);
		for(f=0;f<80&&text[i][f]!='\0';f++)
		{
			if (text[i][f]>='A'&&text[i][f]<='Z')
				a++;
			else if (text[i][f]>='a'&&text[i][f]<='z')
				b++;
			else if (text[i][f]>='0'&&text[i][f]<='9')
				c++;
			else if (text[i][f]==' ')
				d++;
			else
				e++;
		}
	} 
	printf("�����д��ĸ����:%d\n",a);
	printf("���Сд��ĸ����:%d\n",b);
	printf("������ָ���:%d\n",c);
	printf("����ո���:%d\n",d);
	printf("��������ַ�:%d\n",e); 
	return 0 ;
}
