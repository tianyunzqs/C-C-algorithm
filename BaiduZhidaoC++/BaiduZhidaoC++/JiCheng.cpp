//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void fun(){cout<<"funA() is called."<<endl;}
//};
//class B : public A
//{
//public:
//	void fun(){cout<<"funB() is called."<<endl;}
//};
//void main()
//{	
//	B b;
//	A *pA = &b;
//	pA->fun();
//	// 如果fun()是非虚函数，则pA->fun()绑定到funA()，由指针类型所决定
//	// 如果fun()是虚函数，  则pA->fun()绑定到funB()，由指针指向的对象的类型所决定
//}



// 多重继承
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void fun(){cout<<"funA() is called."<<endl;}
//};
//class B : virtual public A
//{
//public:
//	void fun(){cout<<"funB() is called."<<endl;}
//};
//class C : virtual public A
//{
//public:
//	void fun(){cout<<"funC() is called."<<endl;}
//};
//class D : public B, public C
//{
//public:
//	//void fun(){cout<<"funD() is called."<<endl;}
//	void g(){fun();}
//};
//void main()
//{	
//	B b;
//	A *pA = &b;
//	pA->fun();
//	// 如果fun()是非虚函数，则pA->fun()绑定到funA()，由指针类型所决定
//	// 如果fun()是虚函数，  则pA->fun()绑定到funB()，由指针指向的对象的类型所决定
//
//	D d;
//	d.g();
//}



//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//using namespace std;
//#define A(a) ((a)*(a))
//char *GetMemory(int num)
//{
//	char *p; 
//	p = (char *)malloc(sizeof(char)*num);
//	return p;
//}
//
//class A
//{
//	static const int a=0;
//};
//
//void main()
//{	
//	//char *str = NULL;
//	//str = GetMemory(100);
//	//strcpy(str, "hello");
//	//cout<<str<<endl;
//
//	//int a[]={1,2,3,4};
//	//int *p=a;
//	//int *p2 = *(&a+1);
//	//cout<<*(p+1)<<endl;
//	//cout<<&a[0]<<endl;
//	//cout<<&a<<endl;
//	//cout<<a<<endl;
//	//cout<<a+1<<endl;
//	//cout<<&a+1<<endl;
//	//cout<<*(p2-1)<<endl;
//
//
//
//
//struct s1
//{
//   int i: 8;
//   int j: 4;
//   double b;
//   int a:3;
//};
//
//struct s2
//{
//   int i;
//   int j;
//   double b;
//   int a;
//};
//
//struct s3
//{
//   int i;
//   int j;
//   int a;
//   double b;
//};
//
//struct s4
//{
//   int i: 8;
//   int j: 4;
//   int a:3;
//   double b;
//};
//
//struct s5
//{
//   short i: 2;
//   int j: 4;
//   short a: 5;
//   int b : 32;
//};
//struct s6
//{
//   double a[5], c;
//   int j;
//};
//
//
//cout<<sizeof(s1)<<endl;   // 24
//cout<<sizeof(s2)<<endl;   // 24
//cout<<sizeof(s3)<<endl;   // 24
//cout<<sizeof(s4)<<endl;   // 16
//cout<<sizeof(s5)<<endl;   // 16
//cout<<sizeof(s6)<<endl;   // 16
//cout<<"******************************"<<endl;
//cout<<sizeof(short)<<endl;
//cout<<sizeof(double)<<endl;
//cout<<sizeof(long long)<<endl;
//cout<<sizeof(long double)<<endl;
//cout<<"******************************"<<endl;
//double **a[3][4];
//double *(*b)[3][4];
//cout<<"sizeof(a)     = "<<sizeof(a)<<endl;
//cout<<"sizeof(b)     = "<<sizeof(b)<<endl;
//cout<<"sizeof(*a)    = "<<sizeof(*a)<<endl;
//cout<<"sizeof(*b)    = "<<sizeof(*b)<<endl;
//cout<<"sizeof(**a)   = "<<sizeof(**a)<<endl;
//cout<<"sizeof(**b)   = "<<sizeof(**b)<<endl;
//cout<<"sizeof(***a)  = "<<sizeof(***a)<<endl;
//cout<<"sizeof(***b)  = "<<sizeof(***b)<<endl;
//cout<<"sizeof(****a) = "<<sizeof(****a)<<endl;
//cout<<"sizeof(****b) = "<<sizeof(****b)<<endl;
//}


//#include <iostream>
//using namespace std;
//void main()
//{
//	enum workday {sun=0, mon,tur=2147483645, wen, thi, fri};
//	cout<<sun<<ends<<mon<<ends<<tur<<ends<<wen<<ends<<thi<<ends<<fri<<endl;
//}


//#include <iostream>
//#include <regex>
//#include <string>
//using namespace std;
//void main()
//{
//	char *a = new char[12];
//	a[0] = 'a';
//	a[1] = 'b';
//	puts(a);
//}



//#include <iostream>
//#include<windows.h>
//using namespace std;
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
//
//void myprint(char *str, ...)
//{
//	va_list p;
//	char *s = str;
//	int i = 0;
//	va_start(p, str);
//	while(*(s+i)!='\0')
//	{
//		if(*(s+i)=='%')
//		{
//			i++;
//			switch(*(s+i))
//			{
//			case 'd' :
//				printf("%d", va_arg(p, int));
//				break;
//			case 's' :
//				printf("%s", va_arg(p, char*));
//				break;
//			case 'c' :
//				printf("%c", *va_arg(p, char*));
//				break;
//			}
//		}
//		else
//			printf("%c", *(s+i));
//		i++;
//	}
//}
//
//void main()
//{
//	printf("\n%d\n", ripple(3, 5, 7));
//	myprint("%d,%d,sdf,%c", 3, 4, "adf");
//
//	struct stu
//{
//char *name;
//int num;
//char sex;
//float score;
//}boy={"zhangkaicheng",007,'M',87.23},*p;;
//
//p=&boy;
//printf("%s",(*p).name);
//}


//#include <iostream>
//using namespace std;
//void main()
//{
//	int *pInt = new int;  
//    *pInt=10;
//    cout<<"*pInt: "<<*pInt<<endl;  
//    delete pInt;   //pInt为迷途指针!
//	pInt = 0;
//     
//    long *pLong = new long;
//    *pLong=90000;  
//    cout<<"*pLong: "<<*pLong<<endl;  
//     
//    *pInt=20;      //再次使用pInt! 
//     
//    cout<<"*pInt: "<<*pInt<<endl;  
//    cout<<"*pLong: "<<*pLong<<endl;  
//    delete   pLong;  
//}




//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A();
//	A(int a){this->a = a;}
//	~A(){}
//	void fun(){cout<<a<<endl;}
//private:
//	int a;
//};
//void main()
//{
//	A test(4);
//	test.fun();
//}



//#include <iostream>
//
//using namespace std;
//template <typename T>
//struct chainNode
//{
// T element;
//
//};
//void main()
//{
// struct chainNode<char> *c;
//c = new struct chainNode<char> ;
// //struct chainNode<char> *c = (struct chainNode<char>*)malloc(sizeof(chainNode<char>));
// //cout<<sizeof(c)<<endl;
//
//}



//#include <iostream>
//using namespace std;
//
//class chainNode
//{
//private:
//	int t;
//public:
//	chainNode(int a){t=a;}
//
//};
//void main()
//{
//	//chainNode *p;
//	double t;
//	double t1;
//	t1= t=1,t+5,t++;
//	cout<<t1<<endl;
//	double t2 = 1;
//	double t3 = t2++;
//	cout<<t3<<endl<<t2<<endl;
//
//	float a = -1e3;
//	char *s;
//	s={"hello"};
//
//	//char *s;s="hello"
//}


//#include<stdio.h>
//void main()
//{
//	int i=1,j=1;
//	for(i=1;i<=9;i++)
//		for(j=1;j<=i;j++)
//		{
//			printf("%d*%d=%d",j,i,i*j);
//			if(i!=j) printf("\t");
//			if(i==j) printf("\n");
//		}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void main()
//{
//	int a=2;
//	a += a *= a -= a *= 3;
//	printf("%d\n", a);
//}

//#include <stdio.h>
//#include <string.h>
//void strlwr(char* c, int len);
//int main()
//{
//	char a[50];
//	int len = 0;
//	printf("please input lowercase character\n");
//	scanf("%s",a);
//	len = strlen(a);
//	strlwr(a, len);
//	printf("%s\n",a);
//	return 0;
//}
//void strlwr(char* c, int len)
//{
//	for(int i=0; i<len; i++) {
//		if (c[i]<91&&c[i]>64){
//			c[i]=c[i]+32;
//		}		
//	}
//}


#include <stdio.h>
int main()
{
	unsigned short a = 65536;
	int b;
	printf("%u\n", a);
	printf("%d\n", b=a);
	printf("%d\n", sizeof(unsigned short));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof("\\\tabcd\r\12\n"));
}
