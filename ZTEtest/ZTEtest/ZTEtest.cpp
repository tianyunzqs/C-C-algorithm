#include <iostream>
#include <iomanip>
using namespace std;

class DD
{
public:
	DD(){static int i=0; i++; cout<<i<<" constructor is called !"<<endl;}
	DD(DD &d){static int i=0; i++; cout<<i<<" copy constructor is called !"<<endl;}
	~DD(){static int i=0; i++; cout<<i<<" deconstructor is called !"<<endl;}
};


char *getString()
{
	char *p = (char*)malloc(800);
	strcpy(p, "adfs");
	return p;
}

int is_little_endian(void)
{
	int  v = 1;
	if(*((char *)&v) == 1)   
		return 0;
	else
		return 1;
}


union
{
        long Long;
        char Char[sizeof(long)];
}u;

void main()
{
	//cout<<setw(4)<<"aaa"<<endl;
	//cout<<"aaa"<<setw(4)<<endl;
	//cout<<"bbbbbb"<<setw(4)<<"aaaaa"<<endl;
	//cout<<"bbbbbb"<<"aaa"<<setw(4)<<endl;
	//cout<<"b"<<"aaa"<<setw(4)<<"abc"<<"fd"<<"adfsadf"<<endl;
	//cout<<"b"<<setw(4)<<"aaa"<<"abc"<<"fd"<<"adfsadf"<<endl;
	//cout<<"b"<<setw(4)<<"aaa"<<"abc"<<setw(4)<<"fd"<<"adfsadf"<<endl;

	//DD a[5];
	//DD *p;
	//DD a;
	//DD b(a);
	//cout<<is_little_endian()<<endl;

	char a[sizeof(int)];

	u.Long = 1;
        
        if (u.Char[0] == 1)        
        {
                printf("Little Endian!\n");
        }
        else if (u.Char[sizeof(long) - 1] == 1)
        {
                printf("Big Endian!\n");
        }
        else
        {
                printf("Unknown Addressing!\n");
        }

    printf("Now, Let's look at every byte in the memory!\n");
    for (int i = 0; i < sizeof(long); ++i)
    {
        printf("[%x] = %x\n", &u.Char[i], u.Char[i]);
    }

	//char *str;
	//str = getString();
	//printf("%s\n", str);


}