#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�unsigned int OneDegree(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ�ͳ�ƶ�������Ϊ2�Ľ�����
* �� �� ֵ����������Ϊ2�Ľ�����
* ˵    �����������������Һ��ӵĽ��Ϊ��Ϊ2�Ľ��
**************************************************************/
unsigned int TwoDegree(btnode *bt)
{
	static unsigned int num=0;
	if(bt != NULL)
	{	
		if(bt->lchild!=NULL && bt->rchild!=NULL)
			num++;
		num = TwoDegree(bt->lchild);
		num = TwoDegree(bt->rchild);
	}
	return num;
}