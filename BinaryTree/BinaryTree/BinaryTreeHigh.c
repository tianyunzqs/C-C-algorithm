#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：unsigned int BinaryTreeHigh(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：计算二叉树的高度
* 返 回 值：二叉树的高度值
* 说    明：二叉树的高度为二叉树中结点层次的最大值。
		    若一棵二叉树为空，则其高度为0；否则其高度等于左子树
			和右子树的最大高度加1，即：
			h(bt) = 0    (bt=NULL)
			h(bt) = max{h(bt->lchild), h(bt->rchild)}+1  (其他)
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