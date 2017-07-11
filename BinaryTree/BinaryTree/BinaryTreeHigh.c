#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�unsigned int BinaryTreeHigh(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ�����������ĸ߶�
* �� �� ֵ���������ĸ߶�ֵ
* ˵    �����������ĸ߶�Ϊ�������н���ε����ֵ��
		    ��һ�ö�����Ϊ�գ�����߶�Ϊ0��������߶ȵ���������
			�������������߶ȼ�1������
			h(bt) = 0    (bt=NULL)
			h(bt) = max{h(bt->lchild), h(bt->rchild)}+1  (����)
**************************************************************/
unsigned int BinaryTreeHigh(btnode *bt)
{
	unsigned int h, lh, rh;
	if(bt == NULL)
		h = 0;
	else
	{	
		lh = BinaryTreeHigh(bt->lchild);
		rh = BinaryTreeHigh(bt->rchild);
		h = lh>rh ? lh+1 : rh+1;
	}
	return h;
}