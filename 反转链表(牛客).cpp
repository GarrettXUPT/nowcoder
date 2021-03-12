#include<iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == nullptr) {
		return pHead;
	}
	ListNode* preNode = nullptr;
	ListNode* curNode = pHead;
	while (curNode != nullptr) {
		ListNode* nextNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	return preNode;
}