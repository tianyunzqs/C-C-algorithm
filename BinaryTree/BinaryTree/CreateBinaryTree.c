#include <stdio.h>
#include <stdlib.h>  // malloc函数的头文件
#include "BinaryTree.h" 

/******************************************************
* 函数名称：btnode *CtreateBinaryTree(char *str)
* 参    数：str----待创建二叉树的先序遍历字符序列
* 函数功能：根据先序遍历规则创建指定的二叉树		
* 返 回 值：创建二叉树的根结点
* 说    明：无
******************************************************/
btnode *CtreateBinaryTree(char *str)
{
	btnode *bt;
	char x;
	static int i=0;
	//scanf("%c", &x);
	x = str[i++];  // 取出结点数据域的值
	if(x=='#')  // #表示无对应结点
		bt = NULL;
	else
	{
		bt = (btnode *)malloc(sizeof(btnode));
		bt->data = x;
		bt->lchild = CtreateBinaryTree(str);
		bt->rchild = CtreateBinaryTree(str);
	}
	return bt;
}