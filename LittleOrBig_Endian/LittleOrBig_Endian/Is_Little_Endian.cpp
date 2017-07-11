#include <iostream>
using namespace std;
#define SIZE_OF_UNSIGNEDINT sizeof(unsigned int)
#define SIZE_OF_UNSIGNEDCHAR sizeof(unsigned char)

// 方法一
int Is_Little_Endian1(void)
{
	int v = 1;
	if(*((char*)(&v)) == 1)
		return 1;  // little endian
	else
		return 0;  // big endian
}

// 方法二
union test
{
	long Long;
	char Char[sizeof(long)];
}u;

void Is_Little_Endian2(void)
{
	u.Long = 1;     
    if (u.Char[0] == 1)        
        printf("Little Endian!\n");
    else if (u.Char[sizeof(long) - 1] == 1)
		printf("Big Endian!\n");
    else
        printf("Unknown Addressing!\n");

    printf("Now, Let's look at every byte in the memory!\n");
    for (int i = 0; i < sizeof(long); ++i)
        printf("[%x] = %x\n", &u.Char[i], u.Char[i]);
}


void put_32(unsigned char *cmd, unsigned int data)
{
    for (int i=SIZE_OF_UNSIGNEDINT-1; i>=0; --i)
    {
        cmd[i] = data % 256;
        // 或者可以:
        //cmd[i] = data & 0xFF;
        data = data >> 8;
    }
}

unsigned int get_32(unsigned char *cmd)
{
    unsigned int  ret;
    int i;

    for (ret = 0, i = SIZE_OF_UNSIGNEDINT - 1; i >= 0; --i)
    {
        ret  = ret << 8;
        ret |= cmd[i];        
    }
        
    return ret;
}


unsigned int LE2BE(unsigned int data)
{
	unsigned int res=0, tmp;
	while(data)
	{
		tmp = data & 0xFF;
		data = data >> 8;
		res = res | tmp;
		res = res << 8;
	}
	return res;
}

void main()
{
	unsigned int a=0x12345678;
	printf("a = %x\n", a);
	printf("b = %x\n", LE2BE(a));

	//unsigned char cmd[SIZE_OF_UNSIGNEDINT];
	//unsigned int data, ret;
	//unsigned char *p;
	//data = 0x12345678;
 //   printf("data = %x\n", data);
 //   // 以字节为单位打印出数据
 //   p = (unsigned char*)(&data);
 //   for (int i=0; i <sizeof(unsigned int); ++i)
 //   {
 //       printf("%x", *p++);
 //   }
 //   printf("\n");

	//// 以相反的顺序存放到cmd之中
 //   put_32(cmd, data);
 //   for (int i=0; i<SIZE_OF_UNSIGNEDINT; ++i)
 //   {
 //       printf("cmd[%d] = %x\n", i, cmd[i]);
 //   }

	//// 再以相反的顺序保存数据到ret中
 //   // 保存之后的ret数值应该与data相同
 //   ret = get_32(cmd);
 //   printf("ret = %x\n", ret);
 //   p = (unsigned char*)(&ret);
 //   for (int i = 0; i < SIZE_OF_UNSIGNEDINT; ++i)
 //   {
 //       printf("%x", *p++);
 //   }
 //   printf("\n");

}