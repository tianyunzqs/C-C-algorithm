#include <stdio.h>
#include <malloc.h>

typedef int datatype;

// ��������ڵ�
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

/*
// ����ѭ������
linklist *createhhead(int x[], int t)
{
//	datatype x;
	int i = 2;
	linklist *head, *r, *temp;
	head = (linklist *)malloc(sizeof(linklist));
	temp = (linklist *)malloc(sizeof(linklist));
	
	// ͷ���
	head->data = x[0];
	head->next = temp;

	temp->data = x[1];
	temp->next = NULL;

//	x = 1;
	while(i<t)
	{
		r = (linklist *)malloc(sizeof(linklist));
		r->data = x[i];
		r->next = temp->next;
		temp->next = r;
		i++;
	}
	// β�ڵ�����ͷ���
	r->next->next = head;  // p�ڵ��ǵ����ڶ����ڵ�
	return(head);
}
*/

// ����ѭ��������巨��
linklist *createhrear()
{
	datatype x;
	linklist *head, *rear, *p;
	head = (linklist *)malloc(sizeof(linklist));
	head->data = 123;
	rear = head;
	x = 1;
	while(x<5)
	{
		p = (linklist *)malloc(sizeof(linklist));
		p->data = x;
		rear->next = p;
		rear = p;
		x++;
	}
	rear->next = head;
	return(head);
}


void main()
{
	linklist *q;
	q = createhrear();
	for(int j=1; j<12; j++)
	{
		printf("%d\n", q->data);
		q = q->next;
	}
}