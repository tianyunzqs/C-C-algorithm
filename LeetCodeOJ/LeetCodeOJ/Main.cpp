#include <iostream>
#include <string>
#include "LeetCodeOJ.h"
using namespace std;


static void test_twoSum() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(12);
	nums.push_back(15);
	LeetCode *LC = new LeetCode();
	vector<int> result = LC->twoSum(nums, 4);
	for (int i=0; i<result.size(); i++) {
		cout << result.at(i) << endl;
	}
}

static ListNode* CreateList(int val[], int nodeNum) {
	ListNode *head, *rear, *temp;  // ����ͷ��㡢β������ʱ���
	head = (ListNode *)malloc(sizeof(ListNode));  // ���ɱ�ͷ��㣬��ͷ��㲻�������
	head->next = NULL;  // ����ͷ����ָ����ֵΪNULL
	rear = head;  // ����ͷ��㸳ֵ����β���
	for(int i=1; i<=nodeNum; i++)
	{
		temp = (ListNode *)malloc(sizeof(ListNode));  // �����µĽ��
		temp->val = val[i-1];   // ��������������
		temp->next = NULL; // ��������ָ����������β�巨�����Բ���Ľ�㶼��β������ָ����ΪNULL��

		rear->next = temp;  // ʹǰһ�����ָ���������(head->next=temp)
		rear = rear->next;  // ��������㸳ֵ��β��㣨β�巨������Ľ����β����(rear=head->next)
	}
	rear->next = NULL;  // ��β����ָ����ֵΪ�գ�Ϊ�˷�����������Ƿ�Ϊ������
	return head;  // ����ͷ���
}

static void test_addTwoNumbers() {
	int val1[] = {1, 8};
	int val2[] = {0};
	/*int val1[] = {2, 4, 3};
	int val2[] = {5, 6, 4};*/
	ListNode* l1 = CreateList(val1, sizeof(val1)/sizeof(val1[0]));
	ListNode* l2 = CreateList(val2, sizeof(val2)/sizeof(val2[0]));

	LeetCode *LC = new LeetCode();
	ListNode* result = LC->addTwoNumbers(l1, l2);
	while(result != NULL)
	{
		cout << result->val << endl;
		result = result->next;
	}
	free(l1);
	free(l2);
	free(result);
}


static void test_lengthOfLongestSubstring() {
	string str = "ppppwke";
	LeetCode *LC = new LeetCode();
	cout << LC->lengthOfLongestSubstring(str) << endl;
}


static void test_merge() {
	vector<int> nums1(10);  // �洢�ռ���ڵ���m+n
	vector<int> nums2(3);
	nums1.at(0) = 1;
	nums1.at(1) = 2;
	nums1.at(2) = 3;
	nums1.at(3) = 4;
	nums1.at(4) = 5;
	nums1.at(5) = 6;
	
	nums2.at(0) = 2;
	nums2.at(1) = 5;
	nums2.at(2) = 16;

	vector<int> nums3(3);
	nums3.at(0) = 4;
	nums3.at(1) = 5;
	nums3.at(2) = 12;

	int m = 6, n = 3;  // nums1��nums2��Ԫ�ظ���
	LeetCode *LC = new LeetCode();
	LC->merge(nums1, m, nums2, n);
	for(int i=0; i<m+n; i++) {
		cout << nums1.at(i) << endl;
	}
	cout << LC->merge(nums2, nums2.size(), nums3, nums3.size(), 4) << endl;
	//for (vector<int> :: iterator it=nums1.begin(); it!=nums1.end(); it++) {
	//	cout << *it << endl;
	//}
}

void main() {
	//test_twoSum();
	//test_addTwoNumbers();
	//test_lengthOfLongestSubstring();
	test_merge();


	//unordered_map<string, int> hashtable;
	//hashtable["aa"] = 1;
	//hashtable["aa"] = 2;
	//hashtable["aa"] = 3;
	//hashtable["bb"] = 4;
	//for (unordered_map<string, int> ::iterator it=hashtable.begin(); it!=hashtable.end(); it++)
	//{
	//	cout << it->first + "\t";
	//	cout << it->second << endl;
	//}

	//map<string, int> maptable;
	//maptable.insert(make_pair("aa", 1));
	//maptable.insert(make_pair("aa", 2));
	//maptable.insert(make_pair("aa", 3));
	//maptable.insert(make_pair("bb", 4));
	//for (map<string, int>::iterator it=maptable.begin(); it!=maptable.end(); it++)
	//{
	//	cout << it->first + "\t";
	//	cout << it->second << endl;
	//}


	


}

