#include<stdlib.h>
#include "nodedef.h"

// 1.最简单的方法就是先顺序访问其中一个链表，在每访问一个节点时，都对另外一个链表进行遍历，看节点是否相等
// 直到找到一个相等的节点位置，如果链表长度分别是m,n 则时间复杂度为O(mn)
// 2.我们可以知道如果两个链表有公共节点，那么该公共节点之后的所有节点都是两个链表所共有的，所以长度一定也是
// 相等的，如果两个链表的总长度是相等的，那么我们对两个链表进行遍历，则一定同时到达第一个公共节点。但是链表
// 的长度实际上不一定相同，所以我们只需要计算出两个链表的长度之差n，然后让长的那个链表先移动n步，短的链表再
// 开始向后遍历，这样他们一定同时到达第一个公共节点，我们只需要在向后移动的时候比较两个链表的节点是否相等就
// 可以获得第一个公共节点。时间复杂度是O(m+n)
// 3.我们可以将其中一个链表的首尾相连，然后判断另一个链表是否含环。如果含环，则两链表交叉；否则，不交叉。
// 时间复杂度是O(max[m,n])

/*********************************************************************
* 函数名称：linklist *IsCross(linklist *head1, linklist *head2)
* 函数功能：判断两个链表是否交叉。
			如果交叉，则返回head1链表的交叉点；
			否则，返回NULL			
* 参    数：head1----第一个链表的头结点
			head2----第二个链表的头结点
* 返 回 值：交叉点，无交叉返回NULL
* 说    明：无
*********************************************************************/
extern linklist *IsCross(linklist *head1, linklist *head2)
{
	linklist *tp1=head1, *tp2=head2;
	int NodeNum1=0, NodeNum2=0;  // 初始化2链表节点个数
	if(head1==NULL || head2==NULL)
		return NULL;
	// 统计链表1的节点个数
	while(tp1->next!=NULL)
	{
		NodeNum1++;
		tp1 = tp1->next;
	}
	// 统计链表2的节点个数
	while(tp2->next!=NULL)
	{
		NodeNum2++;
		tp2 = tp2->next;
	}
	if(tp1!=tp2)  // 如果两链表的最后一个节点都不一样，那么说明两链表无交叉点
		return NULL;
	else  // 两链表有交叉点
	{
		int i;
		tp1 = head1->next;
		tp2 = head2->next;
		if(NodeNum1 > NodeNum2)
		{
			for(i=0; i<NodeNum1-NodeNum2; i++)			
				tp1 = tp1->next;
			while(tp1->next!=NULL)
				if(tp1==tp2)
					return tp1;
				else
				{
					tp1 = tp1->next;
					tp2 = tp2->next;
				}
		}
		else
		{
			for(i=0; i<NodeNum2-NodeNum1; i++)			
				tp2 = tp2->next;
			while(tp1->next!=NULL)
				if(tp1==tp2)
					return tp1;
				else
				{
					tp1 = tp1->next;
					tp2 = tp2->next;
				}
		}
	}
	
}