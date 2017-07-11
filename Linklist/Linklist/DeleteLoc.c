#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：linklist *DeleteLoc(linklist *head, int Loc)
* 函数功能：在链表的指定位置删除结点
* 参    数：head----链表的头结点
			Loc-----需要删除的结点所在的位置，范围为1~N(N为链表长度)
* 返 回 值：删除指定位置结点后的链表的头结点
* 说    明：无
*********************************************************************/
extern linklist *DeleteLoc(linklist *head, int Loc)
{
	linklist *tmp=head, *p=head;  // 两个临时结点
	int LinklistLen=0;  // 初始化链表长度
	if(head==NULL)
	{
		printf("待插入的链表为空，删除不成功！");
		return NULL;
	}
	// 计算链表长度
	while(tmp->next!=NULL)
	{
		LinklistLen++;
		tmp = tmp->next;
	}
	// 如果输入的删除结点位置小于等于0（0表示头结点）或超出链表长度，打印错误信息，并返回链表头结点
	if(Loc<=0 || Loc>LinklistLen)
	{
		printf("请输入正确的要删除的结点位置(1~%d)！删除不成功！", LinklistLen);
		return head;
	}
	// 获取待删除结点的前驱结点
	while(--Loc)
		p = p->next;
	// 将待删除结点的前驱结点指向待删除结点的后继结点，也即删除待删除的结点
	p->next = p->next->next;
	return head;  // 返回删除指定结点后的链表头结点
}