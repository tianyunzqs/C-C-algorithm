#include <stdio.h>
#include "BinaryTree.h"
/**************************************************************
* �������ƣ�unsigned int IsSortBinaryTree(btnode *bt)
* ��    ����bt----�������ĸ����
* �������ܣ��жϸ����Ķ������Ƿ�Ϊ����������
* �� �� ֵ���ǣ�����1���񣬷���0
* ˵    �������ö��������������ʼ���α�����˼������ж�
**************************************************************/
unsigned int IsSortBinaryTree(btnode *bt)
{
	int front=0, rear=0;  // ���ö�ͷ���β
	btnodePoint queue[20], p; // ���д�С����ݽ�������������pΪ��ʱ���ָ��
	if(bt!=NULL)
	{
		queue[rear++] = bt;  // �Ƚ��������ĸ�������
		while(front!=rear)  // �����ȣ����ʾ�������������
		{
			p = queue[front++]; // ˳�򽫲�α����õ��Ľ�����
			// �����������Ϊ�գ��Ҹ�����ֵ���ڵ������ӽ���ֵ��
			// ��ô���϶������������򣬽����ӽ����������
			if(p->lchild!=NULL && p->data >= p->lchild->data)  
				queue[rear++] = p->lchild;  // �ȷ�����
			// �����������Ϊ�գ��Ҹ�����ֵС�ڵ����Һ��ӽ���ֵ��
			// ��ô���϶������������򣬽��Һ��ӽ����������
			if(p->rchild!=NULL && p->data <= p->rchild->data)
				queue[rear++] = p->rchild;  // �ٷ��Һ���
			// �����϶�����������򷵻�0
			if((p->lchild!=NULL&&p->data < p->lchild->data) || (p->rchild!=NULL&&p->data > p->rchild->data))
				return 0;
		}
		return 1;  // ������������ɣ��Ҷ����϶��������������򷵻�1
	}
	else  // ������Ϊ��
		return 0;
}