#ifndef _SORTMETHOD_H
#define _SORTMETHOD_H

void show(int a[], int len);  // ��ʾ����
int  BubbleSort(int a[], int len);  // ð������
int  BubbleImprovedSort(int a[], int len); // �Ľ���ð������
void QuickSort(int a[], int low, int high);  // ��������
void StraightInsertSort(int a[], int len); // �򵥲�������(ֱ�Ӳ�������)
void ShellSort(int a[], int len);  // ϣ������
void SimpleSelectionSort(int a[], int len);  // ��ѡ������(ֱ��ѡ������)
void HeapSort(int a[], int n);  // ������

#endif