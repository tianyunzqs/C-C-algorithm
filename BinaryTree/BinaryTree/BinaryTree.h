// 将二叉树的结点及相关操作定义为一个头文件

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

// 定义二叉树的结点
typedef struct btreenode
{
	char data;   // 数据域
	struct btreenode *lchild;  // 左孩子指针
	struct btreenode *rchild;  // 右孩子指针
}btnode, *btnodePoint;
// 注意btnode, *btnodePoint
// btnode定义的是结构体变量，btnodePoint定义的是结构体指针变量
// btnode *bt与btnodePoint bt是等价的，bt都是结构体指针变量
// http://blog.sina.com.cn/s/blog_8bba7b400102w2qj.html

btnode *CtreateBinaryTree(char *str);  // 建立二叉树

void PreOrder(btnode *bt);    // 二叉树的先序遍历 ---}
void InOrder(btnode *bt);     // 二叉树的中序遍历 ---}->二叉树的深度优先遍历  
void PostOrder(btnode *bt);   // 二叉树的后序遍历 ---}
void LeverlOrder(btnode *bt); // 二叉树的层次遍历 ----->二叉树的广度优先遍历

unsigned int LeafNodeNum(btnode *bt); // 统计二叉树度为0的结点(叶子结点)个数
unsigned int OneDegree(btnode *bt);   // 统计二叉树度为1的结点个数
unsigned int TwoDegree(btnode *bt);   // 统计二叉树度为1的结点个数
unsigned int BinaryTreeHigh(btnode *bt); // 计算二叉树的高度

unsigned int IsSortBinaryTree(btnode *bt); // 判断给定的二叉树是否为二叉排序树
btnode *InsertNodeToSortTree(btnode *bt, char val); // 二叉排序树的插入操作
btnode *CreateSortBinaryTree(char str[]);  // 建立二叉排序树

#endif