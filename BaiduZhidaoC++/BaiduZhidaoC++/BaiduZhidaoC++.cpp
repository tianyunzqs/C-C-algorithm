#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;
//class A
//{
//public:
//	A(int a) {m_a = a;}
//	int getM_a() {return m_a;}
//private:
//	int m_a;
//};
//
//class B
//{
//public:
//	int m_b;
//	A* m_objA;
//};



//
//void example(char acWelcome[]){
//    printf("%d\n",sizeof(acWelcome));
//    return;
//}


//char *myString()
//{
//    char buffer[6] = {0};
//    char *s = "Hello World!";
//    for (int i = 0; i < sizeof(buffer) - 1; i++)
//    {
//        buffer[i] = *(s + i);
//    }
//	printf("%s\n", buffer);
//    return buffer;
//}


//class MyClass
//{
//public:
//    MyClass(int i = 0)
//    {
//        cout << i;
//    }
//    MyClass(const MyClass &x)  // �������캯��
//    {
//        cout << 2;
//    }
//    MyClass &operator=(const MyClass &x)  // ��ֵ���캯��
//    {
//        cout << 3;
//        return *this;
//    }
//    ~MyClass()
//    {
//        cout << 4;
//    }
//};



//class CTest
//{
//    public:
//        //CTest():m_chData('\0'),m_nData(0)
//        //{
//        //}
//        //virtual void mem_fun(){}
//		void fun1(){int a;}
//    private:
//        //char m_chData;
//        int m_nData;
//        //static char s_chData;
//
//};
//char CTest::s_chData='\0';


//class A
//{
//public:
// void FuncA()
// {
//     printf( "FuncA called\n" );
// }
// virtual void FuncB()
// {
//     printf( "FuncB called\n" );
// }
//};
//class B : public A
//{
//public:
// void FuncA()
// {
//     A::FuncA();
//     printf( "FuncAB called\n" );
// }
// void FuncB()
// {
//     printf( "FuncBB called\n" );
// }
//};


//class A
//{
//protected:
//	int a;
//public:
//	A(int x){a=x;}
//	int Geta(){return a++;}
//};
//
//class B1:virtual public A
//{
//public:
//	B1(int x):A(x){}
//};
//
//class B2:virtual public A
//{
//public:
//	B2(int x):A(x){}
//};
//
//class C:public B1,public B2
//{
//public:
//	C(int x,int y,int z):A(x),B1(y),B2(z){}
//};

//int *printMatrix(int *matrix[],int row, int col) {
//		int *result=(int*)malloc(row*col*sizeof(int));
//        int **temp=matrix;
//        int k=0;
//		if(row==0 || col==0)
//			return 0;
//		else if(row==1)
//		{
//			for(int i=0; i<col; i++)
//				result[k++] = matrix[0][i];
//			return result;
//		}
//		else if(col==1)
//		{
//			for(int i=0; i<row; i++)
//				result[k++] = matrix[i][0];
//			return result;
//		}
//		else
//		{
//        for(int i=0; i<col; i++){
//            result[k++] = matrix[0][i];
//        }
//        for(int i=1; i<row; i++){
//            result[k++] = matrix[i][col-1];
//        }
//        for(int i=col-2; i>=0; i--){
//            result[k++] = matrix[row-1][i];
//        }
//        for(int i=row-2; i>=1; i--){
//            result[k++] = matrix[i][0];
//        }
//        for(int i=0; i<row-2; i++)
//            for(int j=0; j<col-2; j++)
//            	temp[i][j] = matrix[i+1][j+1];
//       	printMatrix(temp, row-2, col-2);
//		return result;
//		}
//	}
//int arr[6][5]= 
//{
////{1,  16,  3,   2,   17}, 
////{8,  9,   4,   3,   23}, 
////{2,  5,   7,   8,   14},
////{21, 2,   4,   6,   13},
////{11, 18,  15,  13,  12}, 
////{31, 311, 42,  33,  32}
//  {1,  16,  3,   2,   17}
//}; 


	////int MoreThanHalfNum_Solution(vector<int> numbers) {
		/*int temp, maxcnt, index;
        vector<int> cnt;
        for(int i=0; i<numbers.size(); i++){
            temp = numbers[i];
            cnt[i] = -1;*/
           /* for(int j=0; j<numbers.size(); j++){
                if(numbers[j]==temp)
                    cnt[i]++;
            }*/
       // }
		//return numbers.size();
        /*maxcnt = cnt[0];
        index = 0;
        for(int i=1; i<cnt.size(); i++){
            if(cnt[i]>maxcnt){
                maxcnt = cnt[i];
                index = i;
            }
        }
        if(maxcnt>numbers.size()/2)
            return numbers[index];
        else
            return 0;*/
	//}

/*int GetUglyNumber_Solution(int index) {
	int UglyNum=1, cnt=6, num=7, num2=7;
    if(index<7)
        return index;
    while(1){
        if(num%2==0)
            num /= 2;
        else if(num%3==0)
            num /= 3;
        else if(num%5==0)
            num /= 5;
        else{
            if(num<=1){
                UglyNum = num2;
                cnt++;
                if(cnt==index)
                    break;
            }
            num = num2 + 1;
            num2 = num;
        }
                    
    }
    return UglyNum;
}*/

//int Add(int num1, int num2)
//{
//	int sum = 0;
//    int carry = 0;
//    do {
//        // ���ʵ����ӵ�����λ
//        sum = num1 ^ num2;
//        // ��λ�룬�����ƣ��൱�ڽ�λ
//        carry = (num1 & num2) << 1;
//        num1 = sum;
//        num2 = carry;
//    } while (num2 != 0);
//    return num1;
// 
//}

/*��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
����ǷǷ��������ַ�������1aa3���򷵻�0��(�������)
int StrToInt(string str) {
	int i=0, temp=0, num;  
    if(str[0]=='+' || str[0]=='-')
        i = 1;       
    for(; i<str.length(); i++)
	{   
        num = temp;
        if(!(str[i]>='0' && str[i]<='9'))
            return 0;
        else
        {   
            if(str[0]=='+'){
         		temp = temp*10 + str[i] - '0';
                if(temp<num)  // ������������С������ʼ����
                    return 0;
            }
            else if(str[0]=='-'){
         		temp = temp*10 - (str[i] - '0');
                if(temp>num) // �������������������ʼ�ݼ�
                    return 0;
            }
            else
                temp = temp*10 + str[i] - '0';
        }
    }
	return temp;
}*/



//class A
//{
//public:
//	A();
//	A(int a):data(a){}
//	A(int a, int b):data(a),num(b){}
//	int fun();
//	friend A operator+(A&,A&);//��Ԫ���������Դ�2������
//	friend int fun1(A f, int a);
//private:
//	int data;
//	static int a;
//public:
//	int num;
//	static int b;
//};
//
//int A::a=0;
//int A::b=0;
//
//
//
//int A::fun()
//{
//	return this->a; // 1����Ա�������Է���private����
//}
//
//A operator+(A &a,A &b)  // ������Ԫ�������ء�+�������
//{
//	return A(a.data + b.data + 2);
//}
//
//int fun1(A f, int a)
//{
//	return a + f.a; // 2����Ԫ�������Է���private����
//}


/************* private *************/
// 1.�����еĺ���
// 2.����Ԫ�������ʡ�
// ���ܱ��κ��������ʣ�����Ķ���Ҳ���ܷ��ʡ�
/************* protected *************/
// 1.�����еĺ���
// 2.����ĺ���
// 3.����Ԫ�������ʡ� 
// �����ܱ�����Ķ�����ʡ�
/************* public *************/
// 1.�����еĺ���
// 2.����ĺ���
// 3.����Ԫ��������
// 4.����Ķ�����ʡ�
/*************  Ĭ��Ȩ�ޣ�default�� *************/
// �࣬���ݳ�Ա�����췽����������Ա�����ܹ�ʹ��Ĭ��Ȩ�ޣ�����д�κιؼ��֡�
// Ĭ��Ȩ�޼�ͬ��Ȩ�ޣ�ͬ��Ȩ�޵�Ԫ��ֻ���ڶ������ǵ����У��Լ�ͬ�������б����á�

// ע����Ԫ��������3�֣���Ϊ��Ԫ����ͨ�ķǳ�Ա��������Ϊ��Ԫ��������ĳ�Ա��������Ϊ��Ԫ���е����г�Ա������

class A
{
public:
	A():publicA(7){cout<<"A::constructor.";}
public:
	const int publicA;
protected:
	int protectedA;
private:
	int privateA;
};

class B : private A
{
public:
	B(){cout<<"B::constructor.";}
	int fun(){return publicA;}
	B(int i){publicB = A::publicA + i;}
public:
	int publicB;
protected:
	int protectedB;
private:
	int privateB;
};


void main()
{
	B b(10);
	cout<<endl<<b.publicB<<endl;
	printf("%f\n", 12);
	printf("%d\n", 5.05);


// typedef    vector<int>    IntArray;
//IntArray arr; 
//arr.push_back( 1 ); 
//arr.push_back( 2 ); 
//arr.push_back( 2 ); 
//arr.push_back( 3 ); 
//// ɾ��array���������е�2 
//for( vector<int>::iterator itor=arr.begin(); itor!=arr.end(); )
//{
//	if( 2 == *itor )
//		itor=arr.erase( itor );
//	else
//		++itor;
//} 

//const int i = 0; 
//int *j = (int *) &i; 
//*j = 1; 
//printf("%d,%d", i, *j);

	// ����ѭ������Ctrl+C��������
	//char word;
	//while(cin>>word)
	//	cout<<word<<endl;

//float a = 125.5f; 
//cout << (int)a << endl; 
//cout << (int&)a << endl; 
//cout << boolalpha << ( (int)a == (int&)a ) << endl; // ���ʲô�� 
//float b = 0.0f; 
//cout << (int)b << endl; 
//cout << (int&)b << endl; 
//cout << boolalpha << ( (int)b == (int&)b ) << endl; // ���ʲô��

	//A a1(1),a2(2),a3(3), a4(4);
	//cout<<a1.fun()<<endl;
	//a1=a2+a3;
	//cout<<a1.fun()<<endl;
	//cout<<fun1(a4, 5)<<endl;

	//A example(5);
	//// cout<<example.data<<endl; // ����private���ͱ������ܱ���Ķ���������

	//A b1(3,4);
	//cout<<b1.num<<endl;


	//vector<int> num;
	//num.push_back(1); 
	//num.push_back(2); 
	//num.push_back(3); 
	//num.push_back(2); 
	//num.push_back(2); 
	//num.push_back(2); 
	//num.push_back(5); 
	//num.push_back(4); 
	//num.push_back(2);
	//cout << num[5] << endl;
	//cout << MoreThanHalfNum_Solution(num) << endl;


	//vector<int> v(5);
	//for(int i=0; i<5; i++)
	//	v[i]=i+2;
	//cout<<v.at(3)<<endl;









	//// ��ʼ����������
 //   //int startX = 0, endX = 4;
 //   //int startY = 0, endY = 5;
	//int startX = 0, endX = 4;
 //   int startY = 0, endY = 0;
 //   
 //   while(startX<=endX && startY<=endY)  // ѭ������
 //   {
 //       int i;
 //       for(i=startX; i<=endX; i++)  // ����ϱߵ���
 //           cout << arr[startY][i] << " ";
 //       startY ++;         // �еĿ�ʼ��������
	//	if(startY>endY)
	//		break;
 //       for(i=startY; i<=endY; i++)  // ����ұߵ���
 //           cout << arr[i][endX] << " ";
 //       endX --;           // �еĽ��������С
	//	if(endX<0)
	//		break;
 //       for(i=endX; i>=startX; i--)   // ����±߱ߵ���
 //           cout << arr[endY][i] << " ";
 //       endY --;           // �еĽ��������С
	//	if(endY<0)
	//		break;
 //       for(i=endY; i>=startY; i--)  // �����ߵ���
 //           cout << arr[i][startX] << " ";
 //       startX ++;         // �еĿ�ʼ��������
	//	if(startX>endX)
	//		break;
 //   }





	/*int *r=(int*)malloc(16*sizeof(int));
	int *matrix[4];
	for(int i=0; i<4; i++)
		matrix[i] = (int*)malloc(16*sizeof(int));
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			matrix[i][j] = 4*i+j+1;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	r = printMatrix(matrix,4,4);

	for(int i=0; i<16; i++)
		printf("%d ", r[i]);
	printf("\n");*/



	//C c(10,15,20);
	//B1 *b1 = &c;
	////cout<<c.Geta()<<endl;
	//cout<<b1->Geta()<<endl;
	//cout<<c.B2::Geta()<<endl;
	//cout<<(0%3)<<endl;



	//char buf[20];
 //   
 //   cin.ignore(7);//�������������Ϊʲô����ָ��Ҫ�ȴ�����ı�����������
 //   cin.getline(buf , 10); 
 //   cout<< buf<<endl;



	 //B	b;
	 //A	*pa;
	 //pa = &b;
	 //A *pa2 = new A;
	 //pa->FuncA();
	 //pa->FuncB();
	 //pa2->FuncA();
	 //pa2->FuncB();
	 //delete pa2;




	//printf("%d\n", sizeof(CTest));


	//MyClass obj1(1), obj2(2);
 //   MyClass obj3 = obj1;  // ���ÿ������캯��
	//obj3 = obj1;  // ���ø�ֵ���캯��



	//printf("%d\n", sizeof(CTest));

	//char buffer[6] = {0};
	//printf("%s\n", myString());
	//printf("%d\n", sizeof(buffer));


	//char acWelcome[]="Welcome to Huawei Test";
 //   example(acWelcome);


	//enum string{    
 //   x1,    
 //   x2,    
 //   x3=10,    
 //   x4,    
 //   x5,    
	//}x;
	//printf("%d\n", x);


	//B *bp = new B;
	//bp->m_objA = new A(10);
	//cout<<bp->m_objA->getM_a()<<endl;

	//cout<<"Two:"<<endl;
	//int v1;
	//cin>>v1;
	//cout<<v1<<endl;


	//int *ptr, a[10]={1,2,3,4,5,6,7,8,9,10};
	//int *b = new int[10];
	////ptr = a; 
	////b = ptr;

	//cout << "Value of first element in b " << b[0] << endl; 
	//cout << "Value of second element in b " << b[1] << endl; 

	//a[1] = 42;
	//cout << "Value of second element in b " << b[1] << endl;



	//int *p1 = new int[10]; 
	//int *p2 = new int[10]();
	//printf("%d, %d\n", *p1, *(p2+4));
}