// ����N����Χ��һȦ����˳ʱ�뷽���1��N��ţ��ӵ�S���˿�ʼ����1��M������
// ������M����ʱ�����˳�Ȧ���ٴ�������һ�������¿�ʼ1��M�ı�����
// ��˽�����ȥֱ�����е��˶���ȦΪֹ����ӡ��Ȧ����

// ʵ�ַ�����ѭ��������������Ĵ����ͽ���ɾ����
#include <stdio.h>
#include <malloc.h>

typedef int datatype;

// ��������ڵ�
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

// ����ѭ��������巨��
linklist *createhrear(int t)
{
	int i = 2;
	linklist *head, *rear, *r;

	head = (linklist *)malloc(sizeof(linklist));
	head->data = 1;
	rear = head;
	
	while(i<=t)
	{
		r = (linklist *)malloc(sizeof(linklist));
		r->data = i;
		rear->next = r;
		rear = r;
		i++;
	}
	rear->next = head;
	return(head);
}


// ���룺n ��Ϸ������
//		 s ��������ʼ���
//		 m ��������ֵ
// �����p ָ�򳤶�Ϊn�����飬��Ȧ���򱣴���pָ���������
void circle_sort(int n, int s, int m, int *p)
{
	linklist *q, *Nextq, *Frontq;
	int i, j, k;
	q = createhrear(n); // ��ȡ����ͷ���
	// Ѱ����ʼ��Ŷ�Ӧ�Ľ��
	for(j=1; j<s; j++)
		q = q->next;
	
	for(i=1; i<=n; i++)
	{
		// ��λ����ΪM����
		for(j=1; j<m; j++)
			q = q->next;
		*(p+i-1) = q->data; // ��¼��Ȧ�˵ı�ţ���ϳɳ�Ȧ����
		// ��λ����ΪM���˵���һ����Nextq
		Nextq = q->next;
		// ��λ����ΪM���˵�ǰһ����Frontq
		for(k=1; k<=n-i; k++)
			q = q->next;
		free(q->next); // ɾ����Ȧ������Ӧ�Ľ��
		Frontq = q;
		Frontq->next = Nextq;
		q = Nextq;	// �´α����ӳ�Ȧ�˵���һ���˿�ʼ	
	}
	// ��ӡ��Ȧ����
	printf("��Ȧ����:");
	for(i=1; i<=n; i++)
	{
		printf("%d\t", *(p+i-1));
	}
	printf("\n");
}

void main()
{	
	int a[100];
	circle_sort(12,4,6,a);
}