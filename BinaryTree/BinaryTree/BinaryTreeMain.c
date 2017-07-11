#include <stdio.h>
#include "BinaryTree.h"
void main()
{
	btnode *bt, *sbt;
	unsigned int num;
	//char *str = "AB#DG##H##CE##F##";
	//char *str = "-+a##*b##-c##d##/e##f##";
	//char *str = "831##64##7##A#DC###";  // ����������
	char *str = "C52##9##IFD##H##J##";    // ����������
	bt = CtreateBinaryTree(str);
	printf("���������Ķ������������������");
	PreOrder(bt);
	printf("\n");
	printf("���������Ķ������������������");
	InOrder(bt);
	printf("\n");
	printf("���������Ķ��������к��������");
	PostOrder(bt);
	printf("\n");
	printf("���������Ķ��������в�α�����");
	LeverlOrder(bt);
	printf("\n");
	printf("�������Ķ������Ķ�Ϊ0�Ľ��(Ҷ�ӽ��)������");
	num = LeafNodeNum(bt);
	printf("%u\n", num);
	printf("�������Ķ������Ķ�Ϊ1�Ľ�������");
	num = OneDegree(bt);
	printf("%u\n", num);
	printf("�������Ķ������Ķ�Ϊ2�Ľ�������");
	num = TwoDegree(bt);
	printf("%u\n", num);
	printf("�������Ķ������ĸ߶ȣ�");
	num = BinaryTreeHigh(bt);
	printf("%u\n", num);
	printf("�������Ķ������Ƕ����������� ");
	num = IsSortBinaryTree(bt);
	printf("%s\n", num==1 ? "Yes" : "NO");
	printf("**************************************************\n");
	printf("**************************************************\n");
	sbt = CreateSortBinaryTree(str);
	sbt = InsertNodeToSortTree(sbt, 'E');
	sbt = InsertNodeToSortTree(sbt, 'F');
	printf("�Զ����������������������������");
	InOrder(sbt);
	printf("\n");
}