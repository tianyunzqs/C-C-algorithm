#include "stdafx.h"
#include "stdio.h"
void main()
{
	char a[24], b;            //动物特征用一个位的数组存放
	printf("下面是描述动物的特征，若特征为真请按下'1'，为假请按下'0',并按下回车\n");
	printf("该动物有毛发\t");
	a[0]=getchar(); 
	getchar();                                       
	printf("该动物有奶\t");
	a[1]=getchar(); 
	getchar();
	printf("该动物有羽毛\t");
	a[2]=getchar(); 
	getchar(); 
	printf("该动物会飞\t");
	a[3]=getchar(); 
	getchar(); 
	printf("该动物会下蛋\t");
	a[4]=getchar(); 
	getchar(); 
	printf("该动物吃肉\t");
	a[5]=getchar(); 
	getchar(); 
	printf("该动物有犬齿\t");
	a[6]=getchar(); 
	getchar(); 
	printf("该动物有爪\t");
	a[7]=getchar(); 
	getchar(); 
	printf("该动物眼盯前方\t");
	a[8]=getchar(); 
	getchar(); 
	printf("该动物有蹄\t");
	a[9]=getchar(); 
	getchar(); 
	printf("该动物式嚼反刍动物\t");
	a[10]=getchar(); 
	getchar();
	printf("该动物是黄褐色\t");
	a[11]=getchar(); 
	getchar();
	printf("该动物身上有暗斑点\t");
	a[12]=getchar(); 
	getchar(); 
	printf("该动物身上有黑色条纹\t");
	a[13]=getchar(); 
	getchar(); 
	printf("该动物有长脖子\t");
	a[14]=getchar(); 
	getchar(); 
	printf("该动物有长腿\t");
	a[15]=getchar(); 
	getchar();

	//a[3]=1则a[16]=0,即前面已输入会飞,此处自动变为不会飞,反之亦然
	if(a[3]=='1')               
		a[16]='0';
	else a[16]='1';    
	printf("该动物有黑白两色\t");
	a[17]=getchar(); 
	getchar(); 
	printf("该动物会游泳\t");
	a[18]=getchar(); 
	getchar(); 
	printf("该动物善飞\t");
	a[19]=getchar(); 
	getchar(); 

	if(a[0]=='1')                             //规则1
		a[20]='1';
	if(a[1]=='1')                             //规则2
		a[20]='1';
	if(a[2]=='1')                             //规则3
		a[21]='1';
	if(a[3]=='1'&&a[4]=='1')                  //规则4
		a[21]='1';
	if(a[5]=='1')                             //规则5
		a[22]='1';
	if(a[7]=='1'&&a[8]=='1'&&a[6]=='1')       //规则6
		a[22]='1';
	if(a[9]=='1'&&a[20]=='1')                 //规则7
		a[23]='1';
	if(a[10]=='1'&&a[20]=='1')                //规则8
		a[23]='1';
	if(a[20]=='1'&&a[22]=='1'&&a[11]=='1'&&a[12]=='1')       //规则9
		b='1';
	if(a[20]=='1'&&a[22]=='1'&&a[11]=='1'&&a[13]=='1')       //规则10
		b='2';
	if(a[23]=='1'&&a[14]=='1'&&a[15]=='1'&&a[12]=='1')       //规则11
		b='3';
	if(a[23]=='1'&&a[13]=='1')                               //规则12
		b='4';
	if(a[21]=='1'&&a[14]=='1'&&a[15]=='1'&&a[16]=='1'&&a[17]=='1') //规则13
		b='5';
	if(a[21]=='1'&&a[18]=='1'&&a[16]=='1'&&a[17]=='1')       //规则14
		b='6';
	if(a[21]=='1'&&a[19]=='1')                               //规则15
		b='7';

	switch (b)
	{
	case '1':
		printf("该动物是金钱豹\n");
		break;
	case '2':
		printf("该动物是虎\n");
		break;
	case '3':
		printf("该动物是长颈鹿\n");
		break;
	case '4':
		printf("该动物是斑马\n");
		break;
	case '5':
		printf("该动物是鸵鸟\n");
		break;
	case '6':
		printf("该动物是企鹅\n");
		break;
	case '7':
		printf("该动物是信天翁\n");
		break;
	default:
		printf("描述有误，请结束后重新描述\n");
		printf("按回车键结束\n");
		getchar();
	}
}

