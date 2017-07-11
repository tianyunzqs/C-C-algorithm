#include<stdlib.h>
#include "nodedef.h"

#define CreateLinklistWay 1   // 0表示头插法创建链表，1表示尾插法创建链表

#if !CreateLinklistWay

/*********************************************************************
* 函数名称：linklist *CreateLinklistHead()
* 函数功能：利用头插法创建链表
* 参    数：无
* 返 回 值：创建完链表后的链表头结点
* 说    明：无
*********************************************************************/
extern linklist *CreateLinklistHead()
{
	int x, i, nodeNum;
	linklist *head, *temp;  // 头结点与临时结点
	head = (linklist *)malloc(sizeof(linklist));  // 生成表头结点
	head->next = NULL;   // 给表头结点的指针域赋值
	printf("请输入链表中结点的个数：");
	scanf("%d", &nodeNum);
	for(i=1; i<=nodeNum; i++)
	{
		printf("请输入第 %d 个结点的数据：", i);
		scanf("%d", &x);
		temp = (linklist *)malloc(sizeof(linklist));  // 生成新的结点
		temp->data = x;    // 对新结点的数据域赋值
		// 将新结点插到头结点之后
		temp->next = head->next; 
		head->next = temp;
	}
	return head;  // 返回新建链表的头结点
}

#else

/*********************************************************************
* 函数名称：linklist *CreateLinklistRear()
* 函数功能：利用尾插法创建链表
* 参    数：无
* 返 回 值：创建完链表后的链表头结点
* 说    明：无
*********************************************************************/
extern linklist *CreateLinklistRear()
{
	int x, i, nodeNum;
	linklist *head, *rear, *temp;  // 定义头结点、尾结点和临时结点
	head = (linklist *)malloc(sizeof(linklist));  // 生成表头结点，表头结点不存放数据
	head->next = NULL;  // 将表头结点的指针域赋值为NULL
	rear = head;  // 将表头结点赋值给表尾结点
	printf("请输入链表中结点的个数：");
	scanf("%d", &nodeNum);
	for(i=1; i<=nodeNum; i++)
	{
		printf("请输入第 %d 个结点的数据：", i);
		scanf("%d", &x);
		temp = (linklist *)malloc(sizeof(linklist));  // 生成新的结点
		temp->data = x;   // 新增结点的数据域
		temp->next = NULL; // 新增结点的指针域（由于是尾插法，所以插入的结点都在尾部，即指针域为NULL）
		rear->next = temp; // 使前一个结点指向新增结点(head->next=temp)
		rear = temp;  // 将新增结点赋值给尾结点（尾插法，插入的结点在尾部）(rear=head->next)
	}
	//rear->next = NULL;  // 将尾结点的指针域赋值为空（为了方便检验链表是否为空链表）
	return head;  // 返回头结点
}

#endif