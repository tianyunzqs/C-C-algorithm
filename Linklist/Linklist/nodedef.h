#pragma once
#ifndef _NODEDEF_H
#define _NODEDEF_H

#include<stdio.h>
/*********定义一个链表结点*********/
typedef struct node
{
	int data;   // 结点的数据域
	struct node *next;  // 结点的指针域
}linklist;

#endif