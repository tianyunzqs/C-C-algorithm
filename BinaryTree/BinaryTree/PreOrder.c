#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：void PreOrder(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：二叉树的先序遍历
* 返 回 值：无
* 说    明：根结点---左孩子---右孩子
**************************************************************/
void PreOrder(btnode *bt)
{
	if(bt != NULL)
	{
		printf("%-2c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}