#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：unsigned int IsSortBinaryTree(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：判断给定的二叉树是否为二叉排序树
* 返 回 值：是，返回1；否，返回0
* 说    明：利用二叉排序树的性质及层次遍历的思想进行判断
**************************************************************/
unsigned int IsSortBinaryTree(btnode *bt)
{
	int front=0, rear=0;  // 设置队头与队尾
	btnodePoint queue[20], p; // 队列大小需根据结点个数来调整，p为临时结点指针
	if(bt!=NULL)
	{
		queue[rear++] = bt;  // 先将二叉树的根结点入队
		while(front!=rear)  // 如果相等，则表示二叉树遍历完成
		{
			p = queue[front++]; // 顺序将层次遍历得到的结点出队
			// 如果左子树不为空，且父结点的值大于等于左孩子结点的值，
			// 那么符合二叉排序树规则，将左孩子结点存入队列中
			if(p->lchild!=NULL && p->data >= p->lchild->data)  
				queue[rear++] = p->lchild;  // 先放左孩子
			// 如果右子树不为空，且父结点的值小于等于右孩子结点的值，
			// 那么符合二叉排序树规则，将右孩子结点存入队列中
			if(p->rchild!=NULL && p->data <= p->rchild->data)
				queue[rear++] = p->rchild;  // 再放右孩子
			// 不符合二叉排序规则，则返回0
			if((p->lchild!=NULL&&p->data < p->lchild->data) || (p->rchild!=NULL&&p->data > p->rchild->data))
				return 0;
		}
		return 1;  // 二叉树遍历完成，且都符合二叉排序树规则，则返回1
	}
	else  // 二叉树为空
		return 0;
}