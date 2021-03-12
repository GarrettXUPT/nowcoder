#include<iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int value) : val(value), next(nullptr) {};
};


ListNode* reverseList(ListNode* head) {
	ListNode* preNode = nullptr;
	ListNode* curNode = head;
	while (curNode != nullptr) {
		ListNode* nextNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	return preNode;
}

ListNode* addInList(ListNode* head1, ListNode* head2) {
	// write code here
	if (head1 == nullptr) {
		return head2;
	}
	else if (head2 == nullptr) {
		return head1;
	}
	ListNode* rhead1 = reverseList(head1);
	ListNode* rhead2 = reverseList(head2);
	int carry = 0;
	ListNode* newhead = new ListNode(0);
	ListNode* tmphead = newhead;
	while (rhead1 != nullptr && rhead2 != nullptr) {
		int tmp = rhead1->val + rhead2->val + carry;
		ListNode* tmpNode = new ListNode(tmp % 10);
		carry = tmp / 10;
		tmphead->next = tmpNode;
		tmphead = tmphead->next;
		rhead1 = rhead1->next; rhead2 = rhead2->next;
	}
	ListNode* node = rhead1 == nullptr ? rhead2 : rhead1;
	while (node != nullptr) {
		int tmp = node->val + carry;
		carry = tmp / 10;
		ListNode* tmpNode = new ListNode(tmp % 10);
		tmphead->next = tmpNode;
		tmphead = tmphead->next;
		node = node->next;
	}
	if (carry != 0) {
		ListNode* carNode = new ListNode(carry);
		tmphead->next = carNode;
		tmphead = tmphead->next;
	}
	tmphead->next = nullptr;
	ListNode* delNode = newhead;
	delete delNode;
	newhead = newhead->next;
	return reverseList(newhead);
}
 