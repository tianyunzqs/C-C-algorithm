#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：unsigned int OneDegree(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：统计二叉树度为2的结点个数
* 返 回 值：二叉树度为2的结点个数
* 说    明：既有左孩子又有右孩子的结点为度为2的结点
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