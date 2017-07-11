#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：unsigned int LeafNodeNum(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：统计二叉树度为0的结点(叶子结点)个数
* 返 回 值：二叉树度为0的结点(叶子结点)个数
* 说    明：无左孩子和右孩子的结点为叶子结点
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