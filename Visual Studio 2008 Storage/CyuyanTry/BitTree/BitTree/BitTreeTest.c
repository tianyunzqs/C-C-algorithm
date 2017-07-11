#include <stdio.h>
#include <stdlib.h>
/* �������������͵Ķ��� */
typedef struct btreenode
{
	char data;  // ������
	struct btreenode * lchild; // ����ָ��
	struct btreenode * rchild; // �Һ���ָ��
}btnode;

btnode *createbitree()
{
	/* ����������������У����������� */
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


/* ������� */
void preorder(btnode *bt)
{
	if(bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}

/* ������� */
void midorder(btnode *bt)
{
	if(bt != NULL)
	{
		midorder(bt->lchild);
		printf("%c", bt->data);
		midorder(bt->rchild);
	}
}

/* ������� */
void posorder(btnode *bt)
{
	if(bt != NULL)
	{
		posorder(bt->lchild);
		posorder(bt->rchild);
		printf("%c", bt->data);
	}
}

/* ͳ�ƶ�������Ҷ�ӽ����� */
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

/* ����������ĸ߶� */
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
	printf("�����������������");
	preorder(p);
	printf("\n");
	printf("�����������������");
	midorder(p);
	printf("\n");
	printf("�������ĺ��������");
	posorder(p);
	printf("\n");

	printf("��������Ҷ�ӽ�������%d\n", leaf(p, 0));
	printf("�������ĸ߶ȣ�%d\n", high(p));
	
}
