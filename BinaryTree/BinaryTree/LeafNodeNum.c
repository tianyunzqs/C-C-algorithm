#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�unsigned int LeafNodeNum(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ�ͳ�ƶ�������Ϊ0�Ľ��(Ҷ�ӽ��)����
* �� �� ֵ����������Ϊ0�Ľ��(Ҷ�ӽ��)����
* ˵    ���������Ӻ��Һ��ӵĽ��ΪҶ�ӽ��
**************************************************************/
unsigned int LeafNodeNum(btnode *bt)
{
	static unsigned int num=0;
	if(bt != NULL)
	{	
		if(bt->lchild==NULL && bt->rchild==NULL)
			num++;
		num = LeafNodeNum(bt->lchild);
		num = LeafNodeNum(bt->rchild);
	}
	return num;
}