#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：void InOrder(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：二叉树的中序遍历
* 返 回 值：无
* 说    明：左孩子---根结点---右孩子
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