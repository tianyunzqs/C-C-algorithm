#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�void InOrder(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ����������������
* �� �� ֵ����
* ˵    ��������---�����---�Һ���
**************************************************************/
void InOrder(btnode *bt)
{
	if(bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%-2c", bt->data);
		InOrder(bt->rchild);
	}
}