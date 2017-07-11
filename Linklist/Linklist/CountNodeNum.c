#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：int CountNodeNum(linklist *head, int IncludeHead)
* 函数功能：统计链表的结点个数
* 参    数：head----链表的头结点
			IncludeHead----是否包含头结点，若包含，值为1；否则，值为0
* 返 回 值：链表的结点个数
* 说    明：节点个数不包括头结点（因为头结点不含信息）
*********************************************************************/
extern int CountNodeNum(linklist *head, int IncludeHead)
{
	int NodeNum=0;
	linklist *tmp=head;
	if(head==NULL)
		return NodeNum;
	while(tmp->next!=NULL)
	{
		NodeNum++;
		tmp = tmp->next;
	}
	if(IncludeHead)
		return NodeNum;
	else
		return NodeNum+1;
}