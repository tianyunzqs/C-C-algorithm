#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�void PreOrder(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ����������������
* �� �� ֵ����
* ˵    ���������---����---�Һ���
**************************************************************/
void PreOrder(btnode *bt)
{
	if(bt != NULL)
	{
		printf("%-2c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}