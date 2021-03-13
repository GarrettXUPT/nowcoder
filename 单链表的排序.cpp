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
	����1��ֵ���� ֱ��ʹ����������Զ�����
	����2���鲢����
*/

ListNode* sortInList(ListNode* head) {
	// write code here
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	// ʹ�ÿ���ָ���ҵ�������е�
	ListNode* slow = head, * fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// �ָ�Ϊ��������
	ListNode* newList = slow->next;
	slow->next = nullptr;
	// ��������������ָ�
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
 