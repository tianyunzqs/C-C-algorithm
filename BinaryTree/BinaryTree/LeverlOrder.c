#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* 函数名称：void PreOrder(btnode *bt)
* 参    数：bt----二叉树的根结点
* 函数功能：二叉树的层次遍历
* 返 回 值：无
* 说    明：将层次遍历的各结点依次存入数组中，之后依次取出
**************************************************************/
void LeverlOrder(btnode *bt)
{
	//btnodePoint queue[20], p; // 队列大小需根据结点个数来调整，p为临时结点指针
	btnode *queue[20], *p;
	int front=0, rear=0; // 设置队头与队尾
	if(bt)
	{
		queue[rear++] = bt; // 先将二叉树的根结点入队
		while(front!=rear)  // 如果相等，则表示二叉树遍历完成
		{
			p = queue[front++]; // 顺序将层次遍历得到的结点出队
			printf("%-2c", p->data); 
			// 如果左子树不为空，将左孩子结点存入队列中
			if(p->lchild!=NULL)
				queue[rear++] = p->lchild;  // 先放左孩子
			// 如果右子树不为空，将右孩子结点存入队列中
			if(p->rchild!=NULL)
				queue[rear++] = p->rchild;  // 再放右孩子
		}
	}
}