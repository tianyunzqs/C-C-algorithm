#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：btnode *InsertNodeToSortTree(btnode *bt, char val)
* 参    数：bt----二叉排序树的根结点
			val---待插入结点的数据域值
* 函数功能：二叉排序树的插入结点操作
* 返 回 值：插入结点后的二叉排序树的根结点
* 说    明：利用二叉排序树的性质（二分查找的思想）进行插入结点
**************************************************************/
btnode *InsertNodeToSortTree(btnode *bt, char val)
{
	if(bt==NULL)  // 二叉排序树为空，直接将新结点赋值给根结点
	{
		// 初始化新插入的结点
		btnode *newnode=(btnode *)malloc(sizeof(btnode));
		newnode->data = val;
		newnode->lchild = NULL;
		newnode->rchild = NULL;
		bt = newnode;
	}
	else // 如果二叉排序树不为空
	{
		if(bt->data >= val) // 需要在父结点的左边插入新结点
			bt->lchild = InsertNodeToSortTree(bt->lchild, val);
		else  // 需要在父结点的右边插入新结点
			bt->rchild = InsertNodeToSortTree(bt->rchild, val);
	}
	return bt;
}