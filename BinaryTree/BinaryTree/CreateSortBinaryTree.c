#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/**************************************************************
* �������ƣ�btnode *CreateSortBinaryTree(char str[])
* ��    ����str----����������������������ַ�����
* �������ܣ�����һ������������
* �� �� ֵ�������Ķ����������ĸ����
* ˵    �����ȴ���һ��������֮��ÿ�����ֵ��������������У�
			�𲽽�������������
**************************************************************/
btnode *CreateSortBinaryTree(char str[])
{
	btnode *SortBinaryTreeRoot=(btnode *)malloc(sizeof(btnode)); // ������ռ�
	static int i=0;
	SortBinaryTreeRoot = NULL; // ����һ���ն�����
	while(str[i]!='\0')
	{
		if(str[i]!='#')  // '#'��ʾ����������������������Ŀս��
			// ���ν�ÿ������������������У��𲽽��������Ķ���������
			SortBinaryTreeRoot = InsertNodeToSortTree(SortBinaryTreeRoot, str[i]);
		i++;
	}
	return SortBinaryTreeRoot;  // ���ؽ����Ķ����������ĸ����
}