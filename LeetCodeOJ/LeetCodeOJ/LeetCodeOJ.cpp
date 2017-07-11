#include "LeetCodeOJ.h"

/************************************************************************/
/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].                                                                     */
/************************************************************************/
vector<int> LeetCode::twoSum(vector<int>& numbers, int target) {
	unordered_map<int, int> hashtable;
	vector<int> result;
	for(int i=0; i<numbers.size(); i++){
		hashtable[numbers[i]] = i;
	}
	for(int i=0; i<numbers.size(); i++){
		const int diff = target - numbers[i];
		if(hashtable.find(diff) != hashtable.end() && hashtable[diff] > i){
			result.push_back(i+1);
			result.push_back(hashtable[diff]+1);
			break;
		}
	}
	return result;
}

/************************************************************************/
/* 
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8                                                                     */
/************************************************************************/
ListNode* LeetCode::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* result = new ListNode(-1);  // 头结点
	ListNode* tmp = result;

	int carry = 0;
	l1 = l1->next; // 去掉头结点
	l2 = l2->next; // 去掉头结点
	while (l1 != NULL || l2 != NULL)
	{			
		int a1 = l1==NULL ? 0 : l1->val;
		int a2 = l2==NULL ? 0 : l2->val;
		int value = (a1 + a2 + carry) % 10;
		carry = (a1 + a2 + carry) / 10;
		tmp->next = new ListNode(value);
		tmp = tmp->next;
		l1 = l1==NULL ? NULL : l1->next;
		l2 = l2==NULL ? NULL : l2->next;
	}
	if (carry > 0)
	{
		tmp->next = new ListNode(carry);
	}
	return result->next;
}

/************************************************************************/
/* 3. Longest Substring Without Repeating Characters   
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
/************************************************************************/
int LeetCode::lengthOfLongestSubstring(string s) {
	const int ASCII_MAX = 255;
	int last[ASCII_MAX];  // 记录各字符的位置
	int start = 0;  // 开始位置
	fill(last, last+ASCII_MAX, -1);
	int max_len = 0;
	for(int i=0; i<s.size(); i++) {
		if (last[s[i]] >= start) {  // 发现重复字符
			max_len = max(max_len, i-start);
			start = last[s[i]] + 1;  // 开始位置更新为重复位置的下一个位置
		}
		last[s[i]] = i;  // 存放数组下标
	}
	return max(max_len, (int)s.size()-start);
}

/************************************************************************/
/* 88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) 
to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 
are m and n respectively.
                                                                 */
/************************************************************************/
void LeetCode::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int ia = m-1, ib = n-1, icur = m+n-1;
	while (ia>=0 && ib>=0) {
		nums1[icur--] = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--];
	}
	while(ib >= 0) {
		nums1[icur--] = nums2[ib--];
	}
}

// 返回2个有序数组中所有数的第k大的值
int LeetCode::merge(vector<int>& nums1, int m, vector<int>& nums2, int n, int k) {
	int ia = m-1, ib = n-1, icur = 0;
	int kthNum = nums1[0];
	while (ia>=0 && ib>=0) {
		kthNum = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--];
		icur++;
		if (icur == k) {
			return kthNum;
		}
	}
	if (ia < 0) {
		while(ib >= 0) {
			kthNum = nums2[ib--];
			icur++;
			if (icur == k) {
				return kthNum;
			}
		}
	} else {
		while(ia >= 0) {
			kthNum = nums1[ia--];
			icur++;
			if (icur == k) {
				return kthNum;
			}
		}
	}
	
}