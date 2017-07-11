#include<iostream>
using namespace std;
///*class TData
//	{
//	public:
//			void SetData(int y, int m, int d)
//			{
//				year = y; month = m; day = d;
//			}
//			int IsLeapYear()
//			{
//				return(year%4==0&&year%100!=0 || year%400==0);
//			}
//			void print()
//			{
//				cout<<year<<"-"<<month<<"-"<<day<<endl;
//			}
//	private:
//		int year, month, day;
//	};*/
//
////class TData
////{
////public:
////	inline void SetData(int y, int m, int d); // 内联函数
////	char *IsLeapYear()
////	{
////		char *str;
////		if(year%4==0&&year%100!=0 || year%400==0)
////			str = "闰年";
////		else
////			str = "平年";
////		return(str);
////	}
////	void print(){cout<<year<<"-"<<month<<"-"<<day<<endl;}
////private:
////		int year, month, day;
////};
////
////void TData::SetData(int y, int m, int d){year = y; month = m; day = d;}
//
//
//
//class rectangel
//{
//public:
//	rectangel(int l, int w){length = l; width = w;cout<<"有参构造函数调用成功！"<<endl;} // 有参构造函数
//	// 成员变量的初始化，注意：初始化与赋值不同
//	rectangel():length(1),width(8){cout<<"无参构造函数调用成功！"<<endl;} // 无参构造函数
//	int area();
//private:
//	int length, width;
//};
//
//int rectangel::area(){return length*width;}
//
//class rectan:public rectangel  // rectan是基类rectangel的派生类，继承了父类rectangel中的所有属性
//{
//public:
//	rectan(){cout<<"123456"<<endl;}
//};
//
//void main()
//{
//	
//	//TData data;
//	//int y,m,d;
//	//cin>>y>>m>>d;
//	//data.SetData(y,m,d);
//	////int IsLeapYear = data.IsLeapYear();
//	////cout<<IsLeapYear<<endl;
//	//cout<<data.IsLeapYear()<<endl;
//	//data.print();
//
//	rectangel rect(3,4);  // 调用有参构造函数
//	//cout<<rect.length<<ends<<rect.width<<endl; // 对象不能访问类中的private和protected类型
//	cout<<rect.area()<<endl; // 调用无参构造函数
//	cout<<"****************************************"<<endl;
//	rectangel rect2;
//	cout<<rect2.area()<<endl;
//	cout<<"****************************************"<<endl;
//	rectan re;
//	cout<<re.area()<<endl;
//	//char str[8];
//	//cin.getline(str, 5);
//	//cout<<str<<endl;
//	//cin.getline(str, 5);
//	//cout<<str<<endl;
//
//	int aaa[5][4];
//	for(int m=0,n=0; m<5,n<4; m++,n++)
//		cout<<m<<ends<<n<<endl;
//}


//void Func(char str_arg[100])
//{
//	printf("%d\n", sizeof(str_arg));
//}
//int main(void)
//{
//	char str[] = "Hello";
//	printf("%d\n", sizeof(str));
//	printf("%d\n", strlen(str));
//	char *p = str;
//	printf("%d\n", sizeof(p));
//	Func(str);
//	return(0);
//}

void Func(char str_arg[2])
{
	int m = sizeof(str_arg); //指针的大小为4
	int n = strlen(str_arg); //对数组求长度，str_arg 后面的那个2没有任何意义，数组已经退化为指针了
	printf("%d\n",m);
	printf("%d\n",n);
}
int main(void)
{
	char str[]="Hello";
	Func(str);
}