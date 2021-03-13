#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int value) : val(value), next(nullptr) {};
};

/*
	方法1：值排序 直接使用数组进行自动排序
	方法2：归并排序
*/

ListNode* sortInList(ListNode* head) {
	// write code here
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	// 使用快慢指针找到链表的中点
	ListNode* slow = head, * fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// 分割为两个链表
	ListNode* newList = slow->next;
	slow->next = nullptr;
	// 将两个链表继续分割
	ListNode* left = sortInList(head);
	ListNode* right = sortInList(newList);

	ListNode* lhead = new ListNode(0);
	ListNode* retNode = lhead;
	while (left && right) {
		if (left->val < right->val) {
			lhead->next = left;
			left = left->next;
		}
		else {
			lhead->next = right;
			right = right->next;
		}
		lhead = lhead->next;
	}
	lhead->next = right == nullptr ? left : right;
	return retNode->next;
}
 