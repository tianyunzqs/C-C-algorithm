#include<stdio.h>
#include<stdlib.h>
#include "nodedef.h"

#define CreateLinklistWay 1   // 0��ʾͷ�巨��������1��ʾβ�巨��������

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

/*****************���Դ�������CreateLinklistRear()*****************/
	{
		linklist *CreateHead;
		int i, NodeNum;

		CreateHead = head;
		if(CreateHead==NULL || CreateHead->next==NULL)
		{
			printf("�������ֻ��ͷ��������\n");
			return;
		}
		printf("\n����������Ϊ��");
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

/*****************����ɾ������ڵ�DeleteNode(linklist *head, int val)*****************/
	{
		linklist *BeforeDelete, *AfterDelete;
		int i, val, NodeNum;

		BeforeDelete = head;
		if(BeforeDelete==NULL || BeforeDelete->next==NULL)
		{
			printf("�������ֻ��ͷ��㣡�޷����ɾ����������\n");
			return;
		}
		printf("\n�������ɾ���Ľڵ��ֵ��");
		scanf("%d", &val);
		AfterDelete = DeleteNode(BeforeDelete, val);
		printf("\nɾ�����������Ϊ��");
		NodeNum = CountNodeNum(AfterDelete, 1);		
		for(i=0; i<NodeNum; i++)
		{
			printf("%d ", AfterDelete->next->data);
			AfterDelete = AfterDelete->next;
		}
		printf("\n");
	}

/*****************����ɾ������ڵ�DeleteLoc(linklist *head, int Loc)*****************/
	//{
	//	linklist *BeforeDelete, *AfterDelete;
	//	int i, Loc, NodeNum;

	//	BeforeDelete = head;
	//	if(BeforeDelete==NULL || BeforeDelete->next==NULL)
	//	{
	//		printf("�������ֻ��ͷ��㣡�޷����ɾ����������\n");
	//		return;
	//	}
	//	printf("\n�������ɾ���Ľڵ�λ��(1~%d)��", CountNodeNum(BeforeDelete, 1));
	//	scanf("%d", &Loc);
	//	AfterDelete = DeleteLoc(BeforeDelete, Loc);
	//	printf("\nɾ�����������Ϊ��");
	//	NodeNum = CountNodeNum(AfterDelete, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterDelete->next->data);
	//		AfterDelete = AfterDelete->next;
	//	}
	//	printf("\n");
	//}

/*****************���Բ�������ڵ�InsertLoc(linklist *head, int Loc, int val)*****************/
	//{
	//	linklist *BeforeInsert, *AfterInsert;
	//	int i, Loc, val, NodeNum;

	//	BeforeInsert = head;
	//	if(BeforeInsert==NULL)
	//	{
	//		printf("�������޷���ɲ��������\n");
	//		return;
	//	}
	//	printf("\n�����������Ľڵ�λ��(0~%d)(i��ʾ�ڵ�i�����֮�����)��", CountNodeNum(BeforeInsert, 1));
	//	scanf("%d", &Loc);
	//	printf("\n�����������Ľڵ��ֵ��");
	//	scanf("%d", &val);
	//	AfterInsert = InsertLoc(BeforeInsert, Loc, val);
	//	printf("\n������������Ϊ��");
	//	NodeNum = CountNodeNum(AfterInsert, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterInsert->next->data);
	//		AfterInsert = AfterInsert->next;
	//	}
	//	printf("\n");
	//}

/*****************���Է�ת����ResverLinklist(linklist *head)*****************/
	//{
	//	linklist *BeforeResver, *AfterResver;
	//	int i, NodeNum;

	//	BeforeResver = head;
	//	if(BeforeResver==NULL || BeforeResver->next==NULL)
	//	{
	//		printf("���ڿ������ֻ��ͷ��㣡\n");
	//		return;
	//	}
	//	AfterResver = ResverLinklist(BeforeResver);
	//	printf("\n��ת�������Ϊ��");
	//	NodeNum = CountNodeNum(AfterResver, 1);		
	//	for(i=0; i<NodeNum; i++)
	//	{
	//		printf("%d ", AfterResver->next->data);
	//		AfterResver = AfterResver->next;
	//	}
	//	printf("\n");
	//}

/*****************���������Ƿ񽻲�IsCross(linklist *head1, linklist *head2)*****************/
	//{
	//	linklist *BeforeCross1, *BeforeCross2, *AfterCross;
	//	int i, NodeNum;

	//	BeforeCross1 = head;
	//	if(BeforeCross1==NULL || BeforeCross1->next==NULL)
	//	{
	//		printf("���ڿ������ֻ��ͷ��㣡�������棡\n");
	//		return;
	//	}
	//	//BeforeCross2 = NULL;
	//	BeforeCross2 = CreateLinklistRear();		
	//	if(BeforeCross2==NULL || BeforeCross2->next==NULL)
	//	{
	//		printf("���ڿ������ֻ��ͷ��㣡�������棡\n");
	//		return;
	//	}
	//	BeforeCross2->next->next = BeforeCross1->next->next->next;
	//	AfterCross = IsCross(BeforeCross1, BeforeCross2);
	//	if(AfterCross==NULL)
	//	{
	//		printf("�������棡\n");
	//		return;
	//	}
	//	else
	//	{
	//		printf("\n���������棡����㼰�����ڵ�Ϊ��");
	//		NodeNum = CountNodeNum(AfterCross, 0);		
	//		for(i=0; i<NodeNum; i++)
	//		{
	//			printf("%d ", AfterCross->data);
	//			AfterCross = AfterCross->next;
	//		}
	//		printf("\n");
	//	}
	//}	

/*****************���������Ƿ񺬻�IsLoop(linklist *head)*****************/
	//{
	//	linklist *BeforeLoop, *AfterLoop;
	//	int i, NodeNum;

	//	BeforeLoop = head;
	//	if(BeforeLoop==NULL || BeforeLoop->next==NULL)
	//	{
	//		printf("���ڿ������ֻ��ͷ���!\n");
	//		return;
	//	}
	//	BeforeLoop->next->next->next->next = BeforeLoop->next->next;
	//	AfterLoop = IsLoop(BeforeLoop);
	//	if(AfterLoop==NULL)
	//	{
	//		printf("����������\n");
	//		return;
	//	}
	//	else
	//	{
	//		printf("\n��������������ڽڵ�Ϊ��");
	//		NodeNum = 1;		
	//		for(i=0; i<NodeNum; i++)
	//		{
	//			printf("%d ", AfterLoop->data);
	//			//AfterLoop = AfterLoop->next;
	//		}
	//		printf("\n");
	//	}
	//}

///*****************������������SortLinklist(linklist *head)*****************/
//	{
//		linklist *BeforeSort, *AfterSort;
//		int i, NodeNum;
//
//		BeforeSort = head;
//		if(BeforeSort==NULL || BeforeSort->next==NULL)
//		{
//			printf("���ڿ������ֻ��ͷ���!\n");
//			return;
//		}
//		AfterSort = SortLinklist(BeforeSort);
//
//		printf("\n����������Ϊ��");
//		NodeNum = CountNodeNum(AfterSort,1);
//		for(i=0; i<NodeNum; i++)
//		{
//			printf("%d ", AfterSort->next->data);
//			AfterSort = AfterSort->next;
//		}
//		printf("\n");
//	}
}