#include<iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// write code here
	if (l1 == nullptr) {
		return l2;
	}
	else if (l2 == nullptr) {
		return l1;
	}
	ListNode* tmphead1 = l1; ListNode* tmphead2 = l2;
	ListNode* newhead = new ListNode();
	newhead->val = 0; newhead->next = nullptr;
	ListNode* rethead = newhead;
	while (tmphead1 != nullptr && tmphead2 != nullptr) {
		if (tmphead1->val > tmphead2->val) {
			newhead->next = tmphead2;
			tmphead2 = tmphead2->next;
		}
		else
		{
			newhead->next = tmphead1;
			tmphead1 = tmphead1->next;
		}
		newhead = newhead->next;
	}
	ListNode* tmpNode = tmphead1 == nullptr ? tmphead2 : tmphead1;
	while (tmpNode != nullptr) {
		newhead->next = tmpNode;
		newhead = newhead->next;
		tmpNode = tmpNode->next;
	}
	newhead->next = nullptr;
	return rethead->next;
}
 