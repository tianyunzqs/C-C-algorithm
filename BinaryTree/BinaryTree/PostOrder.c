#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�void PostOrder(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ��������ĺ������
* �� �� ֵ����
* ˵    ��������---�Һ���---�����
**************************************************************/
void PostOrder(btnode *bt)
{
	if(bt != NULL)
	{		
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%-2c", bt->data);
	}
}