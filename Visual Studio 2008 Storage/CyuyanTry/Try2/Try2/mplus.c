#include <stdio.h>
#include <malloc.h>
/*
void main()
{
	int x, y;
	printf("Enter integer x,y:");
	scanf_s("%d%d", &x, &y);  // scanf()����Ҳ����
	printf("x+y=%d\n", x+y);
}
*/

typedef int datatype;

// ��������ڵ�
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

// ����ѭ������
linklist *createhhead()
{
	datatype x;
	linklist *head, *p, *temp;
	head = (linklist *)malloc(sizeof(linklist));
	temp = (linklist *)malloc(sizeof(linklist));
	
	// ͷ���
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
	// β�ڵ�����ͷ���
	p->next->next = head;  // p�ڵ��ǵ����ڶ����ڵ�
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