#ifndef LEETCODEOJ_H
#define LEETCODEOJ_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LeetCode {


public:
	vector<int> twoSum(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
	int merge(vector<int>& nums1, int m, vector<int>& nums2, int n, int k); // 返回2个有序数组中所有数的第k大的值
};

#endif