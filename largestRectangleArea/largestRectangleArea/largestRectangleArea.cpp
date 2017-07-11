/************************************************************************/
/* 题目：http://blog.csdn.net/doc_sgl/article/details/11805519
/* 给定一个直方图，求直方图中能够组成的所有矩形中，面积最大为多少。
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
/* 时间复杂度为O(N^2)的解法
/* 基本思想：依次将每个矩形的的高当作最大矩形的高，计算面积，取最大值。
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
/* 时间复杂度为O(N)的解法
/* 基本思想：栈中维护一个高度递增的矩形下标，当遇到矩形高度H小于栈顶元素
/* 对应矩形的高度时，将其弹出，并作为高计算面积（此时长度为1），更新最大
/* 面积。判断新栈顶元素对应矩形的高度大于H时，出栈，并将其作为高计算面积
/* （此时长度为2），更新最大面积。一直到新的栈顶元素对应矩形的高度小于H。
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