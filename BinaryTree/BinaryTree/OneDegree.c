#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：unsigned int OneDegree(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：统计二叉树度为1的结点个数
* 返 回 值：二叉树度为1的结点个数
* 说    明：只有一个左孩子或只有一个右孩子的结点为度为1的结点
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