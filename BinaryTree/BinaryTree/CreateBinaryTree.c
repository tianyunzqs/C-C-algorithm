#include <stdio.h>
#include <stdlib.h>  // malloc������ͷ�ļ�
#include "BinaryTree.h" 

/******************************************************
* �������ƣ�btnode *CtreateBinaryTree(char *str)
* ��    ����str----����������������������ַ�����
* �������ܣ���������������򴴽�ָ���Ķ�����		
* �� �� ֵ�������������ĸ����
* ˵    ������
******************************************************/
btnode *CtreateBinaryTree(char *str)
{
	btnode *bt;
	char x;
	static int i=0;
	//scanf("%c", &x);
	x = str[i++];  // ȡ������������ֵ
	if(x=='#')  // #��ʾ�޶�Ӧ���
		bt = NULL;
	else
	{
		bt = (btnode *)malloc(sizeof(btnode));
		bt->data = x;
		bt->lchild = CtreateBinaryTree(str);
		bt->rchild = CtreateBinaryTree(str);
	}
	return bt;
}