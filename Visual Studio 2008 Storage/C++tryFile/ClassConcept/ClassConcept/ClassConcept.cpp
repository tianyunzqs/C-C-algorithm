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
////	inline void SetData(int y, int m, int d); // ��������
////	char *IsLeapYear()
////	{
////		char *str;
////		if(year%4==0&&year%100!=0 || year%400==0)
////			str = "����";
////		else
////			str = "ƽ��";
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
//	rectangel(int l, int w){length = l; width = w;cout<<"�вι��캯�����óɹ���"<<endl;} // �вι��캯��
//	// ��Ա�����ĳ�ʼ����ע�⣺��ʼ���븳ֵ��ͬ
//	rectangel():length(1),width(8){cout<<"�޲ι��캯�����óɹ���"<<endl;} // �޲ι��캯��
//	int area();
//private:
//	int length, width;
//};
//
//int rectangel::area(){return length*width;}
//
//class rectan:public rectangel  // rectan�ǻ���rectangel�������࣬�̳��˸���rectangel�е���������
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
//	rectangel rect(3,4);  // �����вι��캯��
//	//cout<<rect.length<<ends<<rect.width<<endl; // �����ܷ������е�private��protected����
//	cout<<rect.area()<<endl; // �����޲ι��캯��
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
	int m = sizeof(str_arg); //ָ��Ĵ�СΪ4
	int n = strlen(str_arg); //�������󳤶ȣ�str_arg ������Ǹ�2û���κ����壬�����Ѿ��˻�Ϊָ����
	printf("%d\n",m);
	printf("%d\n",n);
}
int main(void)
{
	char str[]="Hello";
	Func(str);
}