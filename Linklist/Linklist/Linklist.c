#include<stdio.h>
#include<stdlib.h>
#include "nodedef.h"

#define CreateLinklistWay 1   // 0表示头插法创建链表，1表示尾插法创建链表

extern linklist *CreateLinklistRear();
extern linklist *DeleteLoc(linklist *head, int Loc);
extern linklist *DeleteNode(linklist *head, int val);
extern linklist *InsertLoc(linklist *head, int Loc, int val);
extern linklist *ResverLinklist(linklist *head);
extern linklist *IsCross(linklist *head1, linklist *head2);
extern linklist *IsLoop(linklist *head);
extern linklist *SortLinklist(linklist *head);
extern int CountNodeNum(linklist *head, int IncludeHead);


void main()
{
	linklist *head;
#if !CreateLinklistWay
	head = CreateLinklistHead();
#else
	head = CreateLinklistRear();
#endif

/*****************测试创建链表CreateLinklistRear()*****************/
	{
		linklist *CreateHead;
		int i, NodeNum;

		CreateHead = head;
		if(CreateHead==NULL || CreateHead->next==NULL)
		{
			printf("空链表或只含头结点的链表！\n");
			return;
		}
		printf("\n创建的链表为：");
		NodeNum = CountNodeNum(CreateHead, 1);		
		for(i=0; i<NodeNum; i++)
		{
			printf("%d ", CreateHead->next->data);
			CreateHead = CreateHead->next;
		}
		printf("\n");
	}

	if(!head)
		printf("adfsadfsadfasdf\n");
	if(head!=NULL)
		printf("adfsadfsadfasdfadfsadfsadfasdf\n");

/*****************测试删除链表节点DeleteNode(linklist *head, int val)*****************/
	{
		linklist *BeforeDelete, *AfterDelete;
		int i, val, NodeNum;

		BeforeDelete = head;
		if(BeforeDelete==NULL || BeforeDelete->next==NULL)
		{
			printf("空链表或只含头结点！无法完成删除结点操作！\n");
			return;
		}
		printf("\n请输入待删除的节点的值：");
		scanf("%d", &val);
		AfterDelete = DeleteNode(BeforeDelete, val);
		printf("\n删除结点后的链表为：");
		NodeNum = CountNodeNum(AfterDelete, 1);		
		for(i=0; i<NodeNum; i++)
		{
			printf("%d ", AfterDelete->next->data);
			AfterDelete = AfterDelete->next;
		}
		printf("\n");
	}

/*****************测试删除链表节点DeleteLoc(linklist *head, int Loc)*****************/
	//{
	//	linklist *BeforeDelete, *AfterDelete;
	//	int i, Loc, NodeNum;

	//	BeforeDelete = head;
	//	if(BeforeDelete==NULL || BeforeDelete->next==NULL)
	//	{
	//		printf("空链表或只含头结点！无法完成删除结点操作！\n");
	//		return;
	//	}
	//	printf("\n请输入待删除的节点位置(1~%d)：", CountNodeNum(BeforeDelete, 1));
	//	scanf("%d", &Loc);
	//	AfterDelete = DeleteLoc(BeforeDelete, Loc);
	//	printf("\n删除结点后的链表为：");
	//	NodeNum = CountNodeNum(AfterDelete, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterDelete->next->data);
	//		AfterDelete = AfterDelete->next;
	//	}
	//	printf("\n");
	//}

/*****************测试插入链表节点InsertLoc(linklist *head, int Loc, int val)*****************/
	//{
	//	linklist *BeforeInsert, *AfterInsert;
	//	int i, Loc, val, NodeNum;

	//	BeforeInsert = head;
	//	if(BeforeInsert==NULL)
	//	{
	//		printf("空链表，无法完成插入操作！\n");
	//		return;
	//	}
	//	printf("\n请输入待插入的节点位置(0~%d)(i表示在第i个结点之后插入)：", CountNodeNum(BeforeInsert, 1));
	//	scanf("%d", &Loc);
	//	printf("\n请输入待插入的节点的值：");
	//	scanf("%d", &val);
	//	AfterInsert = InsertLoc(BeforeInsert, Loc, val);
	//	printf("\n插入结点后的链表为：");
	//	NodeNum = CountNodeNum(AfterInsert, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterInsert->next->data);
	//		AfterInsert = AfterInsert->next;
	//	}
	//	printf("\n");
	//}

/*****************测试反转链表ResverLinklist(linklist *head)*****************/
	//{
	//	linklist *BeforeResver, *AfterResver;
	//	int i, NodeNum;

	//	BeforeResver = head;
	//	if(BeforeResver==NULL || BeforeResver->next==NULL)
	//	{
	//		printf("存在空链表或只有头结点！\n");
	//		return;
	//	}
	//	AfterResver = ResverLinklist(BeforeResver);
	//	printf("\n反转后的链表为：");
	//	NodeNum = CountNodeNum(AfterResver, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterResver->next->data);
	//		AfterResver = AfterResver->next;
	//	}
	//	printf("\n");
	//}

/*****************测试链表是否交叉IsCross(linklist *head1, linklist *head2)*****************/
	//{
	//	linklist *BeforeCross1, *BeforeCross2, *AfterCross;
	//	int i, NodeNum;

	//	BeforeCross1 = head;
	//	if(BeforeCross1==NULL || BeforeCross1->next==NULL)
	//	{
	//		printf("存在空链表或只有头结点！链表不交叉！\n");
	//		return;
	//	}
	//	//BeforeCross2 = NULL;
	//	BeforeCross2 = CreateLinklistRear();		
	//	if(BeforeCross2==NULL || BeforeCross2->next==NULL)
	//	{
	//		printf("存在空链表或只有头结点！链表不交叉！\n");
	//		return;
	//	}
	//	BeforeCross2->next->next = BeforeCross1->next->next->next;
	//	AfterCross = IsCross(BeforeCross1, BeforeCross2);
	//	if(AfterCross==NULL)
	//	{
	//		printf("链表不交叉！\n");
	//		return;
	//	}
	//	else
	//	{
	//		printf("\n链表发生交叉！交叉点及后续节点为：");
	//		NodeNum = CountNodeNum(AfterCross, 0);		
	//		for(i=0; i<NodeNum; i++)
	//		{
	//			printf("%d ", AfterCross->data);
	//			AfterCross = AfterCross->next;
	//		}
	//		printf("\n");
	//	}
	//}	

/*****************测试链表是否含环IsLoop(linklist *head)*****************/
	//{
	//	linklist *BeforeLoop, *AfterLoop;
	//	int i, NodeNum;

	//	BeforeLoop = head;
	//	if(BeforeLoop==NULL || BeforeLoop->next==NULL)
	//	{
	//		printf("存在空链表或只有头结点!\n");
	//		return;
	//	}
	//	BeforeLoop->next->next->next->next = BeforeLoop->next->next;
	//	AfterLoop = IsLoop(BeforeLoop);
	//	if(AfterLoop==NULL)
	//	{
	//		printf("链表不含环！\n");
	//		return;
	//	}
	//	else
	//	{
	//		printf("\n链表含环！环的入口节点为：");
	//		NodeNum = 1;		
	//		for(i=0; i<NodeNum; i++)
	//		{
	//			printf("%d ", AfterLoop->data);
	//			//AfterLoop = AfterLoop->next;
	//		}
	//		printf("\n");
	//	}
	//}

///*****************测试链表排序SortLinklist(linklist *head)*****************/
//	{
//		linklist *BeforeSort, *AfterSort;
//		int i, NodeNum;
//
//		BeforeSort = head;
//		if(BeforeSort==NULL || BeforeSort->next==NULL)
//		{
//			printf("存在空链表或只有头结点!\n");
//			return;
//		}
//		AfterSort = SortLinklist(BeforeSort);
//
//		printf("\n排序后的链表为：");
//		NodeNum = CountNodeNum(AfterSort,1);
//		for(i=0; i<NodeNum; i++)
//		{
//			printf("%d ", AfterSort->next->data);
//			AfterSort = AfterSort->next;
//		}
//		printf("\n");
//	}
}