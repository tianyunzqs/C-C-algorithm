#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：linklist *DeleteNode(linklist *head, int val)
* 函数功能：删除链表中的结点
* 参    数：head----链表的头结点
			val-----需要删除的结点的值，若找到，删除；否则，不做处理
* 返 回 值：删除指定位置结点后的链表的头结点
* 说    明：无
*********************************************************************/
extern linklist *DeleteNode(linklist *head, int val)
{
	linklist *p1, *p2;
	if(head==NULL || head->next==NULL)
		return head;
	p1=head;
	p2=head->next;
	while(p2!=NULL)
	{
		if(p2->data == val)
		{
			p1->next = p2->next;
			// 删除所有相同的节点
			p2 = p2->next; 
			// 删除第一个相同的节点
			//free(p2);
			//p2 = NULL;
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
		}
	}
	return head;
}