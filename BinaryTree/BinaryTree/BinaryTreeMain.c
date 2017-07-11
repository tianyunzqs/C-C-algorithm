#include <stdio.h>
#include "BinaryTree.h"
void main()
{
	btnode *bt, *sbt;
	unsigned int num;
	//char *str = "AB#DG##H##CE##F##";
	//char *str = "-+a##*b##-c##d##/e##f##";
	//char *str = "831##64##7##A#DC###";  // 二叉排序树
	char *str = "C52##9##IFD##H##J##";    // 二叉排序树
	bt = CtreateBinaryTree(str);
	printf("对所创建的二叉树进行先序遍历：");
	PreOrder(bt);
	printf("\n");
	printf("对所创建的二叉树进行中序遍历：");
	InOrder(bt);
	printf("\n");
	printf("对所创建的二叉树进行后序遍历：");
	PostOrder(bt);
	printf("\n");
	printf("对所创建的二叉树进行层次遍历：");
	LeverlOrder(bt);
	printf("\n");
	printf("所创建的二叉树的度为0的结点(叶子结点)个数：");
	num = LeafNodeNum(bt);
	printf("%u\n", num);
	printf("所创建的二叉树的度为1的结点个数：");
	num = OneDegree(bt);
	printf("%u\n", num);
	printf("所创建的二叉树的度为2的结点个数：");
	num = TwoDegree(bt);
	printf("%u\n", num);
	printf("所创建的二叉树的高度：");
	num = BinaryTreeHigh(bt);
	printf("%u\n", num);
	printf("所创建的二叉树是二叉排序树？ ");
	num = IsSortBinaryTree(bt);
	printf("%s\n", num==1 ? "Yes" : "NO");
	printf("**************************************************\n");
	printf("**************************************************\n");
	sbt = CreateSortBinaryTree(str);
	sbt = InsertNodeToSortTree(sbt, 'E');
	sbt = InsertNodeToSortTree(sbt, 'F');
	printf("对二叉排序树插入结点后进行中序遍历：");
	InOrder(sbt);
	printf("\n");
}