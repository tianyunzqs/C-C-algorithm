#include <stdio.h>
#include "BinaryTree.h"
void DeepOrder(btnode *bt)
{
	btnodePoint queue[10], p;
	int front=0, rear=0;
	if(bt)
	{
		queue[rear++] = bt;
		while(front!=rear)
		{
			p = queue[front++];
			printf("%-2c", p->data);
			if(p->rchild!=NULL)
				queue[rear++] = p->rchild;
			if(p->lchild!=NULL)
				queue[rear++] = p->lchild;
		}
	}
}