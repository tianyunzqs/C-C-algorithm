// 扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。
// 牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）
// 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
// 输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
// 请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

// 基本规则：
//（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，
//     不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
//（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系
//    （如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
//（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；
//     炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
//（4）输入的两手牌不会出现相等的情况。

// 答案提示：
// （1）除了炸弹和对王之外，其他必须同类型比较。
// （2）输入已经保证合法性，不用检查输入是否是合法的牌。
// （3）输入的顺子已经经过从小到大排序，因此不用再排序了.

#include <iostream>
#include <string.h>
using namespace std;
void CardCompare(char output[], char input[], int len);
int main()
{
    char input[] = "joker JOKER-K K K K";
    int len = strlen(input);
    char *output = new char[len];
    memset(output, 0, len);
    CardCompare(output, input, len);
    cout<<output<<endl;
    return 0;
}

// 从最大的开始往小的方向依次比较
void OneNumberCompare(char output[], char *str1, char *str2)
{
	if((str1=="JOKER") || (str2=="JOKER"))  // 如果个子中含有大王，则输出大王
	{
		strcpy(output, "JOKER");
		return;
	}
	else if((str1=="joker") || (str2=="joker"))  // 如果个子中含有小王，则输出小王
	{
		strcpy(output, "joker");
		return;
	}
	else if((str1[0]=='2') || (str2[0]=='2'))  // 如果个子、对子、三个、炸弹中含有2，则输出含有2的那手牌
	{
		strcpy(output, str1[0]=='2' ? str1 : str2);
		return;
	}
	else if(str1[0]=='1' && str1[1]=='0') // 如果第一张牌为10，则比较第一张牌的大小
	{
		strcpy(output, str2[0]>10+'0' ? str2 : str1); 
		return;
	}
	else if(str2[0]=='1' && str2[1]=='0')  // 如果第一张牌为10，则比较第一张牌的大小
	{
		strcpy(output, str1[0]>10+'0' ? str1 : str2);
		return;
	}
	else if(str1[0]>str2[0])  // 不是大小王、2、10等特殊牌型的比较
	{
		strcpy(output, str1);
		return;
	}
	else
	{
		strcpy(output, str2);
		return;
	}
}

void CardCompare(char output[], char input[], int len)
{
	// 如果两手牌中存在对王，则输出对王
    if(strstr(input, "joker JOKER")!=NULL)
    {
        strcpy(output, "joker JOKER");
        return;
    }
    char *str1 = new char[len];  // 存放第一手牌
    char *str2 = new char[len];  // 存放第二手牌
    memset(str1, 0, len);
    memset(str2, 0, len);
    for(int i=0; i<len; ++i)
    {
        if(input[i]=='-')  // 第一手牌和第二手牌用'-'隔开
        {
            strncpy(str1, input, i);
            strncpy(str2, input+i+1, len-i-1);
			break;
        }
    }
	int cnt1=0, cnt2=0; // 用来标志两手牌的张数
	for(int i=0,j=0; i<strlen(str1)||j<strlen(str2); ++i,++j)
	{
		if(str1[i]==' ')
			cnt1++;
		if(str2[j]==' ')
			cnt2++;
	}
	if(cnt1==cnt2) // 如果两数牌张数相同，则说明是同类型的牌比较大小，只需比较第一张牌就行
	{
		OneNumberCompare(output, str1, str2);
	}
	else if(strlen(str1)==7 || strlen(str2)==7)  // 如果两手牌中只有一手牌存在炸弹，则直接输出该炸弹
    {
        strcpy(output, strlen(str1)==7 ? str1 : str2);
        return;
    }
	else  // 如果两手牌张数不同，且不含炸弹，那么无法比较大小，输出"ERROR"
	{
		strcpy(output, "ERROR");
        return;
	}
}    