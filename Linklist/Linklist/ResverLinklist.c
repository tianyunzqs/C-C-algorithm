#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：linklist *ResverLinklist(linklist *head)
* 函数功能：反转链表（逆置链表）
* 参    数：head----链表的头结点
* 返 回 值：反转链表后的链表的头结点
* 说    明：顺序将每个节点移到头结点的后继结点位置上（类似头插法创建链表）
*********************************************************************/
extern linklist *ResverLinklist(linklist *head)
{
	// 当头结点存放数据时，反转链表用下面的（新建一个虚拟头结点）
	//linklist *newhead=(linklist *)malloc(sizeof(linklist)), *current, *p;	
	//current = head;
	//newhead->next = current;
 //   while(current->next != NULL)
 //   {
 //       p = current->next;
 //       current->next = p->next;
 //       p->next = newhead->next;
 //       newhead->next = p;
 //   }
	//return newhead->next;


	// 当头结点不存放数据时，反转链表用下面的
	linklist *current, *p;	// current保存当前节点
	if(head==NULL)
		return NULL;
	current = head->next;   // 使当前节点指向第一个节点
	// 如果当前节点的后继结点不为空，则将当前节点的后继结点移到头结点的后继结点位置上
    while(current->next != NULL)
    {
        p = current->next;
        current->next = p->next;
        p->next = head->next;
        head->next = p;
    }
	return head; // 返回反转后的链表头结点
}