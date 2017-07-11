#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：void PostOrder(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：二叉树的后序遍历
* 返 回 值：无
* 说    明：左孩子---右孩子---根结点
**************************************************************/
void PostOrder(btnode *bt)
{
	if(bt != NULL)
	{		
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%-2c", bt->data);
	}
}