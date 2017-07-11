#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "animal constructor." << endl;
	}
	virtual void sleep()=0;
	/*{
	cout << "animal sleep." << endl;
	}*/
private:	
};

class Fish : public Animal
{
public:
	Fish()
	{
		cout << "fish constructor." << endl;
	}
	void sleep()
	{
		cout << "fish sleep." << endl;
	}
private:
	//int a;
};

//void fun(Animal *pa)
//{
//	pa->sleep();
//}

void main()
{
	// 危险，不推荐
	//Animal an;
	//Fish *ph = (Fish *)&an;
	//ph->sleep();

	// 安全，推荐
	//Fish fh;
	//Animal *pa = &fh;
	//pa->sleep();

	cout << sizeof(Animal) << endl;
	cout << sizeof(Fish) << endl;

	Animal a;
	//Fish fh;
	//Animal *pa = &fh;
	//fun(&fh);
}