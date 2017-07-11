/************************************************************************/
/* ��Ŀ��http://blog.csdn.net/doc_sgl/article/details/11805519
/* ����һ��ֱ��ͼ����ֱ��ͼ���ܹ���ɵ����о����У�������Ϊ���١�
/************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea1(vector<int> &height);
int largestRectangleArea2(vector<int> &height);
void main() {
	//int a[] = {2,1,5,6,2,3};
	int a[] = {2,1,5,6,2,3,4,6,6,2,1};
	vector<int> h;
	for (int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		h.push_back(a[i]);
	}
	cout << largestRectangleArea2(h) << endl;
}

/************************************************************************/
/* ʱ�临�Ӷ�ΪO(N^2)�Ľⷨ
/* ����˼�룺���ν�ÿ�����εĵĸߵ��������εĸߣ����������ȡ���ֵ��
/************************************************************************/
int largestRectangleArea1(vector<int> &height) {
	int end = height.size();
	int begin = 0;
	int largestarea = 0;
	for(int i=begin; i<end; ++i)
	{
		int area;
		int high = height[i];
		for(int j=i; j<end; ++j){
			if(height[j] < high) {
				high = height[j];
			}
			area = (j-i+1) * high;
			if(area > largestarea) {
				largestarea = area;
			}
		}
	}
	return largestarea;
}

/************************************************************************/
/* ʱ�临�Ӷ�ΪO(N)�Ľⷨ
/* ����˼�룺ջ��ά��һ���߶ȵ����ľ����±꣬���������θ߶�HС��ջ��Ԫ��
/* ��Ӧ���εĸ߶�ʱ�����䵯��������Ϊ�߼����������ʱ����Ϊ1�����������
/* ������ж���ջ��Ԫ�ض�Ӧ���εĸ߶ȴ���Hʱ����ջ����������Ϊ�߼������
/* ����ʱ����Ϊ2����������������һֱ���µ�ջ��Ԫ�ض�Ӧ���εĸ߶�С��H��
/************************************************************************/
int Max(int a, int b) {
	return a > b ? a : b;
}  
int largestRectangleArea2(vector<int> &height) {  
	//height.push_back(0);  
	stack<int> stk;  
	int i = 0;  
	int maxArea = 0;  
	while(i < height.size()){  
		if(stk.empty() || height[stk.top()] <= height[i]){  
			stk.push(i++);  
		}else {  
			int t = stk.top();  
			stk.pop();  
			maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));  
		}  
	}  
	return maxArea;  
}