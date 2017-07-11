#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�linklist *DeleteLoc(linklist *head, int Loc)
* �������ܣ��������ָ��λ��ɾ�����
* ��    ����head----�����ͷ���
			Loc-----��Ҫɾ���Ľ�����ڵ�λ�ã���ΧΪ1~N(NΪ������)
* �� �� ֵ��ɾ��ָ��λ�ý���������ͷ���
* ˵    ������
*********************************************************************/
extern linklist *DeleteLoc(linklist *head, int Loc)
{
	linklist *tmp=head, *p=head;  // ������ʱ���
	int LinklistLen=0;  // ��ʼ��������
	if(head==NULL)
	{
		printf("�����������Ϊ�գ�ɾ�����ɹ���");
		return NULL;
	}
	// ����������
	while(tmp->next!=NULL)
	{
		LinklistLen++;
		tmp = tmp->next;
	}
	// ��������ɾ�����λ��С�ڵ���0��0��ʾͷ��㣩�򳬳������ȣ���ӡ������Ϣ������������ͷ���
	if(Loc<=0 || Loc>LinklistLen)
	{
		printf("��������ȷ��Ҫɾ���Ľ��λ��(1~%d)��ɾ�����ɹ���", LinklistLen);
		return head;
	}
	// ��ȡ��ɾ������ǰ�����
	while(--Loc)
		p = p->next;
	// ����ɾ������ǰ�����ָ���ɾ�����ĺ�̽�㣬Ҳ��ɾ����ɾ���Ľ��
	p->next = p->next->next;
	return head;  // ����ɾ��ָ�����������ͷ���
}