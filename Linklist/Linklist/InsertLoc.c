#include<stdlib.h>
#include "nodedef.h"
/*********************************************************************
* �������ƣ�linklist *InsertLoc(linklist *head, int Loc, int val)
* �������ܣ��������ָ��λ�ò�����
* ��    ����head----�����ͷ���
			Loc-----��Ҫ����Ľ�����ڵ�λ�ã���ΧΪ0~N(NΪ������)
			val-----����������������ֵ
* �� �� ֵ����ָ��λ�ò������������ͷ���
* ˵    ������ָ��λ��Loc֮�������
*********************************************************************/
extern linklist *InsertLoc(linklist *head, int Loc, int val)
{
	int LinklistLen=0;  // ��ʼ��������
	linklist *tmp=head, *p=head;  // ��ʱ���
	linklist *newnode=(linklist *)malloc(sizeof(linklist)); // �½�������Ľ��
	newnode->data = val;  // �Դ�����Ľ���������ֵ
	if(head==NULL)
		return newnode;
	// ͳ�������ȣ��������������㣩
	while(tmp->next!=NULL)
	{
		LinklistLen++;
		tmp = tmp->next;
	}
	// �������Ĳ�����λ��С��0��0��ʾ��ͷ������룩�򳬳������ȣ���ӡ������Ϣ������������ͷ���
	if(Loc<0 || Loc>LinklistLen)
	{
		printf("��������ȷ��Ҫ����Ľ��λ��(0��ʾ���뵽ͷ���֮��)(0~%d)", LinklistLen);
		return head;
	}
	// ��ȡ������λ�õĽ�㣨������1����Ѱ�ҵ�1���ڵ㣨����ͷ��㣩��
	while(Loc--)
		p = p->next;
	// ��������Ľ�����������
	newnode->next = p->next; // ʹ������ָ�������λ�ý��ĺ�̽��
	p->next = newnode;  // �������㸳ֵ��������λ�ý��ĺ�̽��
	return head; // ���ز�����������ͷ���
}