#ifndef _SORTMETHOD_H
#define _SORTMETHOD_H

void show(int a[], int len);  // 显示函数
int  BubbleSort(int a[], int len);  // 冒泡排序
int  BubbleImprovedSort(int a[], int len); // 改进的冒泡排序
void QuickSort(int a[], int low, int high);  // 快速排序
void StraightInsertSort(int a[], int len); // 简单插入排序(直接插入排序)
void ShellSort(int a[], int len);  // 希尔排序
void SimpleSelectionSort(int a[], int len);  // 简单选择排序(直接选择排序)
void HeapSort(int a[], int n);  // 堆排序

#endif