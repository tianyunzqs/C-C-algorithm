#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�linklist *ResverLinklist(linklist *head)
* �������ܣ���ת������������
* ��    ����head----�����ͷ���
* �� �� ֵ����ת�����������ͷ���
* ˵    ����˳��ÿ���ڵ��Ƶ�ͷ���ĺ�̽��λ���ϣ�����ͷ�巨��������
*********************************************************************/
extern linklist *ResverLinklist(linklist *head)
{
	// ��ͷ���������ʱ����ת����������ģ��½�һ������ͷ��㣩
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


	// ��ͷ��㲻�������ʱ����ת�����������
	linklist *current, *p;	// current���浱ǰ�ڵ�
	if(head==NULL)
		return NULL;
	current = head->next;   // ʹ��ǰ�ڵ�ָ���һ���ڵ�
	// �����ǰ�ڵ�ĺ�̽�㲻Ϊ�գ��򽫵�ǰ�ڵ�ĺ�̽���Ƶ�ͷ���ĺ�̽��λ����
    while(current->next != NULL)
    {
        p = current->next;
        current->next = p->next;
        p->next = head->next;
        head->next = p;
    }
	return head; // ���ط�ת�������ͷ���
}