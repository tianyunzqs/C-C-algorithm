#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：linklist *InsertLoc(linklist *head, int Loc, int val)
* 函数功能：在链表的指定位置插入结点
* 参    数：head----链表的头结点
			Loc-----需要插入的结点所在的位置，范围为0~N(N为链表长度)
			val-----待插入结点的数据域的值
* 返 回 值：在指定位置插入结点后的链表的头结点
* 说    明：在指定位置Loc之后插入结点
*********************************************************************/
extern linklist *InsertLoc(linklist *head, int Loc, int val)
{
	int LinklistLen=0;  // 初始化链表长度
	linklist *tmp=head, *p=head;  // 临时结点
	linklist *newnode=(linklist *)malloc(sizeof(linklist)); // 新建待插入的结点
	newnode->data = val;  // 对待插入的结点的数据域赋值
	if(head==NULL)
		return newnode;
	// 统计链表长度（不包括待插入结点）
	while(tmp->next!=NULL)
	{
		LinklistLen++;
		tmp = tmp->next;
	}
	// 如果输入的插入结点位置小于0（0表示在头结点后插入）或超出链表长度，打印错误信息，并返回链表头结点
	if(Loc<0 || Loc>LinklistLen)
	{
		printf("请输入正确的要插入的结点位置(0表示插入到头结点之后)(0~%d)", LinklistLen);
		return head;
	}
	// 获取待插入位置的结点（如输入1，则寻找第1个节点（不算头结点））
	while(Loc--)
		p = p->next;
	// 将待插入的结点插入链表中
	newnode->next = p->next; // 使插入结点指向待插入位置结点的后继结点
	p->next = newnode;  // 将插入结点赋值给待插入位置结点的后继结点
	return head; // 返回插入结点后的链表头结点
}