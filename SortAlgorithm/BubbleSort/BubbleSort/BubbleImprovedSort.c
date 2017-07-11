/****************************** 改进的冒泡排序 ******************************
函 数 名：int BubbleImprovedSort(int a[], int n)
参    数：int a[]---待排序的数据
		  int len---待排序数据的个数，也即数组a的长度
功    能：完成改进的冒泡排序
返 回 值：排序过程中发生交换的次数
基本思想：对冒泡排序常见的改进方法是加入一标志性变量exchange，用于标志某一趟
		  排序过程中是否有数据交换，如果进行某一趟排序时并没有进行数据交换，
		  则说明数据已经按要求排列好，可立即结束排序，避免不必要的比较过程。
说    明：排序好的数据依然存放在数组a中
*****************************************************************************/
int BubbleImprovedSort(int a[], int len)
{  
	int i, j, temp, CompareNum=0;
	int exchange; // 交换标志，若某趟排序中所有元素位置未发生交换则说明排序完成
    for(i=0; i<len-1; i++)  // 最多需len-1趟排序
	{
		exchange = 0;
        for(j=0; j<len-i-1; j++)  // 每趟排序最多需要len-i-1次比较
		{
            if(a[j] > a[j+1])   // 将较大的值放到后面
            {  
                temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				exchange = 1;
            }
			CompareNum++;  // 比较次数加1
		}
		if(exchange == 0)  // 说明某趟排序没有发生交换，也即排序完成，可以提前终止
			return CompareNum;
	}
	return CompareNum;
}  