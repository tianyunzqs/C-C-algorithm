#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�int CountNodeNum(linklist *head, int IncludeHead)
* �������ܣ�ͳ������Ľ�����
* ��    ����head----�����ͷ���
			IncludeHead----�Ƿ����ͷ��㣬��������ֵΪ1������ֵΪ0
* �� �� ֵ������Ľ�����
* ˵    �����ڵ����������ͷ��㣨��Ϊͷ��㲻����Ϣ��
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