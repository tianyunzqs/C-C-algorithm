#include "stdafx.h"
#include "stdio.h"
void main()
{
	char a[24], b;            //����������һ��λ��������
	printf("���������������������������Ϊ���밴��'1'��Ϊ���밴��'0',�����»س�\n");
	printf("�ö�����ë��\t");
	a[0]=getchar(); 
	getchar();                                       
	printf("�ö�������\t");
	a[1]=getchar(); 
	getchar();
	printf("�ö�������ë\t");
	a[2]=getchar(); 
	getchar(); 
	printf("�ö�����\t");
	a[3]=getchar(); 
	getchar(); 
	printf("�ö�����µ�\t");
	a[4]=getchar(); 
	getchar(); 
	printf("�ö������\t");
	a[5]=getchar(); 
	getchar(); 
	printf("�ö�����Ȯ��\t");
	a[6]=getchar(); 
	getchar(); 
	printf("�ö�����צ\t");
	a[7]=getchar(); 
	getchar(); 
	printf("�ö����۶�ǰ��\t");
	a[8]=getchar(); 
	getchar(); 
	printf("�ö�������\t");
	a[9]=getchar(); 
	getchar(); 
	printf("�ö���ʽ����ۻ����\t");
	a[10]=getchar(); 
	getchar();
	printf("�ö����ǻƺ�ɫ\t");
	a[11]=getchar(); 
	getchar();
	printf("�ö��������а��ߵ�\t");
	a[12]=getchar(); 
	getchar(); 
	printf("�ö��������к�ɫ����\t");
	a[13]=getchar(); 
	getchar(); 
	printf("�ö����г�����\t");
	a[14]=getchar(); 
	getchar(); 
	printf("�ö����г���\t");
	a[15]=getchar(); 
	getchar();

	//a[3]=1��a[16]=0,��ǰ����������,�˴��Զ���Ϊ�����,��֮��Ȼ
	if(a[3]=='1')               
		a[16]='0';
	else a[16]='1';    
	printf("�ö����кڰ���ɫ\t");
	a[17]=getchar(); 
	getchar(); 
	printf("�ö������Ӿ\t");
	a[18]=getchar(); 
	getchar(); 
	printf("�ö����Ʒ�\t");
	a[19]=getchar(); 
	getchar(); 

	if(a[0]=='1')                             //����1
		a[20]='1';
	if(a[1]=='1')                             //����2
		a[20]='1';
	if(a[2]=='1')                             //����3
		a[21]='1';
	if(a[3]=='1'&&a[4]=='1')                  //����4
		a[21]='1';
	if(a[5]=='1')                             //����5
		a[22]='1';
	if(a[7]=='1'&&a[8]=='1'&&a[6]=='1')       //����6
		a[22]='1';
	if(a[9]=='1'&&a[20]=='1')                 //����7
		a[23]='1';
	if(a[10]=='1'&&a[20]=='1')                //����8
		a[23]='1';
	if(a[20]=='1'&&a[22]=='1'&&a[11]=='1'&&a[12]=='1')       //����9
		b='1';
	if(a[20]=='1'&&a[22]=='1'&&a[11]=='1'&&a[13]=='1')       //����10
		b='2';
	if(a[23]=='1'&&a[14]=='1'&&a[15]=='1'&&a[12]=='1')       //����11
		b='3';
	if(a[23]=='1'&&a[13]=='1')                               //����12
		b='4';
	if(a[21]=='1'&&a[14]=='1'&&a[15]=='1'&&a[16]=='1'&&a[17]=='1') //����13
		b='5';
	if(a[21]=='1'&&a[18]=='1'&&a[16]=='1'&&a[17]=='1')       //����14
		b='6';
	if(a[21]=='1'&&a[19]=='1')                               //����15
		b='7';

	switch (b)
	{
	case '1':
		printf("�ö����ǽ�Ǯ��\n");
		break;
	case '2':
		printf("�ö����ǻ�\n");
		break;
	case '3':
		printf("�ö����ǳ���¹\n");
		break;
	case '4':
		printf("�ö����ǰ���\n");
		break;
	case '5':
		printf("�ö���������\n");
		break;
	case '6':
		printf("�ö��������\n");
		break;
	case '7':
		printf("�ö�����������\n");
		break;
	default:
		printf("�����������������������\n");
		printf("���س�������\n");
		getchar();
	}
}

