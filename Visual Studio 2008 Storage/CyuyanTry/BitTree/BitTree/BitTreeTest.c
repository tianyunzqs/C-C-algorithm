#include <stdio.h>
#include <stdlib.h>
/* 二叉链表结点类型的定义 */
typedef struct btreenode
{
	char data;  // 数据域
	struct btreenode * lchild; // 左孩子指针
	struct btreenode * rchild; // 右孩子指针
}btnode;

btnode *createbitree()
{
	/* 输入扩充的先序序列，建立二叉树 */
	btnode *bt;
	char x;
	scanf("%c", &x);
	if(x == '#')
		bt = NULL;
	else
	{
		bt = (btnode *)malloc(sizeof(btnode));
		bt->data = x;
		bt->lchild = createbitree();
		bt->rchild = createbitree();
	}
	return(bt);
}


/* 先序遍历 */
void preorder(btnode *bt)
{
	if(bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}

/* 中序遍历 */
void midorder(btnode *bt)
{
	if(bt != NULL)
	{
		midorder(bt->lchild);
		printf("%c", bt->data);
		midorder(bt->rchild);
	}
}

/* 后序遍历 */
void posorder(btnode *bt)
{
	if(bt != NULL)
	{
		posorder(bt->lchild);
		posorder(bt->rchild);
		printf("%c", bt->data);
	}
}

/* 统计二叉树的叶子结点个数 */
int leaf(btnode *bt, int n)
{
	if(bt != NULL)
	{
		if(bt->lchild == NULL && bt->rchild == NULL)
			n++;
		n = leaf(bt->lchild, n);
		n = leaf(bt->rchild, n);
	}
	return(n);
}

/* 计算二叉树的高度 */
int high(btnode *bt)
{
	int h, lh, rh;
	if(bt == NULL)
		h = 0;
	else
	{
		lh = high(bt->lchild);
		rh = high(bt->rchild);
		h = lh>rh ? lh+1 : rh+1;
	}
	return(h);
}

void main()
{
	btnode *p;
	p = createbitree();
	printf("二叉树的先序遍历：");
	preorder(p);
	printf("\n");
	printf("二叉树的中序遍历：");
	midorder(p);
	printf("\n");
	printf("二叉树的后序遍历：");
	posorder(p);
	printf("\n");

	printf("二叉树的叶子结点个数：%d\n", leaf(p, 0));
	printf("二叉树的高度：%d\n", high(p));
	
}
