// ����N����Χ��һȦ����˳ʱ�뷽���1��N��ţ��ӵ�S���˿�ʼ����1��M������
// ������M����ʱ�����˳�Ȧ���ٴ�������һ�������¿�ʼ1��M�ı�����
// ��˽�����ȥֱ�����е��˶���ȦΪֹ����ӡ��Ȧ����

// ʵ�ַ�����ѭ��������������Ĵ����ͽ���ɾ����
#include <stdio.h>
#include <malloc.h>

//// ��������ڵ�
//typedef struct node
//{
//	int data;
//	struct node *next;
//}linklist;
//
//// ����ѭ��������巨��
//linklist *createhrear(int t)
//{
//	int i = 2;
//	linklist *head, *rear, *r;
//
//	head = (linklist *)malloc(sizeof(linklist));
//	head->data = 1;
//	rear = head;
//	
//	while(i<=t)
//	{
//		r = (linklist *)malloc(sizeof(linklist));
//		r->data = i;
//		rear->next = r;
//		rear = r;
//		i++;
//	}
//	rear->next = head;
//	return(head);
//}
//
//
//// ���룺n ��Ϸ������
////		 s ��������ʼ���
////		 m ��������ֵ
//// �����p ָ�򳤶�Ϊn�����飬��Ȧ���򱣴���pָ���������
//void circle_sort(int n, int s, int m, int *p)
//{
//	linklist *q, *Nextq;
//	int i, j, k;
//	q = createhrear(n); // ��ȡ����ͷ���
//	// Ѱ����ʼ��Ŷ�Ӧ�Ľ��
//	for(j=1; j<s; j++)
//		q = q->next;
//	
//	for(i=1; i<=n; i++)
//	{
//		// ��λ����ΪM����
//		for(j=1; j<m; j++)
//			q = q->next;
//		*(p+i-1) = q->data; // ��¼��Ȧ�˵ı�ţ���ϳɳ�Ȧ����
//		// ��λ����ΪM���˵���һ����Nextq
//		Nextq = q->next;
//		// ��λ����ΪM���˵�ǰһ����Frontq
//		for(k=1; k<=n-i; k++)
//			q = q->next;
//		free(q->next); // ɾ����Ȧ������Ӧ�Ľ��
//		q->next = Nextq;
//		q = q->next;// �´α����ӳ�Ȧ�˵���һ���˿�ʼ
//	}
//}


void JosephMatrix(int n, int s, int m, int a[])
{
	int i,j,w;
	int s1 = s;
	for(i=0; i<n; i++)      //��n���˵���ŷ�������a[]�У�
		a[i] = i+1;
	for(i=n; i>=2; i--)
	{
		s1 = (s1+m-1)%i;       //s1ÿ�γ�Ȧ�˵�λ�ã���ȥ����Ȧ�˵����к���±꣩
		if(s1 == 0)            //���s1����0����˵��Ҫ��ʼ�������������һ����
			s1 = i;            //�Ѵ�ʱ����i��ֵ����s1
		printf("%d ", s1);
		w = a[s1-1];           //��ÿ�γ�Ȧ�˵���Ÿ���w
		for(j=s1; j<i; j++)  // ��s1�����ÿ������ǰ�ƶ�һ��λ��
			a[j-1] = a[j];
		a[i-1] = w;            //��ÿ�γ�Ȧ�˵���Ÿ���������i��λ���ϣ���Ȧ˳�����δ�ŵ����
	}
	printf("\n");
	for(i=n-1; i>= 0; i--)
         printf("%d ", a[i]);
	printf("\n");
}


void main()
{	
// n ��Ϸ������
// s ��������ʼ���
// m ��������ֵ
	int a[20], i;
	int n=12, s=4, m=6;
	//circle_sort(n,s,m,a);
	//// ��ӡ��Ȧ����
	//printf("��Ȧ����:");
	//for(i=1; i<=n; i++)
	//	printf("%d ", a[i-1]);
	//printf("\n");

	JosephMatrix(n,s,m,a);
}