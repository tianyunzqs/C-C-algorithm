#include <stdio.h>
#include <malloc.h>
/*
void main()
{
	int x, y;
	printf("Enter integer x,y:");
	scanf_s("%d%d", &x, &y);  // scanf()函数也可以
	printf("x+y=%d\n", x+y);
}
*/

typedef int datatype;

// 定义链表节点
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

// 创建循环链表
linklist *createhhead()
{
	datatype x;
	linklist *head, *p, *temp;
	head = (linklist *)malloc(sizeof(linklist));
	temp = (linklist *)malloc(sizeof(linklist));
	
	// 头结点
	head->data = 121;
	head->next = temp;

	temp->data = 232;
	temp->next = NULL;

	x = 1;
	while(x<3)
	{
		p = (linklist *)malloc(sizeof(linklist));
		p->data = x;
		p->next = temp->next;
		temp->next = p;
		x++;
	}
	// 尾节点连接头结点
	p->next->next = head;  // p节点是倒数第二个节点
	return(head);
}

void main()
{
	linklist *q;
	int i;
	q = createhhead();
	for(i=1; i<10; i++)
	{
		printf("%d\n", q->data);
		q = q->next;

	}
	
}