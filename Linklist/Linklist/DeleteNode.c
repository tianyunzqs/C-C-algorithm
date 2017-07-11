#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�linklist *DeleteNode(linklist *head, int val)
* �������ܣ�ɾ�������еĽ��
* ��    ����head----�����ͷ���
			val-----��Ҫɾ���Ľ���ֵ�����ҵ���ɾ�������򣬲�������
* �� �� ֵ��ɾ��ָ��λ�ý���������ͷ���
* ˵    ������
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
			// ɾ��������ͬ�Ľڵ�
			p2 = p2->next; 
			// ɾ����һ����ͬ�Ľڵ�
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