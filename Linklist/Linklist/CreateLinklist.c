#include<stdlib.h>
#include "nodedef.h"

#define CreateLinklistWay 1   // 0��ʾͷ�巨��������1��ʾβ�巨��������

#if !CreateLinklistWay

/*********************************************************************
* �������ƣ�linklist *CreateLinklistHead()
* �������ܣ�����ͷ�巨��������
* ��    ������
* �� �� ֵ������������������ͷ���
* ˵    ������
*********************************************************************/
extern linklist *CreateLinklistHead()
{
	int x, i, nodeNum;
	linklist *head, *temp;  // ͷ�������ʱ���
	head = (linklist *)malloc(sizeof(linklist));  // ���ɱ�ͷ���
	head->next = NULL;   // ����ͷ����ָ����ֵ
	printf("�����������н��ĸ�����");
	scanf("%d", &nodeNum);
	for(i=1; i<=nodeNum; i++)
	{
		printf("������� %d ���������ݣ�", i);
		scanf("%d", &x);
		temp = (linklist *)malloc(sizeof(linklist));  // �����µĽ��
		temp->data = x;    // ���½���������ֵ
		// ���½��嵽ͷ���֮��
		temp->next = head->next; 
		head->next = temp;
	}
	return head;  // �����½������ͷ���
}

#else

/*********************************************************************
* �������ƣ�linklist *CreateLinklistRear()
* �������ܣ�����β�巨��������
* ��    ������
* �� �� ֵ������������������ͷ���
* ˵    ������
*********************************************************************/
extern linklist *CreateLinklistRear()
{
	int x, i, nodeNum;
	linklist *head, *rear, *temp;  // ����ͷ��㡢β������ʱ���
	head = (linklist *)malloc(sizeof(linklist));  // ���ɱ�ͷ��㣬��ͷ��㲻�������
	head->next = NULL;  // ����ͷ����ָ����ֵΪNULL
	rear = head;  // ����ͷ��㸳ֵ����β���
	printf("�����������н��ĸ�����");
	scanf("%d", &nodeNum);
	for(i=1; i<=nodeNum; i++)
	{
		printf("������� %d ���������ݣ�", i);
		scanf("%d", &x);
		temp = (linklist *)malloc(sizeof(linklist));  // �����µĽ��
		temp->data = x;   // ��������������
		temp->next = NULL; // ��������ָ����������β�巨�����Բ���Ľ�㶼��β������ָ����ΪNULL��
		rear->next = temp; // ʹǰһ�����ָ���������(head->next=temp)
		rear = temp;  // ��������㸳ֵ��β��㣨β�巨������Ľ����β����(rear=head->next)
	}
	//rear->next = NULL;  // ��β����ָ����ֵΪ�գ�Ϊ�˷�����������Ƿ�Ϊ������
	return head;  // ����ͷ���
}

#endif