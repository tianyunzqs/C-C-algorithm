#pragma once
#ifndef _NODEDEF_H
#define _NODEDEF_H

#include<stdio.h>
/*********����һ��������*********/
typedef struct node
{
	int data;   // ����������
	struct node *next;  // ����ָ����
}linklist;

#endif