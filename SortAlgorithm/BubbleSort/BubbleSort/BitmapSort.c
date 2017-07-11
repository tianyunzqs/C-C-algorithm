//λͼ���򷨣�ʱ�ո�Ч�����߾���
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
 
 #define BITSPERWORD 32
 #define SHIFT 5
 #define MASK 0x1F
 #define N 10000000
 #define M 20
 int a[1 + N/BITSPERWORD];
 
void set(int i){
    a[i >> SHIFT] |= (1<<(i & MASK));
}
void clr(int i){
    a[i >> SHIFT] &= ~(1<<(i & MASK));
}
int test(int i){
    return a[i >> SHIFT] & (1<<(i & MASK));
}

int myRand()   /* ����һ��0~1֮�������� */
{
  int num;
  num = rand() % 10000000;
  return num;
}
int main(void) {
    int i;
    int j;
    int arr[M];
    int count=0;
    for (i = 0; i < N; i++) {
        clr(i);
    }
    //while (scanf("%d", &i) != EOF) {
    //    set(i);
    //}
    srand( (unsigned)time( NULL ) );     //ע�������������Ӳ��ܷ��ڲ��������myRand()�����У�����ÿ�ε��ö����������ͬһ�������
    printf("The count of array is %d:/n",M);
    for (j = 0; j < M; j++) {    //���򵥵���ȷ�Բ���
        arr[j]=myRand();            //ע�⣬������������ظ�     //����ֻ����һ��
    printf("%d/t",arr[j]);
    }
   
    for (j = 0; j < M; j++) {    //���򵥵���ȷ�Բ���
        set(arr[j]);
    }
   
    printf("/nAfter Sorted:/n");
    for (i = 0; i < N; i++) {
        if (test(i)) {
        printf("%d/t", i);
        count++;
    }
    }
    printf("/nAfter sorted count is %d/n",count);    //��ӡ�����������ָ�����������ظ�������Ϊ���룬����������ֵĸ����������ǰ�١�
    return 0;
} 