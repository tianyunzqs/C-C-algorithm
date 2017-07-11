#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* 函数名称：linklist *SortLinklist(linklist *head)
* 函数功能：链表排序
* 参    数：head----链表的头结点
* 返 回 值：按从小到大的顺序排序后的链表头结点
* 说    明：冒泡排序方法
*********************************************************************/
extern linklist *SortLinklist(linklist *head)
{
	linklist *tp=head, *pretp, *temp;
	if(head==NULL ||head->next==NULL)
		return head;
	while(1)
	{
		int flag=0;  // 标志位，当某趟排序没发生交换时，flag=0，此时说明排序完成
		tp = head->next;  // 将tp指针恢复，准备进行下一趟排序
		pretp = head;  // 将pretp指针恢复，准备进行下一趟排序
		while(tp->next!=NULL)
		{
			if(pretp->next->data > tp->next->data)  // 如果链表前一个节点的值大于后一个结点的值，则交换两结点
			{
				temp = tp->next;
				tp->next = temp->next;
				temp->next = pretp->next;
				pretp->next = temp;
				flag = 1;   // 如果发生交换，置标志位为1
			}
			pretp = pretp->next;  // 将pretp指针前进一个结点
			tp = pretp->next;	  // 将tp指针前进一个结点	
		}
		if(flag==0)  // 如果某趟排序没发生交换时，flag=0，此时说明排序完成，返回头结点
			return head;
	}
}