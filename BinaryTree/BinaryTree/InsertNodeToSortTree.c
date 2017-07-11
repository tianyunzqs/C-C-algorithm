#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�btnode *InsertNodeToSortTree(btnode *bt, char val)
* ��    ����bt----�����������ĸ����
			val---���������������ֵ
* �������ܣ������������Ĳ��������
* �� �� ֵ���������Ķ����������ĸ����
* ˵    �������ö��������������ʣ����ֲ��ҵ�˼�룩���в�����
**************************************************************/
btnode *InsertNodeToSortTree(btnode *bt, char val)
{
	if(bt==NULL)  // ����������Ϊ�գ�ֱ�ӽ��½�㸳ֵ�������
	{
		// ��ʼ���²���Ľ��
		btnode *newnode=(btnode *)malloc(sizeof(btnode));
		newnode->data = val;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		bt = newnode;
	}
	else // ���������������Ϊ��
	{
		if(bt->data >= val) // ��Ҫ�ڸ�������߲����½��
			bt->lchild = InsertNodeToSortTree(bt->lchild, val);
		else  // ��Ҫ�ڸ������ұ߲����½��
			bt->rchild = InsertNodeToSortTree(bt->rchild, val);
	}
	return bt;
}