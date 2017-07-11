#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�unsigned int OneDegree(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ�ͳ�ƶ�������Ϊ1�Ľ�����
* �� �� ֵ����������Ϊ1�Ľ�����
* ˵    ����ֻ��һ�����ӻ�ֻ��һ���Һ��ӵĽ��Ϊ��Ϊ1�Ľ��
**************************************************************/
unsigned int OneDegree(btnode *bt)
{
	static unsigned int num=0;
	if(bt != NULL)
	{	
		if((bt->lchild==NULL && bt->rchild!=NULL) || (bt->lchild!=NULL && bt->rchild==NULL))
			num++;
		num = OneDegree(bt->lchild);
		num = OneDegree(bt->rchild);
	}
	return num;
}