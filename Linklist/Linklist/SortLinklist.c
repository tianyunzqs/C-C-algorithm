#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�linklist *SortLinklist(linklist *head)
* �������ܣ���������
* ��    ����head----�����ͷ���
* �� �� ֵ������С�����˳������������ͷ���
* ˵    ����ð�����򷽷�
*********************************************************************/
extern linklist *SortLinklist(linklist *head)
{
	linklist *tp=head, *pretp, *temp;
	if(head==NULL ||head->next==NULL)
		return head;
	while(1)
	{
		int flag=0;  // ��־λ����ĳ������û��������ʱ��flag=0����ʱ˵���������
		tp = head->next;  // ��tpָ��ָ���׼��������һ������
		pretp = head;  // ��pretpָ��ָ���׼��������һ������
		while(tp->next!=NULL)
		{
			if(pretp->next->data > tp->next->data)  // �������ǰһ���ڵ��ֵ���ں�һ������ֵ���򽻻������
			{
				temp = tp->next;
				tp->next = temp->next;
				temp->next = pretp->next;
				pretp->next = temp;
				flag = 1;   // ��������������ñ�־λΪ1
			}
			pretp = pretp->next;  // ��pretpָ��ǰ��һ�����
			tp = pretp->next;	  // ��tpָ��ǰ��һ�����	
		}
		if(flag==0)  // ���ĳ������û��������ʱ��flag=0����ʱ˵��������ɣ�����ͷ���
			return head;
	}
}