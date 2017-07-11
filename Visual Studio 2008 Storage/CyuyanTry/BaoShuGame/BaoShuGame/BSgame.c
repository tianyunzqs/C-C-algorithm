// 设有N个人围坐一圈并按顺时针方向从1到N编号，从第S个人开始进行1到M报数，
// 报到第M个人时，此人出圈，再从他的下一个人重新开始1到M的报数，
// 如此进行下去直到所有的人都出圈为止，打印出圈次序。

// 实现方法：循环链表（包括链表的创建和结点的删除）
#include <stdio.h>
#include <malloc.h>

typedef int datatype;

// 定义链表节点
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

// 创建循环链表（后插法）
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


// 输入：n 游戏总人数
//		 s 报数的起始编号
//		 m 报数的数值
// 输出：p 指向长度为n的数组，出圈次序保存在p指向的数组中
void circle_sort(int n, int s, int m, int *p)
{
	linklist *q, *Nextq, *Frontq;
	int i, j, k;
	q = createhrear(n); // 获取链表头结点
	// 寻找起始编号对应的结点
	for(j=1; j<s; j++)
		q = q->next;
	
	for(i=1; i<=n; i++)
	{
		// 定位报数为M的人
		for(j=1; j<m; j++)
			q = q->next;
		*(p+i-1) = q->data; // 记录出圈人的编号（组合成出圈次序）
		// 定位报数为M的人的下一个人Nextq
		Nextq = q->next;
		// 定位报数为M的人的前一个人Frontq
		for(k=1; k<=n-i; k++)
			q = q->next;
		free(q->next); // 删除出圈人所对应的结点
		Frontq = q;
		Frontq->next = Nextq;
		q = Nextq;	// 下次报数从出圈人的下一个人开始	
	}
	// 打印出圈次序
	printf("出圈次序:");
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