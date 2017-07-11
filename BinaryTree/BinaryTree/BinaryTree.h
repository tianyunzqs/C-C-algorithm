// ���������Ľ�㼰��ز�������Ϊһ��ͷ�ļ�

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

// ����������Ľ��
typedef struct btreenode
{
	char data;   // ������
	struct btreenode *lchild;  // ����ָ��
	struct btreenode *rchild;  // �Һ���ָ��
}btnode, *btnodePoint;
// ע��btnode, *btnodePoint
// btnode������ǽṹ�������btnodePoint������ǽṹ��ָ�����
// btnode *bt��btnodePoint bt�ǵȼ۵ģ�bt���ǽṹ��ָ�����
// http://blog.sina.com.cn/s/blog_8bba7b400102w2qj.html

btnode *CtreateBinaryTree(char *str);  // ����������

void PreOrder(btnode *bt);    // ��������������� ---}
void InOrder(btnode *bt);     // ��������������� ---}->��������������ȱ���  
void PostOrder(btnode *bt);   // �������ĺ������ ---}
void LeverlOrder(btnode *bt); // �������Ĳ�α��� ----->�������Ĺ�����ȱ���

unsigned int LeafNodeNum(btnode *bt); // ͳ�ƶ�������Ϊ0�Ľ��(Ҷ�ӽ��)����
unsigned int OneDegree(btnode *bt);   // ͳ�ƶ�������Ϊ1�Ľ�����
unsigned int TwoDegree(btnode *bt);   // ͳ�ƶ�������Ϊ1�Ľ�����
unsigned int BinaryTreeHigh(btnode *bt); // ����������ĸ߶�

unsigned int IsSortBinaryTree(btnode *bt); // �жϸ����Ķ������Ƿ�Ϊ����������
btnode *InsertNodeToSortTree(btnode *bt, char val); // �����������Ĳ������
btnode *CreateSortBinaryTree(char str[]);  // ��������������

#endif