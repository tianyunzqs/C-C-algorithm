#include <stdio.h>
#include <string.h>
void main()
{
	long InputCharLen;    // 保存用户输入的字符串的长度
	char InputChar1[50];  // 保存用户输入的字符串
	char InputChar2[50];  // 保存用户输入的字符串
	char InputChar3[50];  // 保存用户输入的字符串
	char OutputChar1[50]; // 保存经过处理后的字符串
	char OutputChar2[50]; // 保存经过处理后的字符串
	char OutputChar3[50]; // 保存经过处理后的字符串
	// 函数声明
	void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
	void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
	void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
	printf("请输入a~z的字符串（按回车键结束输入）："); // 提示用户输入字符串
	gets(InputChar1); // 接受用户输入的字符串
	strcpy(InputChar2, InputChar1); // 将保存在InputChar1数组中的字符串复制到InputChar2数组中
	strcpy(InputChar3, InputChar1); // 将保存在InputChar1数组中的字符串复制到InputChar3数组中
	InputCharLen = strlen(InputChar1); // 计算用户输入的字符串的长度
	stringFilter(InputChar1, InputCharLen, OutputChar1); // 引用字符串过滤函数
	stringZip(InputChar2, InputCharLen, OutputChar2);    // 引用字符串压缩函数
	arithmetic(InputChar3, InputCharLen, OutputChar3);
}

// 通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串过滤程序，
// 若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
// 比如字符串“abacacde”过滤结果为“abcde”。

/* 要求实现函数：
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
【输入】 pInputStr：  输入字符串
         lInputLen：  输入字符串长度        
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例
输入：“deefd”        输出：“def”
输入：“afafafaf”     输出：“af”
输入：“pppppppp”     输出：“p”
*/

// main函数已经隐藏，这里保留给用户的测试入口，在这里测试你的实现函数，可以调用printf打印输出
// 当前你可以使用其他方法测试，只要保证最终程序能正确执行即可
// 该函数实现可以任意修改，但是不要改变函数原型。一定要保证编译运行不受影响
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,count; // 定义循环变量
	int tarlen = 1; // 保存输出字符串指针数组的长度（目标字符串的长度）

	*pOutputStr = *pInputStr; // 将用户输入的第一个字符保存在输出字符指针地址中
	for(i=1; i<lInputLen; i++)
	{
		count = 0; // 每次全部比较完毕，就将比较次数计数器清零
		// 将用户输入的第i个字符与输出字符指针中的字符逐个比较，检查输出字符指针中是否存在该字符
		// 若存在，则跳过该字符；若不存在，比较次数计数器加一，如果计数器的值与输出指针中字符串长度
		// 相等（表明此时已与输出字符串全部比较完毕，并且输出字符串中没有该字符），则将该字符写入输出
		// 字符串指针中。
		for(j=0; j<tarlen; j++)		
		{
			if(*(pInputStr+i) == *(pOutputStr+j)) // 存在
				break;
			else  // 不存在
				count++; // 比较计数器加一
		}
		if(count == tarlen) // 如果比较计数器的值等于输出字符串长度，则将此次比较的字符写入输出字符指针中
		{
			*(pOutputStr+tarlen) = *(pInputStr+i); // 将此次比较的字符写入输出字符指针中
			tarlen++; // 输出字符串的长度加一
		}
	}
	// 打印过滤后的字符串
	printf("过滤后的字符串：");
	for(j=0; j<tarlen; j++)
		printf("%c",*(pOutputStr+j));
	printf("\n");
}


// 通过键盘输入一串小写字母(a~z)组成的字符串。
// 请编写一个字符串压缩程序，将字符串中连续出席的重复字母进行压缩，并输出压缩后的字符串。
// 压缩规则：
// 1. 仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，压缩后的字符串还是"abcbc".
// 2. 压缩字段的格式为"字符重复的次数+字符"。例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"
/* 要求实现函数：
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
【输入】 pInputStr：  输入字符串
         lInputLen：  输入字符串长度        
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例
输入：“cccddecc”   输出：“3c2de2c”
输入：“adef”     输出：“adef”
输入：“pppppppp” 输出：“8p”
*/
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,k,count; // 定义循环变量
	char *temp, b[50]; // 定义一个字符型指针及字符数组
	count = 1; // 连续相同字符计数器初始化
	j = 1; // 输入pInputStr中当前操作字符指示，（j-1）表示当前操作的字符
	k = 0; // 输出pOutputStr中字符串的长度
	temp = b; // 将字符指针指向字符数组的首地址（如果不定义一个字符数组，则字符指针所指向的字符没内存空间）
	*temp = *pInputStr; // 取出输入字符串的第一个字符（保存在b[0]中）

	// 依次取出输入字符串中的每一个字符（放入中间指针temp所指向的地址中）,然后将输入字符串中在该字符后面
	// 的所有字符与该字符相比较，若相同，则连续相同字符计数器加一，继续比较；若不相同，则判断
	// 连续相同字符计数器的数值，为1说明该字符不连续，直接写入输出，大于1则说明该字符连续，需要写入数字与
	// 字符。
	while(1)
	{
		for(i=j; i<=lInputLen; i++)
		{
			// 当前输入指针指向的字符与*temp中保存的字符不相同
			// 或者i == lInputLen说明输入字符串中字符已全部比较完毕
			if(*(pInputStr+i) != *temp || i == lInputLen)
			{
				// 如果连续相同字符计数器的数值为1，说明该字符不连续，直接写入输出
				if(count == 1)
					*(pOutputStr+k++) = *temp;
				// 大于1则说明该字符连续，需要写入数字与字符
				else
				{
					*(pOutputStr+k++) = 48+count; // 将数字转化为字符类型（连续字符数最大为9）
					*(pOutputStr+k++) = *temp;
				}
				j = j + count; // 调整下一个连续字符开始比较的位置
				*temp = *(pInputStr+j-1); // 取出输入字符串中下一个连续字符
				count = 1; // 连续相同字符计数器置一（相当于清零的作用）
				break; // 连续字符已比较完毕，跳出此次连续字符的比较，进入下一个连续字符的比较
			}	
			else // 当前输入指针指向的字符与*temp中保存的字符相同，说明该字符有2个以上连续字符
				count++; // 连续相同字符计数器加一
		}
		// 如果下一个连续字符开始比较的位置在输入字符串的末尾，则说明已全部比较完毕
		if(j >= lInputLen)
		{
			*(pOutputStr+k) = *temp; // 如果末尾字符不连续，则直接写入
			break; // 全部比较完毕
		}
	}
	// 打印压缩后的字符串
	printf("压缩后的字符串：");
	for(i=0; i<=k; i++)
		printf("%c",*(pOutputStr+i));
	printf("\n");
}


// 通过键盘输入100以内正整数的加、减运算式，请编写一个程序输出运算结果字符串。
// 输入字符串的格式为：“操作数1 运算符 操作数2”，“操作数”与“运算符”之间以一个空格隔开。
// 补充说明：
// 1. 操作数为正整数，不需要考虑计算结果溢出的情况。
// 2. 若输入算式格式错误，输出结果为“0”。
/* 要求实现函数：
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
【输入】 pInputStr：  输入字符串
         lInputLen：  输入字符串长度        
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
【注意】只需要完成该函数功能算法，中间不需要有任何IO的输入输出
示例
输入：“4 + 7”  输出：“11”
输入：“4 - 7”  输出：“-3”
输入：“9 ++ 7”  输出：“0” 注：格式错误*/

void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i,j,k,count,flag,PlusLocation; // 定义
	char c[50];
	int num[5];
	char *tp;
	tp = c;
	j = 0;
	k = 0;
	flag = 0;
	count = 0;
	for(i=0; i<lInputLen; i++)
	{
		if(*(pInputStr+i) == '+' || *(pInputStr+i) == '-')
		{				
			k++;
			if(k>1)
			{	
				flag = 1;
				printf("0 注：格式错误\n");
				break;
			}
			else
				PlusLocation = i;
		}
	}
	if(!flag)
	{
		for(i=0; i<PlusLocation-1; i++)
		{
			*(tp+i) = *(pInputStr+i);
			count++;
		}
		if(count<2)
			num[0] = *(tp) - 48;
		else
			num[0] = (*(tp)-48)*10 + (*(tp+1)-48);

		count = 0;
		for(i=PlusLocation+2; i<lInputLen; i++)
		{
			*(tp+i) = *(pInputStr+i);
			count++;
		}
		if(count<2)
			num[1] = *(tp+PlusLocation+2) - 48;
		else
			num[1] = (*(tp+PlusLocation+2)-48)*10 + (*(tp+PlusLocation+2+1)-48);
		printf("%d %c %d的运算结果：",num[0], *(pInputStr+PlusLocation), num[1]);
		if(*(pInputStr+PlusLocation) == '+')
			printf("%d\n", num[0]+num[1]);
		else
			printf("%d\n", num[0]-num[1]);
	}
}