#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/**************************************************************
* 函数名称：btnode *CreateSortBinaryTree(char str[])
* 参    数：str----待创建二叉树的先序遍历字符序列
* 函数功能：创建一个二叉排序树
* 返 回 值：创建的二叉排序树的根结点
* 说    明：先创建一个空树，之后将每个结点值插入二叉排序树中，
			逐步建立二叉排序树
**************************************************************/
btnode *CreateSortBinaryTree(char str[])
{
	btnode *SortBinaryTreeRoot=(btnode *)malloc(sizeof(btnode)); // 申请结点空间
	static int i=0;
	SortBinaryTreeRoot = NULL; // 创建一个空二叉树
	while(str[i]!='\0')
	{
		if(str[i]!='#')  // '#'表示按照先序遍历创建二叉树的空结点
			// 依次将每个结点插入二叉排序树中，逐步建立完整的二叉排序树
			SortBinaryTreeRoot = InsertNodeToSortTree(SortBinaryTreeRoot, str[i]);
		i++;
	}
	return SortBinaryTreeRoot;  // 返回建立的二叉排序树的根结点
}